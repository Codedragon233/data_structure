/*
 * @Author: farron_cat
 * @Date: 2021-09-11 20:00:26
 * @LastEditTime: 2022-11-10 16:12:30
 * @LastEditors: farron_cat
 * @Description: ϣ������
 * @FilePath: \Briup\learn\data_structure\Sort\ShellSort.cpp
 * ��Ȩ�鷨��Сè����
 */

typedef int ElemType;
//A[0]Ϊ�ڱ� Ԫ�ش��±�1��ʼ�洢
void ShellSort(ElemType A[], int n)
{
    int i,j,dk;
    for (dk = n / 2; dk >= 1; dk /= 2)
    {
        for (i = dk + 1; i <= n; ++i) //i = dk + 1���ӱ�ĵڶ���Ԫ�ؿ�ʼ   ++i���ڼ����ӱ�֮���л�����
        {
            if (A[i] < A[i - dk])
            {
                A[0] = A[i];
                for (j = i - dk; j > 0 && A[0] < A[j]; j-=dk) //ע�� j > 0 ��Ϊ����Ϊdk A[0]����ס
                {
                    A[j + dk] = A[j];  //�Ӻ���ǰ���κ���
                }
                A[j + dk] = A[0];
            }
        }
    }
}

/*
 *�ռ䣺O(1)
 *ʱ�䣺�����Ƚϸ��ӣ�n���ض���ΧʱԼΪO(n^1.3)
 *      � O(n^2)
 *�ȶ��ԣ����ܸı���Դ��� ���ȶ�
 */
