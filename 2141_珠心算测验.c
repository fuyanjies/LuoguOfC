/*
题目描述
    珠心算是一种通过在脑中模拟算盘变化来完成快速运算的一种计算技术。
    珠心算训练，既能够开发智力，又能够为日常生活带来很多便利，
    因而在很多学校得到普及。

    某学校的珠心算老师采用一种快速考察珠心算加法能力的测验方法。
    他随机生成一个正整数集合，集合中的数各不相同，然后要求学生回答：
    其中有多少个数，恰好等于集合中另外两个（不同的）数之和？

    最近老师出了一些测验题，请你帮忙求出答案。

    (本题目为2014NOIP普及T1)

输入格式
    共两行，第一行包含一个整数n，表示测试题中给出的正整数个数。

    第二行有n个正整数，每两个正整数之间用一个空格隔开，表示测试题中给出的正整数。

输出格式
    一个整数，表示测验题答案。

For example:
    INPUT:
        4
        1 2 3 4
    OUTPUT:
        2

tips:
    【样例说明】

    由1+2=3,1+3=4，故满足测试要求的答案为2。

    注意，加数和被加数必须是集合中的两个不同的数。

    【数据说明】

    对于100%的数据，3≤n≤100，测验题给出的正整数大小不超过10,000。
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main(void) {
    int n, i, j, k, i_j, cnt=0;
    int *nums;

    scanf("%d", &n);
    nums = (int*)calloc(n, sizeof(int));

    for (i=0; i<n; i++)
        scanf("%d", &nums[i]);
    qsort(nums, n, sizeof(int), cmp);

    for (k=2; k<n; k++) {
        i = 0;
        j = k-1;
        while (i<j) {
            i_j = nums[i] + nums[j];
            if (i_j > nums[k])
                j--;
            else if (i_j < nums[k])
                i++;
            else {
                cnt++;
                break;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}