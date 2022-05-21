/*
题目描述
    输入一组勾股数 a,b,c（a != b != c），用分数格式输出其较小锐角的正弦值。
    （要求约分。）

输入格式
    一行，包含三个正整数，即勾股数 a,b,c（无大小顺序）。

输出格式
    一行，包含一个分数，即较小锐角的正弦值

EXAMPLE
    INPUT:
        3 5 4
    OUTPUT:
        3/5
*/

#include <stdio.h>

#define MAX(a, b) (a>b ? a : b)
#define MIN(a, b) (a<b ? a : b)

int main(void)
{
    int a, b, c, max, min;
    scanf("%d %d %d", &a, &b, &c);
    max = MAX(a, MAX(b, c));
    min = MIN(a, MIN(b, c));

    a = max;
    b = min;
    c = -1;

    while (b > 0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    printf("%d/%d\n", min/a, max/a);

    return 0;
}