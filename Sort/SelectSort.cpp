/*
 * @Author: farron_cat
 * @Date: 2021-09-12 09:26:54
 * @LastEditTime: 2021-09-12 10:14:40
 * @LastEditors: farron_cat
 * @Description: ��ѡ������
 * @FilePath: \Briup\learn\data_structure\Sort\SelectSort.cpp
 * ��Ȩ�鷨��Сè����
 */
typedef int ElemType;
//Ԫ�ش��±� 0��ʼ�洢
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
 *�ռ䣺O(1)
 *ʱ�䣺���� � 3(n-1)�� ��� 0��
        �Ƚ� n(n-1)/2��
 *      O(n^2)
 *�ȶ��ԣ����ȶ�
 */