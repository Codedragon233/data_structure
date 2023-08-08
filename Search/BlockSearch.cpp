/*
 * @Author: farron_cat
 * @Date: 2021-09-19 18:50:57
 * @LastEditTime: 2021-09-20 10:18:39
 * @LastEditors: farron_cat
 * @Description: 分块查找
 * @FilePath: \Briup\learn\data_structure\Search\BlockSearch.cpp
 * 版权归法兰小猫所有
 */

typedef int ElemType;
//索引表
typedef struct 
{
    ElemType maxValue;
    int low, high;
}Index;
//查找表
ElemType List[100];