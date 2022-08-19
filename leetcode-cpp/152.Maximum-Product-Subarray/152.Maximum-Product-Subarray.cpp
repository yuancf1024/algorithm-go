/**
 * @file 152.Maximum-Product-Subarray.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * leetcode-152.乘积最大子数组
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组
（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 32-位 整数。

子数组 是数组的连续子序列。

示例 1:
输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:
输入: nums = [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 
提示:

1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
nums 的任何前缀或后缀的乘积都 保证 是一个 32-位 整数
 */

// DP + 滚动数组
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};


/**
 * @brief 参考leetcode官方题解
 * 方法一：动态规划
思路和算法

如果我们用f_max(i)来表示以第i 个元素结尾的乘积最大子数组的乘积，
a表示输入参数 nums，那么根据「53. 最大子序和」的经验，
我们很容易推导出这样的状态转移方程：

            n
f_max(i) = max {f(i-1)*a_i, a_i}
           i=1

它表示以第i个元素结尾的乘积最大子数组的乘积可以考虑a_i加入前面的
f_max(i - 1)对应的一段，或者单独成为一段，这里两种情况下取最大值。
求出所有的 f_max(i)之后选取最大的一个作为答案。

可是在这里，这样做是错误的。为什么呢？

因为这里的定义并不满足「最优子结构」。
具体地讲，如果a={5,6,−3,4,−3}，那么此时f_max对应的序列是
{5,30,−3,4,−3}，按照前面的算法我们可以得到答案为30，
即前两个数的乘积，而实际上答案应该是全体数字的乘积。
我们来想一想问题出在哪里呢？
问题出在最后一个−3 所对应的 f_max的值既不是−3，
也不是4×(−3)，而是5×6×(−3)×4×(−3)。所以我们得到了一个结论：
当前位置的最优解未必是由前一个位置的最优解转移得到的。

我们可以根据正负性进行分类讨论。

考虑当前位置如果是一个负数的话，那么我们希望以它前一个位置结尾的某个段的积
也是个负数，这样就可以负负得正，并且我们希望这个积尽可能「负得更多」，
即尽可能小。如果当前位置是一个正数的话，我们更希望以它前一个位置结尾的某个段的积
也是个正数，并且希望它尽可能地大。于是这里我们可以再维护一个 
f_min(i)，它表示以第i个元素结尾的乘积最小子数组的乘积，
那么我们可以得到这样的动态规划转移方程：

f_max(i) = max {f_max(i-1) * ai,f_min(i-1)*ai, ai}

f_min(i) = min {f_max(i-1) * ai,f_min(i-1)*ai, ai}

它代表第i个元素结尾的乘积最大子数组的乘积f_max(i)，可以考虑把a_i加入
第i−1个元素结尾的乘积最大或最小的子数组的乘积中，二者加上a_i，三者取大，
就是第i 个元素结尾的乘积最大子数组的乘积。
第i 个元素结尾的乘积最小子数组的乘积f_min(i) 同理。

不难给出这样的实现：
易得这里的渐进时间复杂度和渐进空间复杂度都是O(n)。

考虑优化空间。

由于第i个状态只和第i−1 个状态相关，根据「滚动数组」思想，
我们可以只用两个变量来维护i−1 时刻的状态，
一个维护f_max，一个维护 f_min。细节参见代码。

复杂度分析
记 nums 元素个数为n。

时间复杂度：程序一次循环遍历了 nums，故渐进时间复杂度为 O(n)。

空间复杂度：优化后只使用常数个临时变量作为辅助空间，与n 无关，
故渐进空间复杂度为O(1)。

 */