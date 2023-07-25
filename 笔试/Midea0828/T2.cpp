/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 超市内物品数量
     * @param V int整型 小美能拿的物品的价值总和
     * @param ai int整型vector 表示每个物品的价值
     * @return int整型
     */
    int shopping(int n, int V, vector<int>& ai) {
        // write code here
        /*
        思路：经典背包问题 DP
        1. 确定dp[i]数组及下标的含义
        下标i代表所能拿物品的价值总和，
        dp[i]为物品数
        2. 递推公式
        dp[i] = max(dp[i-ai[]])
        3. 初始化
        4. 遍历方向
        5 模拟

        不对，思路应该是贪心
        从最小的价值的物品数开始拿
        */
        // 排序
        sort(ai.begin(), ai.end());
        int res = 0;
        int value = V;
        for (int i = 0; i < n; ++i) {
            if (value - ai[i] >= 0) {
                res++;
                value -= ai[i];
            }
        }
        return res;
    }
};

int main() {
    // TestCase1
    // int n = 3;
    // int  V = 50;
    // vector<int> values = {50, 105,200};
    // 1

    // TestCase2
    int n = 5;
    int  V = 55;
    vector<int> values = {30, 20,20,40,100};
    // 2

    Solution s;
    int res = s.shopping(n, V, values);
    cout << res << endl;
    return 0;
}