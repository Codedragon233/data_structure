/*
 * @Author: farron_cat
 * @Date: 2021-09-11 17:01:18
 * @LastEditTime: 2021-09-11 17:03:01
 * @LastEditors: farron_cat
 * @Description: ���ĺ����ֵܱ�ʾ
 * @FilePath: \Briup\learn\data_structure\BinaryTree\CSTree.cpp
 * ��Ȩ�鷨��Сè����
 */

typedef int ElemType;
typedef struct CSNode
{
    ElemType data;
    CSNode *firstchild, *nextSibling;
} CSNode, *CSTree;
