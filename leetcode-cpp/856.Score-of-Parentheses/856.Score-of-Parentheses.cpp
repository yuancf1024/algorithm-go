/**
 * @file 856.Score-of-Parentheses.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * leetcode-856.括号的分数
 * 给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：

() 得 1 分。
AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
(A) 得 2 * A 分，其中 A 是平衡括号字符串。

示例 1：
输入： "()"
输出： 1

示例 2：
输入： "(())"
输出： 2

示例 3：
输入： "()()"
输出： 2

示例 4：
输入： "(()(()))"
输出： 6

提示：

S 是平衡括号字符串，且只含有 ( 和 ) 。
2 <= S.length <= 50

 */

#include <bits/stdc++.h>

using namespace std;

// 方法1：分治法
class Solution {
public:
    int scoreOfParentheses(string s) {
        if (s.size() == 2) {
            return 1;
        }
        int bal = 0, n = s.size(), len;
        for (int i = 0; i < n; ++i) {
            bal += (s[i] == '(' ? 1 : -1);
            if (bal == 0) { // 如果s的某个非空前缀对应的和bal=0
                len = i + 1; // 那么这个前缀就是一个平衡括号字符串
                break;
            }
        }
        if (len == n) { // 如果该前缀长度等于s的长度，那么s可以分解为(A)的形式
            return 2 * scoreOfParentheses(s.substr(1, n - 2));
        }
        else {
            return scoreOfParentheses(s.substr(0, len)) +
                   scoreOfParentheses(s.substr(len, n - len));
        }
    }
};

/**
 * @brief 
 * 方法一：分治
根据题意，一个平衡括号字符串s可以被分解为A+B或(A)的形式，
因此我们可以对s进行分解，分而治之。

如何判断s应该分解为A+B或(A)的哪一种呢？
我们将左括号记为1，右括号记为−1，如果s的某个非空前缀对应的和bal=0，
那么这个前缀就是一个平衡括号字符串。如果该前缀长度等于s的长度，
那么s可以分解为(A)的形式；否则s可以分解为A+B 的形式，
其中A为该前缀。将s分解之后，我们递归地求解子问题，
并且s的长度为2时，分数为1。

复杂度分析

时间复杂度：O(n^2)，其中n是字符串的长度。递归深度为O(n)，
每一层的所有函数调用的总时间复杂度都是O(n)，
因此总时间复杂度为 O(n^2)。

空间复杂度：O(n^2)。每一层都需要将字符串复制一遍，
因此总空间复杂度为 O(n^2)。对于字符串支持切片的语言，
空间复杂度为递归栈所需的空间O(n)。
 */

// 方法二：栈 不是很好理解
class Solution {
public:
    int scoreOfParentheses(string s) { 
        stack<int> st;
        st.push(0);
        for (auto& c : s) {
            if (c == '(') {
                st.push(0);
            }
            else {
                int v = st.top();
                st.pop();
                st.top() += max(2 * v, 1);
            }
        }
        return st.top();
    }
};

/**
 * @brief
 *方法二：栈
我们把平衡字符串s看作是一个空字符串加上s本身，
并且定义空字符串的分数为0。使用栈st记录平衡字符串的分数，
在开始之前要压入分数0，表示空字符串的分数。

在遍历字符串s的过程中：

- 遇到左括号，那么我们需要计算该左括号内部的子平衡括号字符串A的分数，
我们也要先压入分数0，表示A前面的空字符串的分数。

- 遇到右括号，说明该右括号内部的子平衡括号字符串A的分数已经计算出来了，
我们将它弹出栈，并保存到变量v 中。如果v=0，
那么说明子平衡括号字符串A是空串，(A)的分数为1，
否则(A)的分数为2v，然后将(A) 的分数加到栈顶元素上。

遍历结束后，栈顶元素保存的就是s的分数。

复杂度分析
时间复杂度：O(n)，其中n是字符串的长度。
空间复杂度：O(n)。栈需要O(n)的空间。
 */

// 方法三：计算最终分数和
class Solution {
public:
    int scoreOfParentheses(string s) { 
        int bal = 0, n = s.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            bal += (s[i] == '(' ? 1 : -1);
            if (s[i] == ')' && s[i-1] == '(') {
                res += 1 << bal;
            }
        }
        return res;
    }
};

/**
 * @brief 
 * 方法三：计算最终分数和
根据题意，s的分数与1分的()有关。对于每个()，
它的最终分数与它所处的深度有关，如果深度为bal，
那么它的最终分数为2^bal。我们统计所有() 的最终分数和即可。

复杂度分析
时间复杂度：O(n)，其中n是字符串的长度。
空间复杂度：O(1)。
 */