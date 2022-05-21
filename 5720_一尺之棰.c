/*
题目描述
    《庄子》中说到，“一尺之棰，日取其半，万世不竭”。
    第一天有一根长度为 a(a≤10^9) 的木棍，
    从第二天开始，每天都要将这根木棍锯掉一半（每次除 2，向下取整）。
    第几天的时候木棍会变为 1？
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    int length;
    scanf("%d", &length);

    printf("%d\n", (int)log2(length)+1);

    return 0;
}