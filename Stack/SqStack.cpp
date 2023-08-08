/*
 * @Author: farron_cat
 * @Date: 2021-07-24 16:52:06
 * @LastEditTime: 2021-09-05 16:40:51
 * @LastEditors: farron_cat
 * @Description: 顺序栈
 * @FilePath: \Briup\learn\data_structure\Stack\SqStack.cpp
 * 版权归法兰小猫所有
 */

#include"SqStack.h"

//初始化
void InitStack(SqStack &S)
{
    for (int i = 0; i < MaxSize; i++)
        S.data[i] = 0;
    S.top = -1;
}

//入栈
bool Push(SqStack &S, ElemType x)
{
    if (S.top == MaxSize - 1)
        return false;
    S.top = S.top + 1; // 二合一 先加指针再填内容
    S.data[S.top] = x; // S.data[++S.top]=x;
    return true;
}

//出栈
bool Pop(SqStack &S, ElemType &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top]; // 二合一 先弹出内容再减指针
    S.top = S.top - 1; // x=S.data[S.top--];
    return true;
}

//返回栈顶 同出栈无需移动指针
bool GetTop(SqStack &S, ElemType &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

//判空 栈顶指针指向-1
bool StackEmpty(SqStack &S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}