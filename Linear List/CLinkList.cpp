/*
 * @Author: farron_cat
 * @Date: 2021-07-16 11:16:21
 * @LastEditTime: 2021-07-16 11:20:27
 * @LastEditors: farron_cat
 * @Description: ѭ��������
 * @FilePath: \Briup\data_structure\Linear List\CLinkList.cpp
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
} LNode, *CLinkList;

//��ͷ ��ʼ��
bool InitList(CLinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = L; //ָ��ͷ���
    return true;
}

//�п�
bool Empty(CLinkList L)
{
    if (L->next == L)
        return true;
    else
        return false;
}

//��β
bool isTail(CLinkList L, LNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}