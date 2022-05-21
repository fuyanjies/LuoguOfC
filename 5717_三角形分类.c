/*
题目描述
    给出三条线段 a,b,c 的长度，均是不大于 10000 的整数。
    打算把这三条线段拼成一个三角形，它可以是什么三角形呢？

    如果三条线段不能组成一个三角形，输出Not triangle；
    如果是直角三角形，输出Right triangle；
    如果是锐角三角形，输出Acute triangle；
    如果是钝角三角形，输出Obtuse triangle；
    如果是等腰三角形，输出Isosceles triangle；
    如果是等边三角形，输出Equilateral triangle。
    如果这个三角形符合以上多个条件，请按以上顺序分别输出，并用换行符隔开。

tips:
    当两短边的平方和大于一长边的平方，说明是锐角三角形。

    当两短边的平方和等于一长边的平方，说明是直角三角形。

    当两短边的平方和小于一长边的平方，说明是钝角三角形。
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main(void) {
    int a, b, c, edges[3];

    scanf("%d %d %d", &edges[0], &edges[1], &edges[2]);

    qsort(edges, 3, sizeof(int), cmp);

    a = edges[0] * edges[0];
    b = edges[1] * edges[1];
    c = edges[2] * edges[2];

    if (edges[0]+edges[1]<=edges[2]) {
        puts("Not triangle");
    } else {
        if (a+b==c) {
            puts("Right triangle");
        } else if (a+b>c) {
            puts("Acute triangle");
        } else if (a+b<c) {
            puts("Obtuse triangle");
        }
        if (a==b || a==c || b==c) {
            puts("Isosceles triangle");
        }
        if (a==b && a==c) {
            puts("Equilateral triangle");
        }
    }

    return 0;
}