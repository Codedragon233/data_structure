/*
 * @Author: farron_cat
 * @Date: 2021-09-11 20:34:18
 * @LastEditTime: 2022-11-10 16:12:28
 * @LastEditors: farron_cat
 * @Description: 冒泡排序
 * @FilePath: \Briup\learn\data_structure\Sort\BubbleSort.cpp
 * 版权归法兰小猫所有
 */

typedef int ElemType;
//元素从下标 0开始存储
void BubbleSort(ElemType A[], int n)
{
    int i, j;
    bool flag;//交换标志
    for (i = 0; i < n - 1; ++i)//n-1趟
    {
        flag = false;//一趟开始前将交换标志设为false
        for (j = n - 1; j < i; --j)//从左向右冒泡 i前已经有序
        {
            if (A[j - 1] < A[j])
            {
                ElemType temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;

                flag = true;//发生交换将交换标志设为true
            }
        }
        if (flag == false)//一趟没有交换则已经有序
            return;
    }
}

/*
 *空间：O(1)
 *时间：最好有序，比较 n-1次 O(n)
 *      最坏逆序，n-1趟排序 第i趟比较n-i次 ，每次比较后有3次交换 O(n^2)
 *稳定性：稳定
 */