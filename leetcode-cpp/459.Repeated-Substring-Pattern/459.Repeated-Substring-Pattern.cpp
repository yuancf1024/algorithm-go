/**
 * @file 459.Repeated-Substring-Pattern.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * leetcode-459. 重复的子字符串
 * 
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

 

示例 1:

输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。

示例 2:

输入: s = "aba"
输出: false

示例 3:

输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 

提示：

1 <= s.length <= 10^4
s 由小写英文字母组成
 * 
 */

// 参考代码随想录
class Solution {
public:
    void getNext(int* next, const string& s) { 
        int j = -1;
        next[0] = -1;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j+1]) {
                j = next[j];
            }
            if (s[i] == s[j+1]) {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len-1] != -1 && len % (len - (next[len-1] + 1)) == 0) {
            return true;
        }
        return false;
    }
};

/**
 * @brief 
 * 思路
这又是一道标准的KMP的题目。

如果KMP还不够了解，可以看我的B站：

我们在字符串：KMP算法精讲 里提到了，在一个串中查找是否出现过另一个串，
这是KMP的看家本领。

那么寻找重复子串怎么也涉及到KMP算法了呢？

这里就要说一说next数组了，next 数组记录的就是最长相同前后缀
这里介绍了什么是前缀，什么是后缀，什么又是最长相同前后缀)， 
如果 next[len - 1] != -1，则说明字符串有最长相同的前后缀
（就是字符串里的前缀子串和后缀子串相同的最长长度）。

最长相等前后缀的长度为：next[len - 1] + 1。
(这里的next数组是以统一减一的方式计算的，因此需要+1)

数组长度为：len。

如果len % (len - (next[len - 1] + 1)) == 0 ，则说明 
(数组长度-最长相等前后缀的长度) 正好可以被 数组的长度整除，
说明有该字符串有重复的子字符串。

数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，
也就是一个周期的长度，如果这个周期可以被整除，
就说明整个数组就是这个周期的循环。

强烈建议大家把next数组打印出来，看看next数组里的规律，有助于理解KMP算法

如图：

字符串：            a  s  d  f  a  s  d  f  a  s  d  f

对应的next数组的值：-1 -1 -1 -1  0  1  2  3  4  5  6  7

next[len - 1] = 7，next[len - 1] + 1 = 8，
8就是此时字符串asdfasdfasdf的最长相同前后缀的长度。

(len - (next[len - 1] + 1)) 也就是： 
12(字符串的长度) - 8(最长公共前后缀的长度) = 4， 
4正好可以被 12(字符串的长度) 整除，所以说明有重复的子字符串（asdf）。

C++代码如下：（这里使用了前缀表统一减一的实现方式）
 */