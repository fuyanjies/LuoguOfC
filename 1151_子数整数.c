/*
题目描述
    对于一个五位数a_1a_2a_3a_4a_5，可将其拆分为三个子数：

    sub_1=a_1a_2a_3
    sub_2=a_2a_3a_4
    sub_3=a_3a_4a_5
    例如，五位数20207可以拆分成

    sub_1=202
    sub_2=020(=20)
    sub_3=207
    现在给定一个正整数K，要求你编程求出10000到30000之间所有满足下述条件
    的五位数，条件是这些五位数的三个子数sub_1,sub_2,sub_3都可被KK整除。

输入格式
    一个正整数K

输出格式
    每一行为一个满足条件的五位数，要求从小到大输出。
    不得重复输出或遗漏。如果无解，则输出“No”。
*/

#include <stdio.h>

int main(void) {
    int num, K;
    int sub1, sub2, sub3;
    int flag = 0;

    scanf("%d", &K);
    for (num=10000; num<=30000; num++) {
        sub1 = num / 100;
        sub2 = (num / 10) % 1000;
        sub3 = num % 1000;
        if (sub1%K==0 && sub2%K==0 &&sub3%K==0) {
            printf("%d\n", num);
            flag = 1;
        }
    }

    if (!flag)  printf("No\n");

    return 0;
}