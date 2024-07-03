/**
 * @file 3099.Harshad-Number.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-3099.哈沙德数 模拟
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 如果一个整数能够被其各个数位上的数字之和整除，
 * 则称之为 哈沙德数（Harshad number）。
 * 给你一个整数 x 。如果 x 是 哈沙德数 ，
 * 则返回 x 各个数位上的数字之和，否则，返回 -1 。

示例 1：
输入： x = 18
输出： 9

解释：
x 各个数位上的数字之和为 9 。18 能被 9 整除。
因此 18 是哈沙德数，答案是 9 。

示例 2：
输入： x = 23
输出： -1

解释：

x 各个数位上的数字之和为 5 。23 不能被 5 整除。
因此 23 不是哈沙德数，答案是 -1 。

提示：

1 <= x <= 100
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int res = -1;
        int sum = 0;
        int t = x;
        // 计算各个数位之和
        while (t > 0) {
            sum += t % 10;
            t /= 10;
        }
        // 判断是否是哈沙德数
        if (x % sum == 0) {
            res = sum;
        }
        return res;
    }
};

int main() {
    int x = 23;
    int res = Solution().sumOfTheDigitsOfHarshadNumber(x);

    cout << res << endl;
    return 0;

}