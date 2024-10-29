/*
# 5 倍经验日

## 题目背景

现在乐斗有活动了！每打一个人可以获得 5 倍经验！absi2011 却无奈的看着那一些比他等级高的好友，想着能否把他们干掉。干掉能拿不少经验的。

## 题目描述

现在 absi2011 拿出了 $x$ 个迷你装药物（嗑药打人可耻…），准备开始与那些人打了。

由于迷你装药物每个只能用一次，所以 absi2011 要谨慎的使用这些药。悲剧的是，用药量没达到最少打败该人所需的属性药药量，则打这个人必输。例如他用 $2$ 个药去打别人，别人却表明 $3$ 个药才能打过，那么相当于你输了并且这两个属性药浪费了。

现在有 $n$ 个好友，给定失败时可获得的经验、胜利时可获得的经验，打败他至少需要的药量。

要求求出最大经验 $s$，输出 $5s$。

## 输入格式

第一行两个数，$n$ 和 $x$。

后面 $n$ 行每行三个数，分别表示失败时获得的经验 $\mathit{lose}_i$，胜利时获得的经验 $\mathit{win}_i$ 和打过要至少使用的药数量 $\mathit{use}_i$。

## 输出格式

一个整数，最多获得的经验的五倍。

## 样例 #1

### 样例输入 #1

```
6 8
21 52 1
21 70 5
21 48 2
14 38 3
14 36 1
14 36 2
```

### 样例输出 #1

```
1060
```

## 提示

**【Hint】**

五倍经验活动的时候，absi2011 总是吃体力药水而不是这种属性药。

**【数据范围】**

- 对于 $10\%$ 的数据，保证 $x=0$。
- 对于 $30\%$ 的数据，保证 $0\le n\le 10$，$0\le x\le 20$。
- 对于 $60\%$ 的数据，保证 $0\le n,x\le 100$， $10<lose_i,win_i\le 100$，$0\le use_i\le 5$。
- 对于 $100\%$ 的数据，保证 $0\le n,x\le 10^3$，$0<lose_i\le win_i\le 10^6$，$0\le use_i\le 10^3$。

**【题目来源】**

fight.pet.qq.com

absi2011 授权题目
*/


#include <stdio.h>
#include <stdlib.h>

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

int main(void)
{
    int n, m, i, j;
    long long lose, win, use;
    long long *dp;

    scanf("%d%d", &n, &m);
    dp = (long long *)calloc((m + 1), sizeof(long long));

    for (i = 0; i < n; ++i) {
        scanf("%lld%lld%lld", &lose, &win, &use);

        for (j = m; j >= use; --j) {
            dp[j] = max(dp[j - use] + win, dp[j] + lose);
        }
        for (; j >= 0; --j) {
            dp[j] += lose;
        }
    }

    printf("%lld\n", 5 * dp[m]);

    return 0;
}