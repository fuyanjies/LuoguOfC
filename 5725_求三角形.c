/*
## 题目描述

    模仿例题，打印出不同方向的正方形，然后打印三角形矩阵。中间有个空行。

## 输入格式

    输入矩阵的规模，不超过 9。

## 输出格式

    输出矩形和正方形

## 样例 #1

    ### 样例输入 #1

    ```
    4
    ```

    ### 样例输出 #1

    ```
    01020304
    05060708
    09101112
    13141516

          01
        0203
      040506
    07080910
    ```
*/

#include <stdio.h>

int main(void) {
    int i, j, num, n;
    
    scanf("%d", &n);

    num = 1;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%02d", num++);
        }
        putchar('\n');
    }
    putchar('\n');

    num = 1;
    for (i=0; i<n; i++) {
        for (j=0; j<n-i-1; j++) printf("  ");
        for (j=0; j<=i; j++) printf("%02d", num++);
        putchar('\n');
    }

    return 0;
}