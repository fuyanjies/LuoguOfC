/*
AC

题目背景
    某蒟蒻迷上了 “小书童”，有一天登陆时忘记密码了（他没绑定邮箱 or 手机），
    于是便把问题抛给了神犇你。

题目描述
    蒟蒻虽然忘记密码，但他还记得密码是由一个字符串组成。
    密码是由原文字符串（由不超过 50 个小写字母组成）中每个字母向后移动 n 位
    形成的。z 的下一个字母是 a，如此循环。
    他现在找到了移动前的原文字符串及 n，请你求出密码。

输入格式
    第一行：n。第二行：未移动前的一串字母

输出格式
    一行，是此蒟蒻的密码

For example:
    INPUT:
        1
        qwe
    OUTPUT:
        rxf
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    int n, len, i;
    char in[51], out[51];
    char c;

    scanf("%d %s", &n, in);
    len = strlen(in);
    for (i=0; i<len; i++) {
        c = in[i];
        c = 97+((c-97)+n)%26;
        out[i] = c;
    }
    out[i] = '\0';
    fputs(out, stdout);

    return 0;
}