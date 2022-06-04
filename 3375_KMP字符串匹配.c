/*
题目描述
    给出两个字符串 s_1 和 s_2 ，若 s_1 的区间 [l,r] 子串与 s_2s 
    2 完全相同，则称 s_2 在 s_1 中出现了，其出现位置为 l。
    现在请你求出 s_2在 s_1中所有出现的位置。

    定义一个字符串 s 的 border 为 s 的一个非 s 本身的子串 t，
    满足 t 既是 s 的前缀，又是 s 的后缀。
    对于 s_2，你还需要求出对于其每个前缀 s'的最长 border t'的长度。

输入格式
    第一行为一个字符串，即为 s_1。
    第二行为一个字符串，即为 s_2。

输出格式
    首先输出若干行，每行一个整数，按从小到大的顺序输出 s_2在 s_1中出现的位置。
    最后一行输出 |s_2|个整数，
    第 i 个整数表示 s_2的长度为 i 的前缀的最长 border 长度。
*/

#include <stdio.h>
#include <string.h>

char first[1000000];
char second[1000000];

int main(void)
{
    scanf("%s %s", first, second);
    int i, j, i_=strlen(first), j_=strlen(second);
    int next[j_];

    // 创建next数组
    next[0] = 0;
    j = 0; i = 1;
    while (i < j_)
    {
        if (second[i] == second[j])
        {
            next[i++] = ++j;
            continue;
        }

        if (j > 0)
            j = next[j-1];
        else 
            next[i++] = j;
    }

    // 查找子串
    j = 0; i = 0;
    while (i < i_)
    {
        if (first[i] == second[j])
        {
            i++;
            j++;
            if (j == j_)
            {
                printf("%d\n", i-j+1);
                j = next[j-1];
            }
            continue;
        }

        if (j > 0)
            j = next[j-1];
        else 
            i++;
    }

    // 显示next数组
    for (i=0; i<j_; i++)
        printf("%d ", next[i]);
    putchar('\n');

    return 0;
}