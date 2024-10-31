/*
# 通天之分组背包

## 题目背景

直达通天路·小 A 历险记第二篇

## 题目描述

自 $01$ 背包问世之后，小 A 对此深感兴趣。一天，小 A 去远游，却发现他的背包不同于 $01$ 背包，他的物品大致可分为 $k$ 组，每组中的物品相互冲突，现在，他想知道最大的利用价值是多少。

## 输入格式

两个数 $m,n$，表示一共有 $n$ 件物品，总重量为 $m$。

接下来 $n$ 行，每行 $3$ 个数 $a_i,b_i,c_i$，表示物品的重量，利用价值，所属组数。

## 输出格式

一个数，最大的利用价值。

## 样例 #1

### 样例输入 #1

```
45 3
10 10 1
10 5 1
50 400 2
```

### 样例输出 #1

```
10
```

## 提示

$0 \leq m \leq 1000$，$1 \leq n \leq 1000$，$1\leq k\leq 100$，$a_i, b_i, c_i$ 在 `int` 范围内。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int weight, profit, group;
} helper_t;

int helper_cmd(const void *a, const void *b)
{
    return ((helper_t *)a)->group - ((helper_t *)b)->group;
} 

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(void)
{
    int n, m, i, j, group;
    int *dp_a, *dp_b;
    helper_t *input;

    scanf("%d%d", &m, &n);

    input = (helper_t *)malloc(n * sizeof(helper_t));
    dp_a = (int *)calloc(m+1, sizeof(int));
    dp_b = (int *)calloc(m+1, sizeof(int));

    for (i = 0; i < n; ++i) {
        scanf("%d%d%d", &input[i].weight, &input[i].profit, &input[i].group);
    }

    qsort(input, n, sizeof(helper_t), helper_cmd);

    group = input[0].group;
    for (i = 0; i < n; ++i) {
        if (group != input[i].group) {
            memcpy(dp_a, dp_b, (m+1) * sizeof(int));
            group = input[i].group;
        }

        for (j = m; j >= input[i].weight; --j) {
            dp_b[j] = max(dp_a[j-input[i].weight] + input[i].profit, dp_b[j]);
        }
    }

    printf("%d\n", dp_b[m]);

    return 0;
}