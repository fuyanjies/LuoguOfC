/*
题目描述
    已知正整数n是两个不同的质数的乘积，试求出两者中较大的那个质数。

输入格式
    一个正整数n。

输出格式
    一个正整数p，即较大的那个质数。
tips:
    n <= 2*(10^9)
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool IsPrime(int num) {
    int i, max;
    max = sqrt(num);

    for (i=2; i<=max; i++)
        if (num % i == 0) return false;
    return true;
}

int main(void) {
    int n, num;
    scanf("%d", &n);

    num = 2;
    while (true) {
        if (n%num==0 && IsPrime(n/num)) {
            num = n / num;
            break;
        }
        num++;
    }
    printf("%d\n", num);

    return 0;
}