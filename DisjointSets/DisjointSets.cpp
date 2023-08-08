/*
 * @Author: farron_cat
 * @Date: 2021-11-13 10:53:31
 * @LastEditTime: 2021-11-13 15:04:58
 * @LastEditors: farron_cat
 * @Description: ���鼯
 * @FilePath: \Briup\learn\data_structure\DisjointSets\DisjointSets.cpp
 * ��Ȩ�鷨��Сè����
 */

#define SIZE 30

int DisjointSets[SIZE];

void Initial(int S[])
{
    for (int i = 0; i < SIZE; i++)
        S[i] = -1;
}

//���� �ʱ�临�Ӷ� O(n)
int Find(int S[], int x)
{
    while (S[x] >= 0)
    {
        x = S[x];
    }
    return x;
}

//�ϲ� ʱ�临�Ӷ�O(1)
void Union(int S[], int Root1, int Root2)
{
    if (Root1 == Root2)
        return;
    S[Root2] = Root1;
}

//�Ż���ĺϲ� ��֤�˹�������߲�����(logn)��ȡ��+1 ʱ�临�Ӷ�O(1)
void UnionOpted(int S[], int Root1, int Root2)
{
    if (Root1 == Root2)
        return;
    //Root2���ϱ�Root1����С
    if (S[Root2] > S[Root1])
    {
        S[Root1] += S[Root2]; //�ۼӽ������
        S[Root2] = Root1;     //С���ϲ�����
    }
    //Root2���ϱ�Root1���ϴ�
    else
    {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
    S[Root2] = Root1;
}

//�Ż���Ĳ��� ��֤���߲�����O(��(n)) ʱ�临�Ӷ�O(��(n))
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

