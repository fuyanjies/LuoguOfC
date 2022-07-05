/*
题目描述
    一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，
    有的还能统计出特定单词在文章中出现的次数。

    现在，请你编程实现这一功能，具体要求是：给定一个单词，
    请你输出它在给定的文章中出现的次数和第一次出现的位置。注意：
    匹配单词时，不区分大小写，但要求完全匹配，
    即给定单词必须与文章中的某一独立单词在不区分大小写的情况下完全相同，
    如果给定单词仅是文章中某一单词的一部分则不算匹配。

输入格式
    共2行。

    第1行为一个字符串，其中只含字母，表示给定单词；

    第2行为一个字符串，其中只可能包含字母和空格，表示给定的文章。

输出格式
    一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，
    分别是单词在文章中出现的次数和第一次出现的位置
    （即在文章中第一次出现时，单词首字母在文章中的位置，位置从0 开始）；如果单词在文章中没有出现，
    则直接输出一个整数-1。
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXFTL 11
#define MAXSTL 1000002

char * s_gets(char *, int);

int main(void) {
    char target[MAXFTL];
    char word[MAXFTL];
    char sec[MAXSTL];
    int i, j, max, len;
    int begin = -1, count = 0;

    scanf("%s", target);
    while (getchar() != '\n') continue;
    for (max=0; target[max] != '\0'; max++)
        target[max] = tolower(target[max]);
    max++;
    s_gets(sec, MAXSTL);
    len = strlen(sec);

    for (j=0; j<len; j++) {
        sec[j] = tolower(sec[j]);
        word[i++] = sec[j];
        if (sec[j] == ' ') {
            word[--i] = '\0';
            i = 0;
            if (strcmp(target, word) == 0) {
                if (begin == -1)
                    begin = j-max+1;
                count++;
            }
        }
        if (i >= max) {
            i = 0;
            while (sec[j] != ' ') j++;
        }
    }
    word[i] = '\0';
    if (strcmp(target, word) == 0) {
        if (begin == -1)
            begin = j-max;
        count++;
    }

    if (begin == -1) 
        printf("-1\n");
    else
        printf("%d %d\n", count, begin);

    return 0;
}

char * s_gets(char * st, int max) {
    char * ret;
    char * find;

    ret = fgets(st, max, stdin);
    if (ret) {
        find = strchr(st, '\n');
        if (find) {
            *find = '\0';
        }
    }

    return ret;
}