/*
题目描述
    给定 n(n≤10000) 和 k(k≤100)，
    将从 1 到 n 之间的所有正整数可以分为两类：
    A 类数可以被 k 整除（也就是说是 k 的倍数），
    而 B 类数不能。请输出这两类数的平均数，精确到小数点后 1 位，用空格隔开。

    数据保证两类数的个数都不会是 0。

输入格式
无

输出格式
无
*/

#include <stdio.h>

int main(void) {
    int a=0, b=0, a_c=0, b_c=0;
    int n, k, i;

    scanf("%d %d", &n, &k);

    for (i=1; i<=n; i++) {
        if (i % k == 0) {
            a += i;
            a_c++;
        } else {
            b += i;
            b_c++;
        }
    }

    printf("%.1f %.1f\n", (float)a/(float)a_c, (float)b/(float)b_c);

    return 0;
}