/*
题目描述
    给出 n(n≤100) 和 n 个整数 a(0≤a≤1000)，
    求这 n 个整数中的极差是什么。
    极差的意思是一组数中的最大值减去最小值的差。

输入格式
    第一行 1个整数 n
    第二行 n个整数

输出格式
    1个整数，即结果
*/

#include <stdio.h>

#define MIN(x, y) (x<y?x:y)
#define MAX(x, y) (x>y?x:y)

int main(void)
{
    int n, i, num, min, max;
    scanf("%d", &n);
    scanf("%d", &min);
    max = min;
    for (i=1; i<n; i++)
    {
        scanf("%d", &num);
        min = MIN(min, num);
        max = MAX(max, num);
    }

    printf("%d\n", max-min);

    return 0;
}