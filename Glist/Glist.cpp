/*
 * @Author: farron_cat
 * @Date: 2021-11-13 15:41:43
 * @LastEditTime: 2021-11-13 16:17:02
 * @LastEditors: farron_cat
 * @Description: �����
 * @FilePath: \Briup\learn\data_structure\Glist\Glist.cpp
 * ��Ȩ�鷨��Сè����
 */

//ͷβ����洢��ʾ
typedef int AtomType;
typedef enum
{
    ATOM,
    LIST
} ElemTag;
//��ԶΪ������Ա �ڶ�����Ա�ڱ�����Ϊ��ԱΪͷβָ��Ľṹ��
typedef struct GLNode
{
    ElemTag tag;
    union
    {
        AtomType atom;               //tagΪ ATOM ʱΪԭ��ֵ��
        struct
        {
            struct GLNode *hp, *tp;
        } ptr;                       //tagΪ LIST ʱΪ��ͷָ����ͱ�βָ����
    };
} * GList;
