/* 377. 组合总和 Ⅳ
给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。
请你从 nums 中找出并返回总和为 target 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

示例 1：

输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。

示例 2：
输入：nums = [9], target = 3
输出：0
 
提示：

1 <= nums.length <= 200
1 <= nums[i] <= 1000
nums 中的所有元素 互不相同
1 <= target <= 1000
 

进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？

*/

// 参考代码随想录
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) { // 遍历背包
            for (int j = 0; j < nums.size(); j++) { // 遍历物品
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i-nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};

/**
 * @brief 
 * 思路
对完全背包还不了解的同学，可以看这篇：动态规划：关于完全背包，
你该了解这些！

本题题目描述说是求组合，但又说是可以元素相同顺序不同的组合算两个组合，
其实就是求排列！

弄清什么是组合，什么是排列很重要。

组合不强调顺序，(1,5)和(5,1)是同一个组合。

排列强调顺序，(1,5)和(5,1)是两个不同的排列。

大家在公众号里学习回溯算法专题的时候，一定做过这两道题目回溯算法：
39.组合总和 和回溯算法：40.组合总和II会感觉这两题和本题很像！

但其本质是本题求的是排列总和，而且仅仅是求排列总和的个数，
并不是把所有的排列都列出来。

如果本题要把排列都列出来的话，只能使用回溯算法爆搜。

动规五部曲分析如下：

1. 确定dp数组以及下标的含义
dp[i]: 凑成目标正整数为i的排列个数为dp[i]

2. 确定递推公式
dp[i]（考虑nums[j]）可以由 dp[i - nums[j]]（不考虑nums[j]） 推导出来。

因为只要得到nums[j]，排列个数dp[i - nums[j]]，就是dp[i]的一部分。

在动态规划：494.目标和 和 动态规划：518.零钱兑换II 中我们已经讲过了，
求装满背包有几种方法，递推公式一般都是dp[i] += dp[i - nums[j]];

本题也一样。

3. dp数组如何初始化
因为递推公式dp[i] += dp[i - nums[j]]的缘故，dp[0]要初始化为1，
这样递归其他dp[i]的时候才会有数值基础。

至于dp[0] = 1 有没有意义呢？

其实没有意义，所以我也不去强行解释它的意义了，因为题目中也说了：
给定目标值是正整数！ 所以dp[0] = 1是没有意义的，仅仅是为了推导递推公式。

至于非0下标的dp[i]应该初始为多少呢？

初始化为0，这样才不会影响dp[i]累加所有的dp[i - nums[j]]。

4. 确定遍历顺序

个数可以不限使用，说明这是一个完全背包。

得到的集合是排列，说明需要考虑元素之间的顺序。

本题要求的是排列，那么这个for循环嵌套的顺序可以有说法了。

在动态规划：518.零钱兑换II 中就已经讲过了。

- 如果求组合数就是外层for循环遍历物品，内层for遍历背包。

- 如果求排列数就是外层for遍历背包，内层for循环遍历物品。

如果把遍历nums（物品）放在外循环，遍历target的作为内循环的话，
举一个例子：计算dp[4]的时候，结果集只有 {1,3} 这样的集合，
不会有{3,1}这样的集合，因为nums遍历放在外层，3只能出现在1后面！

所以本题遍历顺序最终遍历顺序：
target（背包）放在外循环，将nums（物品）放在内循环，内循环从前到后遍历。

5. 举例来推导dp数组
我们再来用示例中的例子推导一下：

如果代码运行处的结果不是想要的结果，就把dp[i]都打出来，
看看和我们推导的一不一样。

以上分析完毕，C++代码如下：

C++测试用例有两个数相加超过int的数据，
所以需要在if里加上dp[i] < INT_MAX - dp[i - num]。

但java就不用考虑这个限制，java里的int也是四个字节吧，
也有可能leetcode后台对不同语言的测试数据不一样。
 */