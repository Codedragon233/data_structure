/*
 * @Author: farron_cat
 * @Date: 2021-09-11 20:48:35
 * @LastEditTime: 2021-09-12 10:49:09
 * @LastEditors: farron_cat
 * @Description: 快速排序
 * @FilePath: \Briup\learn\data_structure\Sort\QuickSort.cpp
 * 版权归法兰小猫所有
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
 *空间：需要递归栈 其容量与最大递归深度有关 最好O(logn) 最坏O(n) 平均O(logn)
 *时间：划分是否对称有关 
 *      最坏最大限度不对称，O(n^2)
 *稳定性：不稳定
 */