/*
 * @Author: farron_cat
 * @Date: 2021-09-12 09:16:15
 * @LastEditTime: 2021-09-12 09:21:13
 * @LastEditors: farron_cat
 * @Description: �ڽӱ�
 * @FilePath: \Briup\learn\data_structure\Graph\ALGraph.cpp
 * ��Ȩ�鷨��Сè����
 */

#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct  ArcNode
{
    int adjvex;
    struct ArcNode *next;
}ArcNode;
typedef struct VNode
{
    VertexType data;
    ArcNode *first;
}VNode,AdjList[MaxVertexNum];
typedef struct 
{
    AdjList Vertices;
    int vexnum,arcnum;
}ALGraph;

