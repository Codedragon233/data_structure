/*
 * @Author: farron_cat
 * @Date: 2021-07-16 11:36:29
 * @LastEditTime: 2021-07-16 11:59:23
 * @LastEditors: farron_cat
 * @Description: ��̬����
 * @FilePath: \Briup\data_structure\Linear List\SLinkLIst.cpp
 * ��Ȩ�鷨��Сè����
 */

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
typedef int ElemType;

//����1
#define MaxSize 10
typedef struct
{
    ElemType e;
    int next;
}Node;
//ʹ�ã�Node l[MaxSize];

//����2
#define MaxSize 10
typedef struct
{
    ElemType e;
    int next;
}SLinkList[MaxSize];
/* ��������ȼ���ʽ
#define MaxSize 10
typedef struct Node
{
    ElemType e;
    int next;
};
typedef struct Node SLinkList[MaxSize];
*/
//ʹ�ã�SLinkList l;






