/**
 * @file 3086.Minimum-Moves-to-Pick-K-Ones.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-3086.Minimum-Moves-to-Pick-K-Ones.cpp
 * @version 0.1
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 给你一个下标从 0 开始的二进制数组 nums，
 * 其长度为 n ；另给你一个 正整数 k 以及一个 非负整数 maxChanges 。

Alice 在玩一个游戏，游戏的目标是让 Alice 使用 最少 数量的 行动 次数
从 nums 中拾起 k 个 1 。游戏开始时，Alice 可以选择数组 [0, n - 1] 
范围内的任何索引 aliceIndex 站立。如果 nums[aliceIndex] == 1 ，
Alice 会拾起一个 1 ，并且 nums[aliceIndex] 变成0（这 不算 作一次行动）。
之后，Alice 可以执行 任意数量 的 行动（包括零次），在每次行动中 Alice 必须 恰好 执行以下动作之一：

- 选择任意一个下标 j != aliceIndex 且满足 nums[j] == 0 ，
然后将 nums[j] 设置为 1 。这个动作最多可以执行 maxChanges 次。
- 选择任意两个相邻的下标 x 和 y（|x - y| == 1）且满足 nums[x] == 1, nums[y] == 0 ，
然后交换它们的值（将 nums[y] = 1 和 nums[x] = 0）。如果 y == aliceIndex，
在这次行动后 Alice 拾起一个 1 ，并且 nums[y] 变成 0 。

返回 Alice 拾起 恰好 k 个 1 所需的 最少 行动次数。

示例 1：
输入：nums = [1,1,0,0,0,1,1,0,0,1],
k = 3, maxChanges = 1
输出：3
解释：如果游戏开始时 Alice 在 aliceIndex == 1 的位置上，
按照以下步骤执行每个动作，他可以利用 3 次行动拾取 3 个 1 ：

游戏开始时 Alice 拾取了一个 1 ，nums[1] 变成了 0。此时 nums 变为 [1,1,1,0,0,1,1,0,0,1] 。
选择 j == 2 并执行第一种类型的动作。nums 变为 [1,0,1,0,0,1,1,0,0,1]
选择 x == 2 和 y == 1 ，并执行第二种类型的动作。nums 变为 [1,1,0,0,0,1,1,0,0,1] 。
    由于 y == aliceIndex，Alice 拾取了一个 1 ，nums 变为  [1,0,0,0,0,1,1,0,0,1] 。
选择 x == 0 和 y == 1 ，并执行第二种类型的动作。nums 变为 [0,1,0,0,0,1,1,0,0,1] 。
    由于 y == aliceIndex，Alice 拾取了一个 1 ，nums 变为  [0,0,0,0,0,1,1,0,0,1] 。
请注意，Alice 也可能执行其他的 3 次行动序列达成拾取 3 个 1 。

示例 2：
输入：nums = [0,0,0,0], k = 2, maxChanges = 3
输出：4
解释：如果游戏开始时 Alice 在 aliceIndex == 0 的位置上，
按照以下步骤执行每个动作，他可以利用 4 次行动拾取 2 个 1 ：

选择 j == 1 并执行第一种类型的动作。nums 变为 [0,1,0,0] 。
选择 x == 1 和 y == 0 ，并执行第二种类型的动作。
    nums 变为 [1,0,0,0] 。由于 y == aliceIndex，Alice 拾起了一个 1 ，
    nums 变为 [0,0,0,0] 。
再次选择 j == 1 并执行第一种类型的动作。
nums 变为 [0,1,0,0] 。
再次选择 x == 1 和 y == 0 ，并执行第二种类型的动作。
nums 变为 [1,0,0,0] 。由于y == aliceIndex，
Alice 拾起了一个 1 ，nums 变为 [0,0,0,0] 。
 

提示：

2 <= n <= 10^5
0 <= nums[i] <= 1
1 <= k <= 10^5
0 <= maxChanges <= 10^5
maxChanges + sum(nums) >= k
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // CV 有点难☹️ 中位数贪心
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        vector<int> pos;
        int c = 0; // nums 中连续的1 长度
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            pos.push_back(i); // 记录 1 的位置
            c = max(c, 1);
            if (i > 0 && nums[i-1] == 1) {
                if (i > 1 && nums[i-2] == 1) {
                    c = 3; // 有3个连续的1
                } else {
                    c = max(c, 2); // 有 2个连续的1
                }
            }
        }

        c = min(c, k);
        if (maxChanges >= k - c) {
            // 其余k-c个1可以全部用两次操作得到
            return max(c-1, 0) + (k - c) * 2;
        }

        int n = pos.size();
        vector<long long> sum(n+1);
        for (int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + pos[i];
        }
        
        long long ans = LLONG_MAX;
        // 除了 maxChanges 个数可以用两次操作得到，其余的1只能一步步移动到pos[i]
        int size = k - maxChanges;
        for (int right = size; right <= n; right++) {
            // s1 + s2 是j 在 [left, right）中的所有pos[j]到index=pos[(left+right)/2]的距离之和
            int left = right - size;
            int i = left + size / 2;
            long long index = pos[i];
            long long s1 = index * (i - left) - (sum[i] - sum[left]);
            long long s2 = sum[right] - sum[i] - index * (right - i);
            ans = min(ans, s1 + s2);
        }
        return ans + maxChanges * 2;
    }
};

int main() {
    vector<int> nums = {0,0,0,0};
    int k = 2, maxChanges = 3;

    long long res = Solution().minimumMoves(nums, k, maxChanges);
    cout << res << endl;

    return 0;
}

/**
 * @brief 参考大佬@灵茶山艾府 
 * https://leetcode.cn/problems/minimum-moves-to-pick-k-ones/solutions/2692009/zhong-wei-shu-tan-xin-by-endlesscheng-h972
 * 
 * 中位数贪心
 * 初步分析
把 0 看成「空位」。

第二种操作相当于把一个 1 移动到和它相邻的空位上，
如果我们想得到一个下标在 j 的 1，必须操作 ∣aliceIndex−j∣ 次。

对于第一种操作，贪心地把和 aliceIndex 相邻的 0 变成 1（在此之前先移动相邻的 1），
然后结合第二种操作，把相邻的 1 移动到 aliceIndex，只需 2 次操作就可以得到一个 1。

我们分 maxChanges 较大，和 maxChanges 较小两种情况讨论。

**maxChanges 较大的情况**

应当优先使用第一种操作+第二种操作，毕竟只需要操作 2 次就能得到一个 1。
那么答案就是 2k 吗？

细节：对于 aliceIndex,aliceIndex−1,aliceIndex+1 这三个位置上的 1，可以用更少的操作得到：

- aliceIndex 位置上的 1 无需操作就能得到。
- aliceIndex−1 和 aliceIndex+1 位置上的 1 只需操作 1 次就能得到。

贪心的想法是，选择有三个连续 1 的中间位置，作为 aliceIndex。
如果没有三个连续 1，就看有没有连续两个 1。如果没有连续两个 1，就选任意 1 的位置。
如果没有 1 就随便选。

一般地，设 c 为 nums 中的长度不超过 3 的最长连续 1 的长度。
如果 c>k 则 c=k。

如果 maxChanges≥k−c，我们可以先使用 max(c−1,0) 次第二种操作，
收集这连续的 c 个 1，然后对于其余 k−c 个 1，都可以用 2 次操作得到，
此时可以直接返回 max(c−1,0)+(k−c)⋅2。

接下来，要解决的就是 maxChanges 比较小的情况了。

从特殊到一般，想一想，如果 maxChanges=0，也就是只能使用第二种操作，要如何计算答案呢？

**maxChanges=0 的情况**

首先算出所有 1 的位置，记到一个 pos 数组中。例如示例 1 的 nums=[1,1,0,0,0,1,1,0,0,1]，
其 pos=[0,1,5,6,9]。

示例 1 的 k=3，我们可以枚举 pos 的所有长为 3 的子数组，
例如 [0,1,5]，就好比在坐标轴上的 0,1,5 位置上有 3 个生产商品的工厂，
我们要建造一个货仓存放商品，把货仓建在哪里，可以使所有工厂到货仓的距离之和最小？

这个问题叫做「货仓选址」。根据 中位数贪心及其证明，最优解是把货仓建在工厂位置的中位数上。
例如 [0,1,5] 中的 1，此时距离和等于 ∣0−1∣+∣1−1∣+∣5−1∣=5。

利用前缀和，可以 O(1) 地算出子数组元素到其中位数的距离之和，原理请看 图解。

**maxChanges 较小的情况**

最后，如果 maxChanges>0，我们可以先计算所有长为 k−maxChanges 的子数组的货仓选址问题，取最小值，
然后再通过 maxChanges⋅2 次操作得到 maxChanges 个 1。

示例 1 只需考虑所有长为 k−1=2 的子数组，那么前两个 1 的货仓选址问题就是最小的，
距离之和为 1，也就是这两个 1 需要 1 次操作得到。
然后再通过 2 次操作得到剩下的一个 1，总共需要 1+2=3 次操作。

复杂度分析
时间复杂度：O(n)，其中 n 为 nums 的长度。
空间复杂度：O(n)。
 * 
 */