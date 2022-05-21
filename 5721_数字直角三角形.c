/*
题目描述
    给出n(1≤n≤13)，请输出一个直角边长度是 n 的数字直角三角形。
    所有数字都是 2 位组成的，如果没有 2 位则加上前导 0。
INPUT:
    5
OUTPUT:
    0102030405
    06070809
    101112
    1314
    15
*/

#include <stdio.h>

int main(void)
{
    int n, line, cum, num=1;
    scanf("%d", &n);

    for (line=0; line<n; line++)
    {
        for (cum=0; cum<n-line; cum++)
        {
            printf("%02d", num++);
        }
        putchar('\n');
    }
    
    return 0;
}