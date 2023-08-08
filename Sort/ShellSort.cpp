/*
 * @Author: farron_cat
 * @Date: 2021-09-11 20:00:26
 * @LastEditTime: 2022-11-10 16:12:30
 * @LastEditors: farron_cat
 * @Description: 希尔排序
 * @FilePath: \Briup\learn\data_structure\Sort\ShellSort.cpp
 * 版权归法兰小猫所有
 */

typedef int ElemType;
//A[0]为哨兵 元素从下标1开始存储
void ShellSort(ElemType A[], int n)
{
    int i,j,dk;
    for (dk = n / 2; dk >= 1; dk /= 2)
    {
        for (i = dk + 1; i <= n; ++i) //i = dk + 1从子表的第二个元素开始   ++i会在几个子表之间切换操作
        {
            if (A[i] < A[i - dk])
            {
                A[0] = A[i];
                for (j = i - dk; j > 0 && A[0] < A[j]; j-=dk) //注意 j > 0 因为减量为dk A[0]拦不住
                {
                    A[j + dk] = A[j];  //从后往前依次后移
                }
                A[j + dk] = A[0];
            }
        }
    }
}

/*
 *空间：O(1)
 *时间：分析比较复杂，n在特定范围时约为O(n^1.3)
 *      最坏 O(n^2)
 *稳定性：可能改变相对次序 不稳定
 */
