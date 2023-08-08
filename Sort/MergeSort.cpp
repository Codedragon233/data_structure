/*
 * @Author: farron_cat
 * @Date: 2021-09-12 12:17:00
 * @LastEditTime: 2021-09-20 10:19:05
 * @LastEditors: farron_cat
 * @Description: �鲢����
 * @FilePath: \Briup\learn\data_structure\Sort\MergeSort.cpp
 * ��Ȩ�鷨��Сè����
 */

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#define N 20
typedef int ElemType;

//��������B
int *B = (int *)malloc(N * sizeof(int)); //NΪA�ĳ���

void Merge(int A[], int low, int mid, int high)
{
    int i, j, k;
    //A���Ƶ���������B��
    for (k = low; k <= high; k++)
        B[k] = A[k];
    
    //�����������������ι鲢��A�� ��С����
    for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }

    //����ʣ�µ�β��
    while (i <= mid)
        A[k++] = B[i++];
    while (j <= high)
        A[k++] = B[j++];
}

void MergeSort(int A[], int low, int high)
{
    if (low < high)//�ݹ����
    {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);      //���
        MergeSort(A, mid + 1, high); //�Ұ�
        Merge(A, low, mid, high);    //���Ҳ���
    }
}

/*
 *����ʱ�ѹ鲢���̿��ɵ����Ķ��������鲢����������h-1�ˣ�
 *�鲢Ԫ�ظ���n<=2^(h-1)   h-1 = logn ����ȡ��
 *
 *�ռ䣺��������B O(n)
 *ʱ�䣺ÿ�˹鲢 O(n)
 *      �ܹ� O(nlogn)
 *�ȶ��ԣ��ȶ�
 */