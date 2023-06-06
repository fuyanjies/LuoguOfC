/*
题目背景
  小明在 A 公司工作，小红在 B 公司工作。

题目描述
  这两个公司的员工有一个特点：一个公司的员工都是同性。

  A 公司有 N 名员工，其中有 P 对朋友关系。
  B 公司有 M 名员工，其中有 Q 对朋友关系。
  朋友的朋友一定还是朋友。

  每对朋友关系用两个整数 (X_i,Y_i) 组成，
  表示朋友的编号分别为 X_i,Y_i。男人的编号是正数，女人的编号是负数。
  小明的编号是 1，小红的编号是 −1。

  大家都知道，小明和小红是朋友，那么，请你写一个程序求出两公司之间，
  通过小明和小红认识的人最多一共能配成多少对情侣（包括他们自己）。

输入格式
  输入的第一行，包含 44 个空格隔开的正整数 N,M,P,Q。

  之后 P 行，每行两个正整数 X_i,Y_i。

  之后 Q 行，每行两个负整数 X_i,Y_i。

输出格式
  输出一行一个正整数，表示通过小明和小红认识的人最多一共能配成多少对情侣（包括他们自己）。
*/

#include <stdio.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int raise(int * list, int idx) {
  if (idx == list[idx]) return idx;

  return (list[idx] = raise(list, list[idx]));
}

int count(int * list, int size) {
  int i, tmp = raise(list, 1);
  int cnt = 1;

  for (i = 2; i <= size; ++i)
    cnt += tmp == raise(list, i);

  return cnt;
}

int main() {
  int list1[10001], list2[10001];
  int n, m, p, q;
  int i, x, y;

  scanf("%d %d %d %d", &n, &m, &p, &q);
  x = MAX(n, m);
  for (i = 1; i <= x; ++i)
    list1[i] = (list2[i] = i);
  
  for (i = 0; i < p; ++i) {
    scanf("%d %d", &x, &y);
    list1[raise(list1, x)] = raise(list1, y);
  }
  for (i = 0; i < q; ++i) {
    scanf("%d %d", &x, &y);
    list2[raise(list2, -x)] = raise(list2, -y);
  }

  printf("%d\n", MIN(count(list1, n), count(list2, m)));

  return 0;
}