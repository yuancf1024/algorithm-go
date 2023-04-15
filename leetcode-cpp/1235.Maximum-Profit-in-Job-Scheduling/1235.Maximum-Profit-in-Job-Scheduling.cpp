/**
 * @file 1235.Maximum-Profit-in-Job-Scheduling.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-23
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1235.规划兼职工作
 * 
 * 你打算利用空闲时间来做兼职工作赚些零花钱。

这里有 n 份兼职工作，每份工作预计从startTime[i]开始到 endTime[i] 结束，
报酬为 profit[i]。

给你一份兼职工作表，包含开始时间 startTime，结束时间 endTime 
和预计报酬 profit 三个数组，请你计算并返回可以获得的最大报酬。

注意，时间上出现重叠的 2 份工作不能同时进行。

如果你选择的工作在时间 X 结束，那么你可以立刻进行在时间 X 开始的下一份工作。

示例 1：

输入：startTime = [1,2,3,3], endTime = [3,4,5,6], 
profit = [50,10,40,70]
输出：120

解释：
我们选出第 1 份和第 4 份工作， 
时间范围是 [1-3]+[3-6]，共获得报酬 120 = 50 + 70。

示例 2：

输入：startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
输出：150

解释：
我们选择第 1，4，5 份工作。 
共获得报酬 150 = 20 + 70 + 60。

示例 3：

输入：startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
输出：6
 
提示：

1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
1 <= startTime[i] < endTime[i] <= 10^9
1 <= profit[i] <= 10^4

 */

#include <bits/stdc++.h>

using namespace std;

// leetcode官方题解 动态规划 + 二分查找
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        // 对区间按照开始时间从小到大排序
        sort(jobs.begin(), jobs.end(),
             [](const vector<int>& job1, const vector<int>& job2) -> bool {
                 return job1[1] < job2[1];
             });

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int k =
                upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0],
                            [&](int st, const vector<int>& job) -> bool {
                                return st < job[1];
                            }) - jobs.begin();
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};

// 简化版
class Solution1 {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        // 对区间按照开始时间从小到大排序
        sort(jobs.begin(), jobs.end(),
             [](const vector<int>& job1, const vector<int>& job2) -> bool {
                 return job1[1] < job2[1];
             });
        // 对每个工作的结束时间，按照从小到大排序
        sort(endTime.begin(), endTime.end());

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            // 找到结束时间小于等于第i−1份工作开始时间的兼职工作数量
            int k = upper_bound(endTime.begin(), endTime.begin() + i - 1, jobs[i - 1][0]) - endTime.begin();
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};

/**
 * @brief 
 * 方法一：动态规划 + 二分查找
我们首先将兼职工作按结束时间endTime 从小到大进行排序。
使用dp[i]表示前i份兼职工作可以获得的最大报酬，
初始时dp[0]=0，那么对于i>0，我们有以下转移方程：

dp[i] = max(dp[i−1], dp[k] + profit[i−1])

其中k表示满足结束时间小于等于第i−1份工作开始时间的兼职工作数量，
可以通过二分查找获得。

复杂度分析
时间复杂度：O(nlogn)，其中n是兼职工作的数量。
排序需要O(nlogn)，遍历+二分查找需要O(nlogn)，
因此总时间复杂度为O(nlogn)。

空间复杂度：O(n)。需要O(n)的空间来保存dp。

 */