/*
题目描述
    一个n个元素的整数数组，如果数组两个连续元素之间差的绝对值包括了[1,n-1]
    之间的所有整数，则称之符合“欢乐的跳”，如数组1 4 2 3符合“欢乐的跳”，
    因为差的绝对值分别为：3,2,1。

    给定一个数组，你的任务是判断该数组是否符合“欢乐的跳”。

输入格式
    每组测试数据第一行以一个整数n(1≤n≤1000)开始，
    接下来n个空格隔开的在[-10^8,10^8]之间的整数。

输出格式
    对于每组测试数据，输出一行若该数组符合“欢乐的跳”则输出"Jolly"，
    否则输出"Not jolly"。
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int *nums;
    int num, prev, this, i, n;

    scanf("%d %d", &n, &prev);
    nums = (int*)calloc(n, sizeof(int));
    memset(nums, 0, sizeof(int));

    for (i=1; i<n; i++) {
        scanf("%d", &this);
        num = abs(this-prev);
        if (num < n) nums[num]++;
        prev = this;
    }

    for (i=1; i<n; i++) {
        if (!nums[i]) {
            printf("Not jolly\n");
            break;
        }
    }
    if (i==n) printf("Jolly\n");

    return 0;
}