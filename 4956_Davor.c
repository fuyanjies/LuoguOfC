/*
题目描述
After successfully conquering the South Pole, 
Davor is preparing for new challenges. Next up is the Arctic 
expedition to Siberia, Greenland and Norway. He begins his travels 
on 31 December 2018, and needs 
to collect ​N kunas (Croatian currency) by then. 
In order to do this, he has decided to put away ​X (​X ≤ 100) kunas 
every Monday to his travel fund, ​X + K kunas every Tuesday,
​X + 2* ​K every Wednesday, and so on until Sunday, 
when he will put away ​X + 6* ​K kunas. This way, 
he will collect money for 52 weeks, 
starting with 1 January 2018 (Monday) until 30 December 2018 (Sunday).

If we know the amount of money ​N​, 
output the values ​X and ​K so that it is possible 
to collect the ​exact money amount in the given timespan. 
The solution will always exist, and if there are multiple,
output the one with the greatest ​X ​ and smallest ​K ​.

输入格式
The first line of input contains the integer ​N​ (1456 ≤ ​N​ ≤ 145600),
the number from the task.

输出格式
The first line of output must contain the value of ​X (​0 < ​X ​≤ 100 ​)​,
and the second the value of K (K ​> 0 ​)​.

题意翻译
    在征服南极之后，Davor 开始了一项新的挑战。
    下一步是在西伯利亚、格林兰、挪威的北极圈远征。
    他将在 2018 年 12 月 31 日开始出发，在这之前需要一共筹集 n 元钱。
    他打算在每个星期一筹集 x 元，星期二筹集 x+k 元，…，
    星期日筹集 x+6k 元，并连续筹集 52 个星期。其中 x,k 为正整数，
    并且满足 1≤x≤100。

    现在请你帮忙计算 x,k 为多少时，能刚好筹集 n 元。

    如果有多个答案，输出 x 尽可能大，k 尽可能小的。注意 k 必须大于 0。
*/

#include <stdio.h>

int main(void) {
    int N, k=0;

    scanf("%d", &N);
    N /= 52;
    while (++k) {
        if ((N-21*k)%7 == 0 && (N-21*k)/7 <= 100)
            break;
    }
    printf("%d\n%d\n", (N-21*k)/7, k);

    return 0;
}