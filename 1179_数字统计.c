/*
题目描述
    请统计某个给定范围[L,R]的所有整数中，数字 2 出现的次数。

    比如给定范围[2,22]，数字22 在数 22中出现了 1 次，在数12 中出现 1 次，
    在数 20 中出现 1次，在数 21 中出现 1 次，在数 22 中出现 2次，
    所以数字2 在该范围内一共出现了 6 次。

输入格式
    2个正整数 L 和 R，之间用一个空格隔开。

输出格式
    数字 2出现的次数。
*/

#include <stdio.h>

int count_2(int num);

int main(void) {
    int l, r, num, ans=0;

    scanf("%d %d", &l, &r);
    for (num=l; num<=r; num++) {
        ans += count_2(num);
    }
    printf("%d\n", ans);

    return 0;
}

int count_2(int num) {
    int ans = 0;
    while (num > 0) {
        if (num%10 == 2) ans++;
        num /= 10;
    }

    return ans;
}