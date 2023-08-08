/*
 * @Author: farron_cat
 * @Date: 2021-09-12 09:37:39
 * @LastEditTime: 2021-09-20 10:19:04
 * @LastEditors: farron_cat
 * @Description: 堆排序
 * @FilePath: \Briup\learn\data_structure\Sort\HeapSort.cpp
 * 版权归法兰小猫所有
 */

typedef int ElemType;
//A[0]辅助空间 元素从下标1开始存储
//调整
void HeadAdjust(ElemType A[], int k, int len) //调整k为根的子树
{
    int i;
    A[0] = A[k];                     //A[0]临时保存根内容
    for (i = 2 * k; i < len; i *= 2) //从k的左孩子开始，一路向下
    {
        if (i < len && A[i] < A[i + 1]) //左右孩子比较选择最大的
            i++;
        if (A[0] >= A[i]) //根和最大的孩子比较
            break;
        else
        {
            A[k] = A[i]; //根小于最大的孩子 将孩子放到根的位置
            k = i;       //根标记下移
        }
    }
    A[k] = A[0]; //将根放入最终位置
}

//构建大根堆
void BuildMaxHeap(ElemType A[], int len)
{
    for (int i = len / 2; i > 0; i--) //从最后一个非叶结点开始向上调整
        HeadAdjust(A, i, len);
}

//排序
void HeapSort(ElemType A[], int len)
{
    int i;
    BuildMaxHeap(A, len); //最初的堆
    for (i = len; i > 1; --i)
    {
        //顶和最后一个叶子交换
        ElemType temp = A[i];
        A[i] = A[1];
        A[1] = temp;

        HeadAdjust(A, 1, i - 1); //i-1后固定 调整之前的
    }
}

/*
 *空间：O(1)
 *时间：建堆 O(n) n-1次向下调整，每次调整O(h)
 *      最好最坏平均 O(nlogn)
 *稳定性：不稳定
 */
