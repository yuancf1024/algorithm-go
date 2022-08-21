/**
 * @file 6157.Time-Needed-to-Rearrange-a-Binary-String.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * leetcode-6157.二进制字符串重新安排顺序需要的时间
 * 
给你一个二进制字符串 s 。在一秒之中，所有 子字符串 "01" 同时 
被替换成 "10" 。这个过程持续进行到没有 "01" 存在。

请你返回完成这个过程所需要的秒数。

示例 1：
输入：s = "0110101"
输出：4

解释：
一秒后，s 变成 "1011010" 。
再过 1 秒后，s 变成 "1101100" 。
第三秒过后，s 变成 "1110100" 。
第四秒后，s 变成 "1111000" 。
此时没有 "01" 存在，整个过程花费 4 秒。
所以我们返回 4 。

示例 2：
输入：s = "11100"
输出：0
解释：
s 中没有 "01" 存在，整个过程花费 0 秒。
所以我们返回 0 。
 
提示：

1 <= s.length <= 1000
s[i] 要么是 '0' ，要么是 '1' 。

 */

// 参考@灵茶山艾府 一次遍历 不太好理解
class Solution {
public:
    int secondsToRemoveOccurrences(string s) { 
        int f = 0, pre0 = 0;
        for (char c : s) {
            if (c == '0') {
                ++pre0;
            }
            else if (pre0) {
                f = max(f + 1, pre0); // 前面有0的时候才会移动
            }
        }
        return f;
    }
};

// 暴力解法
class Solution {
public:
    int secondsToRemoveOccurrences(string s) { 
        int res = 0; 
        while (change(s)) {
            res++;
        }
        return res;
    }

    // 辅函数
    bool change(string& s) { 
        int n = s.size(), i = 0;
        bool f = false;
        while (i < n-1) {
            if (s[i] == '0' && s[i+1] == '1') {
                s[i] = '1';
                s[i + 1] = '0';
                i += 2;
                f = true;
            } else {
                i++;
            }
        }
        return f;
    }
};

/**
 * @brief 
 * 参考@灵茶山艾府
 * O(n)操作可参考 https://leetcode.cn/problems/time-needed-to-rearrange-a-binary-string/solution/by-newhar-o6a1/
把替换操作看成是1同时往左移动（如果左侧为0的话）。

定义f[i]表示把s的前i个字符完成移动所需的秒数。

- 如果s[i]=0，则 f[i]=f[i−1]。

- 如果s[i]=1，记前i个字符中0 的个数为pre_0，则f[i] 至少为 pre_0。
如果s[i]在移动的过程中被前面的1堵住了，那么必须要等前面空出
一个 0才能继续移动；另外，一旦前面空出了0，说明前方「道路通畅」，
后续移动不会出现堵车，因此 f[i]=f[i−1]+1。

这两者取最大值，即

f[i]=max(f[i−1]+1,pre_0)

答案为f[n−1]。

代码实现时f可以压缩成一个变量。

复杂度分析
时间复杂度：O(n)，其中n为s的长度。
空间复杂度：O(1)，仅用到若干变量。
 */