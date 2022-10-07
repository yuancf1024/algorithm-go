/**
 * @file 1800.Maximum-Ascending-Subarray-Sum.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1800.最大升序子数组和
 * 
 * 给你一个正整数组成的数组 nums ，
 * 返回 nums 中一个 升序 子数组的最大可能元素和。

子数组是数组中的一个连续数字序列。

已知子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
若对所有 i（l <= i < r），numsi < numsi+1 都成立，
则称这一子数组为 升序 子数组。
注意，大小为 1 的子数组也视作 升序 子数组。

示例 1：

输入：nums = [10,20,30,5,10,50]
输出：65
解释：[5,10,50] 是元素和最大的升序子数组，最大元素和为 65 。
示例 2：

输入：nums = [10,20,30,40,50]
输出：150
解释：[10,20,30,40,50] 是元素和最大的升序子数组，最大元素和为 150 。 
示例 3：

输入：nums = [12,17,15,13,10,11,12]
输出：33
解释：[10,11,12] 是元素和最大的升序子数组，最大元素和为 33 。 
示例 4：

输入：nums = [100,10,1]
输出：100
 

提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100

 */
#include <bits/stdc++.h>

using namespace std;

// 参考leetcode官方题解 DP
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) { 
        int res = 0;
        int l = 0;
        while (l < nums.size()) {
            int cursum = nums[l++];
            while (l < nums.size() && nums[l] > nums[l-1]) {
                cursum += nums[l++];
            }
            res = max(res, cursum);
        }
        return res;
    }
};

/*
方法一：动态规划
思路与算法

题目给定了一个长度为n的正整数数组nums，
现在要求一个升序的子数组最大可能的元素和。
那么我们设 dp[i] 表示以 nums[i] 结尾的的最长升序子数组的元素和。
那么我们考虑如何求解每一个状态：

当nums[i]>nums[i−1] 时：dp[i]=dp[i−1]+nums[i]

当nums[i]≤nums[i−1] 时：dp[i]=nums[i]

以上的讨论是建立在i>0 的情况，我们还需要考虑动态规划的边界条件，
即i=0 的情况：此时nums[0] 前面没有元素，本身可以构成一个长度为1 的子数组，
即dp[0]=nums[0]。

又因为求解状态的过程只和前一个状态有关，
所以可以用「滚动数组」的方法来进行空间优化。


复杂度分析
时间复杂度：O(n)，其中 n 为数组 nums 的长度。
空间复杂度：O(1)，仅使用常量空间。
*/