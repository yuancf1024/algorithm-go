/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-30
 *
 * @copyright Copyright (c) 2022
 *
 * 篮球转移 25分
 *
 * 现在有一袋子中共有n个篮球，由于袋子损坏，你需要
 * 将这一袋子篮球转移到另一个袋子存放。
 *
 * 假设每次你可以拿1或2个篮球进行转移，请问你有多少种
 * 不同的方法转移完所有篮球？

输入描述：
原袋子中的篮球数量为n，
当n为1时，即袋子中有1个篮球，此时转移篮球的方法数为1:1
当n为2时，即袋子中有2个篮球，此时转移篮球的方法数2：1+1；2
当n为3时，即袋子中有3个篮球，此时转移篮球的方法数为3:1+1+1;1+2;2+1

输出描述：


示例1：
1

1

示例2：
2

2

示例3：
3

3

示例4：
11

144

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    // 核心代码
    // 思路：DP
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    // dp[3] = 3;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << endl;
    return 0;
}