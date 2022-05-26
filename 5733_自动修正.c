/*
题目描述
    大家都知道一些办公软件有自动将字母转换为大写的功能。
    输入一个长度不超过 100 且不包括空格的字符串。
    要求将该字符串中的所有小写字母变成大写字母并输出。
*/

#include <stdio.h>

int main(void) {
    char c=1;
    while (c!='\n') {
        c = getchar();
        if (97<=c && c<=122)
            putchar(c-32);
        else
            putchar(c);
    }
    putchar('\n');

    return 0;
}