/*
 * @Author: farron_cat
 * @Date: 2021-07-26 16:43:08
 * @LastEditTime: 2021-09-05 16:57:16
 * @LastEditors: farron_cat
 * @Description: 顺序队列(循环队列)
 * @FilePath: \Briup\learn\data_structure\Queue\SqQueue.cpp
 * 版权归法兰小猫所有
 */

#define MaxSize 10
typedef int ElemType;
//定义
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

//初始化
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

//入队
bool EnQueue(SqQueue &Q, ElemType x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)//队满错误
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;//循环加一
    return true;
}

//出队
bool DeQueue(SqQueue &Q, ElemType &x)
{
    if (Q.front == Q.rear)//队空错误
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;//循环加一
    return true;
}

//判空
bool isEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)//首尾重合则队空
        return true;
    else
        return false;
}