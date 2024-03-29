/*
题目描述
    现代数学的著名证明之一是 Georg Cantor 证明了有理数是可枚举的。
    他是用下面这一张表来证明这一命题的：

    1/1 , 1/2 , 1/3 , 1/4, 1/5, …

    2/1, 2/2 , 2/3, 2/4, …

    3/1 , 3/2, 3/3, …

    4/1, 4/2, …

    5/1, …

    …

    我们以 Z 字形给上表的每一项编号。第一项是 1/1，
    然后是 1/2，2/1，3/1，2/2，…

输入格式
    整数N（1≤N≤10^7）。

输出格式
    表中的第 N 项。
*/

#include <stdio.h>

int main(void) {
    int n, i;

    scanf("%d", &n);
    i = 1;
    while (n>i) {
        n -= i;
        i++;
    }
    if (i%2==0) printf("%d/%d\n", n, i+1-n);
    else printf("%d/%d\n", i+1-n, n);
    
    return 0;
}