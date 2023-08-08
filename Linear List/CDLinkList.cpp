/*
 * @Author: farron_cat
 * @Date: 2021-07-16 11:25:32
 * @LastEditTime: 2021-09-05 16:24:28
 * @LastEditors: farron_cat
 * @Description: ѭ��˫����
 * @FilePath: \Briup\learn\data_structure\Linear List\CDLinkList.cpp
 * ��Ȩ�鷨��Сè����
 */

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
typedef int ElemType;

//����
typedef struct DNode
{
    ElemType e;
    struct DNode *prior, *next;
} DNode, *CDLinkList;

//��ʼ��
bool InitDLinkList(CDLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = L;
    L->next = L;
    return true;
}


//�п�
bool Empty(CDLinkList L)
{
    if (L->next == L)
        return true;
    else
        return false;
}

//��β
bool isTail(CDLinkList L, DNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}

//ָ�������
//��Ϊ��ѭ������ ���Բ������˫����β��������������
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

//ɾ��ָ������̽��
//��Ϊ��ѭ������ ���Բ������˫����ɾ��β�����������
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