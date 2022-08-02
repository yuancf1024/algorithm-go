/**
 * @file 541.Reverse-String-II.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * leetcode-541. 反转字符串 II
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，
 * 就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，
其余字符保持原样。
 

示例 1：
输入：s = "abcdefg", k = 2
输出："bacdfeg"

示例 2：
输入：s = "abcd", k = 2
输出："bacd"
 
提示：

1 <= s.length <= 10^4
s 仅由小写英文组成
1 <= k <= 10^4
 */

// 参考代码随想录
// 使用C++库函数reverse
class Solution {
public:
    string reverseStr(string s, int k) { 
        for (int i = 0; i < s.size(); i += (2*k)) {
            // 1. 每隔2k个字符的前k个字符进行反转
            // 2. 剩余字符小于2k但大于等于k个，则反转前k个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                // 3. 剩余字符少于k个，则将剩余字符全部反转
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

// 自行实现reverse函数，区间左闭右闭
class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    
    string reverseStr(string s, int k) { 
        for (int i = 0; i < s.size(); i += (2 * k) {
            // 1. 每隔2k个字符的前k个字符进行反转
            // 2. 剩余字符小于2k但大于等于k个，则反转前k个字符
            if (i + k <= s.size()) {
                reverse(s, i, i + k - 1);
                continue;
            }
            // 3. 剩余字符少于k个，则将剩余字符全部反转
            reverse(s, i, s.size() - 1);
        }
        return s;
    }
};


/*
思路

这道题目其实也是模拟，实现题目中规定的反转规则就可以了。

一些同学可能为了处理逻辑：每隔2k个字符的前k的字符，
写了一堆逻辑代码或者再搞一个计数器，来统计2k，再统计前k个字符。

其实在遍历字符串的过程中，只要让 i += (2 * k)，
i 每次移动 2 * k 就可以了，然后判断是否需要有反转的区间。

因为要找的也就是每2 * k 区间的起点，这样写，程序会高效很多。

所以当需要固定规律一段一段去处理字符串的时候，
要想想在在for循环的表达式上做做文章。

性能如下： 

那么这里具体反转的逻辑我们要不要使用库函数呢，
其实用不用都可以，使用reverse来实现反转也没毛病，
毕竟不是解题关键部分。
*/