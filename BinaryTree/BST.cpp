/*
 * @Author: farron_cat
 * @Date: 2021-09-11 17:04:25
 * @LastEditTime: 2021-09-12 09:11:56
 * @LastEditors: farron_cat
 * @Description: �������������
 * @FilePath: \Briup\learn\data_structure\BinaryTree\BST.cpp
 * ��Ȩ�鷨��Сè����
 */

#include <malloc.h>
#include <stddef.h>
#include <stdio.h>
typedef int ElemType;

typedef struct BSTNode
{
    ElemType key;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

//���� �����㷨 �ռ�O(1)
BSTNode *BST_Search(BSTree T, int key)
{
    while (T != NULL && key != T->key)
    {
        if (key < T->key)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}

//���� �ݹ��㷨 �ռ�O(h) hΪ����
BSTNode *BST_Search2(BSTree T, int key)
{
    if (T == NULL)
        return NULL;
    if (key == T->key)
        return T;
    else if (key < T->key)
        return BST_Search2(T->lchild, key);
    else
        return BST_Search2(T->rchild, key);
}

//�ǵݹ����

//���� �ݹ��㷨 �ռ�O(h) hΪ����
bool BST_Insert2(BSTree T, int key)
{
    if (T == NULL)
    {
        T = (BSTNode *)malloc(sizeof(BSTNode));
        T->key = key;
        T->lchild = T->rchild = NULL;
        return true;
    }
    if (key == T->key)
        return false;
    else if (key < T->key)
        return BST_Search2(T->lchild, key);
    else
        return BST_Search2(T->rchild, key);
}

//�������й�������������
void Creat_BST(BSTree &T,int str[], int n)
{
    T=NULL;
    int i=0;
    while(i<n)
    {
        BST_Insert2(T,str[i]);
        i++;
    }
}