/*
 * @Author: farron_cat
 * @Date: 2021-08-27 14:40:18
 * @LastEditTime: 2021-09-05 16:57:18
 * @LastEditors: farron_cat
 * @Description: 共享栈
 * @FilePath: \Briup\learn\data_structure\Stack\ShareStack.cpp
 * 版权归法兰小猫所有
 */

#define MaxSize 10
typedef int ElemType;
//定义 左右二栈共享
typedef struct
{
    ElemType data[MaxSize];
    int left;
    int right;
} ShareStack;

//初始化
void InitStack(ShareStack &S)
{
    for (int i = 0; i < MaxSize; i++)
        S.data[i] = 0;
    S.left = -1;
    S.right = MaxSize;
}

//左入栈
bool LeftPush(ShareStack &S, ElemType x)
{
    if (S.left == S.right - 1)
        return false;
    S.left = S.left + 1;
    S.data[S.left] = x;
    return true;
}

//右入栈
bool RightPush(ShareStack &S, ElemType x)
{
    if (S.left == S.right - 1)
        return false;
    S.right = S.right - 1;
    S.data[S.right] = x;
    return true;
}

//左出栈
bool LeftPop(ShareStack &S, ElemType &x)
{
    if (S.left == -1)
        return false;
    x = S.data[S.left];
    S.left = S.left - 1;
    return true;
}

//右出栈
bool RightPop(ShareStack &S, ElemType &x)
{
    if (S.right == MaxSize)
        return false;
    x = S.data[S.right];
    S.right = S.right + 1;
    return true;
}

//左返回栈顶
bool LeftGetTop(ShareStack &S, ElemType &x)
{
    if (S.left == -1)
        return false;
    x = S.data[S.left];
    return true;
}

//右返回栈顶
bool RightGetTop(ShareStack &S, ElemType &x)
{
    if (S.right == MaxSize)
        return false;
    x = S.data[S.right];
    return true;
}