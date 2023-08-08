/*
 * @Author: farron_cat
 * @Date: 2021-08-29 09:18:54
 * @LastEditTime: 2021-09-11 15:55:45
 * @LastEditors: farron_cat
 * @Description: ����
 * @FilePath: \Briup\learn\data_structure\Queue\LinkQueue.cpp
 * ��Ȩ�鷨��Сè����
 */

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
typedef int ElemType;

//����
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

//��ʼ��
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//���
bool EnQueue(LinkQueue &Q, ElemType x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    if (s == NULL)
        return false;
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
    return true;
}

//����
bool DeQueue(LinkQueue &Q, ElemType &x)
{
    if (Q.front == Q.rear)//�ӿմ���
        return false;
    //pָ���ǵ������
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)//pΪ��β���������
        Q.rear = Q.front;
    free(p);
    return true;
}

//�п�
bool isEmpty(LinkQueue &Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}