/*
 * @Author: farron_cat
 * @Date: 2021-09-19 18:32:53
 * @LastEditTime: 2021-09-19 18:49:42
 * @LastEditors: farron_cat
 * @Description: 顺序查找
 * @FilePath: \Briup\learn\data_structure\Search\SeqSearch.cpp
 * 版权归法兰小猫所有
 */

typedef int ElemType;
typedef struct
{
    ElemType *elem; //elem[0]留空作为哨兵
    int TableLen;   //表长
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
 * ASL成功（n+1)/2
 * ASL失败 n+1
 * 空间：O(1)
 * 时间：O(n)
 */