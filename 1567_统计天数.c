/*
题目描述
    炎热的夏日，KC 非常的不爽。他宁可忍受北极的寒冷，也不愿忍受厦门的夏天。
    最近，他开始研究天气的变化。他希望用研究的结果预测未来的天气。

    经历千辛万苦，他收集了连续 N(1≤N≤10^6) 的最高气温数据。

    现在，他想知道最高气温一直上升的最长连续天数。

输入格式
    第 1 行：一个整数 N 。1≤N≤10^6
 

    第 2 行：N个空格隔开的整数，表示连续 N 天的最高气温。
    0≤最高气温≤10^9
  。

输出格式
    1 行：一个整数，表示最高气温一直上升的最长连续天数。
*/

#include <stdio.h>

#define MAX(x, y) (x>y?x:y)

int main(void) {
    int n, today, prev=-1, cnt=0, max=0;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &today);
        if (today>prev) cnt++;
        else cnt = 1;
        prev = today;
        max = MAX(max, cnt);
    }

    printf("%d\n", max);

    return 0;
}