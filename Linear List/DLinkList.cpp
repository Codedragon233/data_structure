/*
 * @Author: farron_cat
 * @Date: 2021-07-16 10:31:12
 * @LastEditTime: 2021-09-05 16:08:28
 * @LastEditors: farron_cat
 * @Description: 双链表
 * @FilePath: \Briup\learn\data_structure\Linear List\DLinkList.cpp
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
} DNode, *DLinkList;

//初始化
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//指定结点后插 注意边界情况：p结点为尾结点
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    //p不是尾结点
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//删除指定结点后继结点 注意边界情况：删除结点为尾结点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;
    DNode *q = p->next;
    //p是尾结点 q为空 删除失败
    if (q == NULL)
        return false;
    p->next = q->next;
    //q不是尾结点 进行前向指针操作 
    if (q != NULL)
        q->next->prior = p;
    free(q);
}

//销毁
void DestoryList(DLinkList &L)
{
    while (L->next != NULL)
    {
        DeleteNextDNode(L);
    }
    free(L);
    L = NULL;
}

//后向遍历
// while(p!=NULL){  //条件改为 p->next!=NULL 则跳过尾节点
//     do something
//     p=p->next;
// }

//前向遍历
// while(p!=NULL){  //条件改为 p->prior!=NULL 则跳过头节点
//     do something
//     p=p->prior;
// }

//查找只能通过遍历 O(n)