/*
题目描述
    输入长度为 n 的一个正整数序列，要求输出序列中最长连号的长度。

    连号指在序列中，从小到大的连续自然数。

输入格式
    第一行，一个整数 n。

    第二行，n 个整数 a_i ，之间用空格隔开。

输出格式
    一个数，最长连号的个数。

For example:
    INPUT:
        10
        1 5 6 2 3 4 5 6 8 9
    OUTPUT:
        5
*/

#include <stdio.h>

#define MAX(x, y) (x>y?x:y)

int main(void) {
    int n, i, prev, num, max=1, con;

    scanf("%d", &n);

    scanf("%d", &prev);
    con = 1;

    for (i=1; i<n; i++) {
        scanf("%d", &num);
        if (num == prev+1) {
            con++;
            max = MAX(max, con);
        } else {
            con = 1;
        }
        prev = num;
    }

    printf("%d\n", max);

    return 0;
}