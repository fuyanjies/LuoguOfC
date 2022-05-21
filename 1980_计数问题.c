/*
题目描述
    试计算在区间 1 到 n 的所有整数中，数字 x（0≤x≤9）共出现了多少次？
    例如，在 1 到 11 中，即在 1,2,3,4,5,6,7,8,9,10,11 中，数字 1 出现了 4 次。

输入格式
    2个整数 n,x 之间用一个空格隔开。

输出格式
    1个整数，表示 x 出现的次数。
*/

#include <stdio.h>

/* 
    给定两个整数 num, x
    返回 num 中有多少个 x
*/
int count(int num, int x)
{
    int ans = 0;
    while (num > 0)
    {
        int remind = num % 10;
        num /= 10;
        if (remind == x)
            ans++;
    }

    return ans;
}

int main(void)
{
    int n, x, i, ans=0;
    scanf("%d %d", &n, &x);

    for (i=1; i<=n; i++)
    {
        ans += count(i, x);
    }

    printf("%d\n", ans);

    return 0;
}