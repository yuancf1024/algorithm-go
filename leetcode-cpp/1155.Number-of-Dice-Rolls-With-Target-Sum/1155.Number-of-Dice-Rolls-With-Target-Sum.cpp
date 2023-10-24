/**
 * @file 1155.Number-of-Dice-Rolls-With-Target-Sum.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-1155.掷骰子等于目标和的方法数
 * @version 0.1
 * @date 2023-10-24
 * 
 * @copyright Copyright (c) 2023
 * 这里有 n 个一样的骰子，每个骰子上都有 k 个面，分别标号为 1 到 k 。

给定三个整数 n ,  k 和 target ，返回可能的方式(从总共 k^n 种方式中)滚动骰子的数量，
使正面朝上的数字之和等于 target 。

答案可能很大，你需要对 10^9 + 7 取模 。

示例 1：
输入：n = 1, k = 6, target = 3
输出：1
解释：你扔一个有 6 个面的骰子。
得到 3 的和只有一种方法。

示例 2：
输入：n = 2, k = 6, target = 7
输出：6
解释：你扔两个骰子，每个骰子有 6 个面。
得到 7 的和有 6 种方法：1+6 2+5 3+4 4+3 5+2 6+1。

示例 3：
输入：n = 30, k = 30, target = 500
输出：222616187

解释：返回的结果必须是对 10^9 + 7 取模。
 

提示：

1 <= n, k <= 30
1 <= target <= 1000
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 会超时的递归实现
    int numRollsToTarget(int n, int k, int target) {
        if (target < n || target > n * k) {
            return 0; // 无法组成 target
        }
        const int MOD = 1000000007;
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (j < 0) {
                return 0; // j 不能是负数
            }
            if (i == 0) {
                return j == 0;
            }
            int res = 0;
            for (int x = 1; x < k; x++) {
                res = (res + dfs(i - 1, j - x)) % MOD;
            }
            return res;
        };
        return dfs(n, target);
    }
    /**
     * @brief 
     * 时间复杂度：O(k^n)。搜索树可以近似为一棵 k 叉树，
     * 树高为 O(n)，所以节点个数为 O(k^n)，遍历搜索树需要 O(k^n) 的时间。
        空间复杂度：O(n)。递归需要 O(n) 的栈空间。
     */

    // 递归 + 记录返回值 = 记忆化搜索
    int numRollsToTarget_v2(int n, int k, int target) {
        if (target < n || target > n * k) {
            return 0; // 无法组成 target
        }
        const int MOD = 1000000007;
        vector<vector<int>> memo(n + 1, vector<int>(target - n + 1, -1)); // -1表示没有计算过
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i == 0) {
                return j == 0;
            }
            int &res = memo[i][j]; // 注意这里是引用
            if (res != -1) {
                return res;
            }
            res = 0;
            for (int x = 0; x < k && x <= j; x++) {
                res = (res + dfs(i -1, j - x)) % MOD;
            }
            return res;
        };
        return dfs(n, target - n);
    }
};

int main() {
    int n = 30, k = 30, target = 500;

    int res = Solution().numRollsToTarget_v2(n, k, target);
    cout << res << endl;
    return 0;
}

/**
 * @brief 参考灵神解答 https://leetcode.cn/problems/number-of-dice-rolls-with-target-sum/solutions/2495836/ji-bai-100cong-ji-yi-hua-sou-suo-dao-di-421ab/?envType=daily-question&envId=2023-10-24
 * 
 * 
 * 
 */