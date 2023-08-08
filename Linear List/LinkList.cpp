/*
 * @Author: farron_cat
 * @Date: 2021-07-15 09:33:59
 * @LastEditTime: 2022-08-19 19:34:52
 * @LastEditors: farron_cat
 * @Description: 单链表
 * @FilePath: \Briup\learn\data_structure\Linear List\LinkList.cpp
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
} LNode, *LinkList;

/*
//不带头 初始化
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}
*/

//带头 初始化
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

//指定结点后插 O(1)
bool InsertNextNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;

    LNode *node = (LNode *)malloc(sizeof(LNode));
    if (node == NULL)
        return false;

    node->data = e;
    node->next = p->next;
    p->next = node;
    return true;
}

//指定结点前插 O(1)
bool InsertPriorNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;

    LNode *node = (LNode *)malloc(sizeof(LNode));
    if (node == NULL)
        return false;

    node->next = p->next;
    p->next = node;
    //将插入结点值换为p结点值，p结点值设为e
    node->data = p->data;
    p->data = e;
    return true;
}
//变体(LNode *p,LNode *s) 将s结点插入p之后 将它们的data交换即可

/*
//不带头 指定位序插入
bool ListInsert(LinkList &L, int i, ElemType e){
    if (i < 1)
        return false;
    //头位置插入需要特殊处理
    if(i==1){
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->next = L;
        node->data = e;
        L=node;
        return true;
    }

    LNode *p = L;
    int j = 1;
    //循环完毕j==i-1
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    //i超出最后一个结点
    return InsertNextNode(p,e);
}
*/
//带头 指定位序插入
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;

    LNode *p = L;
    int j = 0;
    //按位序查找i-1处结点 循环完毕j==i-1
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p==NULL)
        return false;
    //i超出最后一个结点
    return InsertNextNode(p, e);
}

//带头 删除指定位序 O(n)
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1)
        return false;

    LNode *p = L;
    int j = 0;
    //循环完毕j==i-1 p指向被删结点直接前驱结点
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }

    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;

    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//带头 删除指定结点 O(1) 指定结点p不能为尾结点
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;

    LNode *q = p->next;
    //将p后继结点值赋予p，然后删除p的后继
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//带头 按位序查找 O(n)
LNode *GetElem(LinkList &L, int i)
{
    if (i < 0)
        return NULL;
    if (i == 0)
        return L;
    int j = 1;
    LNode *p = L->next;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

//带头 按值查找 O(n)
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL & p->data != e)
    {
        p = p->next;
    }
    return p;
}

//带头 求表长
int Length(LinkList L)
{
    LNode *p = L->next;
    int j = 1;
    while (p)
    {
        p = p->next;
        j++;
    }
    return j;
}

//带头 尾插建立 O(n)
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;   //只要初始化单链表，都先把头指针指向NULL
    LNode *s, *r = L; //r指针指向表尾结点
    scanf("%d", &x);
    while (x != 9999) //输入9999时停止插入
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

//带头 头插建立（可以实现链表逆置）
LinkList List_HeadInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL; //只要初始化单链表，都先把头指针指向NULL
    LNode *s;
    scanf("%d", &x);
    while (x != 9999) //输入9999时停止插入
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}