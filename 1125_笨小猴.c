/*
题目描述
    笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。
    但是他找到了一种方法，经试验证明，
    用这种方法去选择选项的时候选对的几率非常大！

    这种方法的具体描述如下：
    假设maxn是单词中出现次数最多的字母的出现次数，
    minn是单词中出现次数最少的字母的出现次数，如果maxn-minn是一个质数，
    那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。

输入格式
    一个单词，其中只可能出现小写字母，并且长度小于100。

输出格式
    共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，
    那么输出“Lucky Word”，否则输出“No Answer”；

    第二行是一个整数，如果输入单词是Lucky Word，
    输出maxn-minn的值，否则输出00。
*/

#include <stdio.h>

#define MAX(x, y) (x>y?x:y)

int asc[256];
int Primer[101] = {1, 1};

void primer(void)
{
    for (int i=2; i<101; i++)
    {
        if (Primer[i])
            continue;
        for (int j=i*2; j<101; j+=i)
            Primer[j] = 1;
    }
}

int main(void)
{
    char in[101];
    char c = -1;
    int max=-1, min=100;

    scanf("%s", in);

    for (int i=0; in[i] != '\0'; i++)
    {
        asc[in[i]]++;
        max = MAX(max, asc[in[i]]);
        
        if (in[i] == c)
            min++;
        if (asc[in[i]] < min)
        {
            min = asc[in[i]];
            c = in[i];
        }
    }

    if (!Primer[max-min])
        printf("Lucky Word\n%d\n", max-min);
    else
        printf("No Answer\n0\n");

    return 0;
}