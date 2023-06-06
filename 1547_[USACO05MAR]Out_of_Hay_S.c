/*
题目描述
    Bessie 计划调查 N（2≤N≤2000）个农场的干草情况，它从 1 号农场出发。
    农场之间总共有 M（1≤M≤10^4）条双向道路，所有道路的总长度不超过 10^9。
    有些农场之间存在着多条道路，所有的农场之间都是连通的。

    Bessie 希望计算出该图中最小生成树中的最长边的长度。

输入格式
    第一行两个整数 N,M。

    接下来 M 行，每行三个用空格隔开的整数 A_i,B_i,L_i，表示 A_i,B_i之间有一条道路，
    长度为 L_i。

输出格式
    一个整数，表示最小生成树中的最长边的长度
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct {
    int dot1, dot2;
    unsigned fare;
} Edge;

int u, v, i, n, m;
unsigned w, max = 0;
int book[2001];
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
    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; ++i)
        book[i] = i;
    for (i = 0; i < m; ++i)
        scanf("%d %d %u", &edges[i].dot1, &edges[i].dot2, &edges[i].fare);
    
    qsort(edges, m, sizeof(Edge), Edge_cmp);

    for (i = 0; i < m; ++i) {
        if (n <= 0)
            break;
        if (front(edges[i].dot1) == front(edges[i].dot2))
            continue;
        
        --n;
        book[front(edges[i].dot1)] = front(edges[i].dot2);
        max = MAX(max, edges[i].fare);
    }
}

int main(void) {
    kruskal();

    printf("%u\n", max);

    return 0;
}