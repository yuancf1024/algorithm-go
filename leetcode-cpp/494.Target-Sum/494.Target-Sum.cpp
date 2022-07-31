/* 494. 目标和
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 
表达式 ：
例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，
然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

示例 1：
输入：nums = [1,1,1,1,1], target = 3
输出：5

解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

示例 2：
输入：nums = [1], target = 1
输出：1
 

提示：

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

*/

// 参考代码随想录
// 回溯 (会超时)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
        }

        // 如果 sum+candidates[i]>target 就终止遍历
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) { 
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (target > sum) {
            return 0; // 此时没有方案
        }
        if ((target + sum) % 2) {
            return 0; // 此时没有方案，两个int相加的时候各位要小心数值溢出的问题
        }

        int bagSize = (target + sum) / 2; // 转变为组合总和问题，bagSize就是要求的和

        // 一下为回溯法的代码
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // 需要排序
        backtracking(nums, bagSize, 0, 0);
        return result.size();
    }
};


// 参考代码随想录
// DP 动态规划解法
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) { 
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (abs(target) > sum) {
            return 0; // 此时没有方案
        }
        if ((target+sum) % 2 == 1) {
            return 0; // 此时没有方案
        }
        int bagSize = (target + sum) / 2;
        /*
        left组合 - right组合 = target
        left - (sum - left) = target -> left = (target + sum)/2
        隐含的前提: left组合 > 0
        */

        // DP
        if (bagSize < 0) {
            return 0;
        }
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};

/*
思路

如果对背包问题不都熟悉先看这两篇：

如果跟着「代码随想录」一起学过回溯算法系列 (opens new window)的录友，
看到这道题，应该有一种直觉，就是感觉好像回溯法可以爆搜出来。

事实确实如此，下面我也会给出相应的代码，只不过会超时，哈哈。

这道题目咋眼一看和动态规划背包啥的也没啥关系。

本题要如何使表达式结果为target，

既然为target，那么就一定有 left组合 - right组合 = target。

left + right等于sum，而sum是固定的。

公式来了， left - (sum - left) = target -> left = (target + sum)/2 。

target是固定的，sum是固定的，left就可以求出来。

此时问题就是在集合nums中找出和为left的组合

回溯算法

在回溯算法系列中，一起学过这道题目回溯算法：
39. 组合总和 的录友应该感觉很熟悉，
这不就是组合总和问题么？

此时可以套组合总和的回溯法代码，几乎不用改动。

当然，也可以转变成序列区间选+ 或者 -，使用回溯法，那就是另一个解法。

我也把代码给出来吧，大家可以了解一下，回溯的解法，

以下是本题转变为组合总和问题的回溯法代码：


动态规划


如何转化为01背包问题呢。

假设加法的总和为x，那么减法对应的总和就是sum - x。

所以我们要求的是 x - (sum - x) = S

x = (S + sum) / 2

此时问题就转化为，装满容量为x背包，有几种方法。

大家看到(S + sum) / 2 应该担心计算的过程中向下取整有没有影响。

这么担心就对了，例如sum 是5，S是2的话其实就是无解的，所以：

if ((S + sum) % 2 == 1) return 0; // 此时没有方案

同时如果 S的绝对值已经大于sum，那么也是没有方案的。

if (abs(S) > sum) return 0; // 此时没有方案

再回归到01背包问题，为什么是01背包呢？

因为每个物品（题目中的1）只用一次！

这次和之前遇到的背包问题不一样了，之前都是求容量为j的背包，最多能装多少。

本题则是装满有几种方法。其实这就是一个组合问题了。

1. 确定dp数组以及下标的含义
dp[j] 表示：填满j（包括j）这么大容积的包，有dp[j]种方法

其实也可以使用二维dp数组来求解本题，dp[i][j]：
使用 下标为[0, i]的nums[i]能够凑满j（包括j）这么大容量的包，
有dp[i][j]种方法。

下面我都是统一使用一维数组进行讲解， 二维降为一维（滚动数组），
其实就是上一层拷贝下来，这个我在动态规划：关于01背包问题，你该了解这些！
（滚动数组）也有介绍。

2.确定递推公式
有哪些来源可以推出dp[j]呢？

不考虑nums[i]的情况下，填满容量为j - nums[i]的背包，有dp[j - nums[i]]种方法。

那么只要搞到nums[i]的话，凑成dp[j]就有dp[j - nums[i]] 种方法。

例如：dp[j]，j 为5，

已经有一个1（nums[i]） 的话，有 dp[4]种方法 凑成 dp[5]。
已经有一个2（nums[i]） 的话，有 dp[3]种方法 凑成 dp[5]。
已经有一个3（nums[i]） 的话，有 dp[2]中方法 凑成 dp[5]
已经有一个4（nums[i]） 的话，有 dp[1]中方法 凑成 dp[5]
已经有一个5 （nums[i]）的话，有 dp[0]中方法 凑成 dp[5]
那么凑整dp[5]有多少方法呢，也就是把 所有的 dp[j - nums[i]] 累加起来。

所以求组合类问题的公式，都是类似这种：

dp[j] += dp[j - nums[i]]

这个公式在后面在讲解背包解决排列组合问题的时候还会用到！

3. dp数组如何初始化
从递归公式可以看出，在初始化的时候dp[0] 一定要初始化为1，
因为dp[0]是在公式中一切递推结果的起源，如果dp[0]是0的话，递归结果将都是0。

dp[0] = 1，理论上也很好解释，装满容量为0的背包，有1种方法，就是装0件物品。

dp[j]其他下标对应的数值应该初始化为0，从递归公式也可以看出，
dp[j]要保证是0的初始值，才能正确的由dp[j - nums[i]]推导出来。

4. 确定遍历顺序
在动态规划：关于01背包问题，你该了解这些！（滚动数组） 中，
我们讲过对于01背包问题一维dp的遍历，nums放在外循环，target在内循环，
且内循环倒序。

举例推导dp数组

输入：nums: [1, 1, 1, 1, 1], S: 3

bagSize = (S + sum) / 2 = (3 + 5) / 2 = 4

dp数组状态变化如下：

*/