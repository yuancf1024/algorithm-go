/**
 * @file 1768.Merge-Strings-Alternately.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-23
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1768.交替合并字符串
 * 给你两个字符串 word1 和 word2 。
 * 请你从 word1 开始，通过交替添加字母来合并字符串。
 * 如果一个字符串比另一个字符串长，就将多出来的字母追
 * 加到合并后字符串的末尾。

返回 合并后的字符串 。

示例 1：
输入：word1 = "abc", word2 = "pqr"
输出："apbqcr"

解释：字符串合并情况如下所示：
word1：  a   b   c
word2：    p   q   r
合并后：  a p b q c r

示例 2：
输入：word1 = "ab", word2 = "pqrs"
输出："apbqrs"

解释：注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
word1：  a   b 
word2：    p   q   r   s
合并后：  a p b q   r   s

示例 3：
输入：word1 = "abcd", word2 = "pq"
输出："apbqcd"

解释：注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
word1：  a   b   c   d
word2：    p   q 
合并后：  a p b q c   d

提示：
1 <= word1.length, word2.length <= 100
word1 和 word2 由小写英文字母组成
 */

#include <bits/stdc++.h>

using namespace std;

// 参考leetcode官方题解 双指针
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int i = 0, j = 0;

        string res;
        res.reserve(m + n);
        while (i < m || j < n) { // 使用双指针巧妙地解决了2个字符串长度不同的情况
            if (i < m) {
                res.push_back(word1[i]);
                ++i;
            }
            if (j < n) {
                res.push_back(word2[j]);
                ++j;
            }
        }
        return res;
    }
};

// 精简版
class Solution {
public:
    string mergeAlternately(string word1, string word2) { 
        string res;
        int i = 0, j = 0, m = word1.size(), n = word2.size();
        while (i < m || j < n) {
            if (i < m) {
                res.push_back(word1[i++]);
            }
            if (j < n) {
                res.push_back(word2[j++]);
            }
        }
        return res;
    }
};
/**
 * @brief
 * 思路与算法

我们直接按照题目的要求模拟即可。我们使用两个指针i和j，
初始时分别指向两个字符串的首个位置。
随后的每次循环中，依次进行如下的两步操作：

- 如果i没有超出word_1的范围，就将word_1[i] 加入答案，
并且将i移动一个位置；
- 如果j没有超出word_2的范围，就将word_2[j] 加入答案，
并且将j移动一个位置。

当i和j都超出对应的范围后，结束循环并返回答案即可。


复杂度分析

时间复杂度：O(m+n)，其中m和n分别是字符串word_1和word_2的长度。
空间复杂度：O(1)或O(m+n)。
如果使用的语言支持可修改的字符串，那么空间复杂度为O(1)，
否则为O(m+n)。注意这里不计入返回值需要的空间。
 */

// 自己写的代码，不够简洁
class Solution {
public:
    // 思路：考虑3种情况
    // s1 > s2, s1 == s2, s1 < s2
    // 代码写得不够简洁，如何重构？
    string mergeAlternately(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size();
        string res = "";
        if (s1 == s2) {
            for (int i = 0; i < s1; ++i) {
                res += word1[i];
                res += word2[i];
            }
        }
        if (s1 > s2) {
            for (int i = 0; i < s2; ++i) {
                res += word1[i];
                res += word2[i];
            }
            for (int j = s2; j < s1; ++j) {
                res += word1[j];
            }
        }
        if (s1 < s2) {
            for (int i = 0; i < s1; ++i) {
                res += word1[i];
                res += word2[i];
            }
            for (int j = s1; j < s2; ++j) {
                res += word2[j];
            }
        }
        return res;
    }
};