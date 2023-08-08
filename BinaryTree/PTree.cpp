/*
 * @Author: farron_cat
 * @Date: 2021-09-11 16:58:05
 * @LastEditTime: 2021-09-20 10:18:56
 * @LastEditors: farron_cat
 * @Description: ����˫�ױ�ʾ
 * @FilePath: \Briup\learn\data_structure\BinaryTree\PTree.cpp
 * ��Ȩ�鷨��Сè����
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
