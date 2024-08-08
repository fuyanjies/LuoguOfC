// # 【深基6.例6】文字处理软件
// 
// ## 题目描述
// 
// 你需要开发一款文字处理软件。最开始时输入一个字符串作为初始文档。可以认为文档开头是第 $0$ 个字符。需要支持以下操作：
// 
// - `1 str`：后接插入，在文档后面插入字符串 $\texttt{str}$，并输出文档的字符串；
// - `2 a b`：截取文档部分，只保留文档中从第 $a$ 个字符起 $b$ 个字符，并输出文档的字符串；
// - `3 a str`：插入片段，在文档中第 $a$ 个字符前面插入字符串 $\texttt{str}$，并输出文档的字符串；
// - `4 str`：查找子串，查找字符串 $\texttt{str}$ 在文档中最先的位置并输出；如果找不到输出 $-1$。
// 
// 为了简化问题，规定初始的文档和每次操作中的 $\texttt{str}$ 都不含有空格或换行。最多会有 $q$ 次操作。
// 
// ## 输入格式
// 
// 第一行输入一个正整数 $q$，表示操作次数。
// 
// 第二行输入一个字符串 $\texttt{str}$，表示最开始的字符串。
// 
// 第三行开始，往下 $q$ 行，每行表示一个操作，操作如题目描述所示。

// ## 输出格式
// 
// 一共输出 $q$ 行。
// 
// 对于每个操作 $1,2,3$，根据操作的要求输出一个字符串。
// 
// 对于操作 $4$，根据操作的要求输出一个整数。
// 
// ## 样例 #1
// 
// ### 样例输入 #1
// 
// ```
// 4
// ILove
// 1 Luogu
// 2 5 5
// 3 3 guGugu
// 4 gu
// ```
// 
// ### 样例输出 #1
// 
// ```
// ILoveLuogu
// Luogu
// LuoguGugugu
// 3
// ```
// 
// ## 提示
// 
// 数据保证，$1 \leq q\le 100$，开始的字符串长度 $\leq 100$。

#include <stdio.h>
#include <stdlib.h>

char *data = NULL;
size_t data_size = 0;
size_t data_capacity = 0;

int slen(const char *s)
{
    int i = 0;
    for (; s[i]; ++i);

    return i;
}

void init(void)
{
    data_capacity = 20;
    data = (char *)calloc(data_capacity, sizeof(char));
}

void strech(void)
{
    data_capacity = data_capacity * 2 + data_capacity / 2;
    data = (char *)realloc(data, data_capacity);
}

void append(const char *str)
{
    int str_len = slen(str);

    while (data_size + str_len >= data_capacity) {
        strech();
    }

    sprintf(data+data_size, "%s", str);
    data_size += str_len;
}

void insert(const char *str, int index)
{
    int str_len = slen(str);
    int i;

    while (data_size + str_len >= data_capacity) {
        strech();
    }

    for (i = data_size; i >= index; --i) {
        data[str_len + i] = data[i];
    }

    for (i = 0; str[i]; ++i) {
        data[i + index] = str[i];
    }

    data_size += str_len;
}

void erase(int start, int len)
{
    int i = 0;

    for (; i < len; ++i) {
        data[i] = data[start + i];
    }

    data[len] = '\0';
    data_size = len;
}

void kmp_make_index(char *target, int target_size, int *index)
{
    int i, j;

    i = 1;
    j = 0;

    for (; i < target_size; ++i) {
        if (target[i] == target[j]) {
            index[i] = ++j;
            continue;
        }

        if (0 < j) {
            j = index[j-1];
            --i;
        } else {
            index[i] = j;
        }
    }
}

int kmp_find_first(char *target)
{
    int i = 0, j = 0;
    int len = slen(target);
    int *index = NULL;

    index = (int *)calloc(len, sizeof(int));

    kmp_make_index(target, len, index);

    for (; i < data_size; ++i) {
        if (data[i] == target[j]) {
            ++j;
            if (j == len) {
                free(index);
                return i - j + 1;
            }
            continue;
        }

        if (0 < j) {
            --i;
            j = index[j];
        }
    }

    free(index);
    return -1;
}

int main(void)
{
    int times = 0;
    int command = 0;
    int a, b;
    char *str = (char *)calloc(100000, sizeof(char));

    init();

    scanf("%d ", &times);
    scanf("%s", str);
    append(str);

    while (times--) {
        scanf("%d", &command);

        switch (command) {
        case 1 :
            scanf("%s", str);
            append(str);
            printf("%s\n", data);
            break;
        case 2 :
            scanf("%d%d", &a, &b);
            erase(a, b);
            printf("%s\n", data);
            break;
        case 3 :
            scanf("%d%s", &a, str);
            insert(str, a);
            printf("%s\n", data);
            break;
        case 4 :
            scanf("%s", str);
            printf("%d\n", kmp_find_first(str));
            break;
        default :
            exit(-1);
        }
    }

    free(str);
    return 0;
}