/*
题目背景
    本题为提交答案题，您可以写程序或手算在本机上算出答案后，
    直接提交答案文本，也可提交答案生成程序。

题目描述
    将 1, 2, ... , 9 共 9 个数分成 3 组，分别组成 3 个三位数，
    且使这 3 个三位数构成 1:2:3 的比例，试求出所有满足条件的 3 个三位数。

输入格式
    无

输出格式
    若干行，每行 3 个数字。按照每行第 1 个数字升序排列。
*/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    bool flag=true;
    int a, b, c, i, num;
    int nums[10];

    for (a=1; a<4; a++) {
        for (b=1; b<10; b++) {
            for (c=1; c<10; c++) {
                for (i=1; i<10; i++) nums[i] = 0;
                flag = true;
                nums[a]++;
                nums[b]++;
                nums[c]++;
                num = a*200+b*20+c*2;
                while (num>0) {
                    nums[num%10]++;
                    num /= 10;
                }

                num = a*300+b*30+c*3;
                while (num>0) {
                    nums[num%10]++;
                    num /= 10;
                }

                for (i=1; i<10; i++)
                    if (nums[i]==0)
                        flag = false;
                if (flag)
                    printf("%d %d %d\n", a*100+b*10+c, a*200+b*20+c*2, a*300+b*30+c*3);
            }
        }
    }

    return 0;
}