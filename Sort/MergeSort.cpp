/*
 * @Author: farron_cat
 * @Date: 2021-09-12 12:17:00
 * @LastEditTime: 2021-09-20 10:19:05
 * @LastEditors: farron_cat
 * @Description: 归并排序
 * @FilePath: \Briup\learn\data_structure\Sort\MergeSort.cpp
 * 版权归法兰小猫所有
 */

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#define N 20
typedef int ElemType;

//辅助数组B
int *B = (int *)malloc(N * sizeof(int)); //N为A的长度

void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    //A复制到辅助数组B中
    for (k = low; k <= high; k++)
        B[k] = A[k];
    
    //辅助数组中左右两段归并到A中 从小到大
    for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }

    //处理剩下的尾巴
    while (i <= mid)
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[j++];
}

void MergeSort(int A[], int low, int high)
{
    if (low < high)//递归出口
    {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);      //左半
        MergeSort(A, mid + 1, high); //右半
        Merge(A, low, mid, high);    //左右并归
    }
}

/*
 *分析时把归并过程看成倒立的二叉树，归并趟数是树高h-1趟，
 *归并元素个数n<=2^(h-1)   h-1 = logn 向下取整
 *
 *空间：辅助数组B O(n)
 *时间：每趟归并 O(n)
 *      总共 O(nlogn)
 *稳定性：稳定
 */