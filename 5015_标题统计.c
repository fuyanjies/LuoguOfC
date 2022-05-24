/*
题目描述
    凯凯刚写了一篇美妙的作文，请问这篇作文的标题中有多少个字符？ 
    注意：标题中可能包含大、小写英文字母、数字字符、空格和换行符。
    统计标题字符数时，空格和换行符不计算在内。

输入格式
    输入文件只有一行，一个字符串 s。

输出格式
    输出文件只有一行，包含一个整数，即作文标题的字符数（不含空格和换行符）。

For example:
    1,
    INPUT:
        234
    OUTPUT:
        3
    2,
    INPUT:
        Ca 45
    OUTPUT:
        4
*/

#include <stdio.h>

int main(void) {
    char c;
    int cnt=0;

    c = getchar();
    while (c != '\n') {
        if (c != ' ') cnt++;
        c = getchar();
    }
    printf("%d\n", cnt);

    return 0;
}