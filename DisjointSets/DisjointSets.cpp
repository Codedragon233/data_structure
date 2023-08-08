/*
 * @Author: farron_cat
 * @Date: 2021-11-13 10:53:31
 * @LastEditTime: 2021-11-13 15:04:58
 * @LastEditors: farron_cat
 * @Description: 并查集
 * @FilePath: \Briup\learn\data_structure\DisjointSets\DisjointSets.cpp
 * 版权归法兰小猫所有
 */

#define SIZE 30

int DisjointSets[SIZE];

void Initial(int S[])
{
    for (int i = 0; i < SIZE; i++)
        S[i] = -1;
}

//查找 最坏时间复杂度 O(n)
int Find(int S[], int x)
{
    while (S[x] >= 0)
    {
        x = S[x];
    }
    return x;
}

//合并 时间复杂度O(1)
void Union(int S[], int Root1, int Root2)
{
    if (Root1 == Root2)
        return;
    S[Root2] = Root1;
}

//优化后的合并 保证了构造的树高不超过(logn)下取整+1 时间复杂度O(1)
void UnionOpted(int S[], int Root1, int Root2)
{
    if (Root1 == Root2)
        return;
    //Root2集合比Root1集合小
    if (S[Root2] > S[Root1])
    {
        S[Root1] += S[Root2]; //累加结点总数
        S[Root2] = Root1;     //小树合并大树
    }
    //Root2集合比Root1集合大
    else
    {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
    S[Root2] = Root1;
}

//优化后的查找 保证树高不超过O(α(n)) 时间复杂度O(α(n))
int FindOpted(int S[], int x)
{
    int root = x;
    while (S[root] >= 0)
        root = S[root];
    while (x != root)
    {
        int temp = S[x];
        S[x] = root;
        x = temp;
    }
    return root;
}

