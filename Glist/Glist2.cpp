/*
 * @Author: farron_cat
 * @Date: 2021-11-13 15:49:21
 * @LastEditTime: 2021-11-13 15:56:30
 * @LastEditors: farron_cat
 * @Description: 广义表2
 * @FilePath: \Briup\learn\data_structure\Glist\Glist2.cpp
 * 版权归法兰小猫所有
 */

//扩展线性表存储表示
typedef int AtomType;
typedef enum
{
    ATOM,
    LIST
} ElemTag;
//永远三个成员，第二个成员共用空间
typedef struct GLNode
{
    ElemTag tag;
    union
    {
        AtomType atom;     //tag为 ATOM 时为原子值域
        struct GLNode *hp; //tag为 LIST 时为表头指针域
    };
    struct GLNode *tp;
} * GList;