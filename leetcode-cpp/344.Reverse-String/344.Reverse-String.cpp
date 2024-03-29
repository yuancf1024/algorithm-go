/**
 * @file 344.Reverse-String.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 344. 反转字符串
 * 编写一个函数，其作用是将输入的字符串反转过来。
 * 输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，
你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

示例 1：

输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]

示例 2：

输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
 
提示：

1 <= s.length <= 10^5
s[i] 都是 ASCII 码表中的可打印字符

 */

#include <bits/stdc++.h>

using namespace std;

// 自己实现 双指针
class Solution {
public:
    void reverseString(vector<char>& s) { 
        int left = 0, right = s.size()-1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        // return s;
    }
};

// 参考代码随想录
class Solution1 {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};

// 2023-08更精细化的实现
class Solution2 {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0, j = n-1; i < j; i++, j--) {
            char t;
            t = s[i];
            s[i] = s[j];
            s[j] = t;
        }
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution2().reverseString(s);
    // 打印s
    for (auto & a : s) {
        cout << a << endl;
    }

    return 0;
}

/*
思路

双指针

代码随想录的思路

先说一说题外话：

对于这道题目一些同学直接用C++里的一个库函数 reverse，
调一下直接完事了， 相信每一门编程语言都有这样的库函数。

如果这么做题的话，这样大家不会清楚反转字符串的实现原理了。

但是也不是说库函数就不能用，是要分场景的。

如果在现场面试中，我们什么时候使用库函数，什么时候不要用库函数呢？

如果题目关键的部分直接用库函数就可以解决，建议不要使用库函数。

毕竟面试官一定不是考察你对库函数的熟悉程度， 
如果使用python和java 的同学更需要注意这一点，
因为python、java提供的库函数十分丰富。

如果库函数仅仅是 解题过程中的一小部分，并且你已经很清楚这个
库函数的内部实现原理的话，可以考虑使用库函数。

建议大家平时在leetcode上练习算法的时候本着这样的原则去练习，
这样才有助于我们对算法的理解。

不要沉迷于使用库函数一行代码解决题目之类的技巧，不是说这些技巧不好，
而是说这些技巧可以用来娱乐一下。

真正自己写的时候，要保证理解可以实现是相应的功能。

接下来再来讲一下如何解决反转字符串的问题。

大家应该还记得，我们已经讲过了206.反转链表 。

在反转链表中，使用了双指针的方法。

那么反转字符串依然是使用双指针的方法，只不过对于字符串的反转，
其实要比链表简单一些。

因为字符串也是一种数组，所以元素在内存中是连续分布，
这就决定了反转链表和反转字符串方式上还是有所差异的。

对于字符串，我们定义两个指针（也可以说是索引下标），一个从字符串前面，
一个从字符串后面，两个指针同时向中间移动，并交换元素。

swap可以有两种实现

一种就是常见的交换数值：

int tmp = s[i];
s[i] = s[j];
s[j] = tmp;

一种就是通过位运算：

s[i] ^= s[j];
s[j] ^= s[i];
s[i] ^= s[j];
*/