/*
 * @Author: farron_cat
 * @Date: 2021-07-16 11:36:29
 * @LastEditTime: 2021-07-16 11:59:23
 * @LastEditors: farron_cat
 * @Description: 静态链表
 * @FilePath: \Briup\data_structure\Linear List\SLinkLIst.cpp
 * 版权归法兰小猫所有
 */

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
typedef int ElemType;

//定义1
#define MaxSize 10
typedef struct
{
    ElemType e;
    int next;
}Node;
//使用：Node l[MaxSize];

//定义2
#define MaxSize 10
typedef struct
{
    ElemType e;
    int next;
}SLinkList[MaxSize];
/* 上述代码等价形式
#define MaxSize 10
typedef struct Node
{
    ElemType e;
    int next;
};
typedef struct Node SLinkList[MaxSize];
*/
//使用：SLinkList l;






