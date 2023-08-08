/*
 * @Author: farron_cat
 * @Date: 2021-08-30 09:37:47
 * @LastEditTime: 2021-09-20 10:18:36
 * @LastEditors: farron_cat
 * @Description: 辅助顺序栈 头文件
 * @FilePath: \Briup\learn\data_structure\BinaryTree\SqStack.h
 * 版权归法兰小猫所有
 */

#define MaxSize 10
typedef BiTree ElemType;

//定义
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S);

bool Push(SqStack &S, ElemType x);

bool Pop(SqStack &S, ElemType &x);

bool GetTop(SqStack &S, ElemType &x);

bool StackEmpty(SqStack &S);
