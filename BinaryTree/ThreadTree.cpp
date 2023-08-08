/*
 * @Author: farron_cat
 * @Date: 2021-09-11 15:57:38
 * @LastEditTime: 2021-09-20 10:18:29
 * @LastEditors: farron_cat
 * @Description: 线索二叉树
 * @FilePath: \Briup\learn\data_structure\BinaryTree\ThreadTree.cpp
 * 版权归法兰小猫所有
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

        if (p->lchild == NULL)//左子树空
        {
            p->lchild = pre;//左孩子指向前驱
            p->ltag = 1;
        }
        if (pre != NULL && pre->rchild == NULL)//前驱非空且其右孩子空
        {
            pre->rchild = p;//前驱的右孩子指向该结点
            p->rtag = 1;
        }
        pre = p;//更新前驱标记

        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree T)
{
    ThreadTree pre = NULL;//标记前一个访问的结点 前驱
    if (T != NULL)
    {
        InThread(T, pre);//树非空就线索化

        pre->rchild = NULL;//注意处理最后一个结点
        pre->rtag = 1;
    }
}

ThreadNode *Firstnode(ThreadNode *p)
{
    while (p->ltag == 0)//第一个结点是最左下结点
        p = p->lchild;
    return p;
}

ThreadNode *Nextnode(ThreadNode *p)
{
    if (p->rtag == 0)
        //右孩子不是线索 下一个结点就是右子树的最左下
        return Firstnode(p->rchild);
    else
        //右孩子是线索 下一个结点是右孩子指向的结点
        return p->rchild;
}

void Inorder(ThreadNode *T)
{
    for (ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
    {
        visit(p);
    }
}