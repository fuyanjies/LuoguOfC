/*
题目描述
    如题，给出一个有向图，请输出从某一点出发到所有点的最短路径长度。

输入格式
    第一行包含三个整数 n,m,s，分别表示点的个数、有向边的个数、出发点的编号。

    接下来 m 行每行包含三个整数 u,v,w，表示一条 u→v 的，长度为 w 的边。

输出格式
    输出一行 n 个整数，第 i 个表示 s 到第 i 个点的最短路径，若不能到达则输出 2^31 - 1
*/

#include <stdio.h>
#include <stdlib.h>

#define MY_INT_MAX 2147483647
#define NODE_SIZE 10001

typedef struct Node {
    size_t to;
    unsigned fare;
    struct Node *next;
} Node;

Node * new_Node_default() {
    Node *obj = (Node *)malloc(sizeof(Node));
    
    obj->next = NULL;

    return obj;
}

Node * new_Node(const size_t To, const unsigned Fare, Node *Next) {
    Node *obj = (Node *)malloc(sizeof(Node));

    obj->to = To;
    obj->fare = Fare;
    obj->next = Next;

    return obj;
}
void free_Node(Node *obj) {
    Node *node;

    while (obj->next) {
        node = obj->next;
        obj->next = node->next;
        free(node);
    }
    free(obj);
}

Node *nodes[NODE_SIZE];
Node *node;
size_t queue[NODE_SIZE * NODE_SIZE];
size_t n, m, s, u, v, head, tail, temp, i;
unsigned fares[NODE_SIZE];
unsigned w;

int main(void) {
    scanf("%zd %zd %zd", &n, &m, &s);

    for (i = 1; i <= n; ++i) {
        nodes[i] = new_Node_default();
        fares[i] = MY_INT_MAX;
    }
    for (i = 0; i < m; ++i) {
        scanf("%zd %zd %u", &u, &v, &w);
        if (u == v) continue;
        nodes[u]->next = new_Node(v, w, nodes[u]->next);
    }

    queue[tail++] = s;
    fares[s] = 0;
    while (head != tail) {
        temp = tail;
        while (head != temp) {
            node = nodes[queue[head]]->next;
            while (node) {
                if (fares[node->to] > fares[queue[head]] + node->fare) {
                    queue[tail++] = node->to;
                    fares[node->to] = fares[queue[head]] + node->fare;
                }
                node = node->next;
            }
            ++head;
        }
    }

    for (i = 1; i <= n; ++i) {
        printf("%u ", fares[i]);
        free_Node(nodes[i]);
    }

    return 0;
}