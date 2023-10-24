/* 198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋
装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，
系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，
计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

示例 1：
输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 2：
输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 400

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // 参考代码随想录
    int rob(vector<int>& nums) {
        if (nums.size() == 0) // 输入数组没有元素
            return 0;
        if (nums.size() == 1) // 输入数组仅有一个元素的case
            return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }

    // 参考灵茶山艾府
    // 递归搜索 + 保存计算结果 = 记忆化搜索
    int rob_v1(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1); // -1表示没有计算过
        // dfs(i)表示从nums[0]到nums[i]最多能偷多少
        function<int(int)> dfs = [&](int i) -> int {
            if (i < 0) return 0; // 递归边界（没有房子）
            if (memo[i] != -1) return memo[i]; // 前面计算过
            return memo[i] = max(dfs(i-1), dfs(i - 2) + nums[i]);
        };
        return dfs(n - 1); // 从最后一个房子开始思考
    }
    /*
    时间复杂度：O(n)，其中 n 为 nums 的长度。
    空间复杂度：O(n)。
    */
};

int main() {
    vector<int> nums = {1,2,3,1};
    int res = Solution().rob_v1(nums);
    cout << res << endl;
    return 0;
}
/* 参考代码随想录：
DP解题步骤
1. 确定dp数组（dp table）以及下标的含义
2. 确定递推公式
3. dp数组如何初始化
4. 确定遍历顺序
5. 举例推导dp数组

打家劫舍是dp解决的经典问题，动规五部曲分析如下：

1. 确定dp数组（dp table）以及下标的含义
dp[i]：考虑下标i（包括i）以内的房屋，最多可以偷窃的金额为dp[i]。

2. 确定递推公式
决定dp[i]的因素就是第i房间偷还是不偷。

- 如果偷第i房间，那么dp[i] = dp[i - 2] + nums[i] ，
即：第i-1房一定是不考虑的，找出 下标i-2（包括i-2）
以内的房屋，最多可以偷窃的金额为dp[i-2] 加上第i房间偷到的钱。

- 如果不偷第i房间，那么dp[i] = dp[i - 1]，
即考虑i-1房，（注意这里是考虑，并不是一定要偷i-1房，
这是很多同学容易混淆的点）

然后dp[i]取最大值，即 dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);

3. dp数组如何初始化
从递推公式dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
可以看出，递推公式的基础就是dp[0] 和 dp[1]

从dp[i]的定义上来讲，dp[0] 一定是 nums[0]，
dp[1]就是nums[0]和nums[1]的最大值即：
dp[1] = max(nums[0], nums[1]);

代码如下：

vector<int> dp(nums.size());
dp[0] = nums[0];
dp[1] = max(nums[0], nums[1]);

4. 确定遍历顺序
dp[i] 是根据dp[i - 2] 和 dp[i - 1] 推导出来的，
那么一定是从前到后遍历！

代码如下：

for (int i = 2; i < nums.size(); i++) {
    dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
}

5. 举例推导dp数组
以示例二，输入[2,7,9,3,1]为例。

红框dp[nums.size() - 1]为结果

*/