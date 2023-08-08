/*
 * @Author: farron_cat
 * @Date: 2021-08-30 16:14:31
 * @LastEditTime: 2021-08-31 21:56:28
 * @LastEditors: farron_cat
 * @Description: 链串
 * @FilePath: \Briup\learn\data_structure\String\String.cpp
 * 版权归法兰小猫所有
 */

/*
//存储密度低
typedef struct StringNode
{
    char ch;
    struct StringNode * next;
}StringNode,*String;
*/

typedef struct StringNode
{
    char ch[4];
    struct StringNode * next;
}StringNode,*String;
