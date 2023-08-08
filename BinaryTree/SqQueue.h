/*
 * @Author: farron_cat
 * @Date: 2021-09-11 12:42:19
 * @LastEditTime: 2021-09-20 10:19:31
 * @LastEditors: farron_cat
 * @Description: 辅助队列 头文件
 * @FilePath: \Briup\learn\data_structure\BinaryTree\SqQueue.h
 * 版权归法兰小猫所有
 */
#define MaxSize 10
typedef BiTree ElemType;

typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

//初始化
void InitQueue(SqQueue &Q);

//入队
bool EnQueue(SqQueue &Q, ElemType x);

//出队
bool DeQueue(SqQueue &Q, ElemType &x);

//判空
bool isEmpty(SqQueue Q);
