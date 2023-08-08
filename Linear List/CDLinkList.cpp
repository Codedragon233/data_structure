/*
 * @Author: farron_cat
 * @Date: 2021-07-16 11:25:32
 * @LastEditTime: 2021-09-05 16:24:28
 * @LastEditors: farron_cat
 * @Description: 循环双链表
 * @FilePath: \Briup\learn\data_structure\Linear List\CDLinkList.cpp
 * 版权归法兰小猫所有
 */

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
typedef int ElemType;

//定义
typedef struct DNode
{
    ElemType e;
    struct DNode *prior, *next;
} DNode, *CDLinkList;

//初始化
bool InitDLinkList(CDLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = L;
    L->next = L;
    return true;
}


//判空
bool Empty(CDLinkList L)
{
    if (L->next == L)
        return true;
    else
        return false;
}

//判尾
bool isTail(CDLinkList L, DNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}

//指定结点后插
//因为是循环链表 所以不会出现双链表尾结点插入的特殊情况
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//删除指定结点后继结点
//因为是循环链表 所以不会出现双链表删除尾结点的特殊情况
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;
    DNode *q = p->next;
    if (q == NULL)
        return false;
    
    p->next = q->next;
    q->next->prior = p;
    free(q);
}