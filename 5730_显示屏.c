/*
题目描述
    液晶屏上，每个阿拉伯数字都是可以显示成 3×5 的点阵的（其中 X 表示亮点，
    . 表示暗点）。现在给出数字位数（不超过 100）和一串数字，
    要求输出这些数字在显示屏上的效果。数字的显示方式如同样例输出，
    注意每个数字之间都有一列间隔。
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 101

char *a[] = {"XXX", "..X", "XXX", "XXX", "X.X", "XXX", "XXX", "XXX", "XXX", "XXX"};
char *b[] = {"X.X", "..X", "..X", "..X", "X.X", "X..", "X..", "..X", "X.X", "X.X"};
char *c[] = {"X.X", "..X", "XXX", "XXX", "XXX", "XXX", "XXX", "..X", "XXX", "XXX"};
char *d[] = {"X.X", "..X", "X..", "..X", "..X", "..X", "X.X", "..X", "X.X", "..X"};
char *e[] = {"XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX"};

int main(void) {
    char nums[MAXSIZE];
    char **asc[5] = {a, b, c, d, e};
    int max, i, j;

    scanf("%d %s", &max, nums);

    for (i=0; i<5; i++) {
        for (j=0; j<max; j++) {
            if (j == max-1) {
                printf("%s", asc[i][nums[j]-'0']);
            } else {
                printf("%s.", asc[i][nums[j]-'0']);
            }
        }
        putchar('\n');
    }

    return 0;
}