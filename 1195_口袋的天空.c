/*
题目背景
    小杉坐在教室里，透过口袋一样的窗户看口袋一样的天空。

    有很多云飘在那里，看起来很漂亮，小杉想摘下那样美的几朵云，做成棉花糖。

题目描述
    给你云朵的个数 N，再给你 M 个关系，表示哪些云朵可以连在一起。

    现在小杉要把所有云朵连成 K 个棉花糖，一个棉花糖最少要用掉一朵云，
    小杉想知道他怎么连，花费的代价最小。

输入格式
    第一行有三个数 N,M,K。

    接下来 MM 行每行三个数 X,Y,L，表示 X 云和 Y 云可以通过 L 的代价连在一起。

输出格式
    对每组数据输出一行，仅有一个整数，表示最小的代价。

    如果怎么连都连不出 K 个棉花糖，请输出 No Answer。
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dot1, dot2;
    int fare;
} Edge;

int n, m, k, u, v, w, i;
int ans;
int book[1001];
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
    scanf("%d %d %d", &n, &m, &k);

    for (i = 1; i <= n; ++i)
        book[i] = i;
    for (i = 0; i < m; ++i)
        scanf("%d %d %d", &edges[i].dot1, &edges[i].dot2, &edges[i].fare);
    
    qsort(edges, m, sizeof(Edge), Edge_cmp);
    
    for (i = 0; i < m; ++i) {
        if (n <= k) return ;
        if (front(edges[i].dot1) == front(edges[i].dot2))
            continue;
        ans += edges[i].fare;
        --n;
        book[front(edges[i].dot1)] = front(edges[i].dot2);
    }
}

int main(void) {
    kruskal();

    if (n > k)
        printf("No Answer\n");
    else
        printf("%d\n", ans);
    
    return 0;
}