/*
 * @Author: farron_cat
 * @Date: 2021-08-27 14:40:18
 * @LastEditTime: 2021-09-05 16:57:18
 * @LastEditors: farron_cat
 * @Description: ����ջ
 * @FilePath: \Briup\learn\data_structure\Stack\ShareStack.cpp
 * ��Ȩ�鷨��Сè����
 */

#define MaxSize 10
typedef int ElemType;
//���� ���Ҷ�ջ����
typedef struct
{
    ElemType data[MaxSize];
    int left;
    int right;
} ShareStack;

//��ʼ��
void InitStack(ShareStack &S)
{
    for (int i = 0; i < MaxSize; i++)
        S.data[i] = 0;
    S.left = -1;
    S.right = MaxSize;
}

//����ջ
bool LeftPush(ShareStack &S, ElemType x)
{
    if (S.left == S.right - 1)
        return false;
    S.left = S.left + 1;
    S.data[S.left] = x;
    return true;
}

//����ջ
bool RightPush(ShareStack &S, ElemType x)
{
    if (S.left == S.right - 1)
        return false;
    S.right = S.right - 1;
    S.data[S.right] = x;
    return true;
}

//���ջ
bool LeftPop(ShareStack &S, ElemType &x)
{
    if (S.left == -1)
        return false;
    x = S.data[S.left];
    S.left = S.left - 1;
    return true;
}

//�ҳ�ջ
bool RightPop(ShareStack &S, ElemType &x)
{
    if (S.right == MaxSize)
        return false;
    x = S.data[S.right];
    S.right = S.right + 1;
    return true;
}

//�󷵻�ջ��
bool LeftGetTop(ShareStack &S, ElemType &x)
{
    if (S.left == -1)
        return false;
    x = S.data[S.left];
    return true;
}

//�ҷ���ջ��
bool RightGetTop(ShareStack &S, ElemType &x)
{
    if (S.right == MaxSize)
        return false;
    x = S.data[S.right];
    return true;
}