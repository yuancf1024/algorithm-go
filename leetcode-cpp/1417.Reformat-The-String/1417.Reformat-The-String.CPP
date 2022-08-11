/**
 * @file 1417.Reformat-The-String.CPP
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * LEETCODE-1417.重新格式化字符串
 * 
给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。

请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。
也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。

请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，
则返回一个 空字符串 。

 

示例 1：
输入：s = "a0b1c2"
输出："0a1b2c"
解释："0a1b2c" 中任意两个相邻字符的类型都不同。
 "a0b1c2", "0a1b2c", "0c2a1b" 也是满足题目要求的答案。

示例 2：
输入：s = "leetcode"
输出：""
解释："leetcode" 中只有字母，所以无法满足重新格式化的条件。

示例 3：
输入：s = "1229857369"
输出：""
解释："1229857369" 中只有数字，所以无法满足重新格式化的条件。

示例 4：
输入：s = "covid2019"
输出："c2o0v1i9d"

示例 5：
输入：s = "ab123"
输出："1a2b3"
 
提示：

1 <= s.length <= 500
s 仅由小写英文字母和/或数字组成。
 */

class Solution {
public:
    string reformat(string s) { 
        int sum_digit = 0;
        for (auto& c : s) {
            if (isdigit(c)) {
                sum_digit++;
            }
        }
        int sum_alpha = s.size() - sum_digit;
        if (abs(sum_digit - sum_alpha) > 1) {
            return "";
        }
        bool flag = sum_digit > sum_alpha;
        /*只处理不合理情况，偶数位i应放置个数多的字符类型，奇数位j应放置个数少的字符类型*/
        for (int i = 0, j = 1; i < s.size(); i += 2) {
            if (isdigit(s[i]) != flag) { // s[i] 为个数少的字符类型时
                while (isdigit(s[j]) != flag) { // s[j]为个数少的字符类型时，向右移动
                    j += 2;
                }
                swap(s[i], s[j]); // s[j] 为字符个数多的字符
            }
        }
        return s;
    }
};

/**
 * @brief 
方法一：双指针
思路与算法

题目给定字符串 s，我们记 sum_digit 为字符串中数字的个数，
sum_alpha 为字符串中字母的个数。
那么能按照题目要求格式化字符串的充要条件为：
∣sum_digit−sum_alpha∣≤1
那么当给定字符串 s 满足上述条件时，
我们把数字和字母中个数多的放在偶数位上（字符串下标从 0开始），
个数少的放在奇数位上，此时可以构造出满足题目条件的字符串。
那么我们用 i 和 j 来分别表示个数多的和个数少的字符放置的下标，
初始为i=0,j=1，然后从左到右移动 i，当 s[i] 为个数少的字符类型时，
那么向右移动 j 找到往后的第一个 s[j] 为个数多的字符类型，
然后交换两个字符即可，不断重复该过程直至 i 移动到字符串结尾即可。

复杂度分析
时间复杂度：O(n)，其中 n 为字符串 s 的长度，需要遍历两遍字符串。
空间复杂度：对于字符串可变的语言为 O(1)，仅使用常量空间。
而对于字符串不可变的语言需要新建一个和 s 等长的字符串，
所以空间复杂度是 O(n)。

反思：本题的总体思路是对的，但是一些细节的处理没有leetcode官方解答好。
 */

// 2022-08-11 自己实现
class Solution {
public:
    string reformat(string s) {
        vector<char> alpha;
        vector<int> num;
        for (auto i : s) {
            if (i >= '0' && i <= '9') {
                num.push_back(i);
            } else if (i >= 'a' && i <= 'z') {
                alpha.push_back(i);
            }
        }
        // if (num.size()-alpha.size() > 1 || num.size()-alpha.size() <= -1) {
        //     return "";
        // }
        string res;
        // for (int i = 0; i < num.size(); ++i) {
        //     res.push_back(num[i]);
        //     res.push_back(alpha[i]);
        // }
        if (num.size() > alpha.size()) {
            for (int i = 0; i < alpha.size(); ++i) {
                res.push_back(num[i]);
                res.push_back(alpha[i]);
            }
            res.push_back(num.back());
        } else {
            for (int i = 0; i < num.size(); ++i) {
                res.push_back(alpha[i]);
                res.push_back(num[i]);
            }
            res.push_back(alpha.back());
        }
        return res;
    }
};

/*
思路：
首先统计字符串s中字母和数字的个数，如果字母与数字个数的差值的绝对值不超过2，进入下面的处理，
否则直接输出""
用两个vector数组分别保存字母和数字，然后交替放入到字符串中，输出。
存在的问题：
一些边界情况处理不好：
如字符串中字母数字一样的情况
通过测试用例：
241 / 302
输入：
"a0b1c2"
输出：
"a0b1c2c"
预期结果：
"0a1b2c"
*/