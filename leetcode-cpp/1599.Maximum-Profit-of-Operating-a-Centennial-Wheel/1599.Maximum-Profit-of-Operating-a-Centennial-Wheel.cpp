/**
 * @file 1599.Maximum-Profit-of-Operating-a-Centennial-Wheel.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-1599.经营摩天轮的最大利润
 * @version 0.1
 * @date 2024-01-01
 * 
 * @copyright Copyright (c) 2024
 * 你正在经营一座摩天轮，该摩天轮共有 4 个座舱 ，
 * 每个座舱 最多可以容纳 4 位游客 。你可以 逆时针 轮转座舱，
 * 但每次轮转都需要支付一定的运行成本 runningCost 。
 * 摩天轮每次轮转都恰好转动 1 / 4 周。
给你一个长度为 n 的数组 customers ， 
customers[i] 是在第 i 次轮转（下标从 0 开始）之前到达的新游客的数量。
这也意味着你必须在新游客到来前轮转 i 次。
每位游客在登上离地面最近的座舱前都会支付登舱成本 boardingCost ，
一旦该座舱再次抵达地面，他们就会离开座舱结束游玩。

你可以随时停下摩天轮，即便是 在服务所有游客之前 。
如果你决定停止运营摩天轮，为了保证所有游客安全着陆，将免费进行所有后续轮转 。
注意，如果有超过 4 位游客在等摩天轮，那么只有 4 位游客可以登上摩天轮，
其余的需要等待 下一次轮转 。

返回最大化利润所需执行的 最小轮转次数 。 
如果不存在利润为正的方案，则返回 -1 。
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int ans = -1;
        int mx = 0, t = 0;
        int wait = 0, i = 0;
        while (wait || i < customers.size()) {
            wait += i < customers.size() ? customers[i] : 0;
            int up = min(4, wait);
            wait -= up;
            ++i;
            t += up * boardingCost - runningCost;
            if (t > mx) {
                mx = t;
                ans = i;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {8, 3};
    int boardingCost = 5, runningCost = 6;
    int res = Solution().minOperationsMaxProfit(nums, boardingCost, runningCost);
    cout << res << endl;
    return 0;
}

/* 参考大佬@ylb题解
方法一：模拟

我们直接模拟摩天轮的轮转过程，每次轮转时，
累加等待的游客以及新到达的游客，然后最多 4 个人上船，
更新等待的游客数和利润，记录最大利润与其对应的轮转次数。

*/