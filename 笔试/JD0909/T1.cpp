/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-09
 * 
 * @copyright Copyright (c) 2022
 * 
 * 小红的好red串 15分
 * 
 * 小红定义一个字符串为"好串"，当且仅当相邻两个字母不相同。
 * 小红拿到了一个仅由'r','e','d'三种字符组成的字符串，
 * 她有一个魔法：将相邻两个相同的字母同时删除，
 * 并在其位置生成任意一个字母('r','e','d'三种中的一种)。
 * 例如：对于字符串"dedd",小红可以选择中间两个相邻
 * 字母"dd",将其变成'r',此时字符串变为"der".
 * 小红希望将给定的字符串变成"好串"，她想知道自己
 * 最少需要多少次操作？
 * 
 * 输入描述：
 * 一个长度不超过200000的、仅由'r','e','d'
 * 三种字符组成的字符串。
 * 输出描述：
 * 一个整数，代表操作的最小次数。

示例1：
rrdd

2

示例2：
rede

0

示例3：
rreedd

3
 */

#include <bits/stdc++.h>

using namespace std;

bool isSame(string& str) {
    bool flag = false;
    for (int i = 0; i < str.size() - 1; ++i) {
        if (str[i] == str[i+1]) {
            flag = true;
        }
    }
    return flag;
}

int main() {
    string str;
    cin >> str;

    // 核心代码
    queue<char> queue;
    queue.push(str[0]);

    for (int i = 1; i < str.size(); ++i) {
        if (queue.front() == str[i]) {
            queue.pop();
            // 怎么在字符串末尾添加不同的字符r e d呢？

        }
    } 
    return 0;
}