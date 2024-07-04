/**
 * @file 2602.Minimum-Operations-to-Make-All-Array-Elements-Equal.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-2602.使数组元素全部相等的最少操作次数 排序+前缀和+二分
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 给你一个正整数数组 nums 。

同时给你一个长度为 m 的整数数组 queries 。
第 i 个查询中，你需要将 nums 中所有元素变成 queries[i] 。
你可以执行以下操作 任意 次：

- 将数组里一个元素 增大 或者 减小 1 。

请你返回一个长度为 m 的数组 answer ，
其中 answer[i]是将 nums 中所有元素变成 queries[i] 的 最少 操作次数。

注意，每次查询后，数组变回最开始的值。

示例 1：
输入：nums = [3,1,6,8], queries = [1,5]
输出：[14,10]
解释：第一个查询，我们可以执行以下操作：
- 将 nums[0] 减小 2 次，nums = [1,1,6,8] 。
- 将 nums[2] 减小 5 次，nums = [1,1,1,8] 。
- 将 nums[3] 减小 7 次，nums = [1,1,1,1] 。
第一个查询的总操作次数为 2 + 5 + 7 = 14 。
第二个查询，我们可以执行以下操作：
- 将 nums[0] 增大 2 次，nums = [5,1,6,8] 。
- 将 nums[1] 增大 4 次，nums = [5,5,6,8] 。
- 将 nums[2] 减小 1 次，nums = [5,5,5,8] 。
- 将 nums[3] 减小 3 次，nums = [5,5,5,5] 。
第二个查询的总操作次数为 2 + 4 + 1 + 3 = 10 。

示例 2：
输入：nums = [2,9,6,3], queries = [10]
输出：[20]
解释：我们可以将数组中所有元素都增大到 10 ，
总操作次数为 8 + 1 + 4 + 7 = 20 。
 
提示：
n == nums.length
m == queries.length
1 <= n, m <= 105
1 <= nums[i], queries[i] <= 10^9
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 最简单的方法 暴力计算 PASS 21/31 Error: runtime error: signed integer overflow
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> res;
        for (auto& x : queries) {
            int sum = 0;
            // 累加
            for (auto& y : nums) {
                if (x > y) {
                    sum += x - y;
                } else {
                    sum += y - x;
                }
            }

            res.push_back(sum);
        }
        return res;
    }

    // 参考@灵茶山艾府 排序+前缀和+二分
    vector<long long> minOperations_v2(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> sum(n + 1); // 前缀和
        for (int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + nums[i];
        }

        int m = queries.size();
        vector<long long> ans(m);
        for (int i = 0; i < m; i++) {
            int q = queries[i];
            long long j = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long left = q * j - sum[j]; // 蓝色面积
            long long right = sum[n] - sum[j] - q * (n - j); // 绿色面积
            ans[i] = right + left;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {3,1,6,8};
    vector<int> queries = {1,5};

    vector<long long> res = Solution().minOperations_v2(nums, queries);

    for (auto& x : res) {
        cout << x << endl;
    }

    return 0;
}

/**
 * @brief 参考@灵茶山艾府 排序+前缀和+二分
 * https://leetcode.cn/problems/minimum-operations-to-make-all-array-elements-equal/solutions/2191417/yi-tu-miao-dong-pai-xu-qian-zhui-he-er-f-nf55
 * 数组排序后，二分找q的位置
 * 蓝色面积+绿色面积即为答案
 * 这可以用前缀和优化
 * 
 * 复杂度分析
时间复杂度：O((n+q)logn)，其中 n 为 nums 的长度，q 为 queries 的长度。
空间复杂度：O(n)。返回值不计入。
 * 
 */