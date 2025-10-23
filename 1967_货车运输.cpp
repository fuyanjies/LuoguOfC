#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

struct Node
{
    int idx = 0;
    int cost = std::numeric_limits<int>::max();
    int level =0;
    Node *parent = nullptr;
    std::vector<Node *> childs;
};

struct Set
{
    std::vector<int> data;

    Set(int n) : data(n+1) {}

    void reset()
    {
        for (int i = 1; i < data.size(); ++i) data[i] = i;
    }

    int find(const int idx)
    {
        if (idx == data[idx]) return idx;

        return data[idx] = find(data[idx]);
    }

    void set(const int idx_a, const int idx_b)
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
lca(const Node *a, const Node *b)
{
    int ca = std::numeric_limits<int>::max();
    int cb = std::numeric_limits<int>::max();

    while (a->level > b->level)
    {
        ca = std::min(ca, a->cost);
        a = a->parent;
    }

    while (a->level < b->level)
    {
        cb = std::min(cb, b->cost);
        b = b->parent;
    }

    while (a->level && a != b)
    {
        ca = std::min(ca, a->cost);
        cb = std::min(cb, b->cost);

        a = a->parent;
        b = b->parent;
    }

    return (a == b) ? std::min(ca, cb) : -1;
}

void
set_level(Node *node)
{
    for (Node *n : node->childs)
    {
        n->level = 1 + node->level;
        set_level(n);
    }
}

int
main(void)
{
    std::ios::sync_with_stdio(false);

    int i, c, s;
    int n, m, q, x, y;

    std::cin >> n >> m;

    std::vector<Node> nodes(n+1);
    Set set(n+1);
    std::vector<Side> sides;

    for (i = 1; i <= n; ++i) nodes[i].idx = i;
    set.reset();

    for (i = 0; i < m; ++i)
    {
        std::cin >> x >> y >> c;
        sides.push_back({x, y, c});
    }

    std::sort(sides.begin(), sides.end(), std::greater<Side>());

    for (s = n, i = 0; i < m; ++i)
    {
        if (set.find(sides[i].x) == set.find(sides[i].y)) continue;

        set.set(sides[i].x, sides[i].y);

        Node *p = nodes[sides[i].x].parent;

        if (nullptr == p)
        {
            nodes[sides[i].x].parent = &nodes[sides[i].y];
            nodes[sides[i].x].cost = sides[i].c;
            nodes[sides[i].y].childs.push_back(&nodes[sides[i].x]);
        }
        else
        {
            while (p->parent) p = p->parent;

            p->parent = &nodes[sides[i].y];
            p->cost = sides[i].c;
            nodes[sides[i].y].childs.push_back(p);
        }

        if (1 == --s) break;
    }

    for (i = 1; i <= n; ++i)
    {
        if (nodes[i].parent) continue;
        set_level(&nodes[i]);
    }

    std::cin >> q;
    for (i = 0; i < q; ++i)
    {
        std::cin >> x >> y;

        std::cout << lca(&nodes[x], &nodes[y]) << '\n';
    }

    return 0;
}