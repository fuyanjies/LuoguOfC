/*
题目描述
    话说有一天 linyorson 在“我的世界”开了一个 n×n（n≤100）
    的方阵，现在他有 m 个火把和 k 个萤石，
    分别放在 (x_1, y_1) ~ (x_m, y_m) 和
     (o_1, p_1) ~ (o_k, p_k)的位置，
    没有光或没放东西的地方会生成怪物。请问在这个方阵中有几个点会生成怪物？

    P.S. 火把的照亮范围是：

        |暗|暗| 光 |暗|暗|
        |暗|光| 光 |光|暗|
        |光|光|火把|光|光|
        |暗|光| 光 |光|暗|
        |暗|暗| 光 |暗|暗|
    萤石：

        |光|光| 光 |光|光|
        |光|光| 光 |光|光|
        |光|光|萤石|光|光|
        |光|光| 光 |光|光|
        |光|光| 光 |光|光|
输入格式
    输入共 m+k+1 行。
    第一行为 n, m, k。
    第 2 到第 m+1 行分别是火把的位置 x_i, y_i。
    第 m+2 到第 m+k+1 行分别是萤石的位置 o_i, p_i。

    注：可能没有萤石，但一定有火把。

    所有数据保证在 int 范围内。

输出格式
    有几个点会生出怪物。
*/

#include <stdio.h>
#include <stdlib.h>

void fire(int **atlas, int x, int y, int n)
{
    for (int nx=x-2; nx<x+3; nx++)
    {
        if (0 <= nx && nx < n)
            atlas[nx][y] = 1;
    }
    for (int ny=y-2; ny<y+3; ny++)
    {
        if (0 <= ny && ny < n)
            atlas[x][ny] = 1;
    }
    for (int nx=x-1; nx<x+2; nx++)
    {
        if (0 <= nx && nx < n)
        {
            for (int ny=y-1; ny<y+2; ny++)
            {
                if (0 <= ny && ny < n)
                    atlas[nx][ny] = 1;
            }
        }
    }
}

void stone(int **atlas, int x, int y, int n)
{
    for (int nx=x-2; nx<x+3; nx++)
    {
        if (0 <= nx && nx < n)
        {
            for (int ny=y-2; ny<y+3; ny++)
            {
                if (0 <= ny && ny < n)
                    atlas[nx][ny] = 1;
            }
        }
    }
}

int main(void)
{
    int n, m, k, x, y;
    int ans = 0;
    int **atlas;

    scanf("%d %d %d", &n, &m, &k);

    atlas = (int **)malloc(n * sizeof(int *));

    for (int i=0; i<n; i++)
    {
        atlas[i] = (int *)calloc(n, sizeof(int));
    }

    for (int i=0; i<m; i++)
    {
        scanf("%d %d", &x, &y);
        fire(atlas, --x, --y, n);
    }
    for (int i=0; i<k; i++)
    {
        scanf("%d %d", &x, &y);
        stone(atlas, --x, --y, n);
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (!atlas[i][j])
                ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}