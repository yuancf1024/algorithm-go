/**
 * @file 2520.Count-the-Digits-That-Divide-a-Number.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-2520.统计能整除数字的位数
 * @version 0.1
 * @date 2023-10-26
 * 
 * @copyright Copyright (c) 2023
 * 给你一个整数 num ，返回 num 中能整除 num 的数位的数目。

如果满足 nums % val == 0 ，则认为整数 val 可以整除 nums 。

 

示例 1：

输入：num = 7
输出：1
解释：7 被自己整除，因此答案是 1 。
示例 2：

输入：num = 121
输出：2
解释：121 可以被 1 整除，但无法被 2 整除。由于 1 出现两次，所以返回 2 。
示例 3：

输入：num = 1248
输出：4
解释：1248 可以被它每一位上的数字整除，因此答案是 4 。
 

提示：

1 <= num <= 109
num 的数位中不含 0
 */
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    // 自己实现
    int countDigits(int num) {
        int ans = 0;
        vector<int> res;
        int t = num;
        while (t > 0) {
            int temp = t % 10;
            res.push_back(temp);
            t /= 10;
        }

        for (auto x : res) {
            if (num % x == 0) {
                ans++;
            }
        }
        return ans;
    }
    // 参考官方leetcode题解
    int countDigits_v2(int num) {
        int t = num, res = 0;
        while (t) {
            if (num % (t % 10) == 0) {
                res++;
            }
            t /= 10;
        }
        return res;
    }
};

int main() {
    int num = 1248;

    int res = Solution().countDigits_v2(num);
    cout << res << endl;
    return 0;
}

/**
 * @brief 自己的思路
 * 先循环保存num每个数位，然后for遍历判断能否整除。
 * 
 * leetcode官方题解
 * 方法一：模拟
思路

根据题目要求，从低位到高位，依次判断除 nums
的余数是否为 0。统计所有余数为 0 的次数后返回。

复杂度分析

时间复杂度：O(log⁡nums)，nums 的位数为 O(log⁡nums)。

空间复杂度：O(1)。

 */