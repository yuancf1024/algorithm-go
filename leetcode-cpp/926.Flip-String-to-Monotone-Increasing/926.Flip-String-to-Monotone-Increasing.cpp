/* 926. 将字符串翻转到单调递增
如果一个二进制字符串，是以一些 0（可能没有 0）
后面跟着一些 1（也可能没有 1）的
形式组成的，那么该字符串是 单调递增 的。

给你一个二进制字符串 s，你可以将任何 0 翻转为 1 或者将 1 翻转为 0 。
返回使 s 单调递增的最小翻转次数。


示例 1：
输入：s = "00110"
输出：1
解释：翻转最后一位得到 00111.

示例 2：
输入：s = "010110"
输出：2
解释：翻转得到 011111，或者是 000111。

示例 3：
输入：s = "00011000"
输出：2
解释：翻转得到 00000000。
 
提示：
1 <= s.length <= 105
s[i] 为 '0' 或 '1'

*/

class Solution {
public:
    // dp[i][0] 当前位为0，dp[i][1] 当前位为1值：需要改变的最少字符个数
    int dp[100010][2];
    int minFlipsMonoIncr(string s) { 
        int n = s.size();
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; ++i) {
            int curr = s[i - 1] - '0';
            // 当前位为0，则前一位只能为0
            dp[i][0] = dp[i - 1][0] + (curr == 0 ? 0 : 1);
            // 当前位为1，则前一位可以为0或1
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (curr == 1 ? 0 : 1);
        }
        return min(dp[n][0], dp[n][1]);
    }
};

// leetcode 官方题解
class Solution {
public:
    int minFlipsMonoIncr(string &s) { 
        int dp0 = 0, dp1 = 0;
        for (char c: s) {
            int dp0New = dp0, dp1New = min(dp0, dp1);
            if (c == '1') {
                dp0New++;
            } else {
                dp1New++;
            }
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return min(dp0, dp1);
    }
};

/*

*/