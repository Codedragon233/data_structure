/*
 * @Author: farron_cat
 * @Date: 2021-11-13 15:49:21
 * @LastEditTime: 2021-11-13 15:56:30
 * @LastEditors: farron_cat
 * @Description: �����2
 * @FilePath: \Briup\learn\data_structure\Glist\Glist2.cpp
 * ��Ȩ�鷨��Сè����
 */

//��չ���Ա�洢��ʾ
typedef int AtomType;
typedef enum
{
    ATOM,
    LIST
} ElemTag;
//��Զ������Ա���ڶ�����Ա���ÿռ�
typedef struct GLNode
{
    ElemTag tag;
    union
    {
        AtomType atom;     //tagΪ ATOM ʱΪԭ��ֵ��
        struct GLNode *hp; //tagΪ LIST ʱΪ��ͷָ����
    };
    struct GLNode *tp;
} * GList;