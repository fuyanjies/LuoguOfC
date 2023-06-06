/*
题目描述
  某市调查城镇交通状况，得到现有城镇道路统计表。
  表中列出了每条道路直接连通的城镇。
  市政府 "村村通工程" 的目标是使全市任何两个城镇间都
  可以实现交通（但不一定有直接的道路相连，只要相互之间可达即可）。
  请你计算出最少还需要建设多少条道路？

输入格式
  输入包含若干组测试数据，每组测试数据的第一行给出两个用空格隔开的正整数，
  分别是城镇数目 n 和道路数目 m ；随后的 m 行对应 m 条道路，
  每行给出一对用空格隔开的正整数，分别是该条道路直接相连的两个城镇的编号。
  简单起见，城镇从 1 到 n 编号。

  注意：两个城市间可以有多条道路相通。

  在输入数据的最后，为一行一个整数 0，代表测试数据的结尾。

输出格式
  对于每组数据，对应一行一个整数。表示最少还需要建设的道路数目。
*/

#include <stdio.h>

int list[10000];
int n, m, cnt, i, from, to;

int raise(int * list, int idx) {
  if (idx == list[idx]) return idx;
  return (list[idx] = raise(list, list[idx]));
}

int main(void) {
  scanf("%d", &n);
  while (n) {
    scanf("%d", &m);
    cnt = 0;

    for (i = 1; i <= n; ++i) list[i] = i;
    for (i = 0; i < m; ++i) {
      scanf("%d %d", &from, &to);
      if (raise(list, from) != raise(list, to)) {
        list[raise(list, from)] = raise(list, to);
        ++cnt;
      }
    }
    printf("%d\n", n - cnt - 1);
    scanf("%d", &n);
  }

  return 0;
}