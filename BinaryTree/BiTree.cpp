/*
 * @Author: farron_cat
 * @Date: 2021-09-01 17:02:33
 * @LastEditTime: 2021-09-20 10:19:10
 * @LastEditors: farron_cat
 * @Description: 二叉树
 * @FilePath: \Briup\learn\data_structure\BinaryTree\BiTree.cpp
 * 版权归法兰小猫所有
 */
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
#include"SqStack.h"
#include"SqQueue.h"
typedef int ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void visit(BiTree)
{
    //do something
}

void PreOrder(BiTree T)
{
    if(T!=NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T)
{
    if(T!=NULL)
    {
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}

void PostOrder(BiTree T)
{
    if(T!=NULL)
    {
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        visit(T);
    }
}

void PreOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p=T;
    while(p||!StackEmpty(S))
    {
        if (p)
        {
            visit(p);
            Push(S,p);
            p=p->lchild;
        }
        else
        {
            Pop(S,p);
            p=p->rchild;
        }
    }
}

void InOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p=T;
    while (p||!StackEmpty(S))
    {
        if(p)
        {
            Push(S,p);
            p=p->lchild;
        }
        else
        {
            Pop(S,p);
            visit(p);
            p=p->rchild;
        }
    }
}

void PostOrder2(BiTree T)
{
    SqStack S;//辅助栈
    InitStack(S);
    BiTree p=T, r=NULL;//p 遍历指针 r 记录上一次访问结点
    while (p||!StackEmpty(S))//p不空或栈不空
    {
        if(p)//p不空 入栈 向左
        {
            Push(S,p);
            p=p->lchild;
        }
        else //p空
        {
            GetTop(S,p);
            if(p->rchild&&p->rchild!=r)//p右孩子不空且右孩子没被访问过
                p=p->rchild;//向右
            else //否则弹出 访问
            {
                Pop(S,p);
                visit(p);
                r=p; //更新r
                p=NULL; //p置空
            }
        }
    }
}

void LevelOrder(BiTree T)
{
    SqQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!isEmpty(Q))
    {
        DeQueue(Q,p);
        visit(p);
        if(p->lchild!=NULL)
            EnQueue(Q, p->lchild);
        if(p->rchild!=NULL)
            EnQueue(Q, p->rchild);
    }
}
