/**
 * @file 6159.Maximum-Segment-Sum-After-Removals.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * leetcode-6159.删除操作后的最大子段和
 * 
给你两个下标从 0 开始的整数数组 nums 和 removeQueries ，
两者长度都为 n 。

对于第 i 个查询，nums 中位于下标 removeQueries[i] 处的元素被删除，
将 nums 分割成更小的子段。

一个 子段 是 nums 中连续 正 整数形成的序列。
子段和 是子段中所有元素的和。

请你返回一个长度为 n 的整数数组 answer ，
其中 answer[i]是第 i 次删除操作以后的 最大 子段和。

注意：一个下标至多只会被删除一次。

示例 1：
输入：nums = [1,2,5,6,1], removeQueries = [0,3,2,4,1]
输出：[14,7,2,2,0]
解释：用 0 表示被删除的元素，答案如下所示：

查询 1 ：删除第 0 个元素，nums 变成 [0,2,5,6,1] ，最大子段和为子段 [2,5,6,1] 的和 14 。
查询 2 ：删除第 3 个元素，nums 变成 [0,2,5,0,1] ，最大子段和为子段 [2,5] 的和 7 。
查询 3 ：删除第 2 个元素，nums 变成 [0,2,0,0,1] ，最大子段和为子段 [2] 的和 2 。
查询 4 ：删除第 4 个元素，nums 变成 [0,2,0,0,0] ，最大子段和为子段 [2] 的和 2 。
查询 5 ：删除第 1 个元素，nums 变成 [0,0,0,0,0] ，最大子段和为 0 ，因为没有任何子段存在。
所以，我们返回 [14,7,2,2,0] 。

示例 2：
输入：nums = [3,2,11,1], removeQueries = [3,2,1,0]
输出：[16,5,3,0]
解释：用 0 表示被删除的元素，答案如下所示：

查询 1 ：删除第 3 个元素，nums 变成 [3,2,11,0] ，最大子段和为子段 [3,2,11] 的和 16 。
查询 2 ：删除第 2 个元素，nums 变成 [3,2,0,0] ，最大子段和为子段 [3,2] 的和 5 。
查询 3 ：删除第 1 个元素，nums 变成 [3,0,0,0] ，最大子段和为子段 [3] 的和 3 。
查询 5 ：删除第 0 个元素，nums 变成 [0,0,0,0] ，最大子段和为 0 ，因为没有任何子段存在。
所以，我们返回 [16,5,3,0] 。
 
提示：

n == nums.length == removeQueries.length
1 <= n <= 105
1 <= nums[i] <= 109
0 <= removeQueries[i] < n
removeQueries 中所有数字 互不相同 。
 */

// 参考@灵茶山艾府 倒序回答 + 并查集
// 不好理解
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        int fa[n + 1];
        iota(fa, fa + n + 1, 0);
        long long sum[n + 1];
        memset(sum, 0, sizeof(sum));
        function<int(int)> find = [&](int x) -> int {
            return fa[x] == x ? x : fa[x] = find(fa[x]);
        };

        vector<long long> ans(n);
        for (int i = n - 1; i > 0; --i) {
            int x = removeQueries[i];
            int to = find(x + 1);
            fa[x] = to; // 合并x 和x+1
            sum[to] += sum[x] + nums[x];
            ans[i - 1] = max(ans[i], sum[to]);
        }
        return ans;
    }
};

/**
 * @brief 参考@灵茶山艾府 倒序回答 + 并查集
 * 提示 1
删除不好做，添加比较好做。不妨倒着思考，删除变成了添加。

提示 2
添加时可能会合并两个子段。

我们需要考虑如何动态维护每个子段的元素和，并高效地合并两个子段。

提示 3
用并查集（视频讲解 中讲了原理），
添加x=removeQueries[i] 时，用并查集合并x和x+1，并把nums[x] 加到子段和中。

ans[i] 要么取上一个ans[i+1] 的最大子段和，
要么取合并后的子段和，这两者取最大值。
 */