/*
 * @Author: farron_cat
 * @Date: 2021-07-14 16:52:44
 * @LastEditTime: 2021-07-16 10:31:49
 * @LastEditors: farron_cat
 * @Description: 顺序表
 * @FilePath: \Briup\data_structure\Linear List\SqlList.cpp
 * 版权归法兰小猫所有
 */

#define MaxSize 10
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

void InitList(SqList &L)
{
    for (int i = 0; i < MaxSize; i++)
        L.data[i] = 0;
    L.length = 0;
}

//
bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    e = L.data[i];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

ElemType GetElem(SqList L, int i)
{
    if (i < 1 || i > L.length)
        return -1;
    return L.data[i - 1];
}

int LocateElem(SqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return i;
    return 0;
}

int main()
{
    SqList L;
    InitList(L);
}
