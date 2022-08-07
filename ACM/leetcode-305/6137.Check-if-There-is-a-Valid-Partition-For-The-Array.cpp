/**
 * @file 6137.Check-if-There-is-a-Valid-Partition-For-The-Array.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * leetcode-6137. 检查数组是否存在有效划分
 * 
给你一个下标从 0 开始的整数数组 nums ，
你必须将数组划分为一个或多个 连续 子数组。

如果获得的这些子数组中每个都能满足下述条件 之一 ，
则可以称其为数组的一种 有效 划分：

- 子数组 恰 由 2 个相等元素组成，例如，子数组 [2,2] 。
- 子数组 恰 由 3 个相等元素组成，例如，子数组 [4,4,4] 。
- 子数组 恰 由 3 个连续递增元素组成，并且相邻元素之间的差值为 1 。
例如，子数组 [3,4,5] ，但是子数组 [1,3,5] 不符合要求。

如果数组 至少 存在一种有效划分，返回 true ，否则，返回 false 。

示例 1：
输入：nums = [4,4,4,5,6]
输出：true
解释：数组可以划分成子数组 [4,4] 和 [4,5,6] 。
这是一种有效划分，所以返回 true 。

示例 2：
输入：nums = [1,1,1,2]
输出：false
解释：该数组不存在有效划分。
 
提示：

2 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
 */

// 线性 DP 参考 @灵茶山艾府
class Solution {
public:
    bool validPartition(vector<int>& nums) { 
        int n = nums.size();
        bool f[n + 1];
        memset(f, 0, sizeof(f));
        f[0] = true;
        for (int i = 1; i < n; ++i) {
            if (f[i-1] && nums[i] == nums[i-1] ||
            i > 1 && f[i-2] && (nums[i] == nums[i-1] && nums[i] == nums[i-2] ||
            nums[i] == nums[i-1] + 1 && nums[i] == nums[i-2] + 2)) {
                f[i + 1] = true;
            }
        }
        return f[n];
    }
};

/**
 * @brief 参考 @灵茶山艾府
 * 线性 DP
定义 f[i+1] 表示从 nums[0] 到 nums[i] 的这些元素能否有效划分。
那么 f[0]=true，答案为 f[n]。

根据题意，有

f[i+1] = OR f[i−1] AND nums[i]=nums[i−1], i > 0
f[i+1] = OR f[i−2] AND nums[i]=nums[i−1]=nums[i−2], i > 1
f[i+1] = OR f[i−2] AND nums[i]=nums[i−1]+1=nums[i−2]+2, i > 1
​
复杂度分析
时间复杂度：O(n)，其中 n 为 nums 的长度。
空间复杂度：O(n)。
 */

// 参考@return up;
// DP
/*
笔记: 划分 -> 子问题 -> DP
*/
const int N = 1e5 + 10;
// f[i+1]表示nums[0]~nums[i]这些元素是否能有效划分
bool f[N];
class Solution {
public:
    bool validPartition(vector<int>& nums) { 
        memset(f, false, sizeof(f));
        // 初始状态f[0]表示没有划分的数组，是有效状态
        f[0] = true; // 空数组也是一种状态，空就相当于划分好了
        int n = nums.size();
        // 进行状态转移: nums[i]对应状态f[i+1], 所以根据nums[i]与前面数的关系进行递推
        // 状态转移中元数组nums下标从1开始，因为子数组最少要求2个元素
        for (int i = 1; i < n; ++i) {
            int x = nums[i];
            // 第一种划分
            if (f[i-1] && nums[i-1] == x) {
                f[i + 1] = true;
            }
            if (i >= 2) {
                // 第二种划分
                if (f[i-2] && nums[i-2] == nums[i-1] && nums[i-1] == x) {
                    f[i + 1] = true;
                }
                // 第三种划分
                if (f[i-2] && nums[i-2]+1 == nums[i-1] && nums[i-1]+1 == x) {
                    f[i + 1] = true;
                }
            }
        }
        return f[n];
    }
};
