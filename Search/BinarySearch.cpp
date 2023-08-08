/*
 * @Author: farron_cat
 * @Date: 2021-09-19 18:42:27
 * @LastEditTime: 2021-09-19 18:49:38
 * @LastEditors: farron_cat
 * @Description: 二分查找
 * @FilePath: \Briup\learn\data_structure\Search\BinarySearch.cpp
 * 版权归法兰小猫所有
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
 * ASL成功 约等于 log(n+1)-1
 * ASL失败 
 * 空间：O(1)
 * 时间：O(logn)
 */