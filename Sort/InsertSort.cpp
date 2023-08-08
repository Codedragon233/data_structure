/*
 * @Author: farron_cat
 * @Date: 2021-09-11 19:42:17
 * @LastEditTime: 2021-09-19 18:23:14
 * @LastEditors: farron_cat
 * @Description: ֱ�Ӳ�������
 * @FilePath: \Briup\learn\data_structure\Sort\InsertSort.cpp
 * ��Ȩ�鷨��Сè����
 */

typedef int ElemType;
//A[0]Ϊ�ڱ� Ԫ�ش��±�1��ʼ�洢
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
 *�ռ䣺O(1)
 *ʱ�䣺���Ϊ���򣬱Ƚ� n-1�� O(n)
 *      �Ϊ���򣬱Ƚ� 2+3+...+n���ƶ� 3+4+...+n+1
 *      ƽ���ܵıȽϴ������ܵ��ƶ�������Ϊ n^2/4
 *      O(n^2)
 *�ȶ��ԣ�A[0]<A[j] ��֤�ȶ�
 */