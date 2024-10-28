/*
# 租用游艇

## 题目描述

长江游艇俱乐部在长江上设置了 $n$ 个游艇出租站 $1,2,\cdots,n$。游客可在这些游艇出租站租用游艇，并在下游的任何一个游艇出租站归还游艇。游艇出租站 $i$ 到游艇出租站 $j$ 之间的租金为 $r(i,j)$（$1\le i\lt j\le n$）。试设计一个算法，计算出从游艇出租站 $1$ 到游艇出租站 $n$ 所需的最少租金。

## 输入格式

第一行中有一个正整数 $n$，表示有 $n$ 个游艇出租站。接下来的 $n-1$ 行是一个半矩阵 $r(i,j)$（$1\le i<j\le n$）。

## 输出格式

输出计算出的从游艇出租站 $1$ 到游艇出租站 $n$ 所需的最少租金。

## 样例 #1

### 样例输入 #1

```
3
5 15
7
```

### 样例输出 #1

```
12
```

## 提示

$n\le 200$，保证计算过程中任何时刻数值都不超过 $10^6$。
*/

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a > b ? b : a;
}

int main(void)
{
    int n, i, j;
    int **map;

    scanf("%d\n", &n);

    map = (int **)malloc(n * sizeof(int *));
    
    for (i = 0; i < n - 1; ++i) {
        map[i] = (int *)malloc(n * sizeof(int));
        for (j = i + 1; j < n; ++j) {
            scanf("%d", map[i] + j);
        }
    }
    map[n-1] = (int *)malloc(n * sizeof(int));

    map[0][0] = 0;
    for (i = 1; i < n; ++i) {
        map[i][i] = 1000000;
    }

    for (i = 0; i < n - 1; ++i) {
        for (j = i + 1; j < n; ++j) {
            map[j][j] = min(map[i][i] + map[i][j], map[j][j]);
        }
    }

    printf("%d\n", map[n-1][n-1]);

    for (i = 0; i < n; ++i)
        free(map[i]);
    free(map);

    return 0;
}