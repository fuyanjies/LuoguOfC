/*
【题目描述】

    三个整数分别为 A,B,C。这三个数字不会按照这样的顺序给你，
    但它们始终满足条件：A<B<C。为了看起来更加简洁明了，
    我们希望你可以按照给定的顺序重新排列它们。

【输入格式】

    第一行包含三个正整数 A,B,C，不一定是按这个顺序。
    这三个数字都小于或等于 100。
    第二行包含三个大写字母 A、B 和 C（它们之间没有空格）表示所需的顺序。

【输出格式】

    在一行中输出 A，B 和 C，用一个 （空格）隔开。

For example :
    Input:
        1 5 3
        ABC
    Output:
        1 3 5
*/

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main(void)
{
    int nums[3];
    int i;
    char str[4];

    for (i=0; i<3; i++)
    {
        scanf("%d", &nums[i]);
    }
    scanf("%s", str);

    qsort(nums, 3, sizeof(int), cmpfunc);

    for (i=0; i<3; i++)
    {
        printf("%d ", nums[str[i]-65]);
    }
    putchar('\n');

    return 0;
}