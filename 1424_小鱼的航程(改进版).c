/*
题目描述
    有一只小鱼，它平日每天游泳 250 公里，周末休息(实行双休日)，
    假设从周 x(1≤x≤7) 开始算起，过了 n(n≤10^6) 天以后，
    小鱼一共累计游泳了多少公里呢？

输入格式
    输入两个整数x,n(表示从周x算起，经过n天）。

输出格式
    输出一个整数，表示小鱼累计游泳了多少公里。
*/

#include <stdio.h>

int main(void)
{
    int x, n, ans=0;

    scanf("%d %d", &x, &n);

    ans += (n/7) * 250 * 5;
    n %= 7;

    if (n>0)
        if (x+n == 7 || x==7)
            ans += (n-1) * 250;
        else if (x+n >= 8)
            ans += (n-2) * 250;
        else
            ans += n * 250;

    printf("%d\n", ans);

    return 0;
}