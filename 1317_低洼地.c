/*
一组数，分别表示地平线的高度变化。
高度值为整数，相邻高度用直线连接。找出并统计有多少个可能积水的低洼地？
输入格式
    两行，第一行n,表示有n个数。第2行连续n个数表示地平线高度变化的数据，
    保证首尾为0。(3<=n<=10000,0<=高度<=1000)

输出格式
    一个数，可能积水低洼地的数目。
*/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int prev, hei, cnt, n, i, flag;
    /*
    prev: heigh of previously mountain
    hei: heigh of this mountain
    n: loop times
    i: count loop times
    flag: false if rise or true if decline
    */
    prev = -1;
    cnt = 0;
    flag = false;
    scanf("%d", &n);

    for (i=0; i<n; i++) {
        scanf("%d", &hei);
        if (hei>prev && flag) {
            cnt++;
            flag = false;
        } else if (hei<prev) {
            flag = true;
        }
        prev = hei;
    }

    printf("%d\n", cnt);

    return 0;
}