/*
题目描述
    Peter 有 n 根烟，他每吸完一根烟就把烟蒂保存起来，
    k（k>1）个烟蒂可以换一个新的烟，那么 Peter 最终能吸到多少根烟呢？

    吸烟有害健康。

输入格式
    每组测试数据一行包括两个整数 n,k（1<n, k≤10^8）。

输出格式
    对于每组测试数据，输出一行包括一个整数表示最终烟的根数。
*/

#include <stdio.h>

int main(void) {
    int n, k, ans;

    scanf("%d %d", &n, &k);
    ans = n;

    while (n>=k) {
        ans += n / k;
        n = n / k + n % k;
    }
    printf("%d\n", ans);

    return 0;
}