/*
# 数楼梯

## 题目描述

楼梯有 $N$ 阶，上楼可以一步上一阶，也可以一步上二阶。

编一个程序，计算共有多少种不同的走法。

## 输入格式

一个数字，楼梯数。

## 输出格式

输出走的方式总数。

## 样例 #1

### 样例输入 #1

```
4
```

### 样例输出 #1

```
5
```

## 提示

- 对于 $60\%$ 的数据，$N \leq 50$；   
- 对于 $100\%$ 的数据，$1 \le N \leq 5000$。
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

void bigNumAdd(char *a, int a_size, char *b, int b_size)
{
    int i, flag, s;

    while (a_size <= b_size) {
        a[a_size++] = '0';
    }
    a[a_size] = 0;

    flag = 0;
    for (i = 0; i < a_size; ++i) {
        s = a[i] - '0';
        s += i < b_size ? b[i] - '0' : 0;
        s += flag ? 1 : 0;

        if (10 <= s) {
            a[i] = s - 10 + '0';
            flag = 1;
        } else {
            a[i] = s + '0';
            flag = 0;
        }
    }

    while ('0' == a[a_size-1]) {
        --a_size;
    }
    a[a_size] = 0;
}

int main(void)
{
    int n;
    intptr_t a, b, c;
    a = (intptr_t)malloc(2000 * sizeof(char));
    b = (intptr_t)malloc(2000 * sizeof(char));
    c = (intptr_t)malloc(2000 * sizeof(char));

    sprintf((char *)a, "0");
    sprintf((char *)b, "1");
    scanf("%d", &n);

    while (n--) {
        sprintf((char *)c, (char *)b);
        bigNumAdd((char *)b, strlen((char *)b), (char *)a, strlen((char *)a));
        a ^= c;
        c ^= a;
        a ^= c;
    }

    for (n = strlen((char *)b) - 1; n > 0 && '0' == ((char *)b)[n]; --n);
    for (; n >= 0; --n) {
        putchar(((char *)b)[n]);
    }
    putchar('\n');

    return 0;
}