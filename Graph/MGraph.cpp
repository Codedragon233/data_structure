/*
 * @Author: farron_cat
 * @Date: 2021-09-12 09:13:04
 * @LastEditTime: 2021-09-19 19:02:45
 * @LastEditors: farron_cat
 * @Description: 邻接矩阵
 * @FilePath: \Briup\learn\data_structure\Graph\MGraph.cpp
 * 版权归法兰小猫所有
 */

#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct 
{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
}MGraph;

