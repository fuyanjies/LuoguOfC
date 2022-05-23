/*
题目描述
    小 A 有一个质数口袋，里面可以装各个质数。他从 2 开始，
    依次判断各个自然数是不是质数，如果是质数就会把这个数字装入口袋。
    口袋的负载量就是口袋里的所有数字之和。但是口袋的承重量有限，
    不能装得下总和超过 L (1≤L≤10^5）的质数。
    给出 L，请问口袋里能装下几个质数？将这些质数从小往大输出，
    然后输出最多能装下的质数个数，所有数字之间有一空行。

输入格式
    一行一个正整数 LL。

输出格式
    将这些质数从小往大输出，然后输出最多能装下的质数个数，所有数字之间有一空行。
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
    int big, num, cnt=0;

    scanf("%d", &big);

    num = 2;
    while (big-num >= 0) {
        if (IsPrime(num)) {
            printf("%d\n", num);
            big -= num;
            cnt++;
        }
        num++;
    }
    printf("%d\n", cnt);

    return 0;
}