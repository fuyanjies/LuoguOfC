/*
题目描述
Bessie loves board games and role-playing games so she persuaded Farmer John to drive her to the hobby shop where she purchased three dice for rolling. These fair dice have S1, S2, and S3 sides

respectively (2 <= S1 <= 20; 2 <= S2 <= 20; 2 <= S3 <= 40).

Bessie rolls and rolls and rolls trying to figure out which three-dice sum appears most often.

Given the number of sides on each of the three dice, determine which three-dice sum appears most frequently. If more than one sum can appear most frequently, report the smallest such sum.

POINTS: 70

输入格式
* Line 1: Three space-separated integers: S1, S2, and S3

输出格式
* Line 1: The smallest integer sum that appears most frequently when the dice are rolled in every possible combination.

题意翻译
贝茜喜欢玩棋盘游戏和角色扮演游戏，所以她说服了约翰开车带她去小商店.
在那里她买了三个骰子。这三个不同的骰子的面数分别为 s_1,s_2,s_3。

对于一个有 SS 个面的骰子每个面上的数字是 1,2,3,…,S。
每个面（上的数字）出现的概率均等。
贝茜希望找出在所有“三个面上的数字的和”中，哪个和的值出现的概率最大。

现在给出每个骰子的面数，需要求出哪个所有“三个面上的数字的和”出现得最频繁。
如果有很多个和出现的概率相同，那么只需要输出最小的那个。

数据范围： 2<=s_1<=20, 2<=s_2<=20, 2<=s_3<=40;
*/

#include <stdio.h>

int nums[81];

int main(void) 
{
    int i, j, k;
    int i_, j_, k_;
    int len, max, ans;

    scanf("%d %d %d", &i_, &j_, &k_);
    len = i_ + j_ + k_;

    for (i=1; i<=i_; i++)
    {
        for (j=1; j<=j_; j++)
        {
            for (k=1; k<=k_; k++)
            {
                nums[i+j+k]++;
            }
        }
    }

    max = nums[3];
    ans = 3;

    for (i=3; i<=len; i++) {
        if (nums[i] > max) {
            max = nums[i];
            ans = i;
        }
    }

    printf("%d\n", ans);

    return 0;
}