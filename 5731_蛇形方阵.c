/*
题目描述
    给出一个不大于 9 的正整数 n，输出 n×n 的蛇形方阵。

    从左上角填上 1 开始，顺时针方向依次填入数字，如同样例所示。
    注意每个数字有都会占用 3 个字符，前面使用空格补齐。
*/

#include <stdio.h>

int nums[9][9];
int diraction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main(void) {
    int n, i=0, j=-1, num=1, idx=0;
    
    scanf("%d", &n);

    while (num <= n*n) {
        i += diraction[idx][0];
        j += diraction[idx][1];
        if (nums[i][j] || i>=n || i<0 || j>=n || j<0) {
            i -= diraction[idx][0];
            j -= diraction[idx][1];
            idx++;
            if (idx==4) idx=0;
            continue;
        }
        nums[i][j] = num++;
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("% 3d", nums[i][j]);
        }
        printf("\n");
    }

    return 0;
}