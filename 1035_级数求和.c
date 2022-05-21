/*
题目描述

    已知：Sn=1+1/2+1/3+…+1/n
    显然对于任意一个整数 k，当 n 足够大的时候，Sn>k。

    现给出一个整数 k，要求计算出一个最小的 nnn，使得 Sn>k。
输入格式

    一个正整数 k。
输出格式

    一个正整数 n。

*/

#include <stdio.h>

int main(void)
{
    int k, n=1;
    double s = 0.0;

    scanf("%d", &k);

    while (s<=k)
    {
        s += 1/(double)n;
        n++;
        printf("now s is %f\n", s);
    }

    printf("%d\n", --n);

    return 0;
}