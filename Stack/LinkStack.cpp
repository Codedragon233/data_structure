/*
 * @Author: farron_cat
 * @Date: 2021-08-27 14:39:30
 * @LastEditTime: 2021-09-05 16:40:50
 * @LastEditors: farron_cat
 * @Description: ��ջ
 * @FilePath: \Briup\learn\data_structure\Stack\LinkStack.cpp
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
    LinkNode *next;
} LinkNode, *LinkStack;

//��ʼ�� ��ͷ����ʾ
void InitStack(LinkStack &S)
{
    S = NULL;
}

//��ջ
bool Push(LinkStack &S, ElemType x)
{
    LinkNode *node = (LinkNode *)malloc(sizeof(LinkNode));
    if (node == NULL)
        return false;
    node->data = x;
    node->next = S->next;
    S->next = node;
    return true;
}

//��ջ
bool Pop(LinkStack &S, ElemType &x)
{
    if (S == NULL)
        return false;
    LinkNode *p;
    x = S->data;
    p = S;
    S->next = p->next;
    free(p);
    return true;
}

//����ջ�� ͬ��ջ����Ҫpָ����ɾ����㲢free
bool GetTop(LinkStack &S, ElemType &x)
{
    if (S == NULL)
        return false;
    x = S->data;
    return true;
}