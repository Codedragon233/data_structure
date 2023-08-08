/*
 * @Author: farron_cat
 * @Date: 2021-07-14 17:11:00
 * @LastEditTime: 2021-07-16 10:31:58
 * @LastEditors: farron_cat
 * @Description: 动态顺序表
 * @FilePath: \Briup\data_structure\Linear List\DSqlList.cpp
 * 版权归法兰小猫所有
 */
#include <malloc.h>

#define InitSize 10
typedef int ElemType;
typedef struct
{
    ElemType *data;
    int max_size;
    int length;
} SqList;

void InitList(SqList &L)
{
    L.data = (ElemType *)malloc(InitSize * sizeof(ElemType));
    L.length = 0;
    L.max_size = InitSize;
}

void IncreaseSize(SqList &L, int len)
{
    int *p = L.data;
    L.data = (ElemType *)malloc((L.max_size + len) * sizeof(ElemType));
    for (int i = 0; i < L.length; i++)
        L.data[i] = p[i];
    L.max_size += len;
    free(p);
}



int main()
{
    SqList L;
    InitList(L);
    IncreaseSize(L,5);
}
