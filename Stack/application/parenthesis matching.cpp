/*
 * @Author: farron_cat
 * @Date: 2021-08-30 09:31:24
 * @LastEditTime: 2022-08-23 22:09:38
 * @LastEditors: farron_cat
 * @Description: 括号匹配
 * @FilePath: \Briup\learn\data_structure\Stack\application\parenthesis matching.cpp
 * 版权归法兰小猫所有
 */

#include"SqStack.h" //使用顺序栈 防止栈满可以用链栈
bool bracketCheck(char str[],int length)
{
    SqStack S;
    InitStack(S);
    //遍历括号序列
    for (int i = 0; i < length; i++)
    {
        //左括号入栈
        if (str[i]=='('||str[i]=='['||str[i]=='{')
        {
            Push(S, str[i]);
        }
        //右括号判断
        else
        {
            //栈空 单身右括号
            if(StackEmpty(S))
                return false;
            
            char topElem;
            Pop(S, topElem);
            //左右不匹配
            if(str[i]==')'&& topElem!='(')
                return false;
            if(str[i]==']'&& topElem!='[')
                return false;
            if(str[i]=='}'&& topElem!='{')
                return false;
        }
    }
    //栈空 单身左括号
    return StackEmpty(S);
}