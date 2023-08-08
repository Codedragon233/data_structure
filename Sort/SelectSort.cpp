/*
 * @Author: farron_cat
 * @Date: 2021-09-12 09:26:54
 * @LastEditTime: 2021-09-12 10:14:40
 * @LastEditors: farron_cat
 * @Description: 简单选择排序
 * @FilePath: \Briup\learn\data_structure\Sort\SelectSort.cpp
 * 版权归法兰小猫所有
 */
typedef int ElemType;
//元素从下标 0开始存储
void SelectSort(ElemType A[], int n)
{
    int i,j,min;
    for (i = 0; i < n - 1; ++i)
    {
        min = i;
        for (j = i + 1; j < n; ++j)
            if (A[j] < A[min])
                min = j;
        if (min != i)
        {
            ElemType temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

/*
 *空间：O(1)
 *时间：交换 最坏 3(n-1)次 最好 0次
        比较 n(n-1)/2次
 *      O(n^2)
 *稳定性：不稳定
 */