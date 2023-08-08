/*
 * @Author: farron_cat
 * @Date: 2021-09-11 19:42:17
 * @LastEditTime: 2021-09-19 18:23:14
 * @LastEditors: farron_cat
 * @Description: 直接插入排序
 * @FilePath: \Briup\learn\data_structure\Sort\InsertSort.cpp
 * 版权归法兰小猫所有
 */

typedef int ElemType;
//A[0]为哨兵 元素从下标1开始存储
void InsertSort(ElemType A[], int n)
{
    int i, j;
    for (i = 2; i <= n; ++i)
    {
        if (A[i] < A[i - 1])
        {
            A[0] = A[i];
            for (j = i - 1; A[0] < A[j]; --j)
                A[j + 1] = A[j];
            A[j + 1] = A[0];
        }
    }
}

/*
 *空间：O(1)
 *时间：最好为有序，比较 n-1次 O(n)
 *      最坏为逆序，比较 2+3+...+n；移动 3+4+...+n+1
 *      平均总的比较次数与总的移动次数最为 n^2/4
 *      O(n^2)
 *稳定性：A[0]<A[j] 保证稳定
 */