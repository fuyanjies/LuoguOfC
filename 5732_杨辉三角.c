/*
题目描述
    给出 n(n≤20)，输出杨辉三角的前 n 行。
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, j, *a, *b, *c;
    a = (int*)calloc(20, sizeof(int));
    b = (int*)calloc(20, sizeof(int));
    a[0] = 1;
    b[0] = 1;
    b[1] = 1;

    scanf("%d", &n);
    if (n==0) {
        return 0;
    } else if (n==1) {
        printf("1\n");
        return 0;
    }

    printf("1\n1 1\n");
    
    for (i=2; i<n; i++) {
        c = b;
        b = a;
        a = c;
        
        b[0] = 1;
        b[i] = 1;
        printf("1 ");
        for (j=1; j<i; j++) {
            b[j] = a[j-1]+a[j];
            printf("%d ", b[j]);
        }
        printf("1\n");
    }

    return 0;
}