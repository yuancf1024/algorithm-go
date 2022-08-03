/**
 * @file 3.Longest-Substring-Without-Repeating-Characters.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-03
 * 
 * @copyright Copyright (c) 2022
 * leetocde-3. 无重复字符的最长子串
 * 
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 
提示：

0 <= s.length <= 5 * 10^4
s 由英文字母、数字、符号和空格组成

 */


// 参考halfrost
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 考虑边界情况
        int n = s.size();
        if (n == 0) {
            return 0;
        }

        vector<int> freq(127);
        int result = 0, left = 0, right = -1;

        while (left < n) {
            if (right + 1 < n && freq[s[right+1]] == 0) {
                freq[s[right + 1]]++;
                right++;
            } else {
                freq[s[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

/*
考察滑动窗口、哈希表、字符串
*/