/*
题目描述
    最近有 n 个不爽的事，每句话都有一个正整数刺痛值（心理承受力极差）。
    爱与愁大神想知道连续 m 个刺痛值的和的最小值是多少，但是由于业务繁忙，
    爱与愁大神只好请你编个程序告诉他。

输入格式
    第一行有两个用空格隔开的整数，分别代表 n 和 m。

    第 2 到第 (n+1) 行，每行一个整数，第 (i+1) 行的整数 a_i代表第 i 件事的刺痛值 a_i​。

输出格式
    输出一行一个整数，表示连续 m 个刺痛值的和的最小值是多少。
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(x, y) (x<y?x:y)

int main(void) {
    int i, j, m, n, cnt=0, min;
    int *nums;

    scanf("%d %d", &n, &m);
    nums = (int*)calloc(n, sizeof(int));

    for (i=0; i<m; i++) {
        scanf("%d", &nums[i]);
        cnt += nums[i];
    }
    min = cnt;
    for (j=0; i<n; i++,j++) {
        scanf("%d", &nums[i]);
        cnt += nums[i]-nums[j];
        min = MIN(min, cnt);
    }

    printf("%d\n", min);

    return 0;
}