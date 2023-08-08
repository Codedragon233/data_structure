/*
 * @Author: farron_cat
 * @Date: 2021-09-11 16:58:05
 * @LastEditTime: 2021-09-20 10:18:56
 * @LastEditors: farron_cat
 * @Description: 树的双亲表示
 * @FilePath: \Briup\learn\data_structure\BinaryTree\PTree.cpp
 * 版权归法兰小猫所有
 */

#define MAX_TREE_SIZE 100
typedef int ElemType;
typedef struct
{
    ElemType data;
    int parent;
} PTNode;

typedef struct
{
    PTNode nodes[MAX_TREE_SIZE];
    int n;
} PTree;
