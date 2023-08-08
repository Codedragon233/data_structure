/*
 * @Author: farron_cat
 * @Date: 2021-09-11 17:04:25
 * @LastEditTime: 2021-09-12 09:11:56
 * @LastEditors: farron_cat
 * @Description: 二叉排序树相关
 * @FilePath: \Briup\learn\data_structure\BinaryTree\BST.cpp
 * 版权归法兰小猫所有
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

//查找 迭代算法 空间O(1)
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

//查找 递归算法 空间O(h) h为树高
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

//非递归插入

//插入 递归算法 空间O(h) h为树高
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

//从序列中构建二叉排序树
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