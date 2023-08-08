/*
 * @Author: farron_cat
 * @Date: 2021-08-29 09:18:54
 * @LastEditTime: 2021-09-11 15:55:45
 * @LastEditors: farron_cat
 * @Description: 链队
 * @FilePath: \Briup\learn\data_structure\Queue\LinkQueue.cpp
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
    struct LinkNode *next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

//初始化
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//入队
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

//出队
bool DeQueue(LinkQueue &Q, ElemType &x)
{
    if (Q.front == Q.rear)//队空错误
        return false;
    //p指针标记弹出结点
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)//p为队尾的特殊情况
        Q.rear = Q.front;
    free(p);
    return true;
}

//判空
bool isEmpty(LinkQueue &Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}