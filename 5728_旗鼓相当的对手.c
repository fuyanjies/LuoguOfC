/*
题目描述
    现有 N(N≤1000) 名同学参加了期末考试，
    并且获得了每名同学的信息：语文、数学、英语成绩（均为不超过 150 的自然数）。
    如果某对学生 <i,j> 的每一科成绩的分差都不大于 5，且总分分差不大于 10，
    那么这对学生就是“旗鼓相当的对手”。现在想知道这些同学中，
    有几对“旗鼓相当的对手”？同样一个人可能会和其他好几名同学结对。

输入格式
    第一行一个正整数 N。

    接下来 N 行，每行三个整数，
    其中第 i 行表示第 i 名同学的语文、数学、英语成绩。
    最先读入的同学编号为 1。

输出格式
    输出一个个整数，表示“旗鼓相当的对手”的对数。
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int c, m, e, s;
} Item;

int main(void) {
    int n, cnt, i, j;
    Item **all, *cur;

    cnt = 0;

    scanf("%d", &n);
    all = (Item**)malloc(sizeof(Item*)*n);

    for (i=0; i<n; i++) {
        cur = (Item*)malloc(sizeof(Item));
        scanf("%d %d %d", &cur->c, &cur->m, &cur->e);
        cur->s = cur->c + cur->m + cur->e;
        all[i] = cur;
    }

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (i!=j && abs(all[i]->c-all[j]->c)<=5 &&\
                    abs(all[i]->m-all[j]->m)<=5 &&\
                    abs(all[i]->e-all[j]->e)<=5 &&\
                    abs(all[i]->s-all[j]->s)<=10)
                cnt++;
        }
    }

    printf("%d\n", cnt/2);
}