/*
题目背景
    Farmer John 被选为他们镇的镇长！他其中一个竞选承诺就是在镇上建立起互联网，
    并连接到所有的农场。当然，他需要你的帮助。

题目描述
    FJ 已经给他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。
    为了用最小的消费，他想铺设最短的光纤去连接所有的农场。

    你将得到一份各农场之间连接费用的列表，你必须找出能连接所有农场并所用光纤最短的方案。
    每两个农场间的距离不会超过 10^5。

输入格式
    第一行农场的个数 N（3≤N≤100）。

    接下来是一个 N×N 的矩阵，表示每个农场之间的距离。理论上，他们是 N 行，
    每行由 N 个用空格分隔的数组成，实际上，由于每行 80 个字符的限制，因此，
    某些行会紧接着另一些行。当然，对角线将会是 0，因为不会有线路从第 i 个农场到它本身。

输出格式
    只有一个输出，其中包含连接到每个农场的光纤的最小长度。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dot1, dot2;
    int fare;
} Edge;

int n, m, i, j, _;
int book[101];
Edge edges[10001];

int Edge_cmp(const void *a, const void *b) {
    return ((Edge *)a)->fare - ((Edge *)b)->fare;
}

int front(const int i) {
    if (i == book[i])
        return i;
    return book[i] = front(book[i]);
}

void kruskal(void) {
    scanf("%d", &n);

    for (i = 1; i <= n; ++i)
        book[i] = i;
    
    for (i = 0; i < n; ++i) {
        for (j = 0; j <= i; ++j)
            scanf("%d", &_);
        for (j = i + 1; j < n; ++j) {
            scanf("%d", &edges[m].fare);
            edges[m].dot1 = i;
            edges[m++].dot2 = j;
        }
    }

    qsort(edges, m, sizeof(Edge), Edge_cmp);

    j = 0;
    for (i = 0; i < m; ++i) {
        if (n <= 0) return ;
        if (front(edges[i].dot1) == front(edges[i].dot2))
            continue;
        
        --n;
        j += edges[i].fare;
        book[front(edges[i].dot1)] = front(edges[i].dot2);
    }
}

int main(void) {
    kruskal();

    printf("%d\n", j);

    return 0;
}