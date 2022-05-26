/*
题目描述
    1个 nxn 的棋盘。
    请编一个程序找出所有棋子放置的解。
    并把它们以上面的序列方法输出，解按字典顺序排列。
    请输出前 3 个解。最后一行是解的总个数。
入格式
    一行一个正整数 n，表示棋盘是 n×n 大小的。

输出格式
    前三行为前三个解，每个解的两个数字之间用一个空格隔开。
    第四行只有一个数字，表示解的总数。
*/

#include <stdio.h>

int subs[30], sums[30], cums[14], lines[14], count=0;

void print(int *lines, int m_line) {
    int line;
    for (line=1; line<=m_line; line++)
        printf("%d ", lines[line]);
    putchar('\n');
}

void queen(int *lines, int line, int n) {
    int cum;

    for (cum=1; cum<=n; cum++) {
        lines[line] = cum;
        if (sums[line+cum] || subs[line-cum+12] || cums[cum]) continue;
        subs[line-cum+12] = 1;
        sums[line+cum] = 1;
        cums[cum] = 1;
        if (line==n) {
            if (count<3) print(lines, line);
            count++;
        } else {
            queen(lines, line+1, n);
        }
        subs[line-cum+12] = 0;
        sums[line+cum] = 0;
        cums[cum] = 0;
    }
}

int main(void) {
    int n;

    scanf("%d", &n);
    queen(lines, 1, n);
    printf("%d\n", count);

    return 0;
}