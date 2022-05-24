/*
题目描述
    现在有 n(n≤1000) 位评委给选手打分，分值从 0 到 10。
    需要去掉一个最高分，去掉一个最低分
    (如果有多个最高或者最低分，也只需要去掉一个)，
    剩下的评分的平均数就是这位选手的得分。
    现在输入评委人数和他们的打分，请输出选手的最后得分，精确到 2 位小数。

输入格式
    无

输出格式
    无

For example:
    INPUT:
        5
        9 5 6 8 9
    OUTPUT:
        7.67
*/

#include <stdio.h>

#define MAX(x, y) (x>y?x:y)
#define MIN(x, y) (x<y?x:y)

int main(void) {
    int min=11, max=0, num, n, i, cnt=0;

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d", &num);
        min = MIN(min, num);
        max = MAX(max, num);
        cnt += num;
    }

    cnt -= max+min;
    printf("%.2f\n", cnt/(n-2.0));

    return 0;
}