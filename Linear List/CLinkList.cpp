/*
 * @Author: farron_cat
 * @Date: 2021-07-16 11:16:21
 * @LastEditTime: 2021-07-16 11:20:27
 * @LastEditors: farron_cat
 * @Description: 循环单链表
 * @FilePath: \Briup\data_structure\Linear List\CLinkList.cpp
 * 版权归法兰小猫所有
 */

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
typedef int ElemType;

//定义
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *CLinkList;

//带头 初始化
bool InitList(CLinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = L; //指向头结点
    return true;
}

//判空
bool Empty(CLinkList L)
{
    if (L->next == L)
        return true;
    else
        return false;
}

//判尾
bool isTail(CLinkList L, LNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}