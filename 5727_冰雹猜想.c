/*
题目描述
    给出一个正整数 n(n\le 100)n(n≤100)，然后对这个数字一直进行下面的操作：
    如果这个数字是奇数，那么将其乘 3 再加 1，否则除以 2。经过若干次循环后，
    最终都会回到 1。
    经过验证很大的数字（7×10^11）都可以按照这样的方式比变成 1，
    所以被称为“冰雹猜想”。
    例如当 n 是 20，变化的过程是 [20, 10, 5, 16, 8, 4, 2, 1]。

    根据给定的数字，验证这个猜想，并从最后的 1 开始，倒序输出整个变化序列。

For example:
    INPUT:
        20
    OUTPUT:
        1 2 4 8 16 5 10 20
*/

#include <stdio.h>

void ice(int num) {
    if (num==1) {
        printf("%d ", num);
        return ;
    }
    if (num % 2 != 0)
        ice(num*3+1);
    else 
        ice(num/2);
    printf("%d ", num);
}

int main(void) {
    int num;
    scanf("%d", &num);
    ice(num);
    putchar('\n');

    return 0;
}