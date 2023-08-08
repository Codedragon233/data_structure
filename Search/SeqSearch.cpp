/*
 * @Author: farron_cat
 * @Date: 2021-09-19 18:32:53
 * @LastEditTime: 2021-09-19 18:49:42
 * @LastEditors: farron_cat
 * @Description: ˳�����
 * @FilePath: \Briup\learn\data_structure\Search\SeqSearch.cpp
 * ��Ȩ�鷨��Сè����
 */

typedef int ElemType;
typedef struct
{
    ElemType *elem; //elem[0]������Ϊ�ڱ�
    int TableLen;   //��
} SSTable;

int SeqSearch(SSTable ST, ElemType key)
{
    int i;
    ST.elem[0] = key;
    for (i = ST.TableLen; ST.elem[i] != key; i--)
        ;
    return i;
}

/*
 * ASL�ɹ���n+1)/2
 * ASLʧ�� n+1
 * �ռ䣺O(1)
 * ʱ�䣺O(n)
 */