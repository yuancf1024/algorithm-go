/* 300. 最长递增子序列
给你一个整数数组 nums ，
找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）
数组中的元素而不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

示例 2：
输入：nums = [0,1,0,3,2,3]
输出：4

示例 3：
输入：nums = [7,7,7,7,7,7,7]
输出：1

提示：
1 <= nums.length <= 2500
-104 <= nums[i] <= 10^4

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        
        vector<int> dp(nums.size(), 1);
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if (dp[i] > result)
                result = dp[i]; // 取长的子序列
        }
        return result;
    }
};

/* 参考代码随想录

最长上升子序列是动规的经典题目，这里dp[i]是可以根据dp[j]
（j < i）推导出来的，那么依然用动规五部曲来分析详细一波：

1. dp[i]的定义
dp[i]表示i之前包括i的以nums[i]结尾最长上升子序列的长度

2. 状态转移方程
位置i的最长升序子序列等于j从0到i-1各个位置的最长升序子序列 + 1 的最大值。

所以：if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);

注意这里不是要dp[i] 与 dp[j] + 1进行比较，而是我们要取dp[j] + 1的最大值。

3. dp[i]的初始化
每一个i，对应的dp[i]（即最长上升子序列）起始大小至少都是1.

4. 确定遍历顺序
dp[i] 是有0到i-1各个位置的最长升序子序列 推导而来，
那么遍历i一定是从前向后遍历。

j其实就是0到i-1，遍历i的循环在外层，遍历j则在内层，代码如下：

for (int i = 1; i < nums.size(); i++) {
    for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
    }
    if (dp[i] > result) result = dp[i]; // 取长的子序列
}

5. 举例推导dp数组

本题最关键的是要想到dp[i]由哪些状态可以推出来，
并取最大值，那么很自然就能想到递推公式：
dp[i] = max(dp[i], dp[j] + 1);

子序列问题是动态规划的一个重要系列，
本题算是入门题目，好戏刚刚开始！
*/