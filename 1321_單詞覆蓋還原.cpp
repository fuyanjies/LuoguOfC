/*
# 单词覆盖还原

## 题目描述

我有一个长度为 $l$ 的字符串，最开始时，这个字符串由 $l$ 个句号（`.`）组成。

我在这个字符串中，将多次把 `boy` 或者 `girl` 两单词，依次贴到这个字符串中。

后贴上单词，会覆盖之前贴上的单词，或者覆盖句号。最终，每个单词至少有一个字符没有被覆盖。

请问，一共贴有几个 `boy` 几个 `girl`？

## 输入格式

一行被反复贴有 `boy` 和 `girl` 两单词的字符串。

## 输出格式

两行，两个整数。第一行为 `boy` 的个数，第二行为 `girl` 的个数。

## 样例 #1

### 样例输入 #1

```
......boyogirlyy......girl.......
```

### 样例输出 #1

```
4
2
```

## 提示

数据保证，$3\le l\le255$，字符串仅仅包含如下字符：$\texttt{.bgilory}$。
 */

#include <iostream>
#include <string>

int main(void)
{
    std::ios::sync_with_stdio(false);

    int boy{0}, girl{0};
    std::string s;

    std::cin >> s;

    for (int i = 0, size = s.size(); i < size; ++i)
    {
        if ('b' == s[i])
        {
            ++boy;

            if (i+1 >= size || 'o' != s[i+1])
            {
                continue;
            }
            ++i;

            if (i+1 >= size || 'y' != s[i+1])
            {
                continue;
            }
            ++i;
        }
        else if ('o' == s[i])
        {
            ++boy;

            if (i+1 >= size || 'y' != s[i+1])
            {
                continue;
            }
            ++i;
        }
        else if ('y' == s[i])
        {
            ++boy;
        }
        else if ('g' == s[i])
        {
            ++girl;

            if (i+1 >= size || 'i' != s[i+1])
            {
                continue;
            }
            ++i;

            if (i+1 >= size || 'r' != s[i+1])
            {
                continue;
            }
            ++i;

            if (i+1 >= size || 'l' != s[i+1])
            {
                continue;
            }
            ++i;
        }
        else if ('i' == s[i])
        {
            ++girl;

            if (i+1 >= size || 'r' != s[i+1])
            {
                continue;
            }
            ++i;

            if (i+1 >= size || 'l' != s[i+1])
            {
                continue;
            }
            ++i;
        }
        else if ('r' == s[i])
        {
            ++girl;
            
            if (i+1 >= size || 'l' != s[i+1])
            {
                continue;
            }
            ++i;
        }
        else if ('l' == s[i])
        {
            ++girl;
        }
    }

    std::cout << boy << '\n' << girl << '\n';

    return 0;
}