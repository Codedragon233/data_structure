/*
 * @Author: farron_cat
 * @Date: 2021-09-19 18:42:27
 * @LastEditTime: 2021-09-19 18:49:38
 * @LastEditors: farron_cat
 * @Description: ���ֲ���
 * @FilePath: \Briup\learn\data_structure\Search\BinarySearch.cpp
 * ��Ȩ�鷨��Сè����
 */

#include "SqlList.h"
typedef int ElemType;

int BinarySearch(SqList L, ElemType key)
{
    int low = 0, high = L.length, mid;
    while (low < +high)
    {
        mid = (low + high) / 2;
        if (L.data[mid] == key)
            return mid;
        else if (L.data[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

/*
 * ASL�ɹ� Լ���� log(n+1)-1
 * ASLʧ�� 
 * �ռ䣺O(1)
 * ʱ�䣺O(logn)
 */