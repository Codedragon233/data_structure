/*
 * @Author: farron_cat
 * @Date: 2021-09-12 09:37:39
 * @LastEditTime: 2021-09-20 10:19:04
 * @LastEditors: farron_cat
 * @Description: ������
 * @FilePath: \Briup\learn\data_structure\Sort\HeapSort.cpp
 * ��Ȩ�鷨��Сè����
 */

typedef int ElemType;
//A[0]�����ռ� Ԫ�ش��±�1��ʼ�洢
//����
void HeadAdjust(ElemType A[], int k, int len) //����kΪ��������
{
    int i;
    A[0] = A[k];                     //A[0]��ʱ���������
    for (i = 2 * k; i < len; i *= 2) //��k�����ӿ�ʼ��һ·����
    {
        if (i < len && A[i] < A[i + 1]) //���Һ��ӱȽ�ѡ������
            i++;
        if (A[0] >= A[i]) //�������ĺ��ӱȽ�
            break;
        else
        {
            A[k] = A[i]; //��С�����ĺ��� �����ӷŵ�����λ��
            k = i;       //���������
        }
    }
    A[k] = A[0]; //������������λ��
}

//���������
void BuildMaxHeap(ElemType A[], int len)
{
    for (int i = len / 2; i > 0; i--) //�����һ����Ҷ��㿪ʼ���ϵ���
        HeadAdjust(A, i, len);
}

//����
void HeapSort(ElemType A[], int len)
{
    int i;
    BuildMaxHeap(A, len); //����Ķ�
    for (i = len; i > 1; --i)
    {
        //�������һ��Ҷ�ӽ���
        ElemType temp = A[i];
        A[i] = A[1];
        A[1] = temp;

        HeadAdjust(A, 1, i - 1); //i-1��̶� ����֮ǰ��
    }
}

/*
 *�ռ䣺O(1)
 *ʱ�䣺���� O(n) n-1�����µ�����ÿ�ε���O(h)
 *      ����ƽ�� O(nlogn)
 *�ȶ��ԣ����ȶ�
 */
