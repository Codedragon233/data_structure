/*
 * @Author: farron_cat
 * @Date: 2021-09-11 20:48:35
 * @LastEditTime: 2021-09-12 10:49:09
 * @LastEditors: farron_cat
 * @Description: ��������
 * @FilePath: \Briup\learn\data_structure\Sort\QuickSort.cpp
 * ��Ȩ�鷨��Сè����
 */

typedef int ElemType;

int Partition(ElemType A[], int low, int high)
{
    ElemType pivot=A[low];
    while (low<high)
    {
        while(low<high&&A[high]>=pivot) --high;
        A[low]=A[high];
        while(low<high&&A[low]<=pivot)  ++low;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
    
}

void QuickSort(ElemType A[],int low, int high)
{
    if(low<high)
    {
        int pivotpos = Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}

/*
 *�ռ䣺��Ҫ�ݹ�ջ �����������ݹ�����й� ���O(logn) �O(n) ƽ��O(logn)
 *ʱ�䣺�����Ƿ�Գ��й� 
 *      �����޶Ȳ��Գƣ�O(n^2)
 *�ȶ��ԣ����ȶ�
 */