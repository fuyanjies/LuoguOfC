#include <stdio.h>
#include <stdlib.h>

int n = 0;
int i = 0;
int j = 0;
static char input[10][10] = {{0}};
static char mid[10][10] = {{0}};
static char output[10][10] = {{0}};

int nothing(void)
{
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (input[i][j] != output[i][j]) {
                return -1;
            }
        }
    }

    return 0;
}

int turn_once(void)
{
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (input[i][j] != output[j][n-i-1]) {
                return -1;
            }
        }
    }

    return 0;
}

int turn_double(void)
{
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (input[i][j] != output[n-i-1][n-j-1]) {
                return -1;
            }
        }
    }

    return 0;
}

int turn_third(void)
{
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (input[i][j] != output[j][i]) {
                return -1;
            }
        }
    }

    return 0;
}

void copy(void)
{
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            mid[i][j] = input[i][j];
        }
    }
}

int reflect(void)
{
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            input[i][n-j-1] = mid[i][j];
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (input[i][j] != output[i][j]) {
                return -1;
            }
        }
    }

    return 0;
}

int main(void)
{
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%s", input+i);
    }

    for (i = 0; i < n; ++i) {
        scanf("%s", output+i);
    }

    if (0 == turn_once()) {
        printf("1\n");
        goto end;
    } else if (0 == turn_double()) {
        printf("2\n");
        goto end;
    } else if (0 == turn_third()) {
        printf("3\n");
        goto end;
    }

    copy();

    if (0 == reflect()) {
        printf("4\n");
        goto end;
    } else if (0 == turn_once() || 0 == turn_double() || 0 == turn_third()) {
        printf("5\n");
        goto end;
    }

    if (0 == nothing()) {
        printf("6\n");
        goto end;
    }

    printf("7\n");

end :
    return 0;
}