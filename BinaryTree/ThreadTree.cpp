/*
 * @Author: farron_cat
 * @Date: 2021-09-11 15:57:38
 * @LastEditTime: 2021-09-20 10:18:29
 * @LastEditors: farron_cat
 * @Description: ����������
 * @FilePath: \Briup\learn\data_structure\BinaryTree\ThreadTree.cpp
 * ��Ȩ�鷨��Сè����
 */

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#include "SqStack.h"
#include "SqQueue.h"
typedef int ElemType;

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

void visit(ThreadNode *p)
{
    //do something
}

void InThread(ThreadTree &p, ThreadTree &pre)
{
    if (p != NULL)
    {
        InThread(p->lchild, pre);

        if (p->lchild == NULL)//��������
        {
            p->lchild = pre;//����ָ��ǰ��
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL)//ǰ���ǿ������Һ��ӿ�
        {
            pre->rchild = p;//ǰ�����Һ���ָ��ý��
            p->rtag = 1;
        }
        pre = p;//����ǰ�����

        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree T)
{
    ThreadTree pre = NULL;//���ǰһ�����ʵĽ�� ǰ��
    if (T != NULL)
    {
        InThread(T, pre);//���ǿվ�������

        pre->rchild = NULL;//ע�⴦�����һ�����
        pre->rtag = 1;
    }
}

ThreadNode *Firstnode(ThreadNode *p)
{
    while (p->ltag == 0)//��һ������������½��
        p = p->lchild;
    return p;
}

ThreadNode *Nextnode(ThreadNode *p)
{
    if (p->rtag == 0)
        //�Һ��Ӳ������� ��һ����������������������
        return Firstnode(p->rchild);
    else
        //�Һ��������� ��һ��������Һ���ָ��Ľ��
        return p->rchild;
}

void Inorder(ThreadNode *T)
{
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
    {
        visit(p);
    }
}