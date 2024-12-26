/*
# 小果的键盘

## 题目背景

小果有一个只有两个键的键盘。

## 题目描述

一天，她打出了一个只有这两个字符的字符串。当这个字符串里含有 `VK` 这个字符串的时候，小果就特别喜欢这个字符串。所以，她想改变至多一个字符（或者不做任何改变）来最大化这个字符串内 `VK` 出现的次数。给出原来的字符串，请计算她最多能使这个字符串内出现多少次 `VK`（只有当 `V` 和 `K` 正好相邻时，我们认为出现了 `VK`。）

## 输入格式

第一行给出一个数字 $n$，代表字符串的长度。

第二行给出一个字符串 $s$。

## 输出格式

第一行输出一个整数代表所求答案。

## 样例 #1

### 样例输入 #1

```
2
VK
```

### 样例输出 #1

```
1
```

## 样例 #2

### 样例输入 #2

```
2
VV
```

### 样例输出 #2

```
1
```

## 样例 #3

### 样例输入 #3

```
1
V
```

### 样例输出 #3

```
0
```

## 样例 #4

### 样例输入 #4

```
20
VKKKKKKKKKVVVVVVVVVK
```

### 样例输出 #4

```
3
```

## 样例 #5

### 样例输入 #5

```
4
KVKV
```

### 样例输出 #5

```
1
```

## 提示

对于 $100\%$ 的数据，$1\le n\le 100$。
*/

#include <iostream>
#include <string>

int main(void)
{
    std::ios::sync_with_stdio(false);

    int size, res{0};
    bool flag{false};
    std::string s;

    std::cin >> size >> s;

    for (int i = 0; i < size; ++i)
    {
        if ('V' == s[i])
        {
            if (i+1 >= size)
            {
                continue;
            }

            if ('K' == s[i+1])
            {
                ++res;
                ++i;
                continue;
            }

            if (i+2 >= size || 'V' == s[i+2])
            {
                ++i;
                flag = true;
                continue;
            }
        }

        if (i+1 >= size || 'V' == s[i+1])
        {
            continue;
        }

        ++i;
        flag = true;
    }

    if (flag)
    {
        ++res;
    }

    std::cout << res << '\n';

    return 0;
}