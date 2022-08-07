/**
 * @file 6138.Longest-Ideal-Subsequence.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * leetcode-6138. 最长理想子序列
 * 
给你一个由小写字母组成的字符串 s ，和一个整数 k 。
如果满足下述条件，则可以将字符串 t 视作是 理想字符串 ：

- t 是字符串 s 的一个子序列。
- t 中每两个 相邻 字母在字母表中位次的绝对差值小于或等于 k 。

返回 最长 理想字符串的长度。

字符串的子序列同样是一个字符串，并且子序列还满足：
可以经由其他字符串删除某些字符（也可以不删除）但不改变剩余字符的顺序得到。

注意：字母表顺序不会循环。
例如，'a' 和 'z' 在字母表中位次的绝对差值是 25 ，而不是 1 。

 
示例 1：
输入：s = "acfgbd", k = 2
输出：4
解释：最长理想字符串是 "acbd" 。该字符串长度为 4 ，所以返回 4 。
注意 "acfgbd" 不是理想字符串，因为 'c' 和 'f' 的字母表位次差值为 3 。

示例 2：
输入：s = "abcd", k = 3
输出：4
解释：最长理想字符串是 "abcd" ，该字符串长度为 4 ，所以返回 4 。

提示：

1 <= s.length <= 10^5
0 <= k <= 25
s 由小写英文字母组成

 */

// 参考@灵茶山艾府 线性 DP + 空间优化
class Solution {
public:
    int longestIdealString(string& s, int k) { 
        int f[26] = {};
        for (char c : s) {
            c -= 'a';
            f[c] = 1 + *max_element(f + max(c - k, 0), f + min(c + k + 1, 26));
        }
        return *max_element(f, f + 26); // max_element(r, r+6),返回数组r中[0, 6)之间的最大值的迭代器
    }
};

/**
 * @brief 线性 DP + 空间优化
 * 定义 f[i][c] 表示 s 的前 i 个字母中的以 c 结尾的理想字符串的最长长度。

考虑 s[i] 选或不选，根据题意：

- 选，需要从 f[i−1] 中的 [s[i]−k,s[i]+k] 范围内的字符转移过来，即


                  min(s[i]+k,25)
f[i][s[i]] = 1 +  max             f[i−1][c]
                  c=max(s[i]−k,0)
​
 
- 其余情况，则 f[i][c]=f[i−1][c]。

答案为 max(f[n−1])。

代码实现时第一维可以压缩掉。

复杂度分析
时间复杂度：O(nk)，其中 n 为 s 的长度。
空间复杂度：O(∣Σ∣)，其中 ∣Σ∣ 为字符集合的大小，
本题中字符均为小写字母，所以 ∣Σ∣=26。
 */
