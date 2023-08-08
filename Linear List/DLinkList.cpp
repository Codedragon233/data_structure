/*
 * @Author: farron_cat
 * @Date: 2021-07-16 10:31:12
 * @LastEditTime: 2021-09-05 16:08:28
 * @LastEditors: farron_cat
 * @Description: ˫����
 * @FilePath: \Briup\learn\data_structure\Linear List\DLinkList.cpp
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
} DNode, *DLinkList;

//��ʼ��
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//ָ������� ע��߽������p���Ϊβ���
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;
    s->next = p->next;
    //p����β���
    if (p->next != NULL)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

//ɾ��ָ������̽�� ע��߽������ɾ�����Ϊβ���
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;
    DNode *q = p->next;
    //p��β��� qΪ�� ɾ��ʧ��
    if (q == NULL)
        return false;
    p->next = q->next;
    //q����β��� ����ǰ��ָ����� 
    if (q != NULL)
        q->next->prior = p;
    free(q);
}

//����
void DestoryList(DLinkList &L)
{
    while (L->next != NULL)
    {
        DeleteNextDNode(L);
    }
    free(L);
    L = NULL;
}

//�������
// while(p!=NULL){  //������Ϊ p->next!=NULL ������β�ڵ�
//     do something
//     p=p->next;
// }

//ǰ�����
// while(p!=NULL){  //������Ϊ p->prior!=NULL ������ͷ�ڵ�
//     do something
//     p=p->prior;
// }

//����ֻ��ͨ������ O(n)