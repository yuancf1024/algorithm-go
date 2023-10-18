/**
 * @file 2530.Maximal-Score-After-Applying-K-Operations.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-2530.Maximal-Score-After-Applying-K-Operations
 * @version 0.1
 * @date 2023-10-18
 * 
 * @copyright Copyright (c) 2023
 * 给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。你的 起始分数 为 0 。

在一步 操作 中：

选出一个满足 0 <= i < nums.length 的下标 i ，
将你的 分数 增加 nums[i] ，并且
将 nums[i] 替换为 ceil(nums[i] / 3) 。
返回在 恰好 执行 k 次操作后，你可能获得的最大分数。

向上取整函数 ceil(val) 的结果是大于或等于 val 的最小整数。

示例 1：
输入：nums = [10,10,10,10,10], k = 5
输出：50
解释：对数组中每个元素执行一次操作。最后分数是 10 + 10 + 10 + 10 + 10 = 50 。

示例 2：
输入：nums = [1,10,3,3,3], k = 3
输出：17
解释：可以执行下述操作：
第 1 步操作：选中 i = 1 ，nums 变为 [1,4,3,3,3] 。分数增加 10 。
第 2 步操作：选中 i = 1 ，nums 变为 [1,2,3,3,3] 。分数增加 4 。
第 3 步操作：选中 i = 2 ，nums 变为 [1,1,1,3,3] 。分数增加 3 。
最后分数是 10 + 4 + 3 = 17 。
 
提示：

1 <= nums.length, k <= 10^5
1 <= nums[i] <= 10^9
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        long long ans = 0;
        for (int _ = 0; _ < k; ++_) {
            int x = q.top();
            q.pop();
            ans += x;
            q.push((x + 2) / 3);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {10,10,10,10,10};
    int k = 5;
    long long res = Solution().maxKelements(nums, k);
    cout << res << endl;

    return 0;
}

/**
 * @brief 官方题解
 * 方法一：贪心 + 优先队列
思路与算法

在一次操作中，我们会将 nums[i] 变成 ⌈nums[i]/3⌉ 
，并且增加 nums[i] 的得分。由于：

- 数组中其它的元素不会变化；
- 对于两个不同的元素 nums[i] 和 nums[j]，
如果 nums[i]≤nums[j]，在对它们都进行一次操作后，
nums[i]≤nums[j] 仍然成立；
这就说明，我们每一次操作都应当贪心地选出当前最大的那个元素。

因此，我们可以使用一个大根堆（优先队列）来维护数组中所有的元素。
在每一次操作中，我们取出堆顶的元素 x，将答案增加 x，再将 ⌈x/3⌉
放回大根堆中即可。

细节

为了避免浮点数运算，我们可以用 (x+2)/3 等价 ⌈x/3⌉
，其中 / 表示整数除法。

复杂度分析

时间复杂度：O(klog⁡n+n)，其中 n 是数组 nums 的长度。
构造优先队列需要的时间为 O(n)，每一轮操作需要的时间为 O(log⁡n)，
一共有 k 轮操作。

空间复杂度：O(n) 或 O(1)。优先队列需要的空间为 
O(n)。某些语言原地对数组建堆，空间复杂度为 O(1)。
 */