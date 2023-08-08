/*
 * @Author: farron_cat
 * @Date: 2021-07-24 16:52:06
 * @LastEditTime: 2021-09-05 16:40:51
 * @LastEditors: farron_cat
 * @Description: ˳��ջ
 * @FilePath: \Briup\learn\data_structure\Stack\SqStack.cpp
 * ��Ȩ�鷨��Сè����
 */

#include"SqStack.h"

//��ʼ��
void InitStack(SqStack &S)
{
    for (int i = 0; i < MaxSize; i++)
        S.data[i] = 0;
    S.top = -1;
}

//��ջ
bool Push(SqStack &S, ElemType x)
{
    if (S.top == MaxSize - 1)
        return false;
    S.top = S.top + 1; // ����һ �ȼ�ָ����������
    S.data[S.top] = x; // S.data[++S.top]=x;
    return true;
}

//��ջ
bool Pop(SqStack &S, ElemType &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top]; // ����һ �ȵ��������ټ�ָ��
    S.top = S.top - 1; // x=S.data[S.top--];
    return true;
}

//����ջ�� ͬ��ջ�����ƶ�ָ��
bool GetTop(SqStack &S, ElemType &x)
{
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

//�п� ջ��ָ��ָ��-1
bool StackEmpty(SqStack &S)
{
    if(S.top == -1)
        return true;
    else
        return false;
}