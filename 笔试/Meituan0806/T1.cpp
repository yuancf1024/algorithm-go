/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-06
 *
 * @copyright Copyright (c) 2022
 *
第一题 分礼盒
题目：
小美做饼干，有AB两种，做成礼盒卖，每个礼盒三个饼干，
且至少包含一个A 和 一个B。现在给你A和B的数量，问最多可以做多少礼盒？

思路：
分析了一下，礼盒的数量为（A，B，（A+B）/3）三者的最小值。

- 简单的贪心 即可得到短板
- min({(a+b)/3, a ,b})即可

可以这样思考：假设能做x盒，那么x <= A, x <= B 且 3x <= A + B
所以x = min({a, b, (a+b)/3});

Case1:
Input:
2
3 3
4 10
Output:
2
4

方法1：使用数组，while循环处理，每输入一组数据，立刻输出该组数据结果；
方法2：使用vector，先将输入数据全部存起来，然后逐行处理，输出全部结果
 */

#include <bits/stdc++.h>

using namespace std;

// 方法1：使用数组
int main() {
    int T; // 记录测试case数量
    cin >> T;
    int x, y; // 定义饼干A B数量
    while (T--) {
        cin >> x >> y;
        int ans = min({(x + y) / 3, x, y});
        cout << ans << endl;
    }
    return 0;
}

/*
2
3 3
4 102

4
*/

// // 方法2：使用vector的解法
// void solve(int x, int y) {
//     cout << min({x, y, (x + y) / 3}) << endl;
// }

// int main() { int T;
//     cin >> T;
//     vector<vector<int>> nums(T, vector<int>(2, 0));
//     for (int i = 0; i < T; ++i) {
//         cin >> nums[i][0];
//         cin >> nums[i][1];
//     }

//     for (int i = 0; i < T; ++i) {
//         solve(nums[i][0], nums[i][1]);
//     }
//     return 0;
// }
/* Output:
2
3 3
4 10
2
4
*/