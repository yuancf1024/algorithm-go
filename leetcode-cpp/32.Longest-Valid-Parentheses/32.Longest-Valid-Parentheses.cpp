/**
 * @file 32.Longest-Valid-Parentheses.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-17
 * 
 * @copyright Copyright (c) 2022
 * leetcode-32. 最长有效括号
 * 
给你一个只包含 '(' 和 ')' 的字符串，
找出最长有效（格式正确且连续）括号子串的长度。

示例 1：
输入：s = "(()"
输出：2

解释：最长有效括号子串是 "()"

示例 2：
输入：s = ")()())"
输出：4

解释：最长有效括号子串是 "()()"

示例 3：

输入：s = ""
输出：0
 
提示：

0 <= s.length <= 3 * 104
s[i] 为 '(' 或 ')'
 */
// 方法一：动态规划 思维难度高
class Solution {
public:
    int longestValidParentheses(string s) { 
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') { // s[i]=‘)’ 且s[i−1]=‘(’，也就是字符串形如“……()”
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i-1] > 0 && s[i-dp[i-1] - 1] == '(') { // s[i]=‘)’ 且s[i−1]=‘)’，也就是字符串形如 “……))”
                    dp[i] = dp[i - 1] +
                            ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};

/**
 * @brief 
 * 方法一：动态规划
思路和算法

我们定义dp[i] 表示以下标i 字符结尾的最长有效括号的长度。
我们将dp 数组全部初始化为0 。显然有效的子串一定以‘)’ 结尾，
因此我们可以知道以‘(’ 结尾的子串对应的dp 值必定为 0 ，
我们只需要求解 ‘)’ 在dp 数组中对应位置的值。

我们从前往后遍历字符串求解dp 值，我们每两个字符检查一次：

1. s[i]=‘)’ 且s[i−1]=‘(’，也就是字符串形如“……()”，我们可以推出：

dp[i]=dp[i−2]+2

我们可以进行这样的转移，是因为结束部分的 "()" 是一个有效子字符串，
并且将之前有效子字符串的长度增加了2 。

2. s[i]=‘)’ 且s[i−1]=‘)’，也就是字符串形如 “……))”，我们可以推出：
如果s[i−dp[i−1]−1]=‘(’，那么

dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2

我们考虑如果倒数第二个‘)’ 是一个有效子字符串的一部分（记作sub_s），
对于最后一个‘)’ ，如果它是一个更长子字符串的一部分，
那么它一定有一个对应的 ‘(’ ，且它的位置在倒数第二个 ‘)’ 所在的有效子字符串的前面
（也就是 sub_s的前面）。因此，如果子字符串sub_s的前面恰好是 
‘(’ ，那么我们就用2 加上 sub_s的长度（dp[i−1]）去更新dp[i]。
同时，我们也会把有效子串 “(sub_s)”之前的有效子串的长度也加上，
也就是再加上dp[i−dp[i−1]−2]。

最后的答案即为dp 数组中的最大值。

复杂度分析

时间复杂度：O(n)，其中n 为字符串的长度。我们只需遍历整个字符串一次，
即可将dp 数组求出来。

空间复杂度：O(n)。我们需要一个大小为n 的dp 数组。
 */


// 方法一：动态规划 思维难度高
class Solution {
public:
    int longestValidParentheses(string s) { 
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') { // 对于遇到的每个‘(’ ，我们将它的下标放入栈中
                stk.push(i);
            } else {
                stk.pop(); // 对于遇到的每个‘)’ ，我们先弹出栈顶元素表示匹配了当前右括号
                if (stk.empty()) { // 如果栈为空，说明当前的右括号为没有被匹配的右括号
                    stk.push(i);
                } else { // 如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
};

/**
 * @brief 
 * 方法二：栈
思路和算法

撇开方法一提及的动态规划方法，相信大多数人对于这题的第一直觉是
找到每个可能的子串后判断它的有效性，但这样的时间复杂度会达到 O(n^3)，
无法通过所有测试用例。
但是通过栈，我们可以在遍历给定字符串的过程中去判断到目前为止扫描的子串的
有效性，同时能得到最长有效括号的长度。

具体做法是我们始终保持栈底元素为当前已经遍历过的元素中
「最后一个没有被匹配的右括号的下标」，这样的做法主要是考虑了边界条件的处理，
栈里其他元素维护左括号的下标：

- 对于遇到的每个‘(’ ，我们将它的下标放入栈中

- 对于遇到的每个‘)’ ，我们先弹出栈顶元素表示匹配了当前右括号：

    - 如果栈为空，说明当前的右括号为没有被匹配的右括号，
    我们将其下标放入栈中来更新我们之前提到的「最后一个没有被匹配的右括号的下标」
    - 如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」

我们从前往后遍历字符串并更新答案即可。

需要注意的是，如果一开始栈为空，第一个字符为左括号的时候我们会将其放入栈中，
这样就不满足提及的「最后一个没有被匹配的右括号的下标」，为了保持统一，
我们在一开始的时候往栈中放入一个值为−1 的元素。

复杂度分析
时间复杂度： O(n)，n 是给定字符串的长度。我们只需要遍历字符串一次即可。
空间复杂度：O(n)。栈的大小在最坏情况下会达到n，因此空间复杂度为O(n) 。

 */