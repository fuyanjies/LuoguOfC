/*
题目背景
  A地区在地震过后，连接所有村庄的公路都造成了损坏而无法通车。
  政府派人修复这些公路。

题目描述
  给出A地区的村庄数N，和公路数M，公路是双向的。
  并告诉你每条公路的连着哪两个村庄，
  并告诉你什么时候能修完这条公路。问最早什么时候任意两个村庄能够通车，
  即最早什么时候任意两条村庄都存在至少一条修复
  完成的道路（可以由多条公路连成一条道路）

输入格式
  第1行两个正整数N,M

  下面M行，每行3个正整数x, y, t，
  告诉你这条公路连着x,y两个村庄，在时间t时能修复完成这条公路。

输出格式
  如果全部公路修复完毕仍然存在两个村庄无法通车，则输出−1，
  否则输出最早什么时候任意两个村庄能够通车。

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int from, to, time;
} Item;

int raise(int * list, int idx) {
  if (idx == list[idx]) return idx;
  return (list[idx] = raise(list, list[idx]));
}

int cmp(const void * a, const void * b) {
  return ((Item *)a)->time - ((Item *)b)->time;
}

int main() {
  int n, m, list[10000], ans = -1, cnt = 0, i, flag = 0;
  scanf("%d %d", &n, &m);
  Item load[m];

  for (i = 1; i <= n; ++i) list[i] = i;
  for (i = 0; i < m; ++i)
    scanf("%d %d %d", &load[i].from, &load[i].to, &load[i].time);
  qsort(load, m, sizeof(Item), cmp);

  for (i = 0; i < m; ++i) {
    if (raise(list, load[i].from) != raise(list, load[i].to)) {
      list[raise(list, load[i].from)] = raise(list, load[i].to);
      ++cnt;
    }
    if (cnt == n-1) {
      ans = load[i].time;
      flag = 1;
      break;
    }
  }

  printf("%d\n", ans);

  return 0;
}