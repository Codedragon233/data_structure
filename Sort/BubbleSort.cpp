/*
 * @Author: farron_cat
 * @Date: 2021-09-11 20:34:18
 * @LastEditTime: 2022-11-10 16:12:28
 * @LastEditors: farron_cat
 * @Description: ð������
 * @FilePath: \Briup\learn\data_structure\Sort\BubbleSort.cpp
 * ��Ȩ�鷨��Сè����
 */

typedef int ElemType;
//Ԫ�ش��±� 0��ʼ�洢
void BubbleSort(ElemType A[], int n)
{
    int i, j;
    bool flag;//������־
    for (i = 0; i < n - 1; ++i)//n-1��
    {
        flag = false;//һ�˿�ʼǰ��������־��Ϊfalse
        for (j = n - 1; j < i; --j)//��������ð�� iǰ�Ѿ�����
        {
            if (A[j - 1] < A[j])
            {
                ElemType temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;

                flag = true;//����������������־��Ϊtrue
            }
        }
        if (flag == false)//һ��û�н������Ѿ�����
            return;
    }
}

/*
 *�ռ䣺O(1)
 *ʱ�䣺������򣬱Ƚ� n-1�� O(n)
 *      �����n-1������ ��i�˱Ƚ�n-i�� ��ÿ�αȽϺ���3�ν��� O(n^2)
 *�ȶ��ԣ��ȶ�
 */