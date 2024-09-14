/**
# 生日

## 题目描述

cjf 君想调查学校 OI 组每个同学的生日，并按照年龄从大到小的顺序排序。但 cjf 君最近作业很多，没有时间，所以请你帮她排序。

## 输入格式

输入共有 $n + 1$ 行，

第 $1$ 行为 OI 组总人数 $n$；

第 $2$ 行至第 $n+1$ 行分别是每人的姓名 $s$、出生年 $y$、月 $m$、日 $d$。

## 输出格式

输出共有 $n$ 行，

即 $n$ 个生日从大到小同学的姓名。（如果有两个同学生日相同，输入靠后的同学先输出）

## 样例 #1

### 样例输入 #1

```
3
Yangchu 1992 4 23
Qiujingya 1993 10 13
Luowen 1991 8 1
```

### 样例输出 #1

```
Luowen
Yangchu
Qiujingya
```

## 提示

数据保证，$1<n<100$，$1\leq |s|<20$。保证年月日实际存在，且年份 $\in [1960,2020]$。
 */

#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char name[20];
    int32_t year, month, day, p;
} person_t;

int32_t
cmp(const void *a, const void *b)
{
    const person_t *ap = a;
    const person_t *bp = b;

    if (ap->year != bp->year) {
        return ap->year - bp->year;
    } else if (ap->month != bp->month) {
        return ap->month - bp->month;
    } else if (ap->day != bp->day) {
        return ap->day - bp->day;
    } else {
        return bp->p - ap->p;
    }
}

int32_t
main(void)
{
    int32_t n, i;
    person_t *ps;

    ps = NULL;
    scanf("%d", &n);

    ps = calloc(n, sizeof(person_t));

    for (i = 0; i < n; ++i) {
        scanf("%s %d %d %d", ps[i].name, &ps[i].year, &ps[i].month, &ps[i].day);
        ps[i].p = i;
    }

    qsort(ps, n, sizeof(person_t), cmp);

    for (i = 0; i < n; ++i) {
        puts(ps[i].name);
    }

    free(ps);

    return 0;
}