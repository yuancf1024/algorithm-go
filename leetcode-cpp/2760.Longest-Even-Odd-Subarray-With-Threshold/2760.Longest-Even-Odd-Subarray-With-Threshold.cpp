/**
 * @file 2760.Longest-Even-Odd-Subarray-With-Threshold.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-2760.最长奇偶子数组
 * @version 0.1
 * @date 2023-11-16
 * 
 * @copyright Copyright (c) 2023
 * 给你一个下标从 0 开始的整数数组 nums 和一个整数 threshold 。

请你从 nums 的子数组中找出以下标 l 开头、下标 r 结尾 (0 <= l <= r < nums.length) 
且满足以下条件的 最长子数组 ：

- nums[l] % 2 == 0
- 对于范围 [l, r - 1] 内的所有下标 i ，nums[i] % 2 != nums[i + 1] % 2
- 对于范围 [l, r] 内的所有下标 i ，nums[i] <= threshold
以整数形式返回满足题目要求的最长子数组的长度。

注意：子数组 是数组中的一个连续非空元素序列。

示例 1：
输入：nums = [3,2,5,4], threshold = 5
输出：3
解释：在这个示例中，我们选择从 l = 1 开始、到 r = 3 结束的子数组 => [2,5,4] ，满足上述条件。
因此，答案就是这个子数组的长度 3 。可以证明 3 是满足题目要求的最大长度。

示例 2：
输入：nums = [1,2], threshold = 2
输出：1
解释：
在这个示例中，我们选择从 l = 1 开始、到 r = 1 结束的子数组 => [2] 。
该子数组满足上述全部条件。可以证明 1 是满足题目要求的最大长度。

示例 3：
输入：nums = [2,3,4,5], threshold = 4
输出：3
解释：
在这个示例中，我们选择从 l = 0 开始、到 r = 2 结束的子数组 => [2,3,4] 。 
该子数组满足上述全部条件。
因此，答案就是这个子数组的长度 3 。可以证明 3 是满足题目要求的最大长度。
 

提示：

1 <= nums.length <= 100 
1 <= nums[i] <= 100 
1 <= threshold <= 100
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int ans = 0, i = 0;
        while (i < n) {
            if (nums[i] > threshold || nums[i] % 2) {
                i++; // 直接跳过
                continue;
            }
            int start = i; // 记录这一组的开始位置
            i++; // 开始位置已经满足要求，从下一个位置开始判断
            while (i < n && nums[i] <= threshold && nums[i] % 2 != nums[i - 1] % 2) {
                i++;
            }
            // 从start 到 i-1是满足题目要求的子数组
            ans = max(ans, i - start);
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {3,2,5,4};
    int n = 5;

    int res = Solution().longestAlternatingSubarray(nums, n);
    cout << res << endl;

    return 0;
}

/**
 * @brief 参考灵茶山艾府的实现
 * 分组循环
适用场景：按照题目要求，数组会被分割成若干组，
且每一组的判断/处理逻辑是一样的。

核心思想：

- 外层循环负责遍历组之前的准备工作（记录开始位置），
和遍历组之后的统计工作（更新答案最大值）。
- 内层循环负责遍历组，找出这一组在哪结束。

这个写法的好处是，各个逻辑块分工明确，也不需要特判最后一组（易错点）。
以我的经验，这个写法是所有写法中最不容易出 bug 的，推荐大家记住。

时间复杂度乍一看是 O(n^2)，但注意变量 i 只会增加，
不会重置也不会减少。所以二重循环总共循环 O(n)次，
所以时间复杂度是 O(n)。
 */