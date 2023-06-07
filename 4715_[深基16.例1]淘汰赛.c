/*
题目描述

有 2^n（n≤7）个国家参加世界杯决赛圈且进入淘汰赛环节。已经知道各个国家的能力值，且都不相等。
能力值高的国家和能力值低的国家踢比赛时高者获胜。1 号国家和 2 号国家踢一场比赛，胜者晋级。
3 号国家和 4 号国家也踢一场，胜者晋级……晋级后的国家用相同的方法继续完成赛程，直到决出冠军。
给出各个国家的能力值，请问亚军是哪个国家？

输入格式

第一行一个整数 n，表示一共 2n2n 个国家参赛。

第二行 2^n 个整数，第 i 个整数表示编号为 i 的国家的能力值（1≤i≤2^n）。

数据保证不存在平局。

输出格式
仅一个整数，表示亚军国家的编号。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int possibility;
    int number;
} Country;

Country binary_tree[256];
Country countries[130];

void make_binary_tree(int index, int left, int right)
{
    int mid = (left + right) >> 1;

    if (left == right) {
        binary_tree[index].possibility = countries[left].possibility;
        binary_tree[index].number = countries[left].number;
        return ;
    }

    make_binary_tree(index << 1, left, mid);
    make_binary_tree((index << 1) + 1, mid+1, right);
    if (binary_tree[index << 1].possibility > binary_tree[(index << 1) + 1].possibility) {
        binary_tree[index].possibility = binary_tree[index << 1].possibility;
        binary_tree[index].number = binary_tree[index << 1].number;
    } else {
        binary_tree[index].possibility = binary_tree[(index << 1) + 1].possibility;
        binary_tree[index].number = binary_tree[(index << 1) + 1].number;
    }
}

int main(void)
{
    int i;
    int possibility;
    int n;
    int size;

    scanf("%d", &n);

    size = pow(2, n);

    for (i = 1; i <= size; ++i) {
        scanf("%d", &possibility);
        countries[i].possibility = possibility;
        countries[i].number = i;
    }

    make_binary_tree(1, 1, size);

    if (binary_tree[1].number == binary_tree[2].number) {
        printf("%d\n", binary_tree[3].number);
    } else {
        printf("%d\n", binary_tree[2].number);
    }

    return 0;
}