/**
 * @file 53.Maximum-Subarray.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * leetcode-53.最大子数组和
 * 
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组
（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

示例 2：
输入：nums = [1]
输出：1

示例 3：
输入：nums = [5,4,-1,7,8]
输出：23
 
提示：
1 <= nums.length <= 105
-104 <= nums[i] <= 104
 
进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。

 */

// 参考代码随想录 DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
            if (dp[i] > res) {
                res = dp[i]; // 保存dp[i]的最大值
            }
        }
        return res;
    }
};

// 贪心
class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        int res = INT_MIN;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i];
            if (count > res) { // 取区间累计的最大值(相当于不断确定最大子序终止位置)
                res = count;
            }
            if (count <= 0) {
                count = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
            }
        }
        return res;
    }
};

// 2022-08-19
/*
思路：DP
1. 确定下标i及dp[i]的含义
i代表nums中第i个元素的序号，dp[i]代表以nums[i]结尾的最大子序和
题目所求为dp[nums.size()-1]

2. 确定递推公式
dp[i] = max(dp[i-1] + nums[i], nums[i])

3. 初始化
dp[0] = nums[0]

4. 遍历顺序
从前往后

5. 举例推导

分治 不太好思考
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) { // 考虑特殊case
            return nums[0];
        }
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxS = dp[0]; // 就是dp[0]
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]); 
            if (dp[i] > maxS) {
                maxS = dp[i];
            }
        }
        return maxS;
    }
};

/**
 * @brief 
 * 思路
 * 
这道题之前我们在讲解贪心专题的时候用贪心算法解决过一次，
贪心算法：最大子序和。

这次我们用动态规划的思路再来分析一次。

动规五部曲如下：

1. 确定dp数组（dp table）以及下标的含义
dp[i]：包括下标i之前的最大连续子序列和为dp[i]。

2. 确定递推公式
dp[i]只有两个方向可以推出来：
- dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
- nums[i]，即：从头开始计算当前连续子序列和

一定是取最大的，所以dp[i] = max(dp[i - 1] + nums[i], nums[i]);

3. dp数组如何初始化
从递推公式可以看出来dp[i]是依赖于dp[i - 1]的状态，
dp[0]就是递推公式的基础。

dp[0]应该是多少呢?
根据dp[i]的定义，很明显dp[0]应为nums[0]
即dp[0] = nums[0]。

4. 确定遍历顺序
递推公式中dp[i]依赖于dp[i - 1]的状态，需要从前向后遍历。

5. 举例推导dp数组
以示例一为例，输入：nums = [-2,1,-3,4,-1,2,1,-5,4]，
对应的dp状态如下： 

注意最后的结果可不是dp[nums.size() - 1]！ ，而是dp[6]。

在回顾一下dp[i]的定义：包括下标i之前的最大连续子序列和为dp[i]。

那么我们要找最大的连续子序列，就应该找每一个i为终点的连续最大子序列。

所以在递推公式的时候，可以直接选出最大的dp[i]。

以上动规五部曲分析完毕，完整代码如下：

时间复杂度：O(n)
空间复杂度：O(n)


贪心解法

贪心贪的是哪里呢？

如果 -2 1 在一起，计算起点的时候，一定是从1开始计算，
因为负数只会拉低总和，这就是贪心贪的地方！

局部最优：当前“连续和”为负数的时候立刻放弃，从下一个元素重新计算“连续和”，
因为负数加上下一个元素 “连续和”只会越来越小。

全局最优：选取最大“连续和”

**局部最优的情况下，并记录最大的“连续和”，可以推出全局最优。**

从代码角度上来讲：遍历nums，从头开始用count累积，
如果count一旦加上nums[i]变为负数，
那么就应该从nums[i+1]开始从0累积count了，因为已经变为负数的count，只会拖累总和。

这相当于是暴力解法中的不断调整最大子序和区间的起始位置。

那有同学问了，区间终止位置不用调整么？ 如何才能得到最大“连续和”呢？

区间的终止位置，其实就是如果count取到最大值了，及时记录下来了。
例如如下代码：

if (count > result) result = count;
这样相当于是用result记录最大子序和区间和（变相的算是调整了终止位置）。

红色的起始位置就是贪心每次取count为正数的时候，开始一个区间的统计。


时间复杂度：O(n)
空间复杂度：O(1)

当然题目没有说如果数组为空，应该返回什么，
所以数组为空的话返回啥都可以了。

不少同学认为 如果输入用例都是-1，或者 都是负数，
这个贪心算法跑出来的结果是0， 这是又一次证明脑洞模拟不靠谱的经典案例，
建议大家把代码运行一下试一试，就知道了，
也会理解 为什么 result 要初始化为最小负数了。
 */