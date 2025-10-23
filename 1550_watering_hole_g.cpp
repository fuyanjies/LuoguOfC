/*
# P1550 [USACO08OCT] Watering Hole G

## 题目描述

Farmer John 的农场缺水了。

他决定将水引入到他的 $n$ 个农场。他准备通过挖若干井，并在各块田中修筑水道来连通各块田地以供水。在第 $i$ 号田中挖一口井需要花费 $W_i$ 元。连接 $i$ 号田与 $j$ 号田需要 $P_{i,j}$（$P_{j,i}=P_{i,j}$）元。

请求出 FJ 需要为使所有农场都与有水的农场相连或拥有水井所需要的最少钱数。

## 输入格式

第一行为一个整数 $n$。

接下来 $n$ 行，每行一个整数 $W_i$。

接下来 $n$ 行，每行 $n$ 个整数，第 $i$ 行的第 $j$ 个数表示连接 $i$ 号田和 $j$ 号田需要的费用 $P_{i,j}$。

## 输出格式

输出最小开销
*/

/**
 * 转换思路，题目要求是把所有农庄和水连起来，水在哪？地下，看作一个单独的农庄就好
 * 那就成了一个n+1个点的最小生成树模板了
 */

#include <iostream>
#include <queue>
#include <vector>

struct Set
{
    std::vector<int> data;

    Set (int n) : data(n+1) {}

    void 
    reset()
    {
        for (int i = 0; i < data.size(); ++i) data[i] = i;
    }

    int
    find(const int idx)
    {
        if (idx == data[idx]) return idx;

        return data[idx] = find(data[idx]);
    }

    void
    set(const int idx_a, const int idx_b)
    {
        if (idx_a == data[idx_a])
        {
            data[idx_a] = find(idx_b);

            return ;
        }

        data[find(idx_a)] = find(idx_b);
    }
};

struct Side
{
    int x, y, c;

    bool operator > (const Side &other) const
    {
        return c > other.c;
    }
};

int
main(void)
{
    std::ios::sync_with_stdio(false);

    int i, j, c, res{};
    int n;

    std::cin >> n;

    Set set(n+1);
    std::priority_queue<Side, std::vector<Side>, std::greater<Side>> pq{};

    for (i = 1; i <= n; ++i)
    {
        std::cin >> c;
        pq.push({0, i, c});
    }

    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= i; ++j) std::cin >> c;

        for (; j <= n; ++j)
        {
            std::cin >> c;

            pq.push({i, j, c});
        }
    }

    set.reset();
    while (!pq.empty())
    {
        Side s = pq.top();
        pq.pop();

        if (set.find(s.x) == set.find(s.y)) continue;

        res += s.c;

        set.set(s.x, s.y);

        if (0 == --n) break;
    }

    std::cout << res << '\n';

    return 0;
}