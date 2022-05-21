#include <stdio.h>

int main(void)
{
    int k, i=2;
    double s=1;

    scanf("%d", &k);

    while (s<=k)
    {
        s += (double)(1/(i++));
    }

    printf("%d\n", --i);

    return 0;
}