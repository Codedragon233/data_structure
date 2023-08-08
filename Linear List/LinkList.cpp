/*
 * @Author: farron_cat
 * @Date: 2021-07-15 09:33:59
 * @LastEditTime: 2022-08-19 19:34:52
 * @LastEditors: farron_cat
 * @Description: ������
 * @FilePath: \Briup\learn\data_structure\Linear List\LinkList.cpp
 * ��Ȩ�鷨��Сè����
 */
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
typedef int ElemType;

//����
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

/*
//����ͷ ��ʼ��
bool InitList(LinkList &L)
{
    L = NULL;
    return true;
}
*/

//��ͷ ��ʼ��
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

//ָ������� O(1)
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

//ָ�����ǰ�� O(1)
bool InsertPriorNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;

    LNode *node = (LNode *)malloc(sizeof(LNode));
    if (node == NULL)
        return false;

    node->next = p->next;
    p->next = node;
    //��������ֵ��Ϊp���ֵ��p���ֵ��Ϊe
    node->data = p->data;
    p->data = e;
    return true;
}
//����(LNode *p,LNode *s) ��s������p֮�� �����ǵ�data��������

/*
//����ͷ ָ��λ�����
bool ListInsert(LinkList &L, int i, ElemType e){
    if (i < 1)
        return false;
    //ͷλ�ò�����Ҫ���⴦��
    if(i==1){
        LNode *node = (LNode *)malloc(sizeof(LNode));
        node->next = L;
        node->data = e;
        L=node;
        return true;
    }

    LNode *p = L;
    int j = 1;
    //ѭ�����j==i-1
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    //i�������һ�����
    return InsertNextNode(p,e);
}
*/
//��ͷ ָ��λ�����
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;

    LNode *p = L;
    int j = 0;
    //��λ�����i-1����� ѭ�����j==i-1
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p==NULL)
        return false;
    //i�������һ�����
    return InsertNextNode(p, e);
}

//��ͷ ɾ��ָ��λ�� O(n)
bool ListDelete(LinkList &L, int i, ElemType &e)
{
    if (i < 1)
        return false;

    LNode *p = L;
    int j = 0;
    //ѭ�����j==i-1 pָ��ɾ���ֱ��ǰ�����
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

//��ͷ ɾ��ָ����� O(1) ָ�����p����Ϊβ���
bool DeleteNode(LNode *p)
{
    if (p == NULL)
        return false;
    if (p->next == NULL)
        return false;

    LNode *q = p->next;
    //��p��̽��ֵ����p��Ȼ��ɾ��p�ĺ��
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//��ͷ ��λ����� O(n)
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

//��ͷ ��ֵ���� O(n)
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL & p->data != e)
    {
        p = p->next;
    }
    return p;
}

//��ͷ ���
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

//��ͷ β�彨�� O(n)
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;   //ֻҪ��ʼ�����������Ȱ�ͷָ��ָ��NULL
    LNode *s, *r = L; //rָ��ָ���β���
    scanf("%d", &x);
    while (x != 9999) //����9999ʱֹͣ����
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

//��ͷ ͷ�彨��������ʵ���������ã�
LinkList List_HeadInsert(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL; //ֻҪ��ʼ�����������Ȱ�ͷָ��ָ��NULL
    LNode *s;
    scanf("%d", &x);
    while (x != 9999) //����9999ʱֹͣ����
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}