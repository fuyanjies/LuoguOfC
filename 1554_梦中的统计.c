/*
题目背景
    Bessie 处于半梦半醒的状态。过了一会儿，她意识到她在数数，不能入睡。

题目描述
    Bessie的大脑反应灵敏，仿佛真实地看到了她数过的一个又一个数。
    她开始注意每一个数码（0…9）：每一个数码在计数的过程中出现过多少次？

    给出两个整数 M 和 N （1≤M≤N≤2×10^9以及 N−M≤5×10^5），
    求每一个数码出现了多少次。

输入格式
    第 1 行: 两个用空格分开的整数 M 和 N。

输出格式
    第 1 行: 十个用空格分开的整数，分别表示数码 0…9 在序列中出现的次数。
*/

#include <stdio.h>

int main(void) {
    int start, end, num, n;
    static int cnt[10];

    scanf("%d %d", &start, &end);

    for (num=start; num<=end; num++) {
        n = num;
        while (n>0) {
            cnt[n%10]++;
            n /= 10;
        }
    }

    for (n=0; n<10; n++)
        printf("%d ", cnt[n]);
    putchar('\n');

    return 0;
}