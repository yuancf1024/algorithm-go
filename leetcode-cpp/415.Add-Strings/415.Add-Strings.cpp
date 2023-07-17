/**
 * @file 415.Add-Strings.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-415.字符串相加
 * @version 0.1
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) 2023
 * 
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

 

示例 1：

输入：num1 = "11", num2 = "123"
输出："134"
示例 2：

输入：num1 = "456", num2 = "77"
输出："533"
示例 3：

输入：num1 = "0", num2 = "0"
输出："0"
 

 

提示：

1 <= num1.length, num2.length <= 104
num1 和num2 都只包含数字 0-9
num1 和num2 都不包含任何前导零
 */

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }

        // 计算完以后的答案需要翻转过来
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string s1 = "11";
    string s2 = "123";

    string res = Solution().addStrings(s1, s2);

    cout << res << endl;

    return 0;
}

/**
 * @brief leetcode官方题解
 * 
方法一：模拟
思路与算法

本题我们只需要对两个大整数模拟「竖式加法」的过程。
竖式加法就是我们平常学习生活中常用的对两个整数相加
的方法，回想一下我们在纸上对两个整数相加的操作，
是不是如下图将相同数位对齐，从低到高逐位相加，
如果当前位和超过10，则向高位进一位？
因此我们只要将这个过程用代码写出来即可。

具体实现也不复杂，我们定义两个指针i和j分别指向 
num1和num2的末尾，即最低位，同时定义一个变量add
维护当前是否有进位，然后从末尾到开头逐位相加即可。
你可能会想两个数字位数不同怎么处理，这里我们统一
在指针当前下标处于负数的时候返回0，
等价于对位数较短的数字进行了补零操作，
这样就可以除去两个数字位数不同情况的处理，
具体可以看下面的代码。

复杂度分析

时间复杂度：O(max(len1,len2))，
其中len1=num1.length，len2=num2.length。
竖式加法的次数取决于较大数的位数。

空间复杂度：O(1)。除答案外我们只需要常数空间
存放若干变量。在 Java 解法中使用到了StringBuffer，
故 Java 解法的空间复杂度为O(n)。
 */