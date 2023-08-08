/*
 * @Author: farron_cat
 * @Date: 2021-09-11 17:01:18
 * @LastEditTime: 2021-09-11 17:03:01
 * @LastEditors: farron_cat
 * @Description: 树的孩子兄弟表示
 * @FilePath: \Briup\learn\data_structure\BinaryTree\CSTree.cpp
 * 版权归法兰小猫所有
 */

typedef int ElemType;
typedef struct CSNode
{
    ElemType data;
    CSNode *firstchild, *nextSibling;
} CSNode, *CSTree;
