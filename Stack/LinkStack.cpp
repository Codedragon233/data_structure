/*
 * @Author: farron_cat
 * @Date: 2021-08-27 14:39:30
 * @LastEditTime: 2021-09-05 16:40:50
 * @LastEditors: farron_cat
 * @Description: 链栈
 * @FilePath: \Briup\learn\data_structure\Stack\LinkStack.cpp
 * 版权归法兰小猫所有
 */
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>

typedef int ElemType;
//定义
typedef struct LinkNode
{
    ElemType data;
    LinkNode *next;
} LinkNode, *LinkStack;

//初始化 无头结点表示
void InitStack(LinkStack &S)
{
    S = NULL;
}

//入栈
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

//出栈
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

//返回栈顶 同出栈不需要p指针标记删除结点并free
bool GetTop(LinkStack &S, ElemType &x)
{
    if (S == NULL)
        return false;
    x = S->data;
    return true;
}