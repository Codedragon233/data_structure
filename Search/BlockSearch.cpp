/*
 * @Author: farron_cat
 * @Date: 2021-09-19 18:50:57
 * @LastEditTime: 2021-09-20 10:18:39
 * @LastEditors: farron_cat
 * @Description: �ֿ����
 * @FilePath: \Briup\learn\data_structure\Search\BlockSearch.cpp
 * ��Ȩ�鷨��Сè����
 */

typedef int ElemType;
//������
typedef struct 
{
    ElemType maxValue;
    int low, high;
}Index;
//���ұ�
ElemType List[100];