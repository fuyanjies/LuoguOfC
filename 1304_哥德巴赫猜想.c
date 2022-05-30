/*
题目描述
    输入一个偶数 N(N<=10000)，
    验证4~N所有偶数是否符合哥德巴赫猜想：
    任一大于 2 的偶数都可写成两个质数之和。
    如果一个数不止一种分法，则输出第一个加数相比其他分法最小的方案。
    例如 10，10=3+7=5+5，则 10=5+5 是错误答案。

输入格式
    第一行N

输出格式
    4=2+2 6=3+3 …… N=x+y
*/

#include <stdio.h>

int nums[10001]; // 对于i的nums[i]有1表示为合数，0表示为质数(不考虑0,1)，
                 // 初始化全为质数

int main(void) {
    int n, i, j;

    scanf("%d", &n);

    // 初始化所有小于 n 的质数
    for (i=2; i<n; i++) {
        if (nums[i]) continue;
        for (j=i*2; j<n; j+=i) {
            nums[j] = 1;
        }
    }

    for (i=4; i<=n; i+=2) {
        for (j=i-2; j>=2; j--) {
            if (!nums[j] && !nums[i-j]) {
                printf("%d=%d+%d\n", i, i-j, j);
                break;
            }
        }
    }

    return 0;
}