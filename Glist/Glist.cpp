/*
 * @Author: farron_cat
 * @Date: 2021-11-13 15:41:43
 * @LastEditTime: 2021-11-13 16:17:02
 * @LastEditors: farron_cat
 * @Description: 广义表
 * @FilePath: \Briup\learn\data_structure\Glist\Glist.cpp
 * 版权归法兰小猫所有
 */

//头尾链表存储表示
typedef int AtomType;
typedef enum
{
    ATOM,
    LIST
} ElemTag;
//永远为两个成员 第二个成员在表结点中为成员为头尾指针的结构体
typedef struct GLNode
{
    ElemTag tag;
    union
    {
        AtomType atom;               //tag为 ATOM 时为原子值域
        struct
        {
            struct GLNode *hp, *tp;
        } ptr;                       //tag为 LIST 时为表头指针域和表尾指针域
    };
} * GList;
