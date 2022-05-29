/*
题目描述
    如题，已知一个数列，你需要进行下面两种操作：

    1.将某区间每一个数加上 k。
    2.求出某区间每一个数的和。
输入格式
    第一行包含两个整数 n,m，分别表示该数列数字的个数和操作的总个数。

    第二行包含 n 个用空格分隔的整数，其中第 i 个数字表示数列第 i 项的初始值。

    接下来 m 行每行包含 3 或 4 个整数，表示一个操作，具体如下：

    1 x y k：将区间 [x,y] 内每个数加上 k。
    2 x y：输出区间 [x,y] 内每个数的和。
输出格式
    输出包含若干行整数，即为所有操作 2 的结果。
*/

#include <stdio.h>

#define ll long long

// 树结点
typedef struct {
    ll l, r, s, lazy;
} Tree;

int nums[100001];
Tree tree[400001];

int build(int idx, int *nums, ll l, ll r) {
    // 初始化树
    ll mid = (l+r)>>1;
    
    tree[idx].l = l;
    tree[idx].r = r;
    tree[idx].lazy = 0;

    if (l == r) {
        tree[idx].s = nums[l];
    } else {
        tree[idx].s = build(idx*2, nums, l, mid)+build(idx*2+1, nums, mid+1, r);
    }

    return tree[idx].s;
}

void pushUp(int idx) {
    // 向上更新
    if (idx == 1) return ;

    idx /= 2;
    tree[idx].s = tree[idx*2].s + tree[idx*2+1].s;
    
    pushUp(idx);
}

void pushDown(int idx) {
    // 向下更新
    if (tree[idx].r == tree[idx].l || tree[idx].lazy == 0) return ;
    tree[idx*2].s += tree[idx].lazy * (tree[idx*2].r-tree[idx*2].l+1);
    tree[idx*2].lazy += tree[idx].lazy;
    tree[idx*2+1].s += tree[idx].lazy * (tree[idx*2+1].r-tree[idx*2+1].l+1);
    tree[idx*2+1].lazy += tree[idx].lazy;
    tree[idx].lazy = 0;
}

void update(int idx, ll l, ll r, ll i) {
    // 更新区间[l,r]的值
    if (l <= tree[idx].l && tree[idx].r <= r) {
        tree[idx].s += i * (tree[idx].r-tree[idx].l+1);
        tree[idx].lazy += i;
        pushUp(idx);
        return ;
    }
    if (l > tree[idx].r || r < tree[idx].l) {
        return ;
    }

    pushDown(idx);

    update(idx*2, l, r, i);
    update(idx*2+1, l, r, i);
}

ll sum(int idx, ll l, ll r) {
    // 返回区间[l,r]的和
    if (l <= tree[idx].l && tree[idx].r <= r) {
        return tree[idx].s;
    }
    if (l > tree[idx].r || tree[idx].l > r) {
        return 0;
    }

    pushDown(idx);

    return sum(idx*2, l, r) + sum(idx*2+1, l, r);
}

int main(void) {
    ll l, r, i, n, m;
    int p;

    scanf("%lld %lld", &n, &m);
    for (p=1; p<=n; p++) scanf("%d", &nums[p]);
    build(1, nums, 1, n);

    while (m--) {
        scanf("%d", &p);
        if (p==1) {
            scanf("%lld %lld %lld", &l, &r, &i);
            update(1, l, r, i);
        } else {
            scanf("%lld %lld", &l, &r);
            printf("%lld\n", sum(1, l, r));
        }
    }

    return 0;
}