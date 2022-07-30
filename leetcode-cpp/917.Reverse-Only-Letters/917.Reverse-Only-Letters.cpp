/* 917. 仅仅反转字母
给你一个字符串 s ，根据下述规则反转字符串：

- 所有非英文字母保留在原有位置。
- 所有英文字母（小写或大写）位置反转。
返回反转后的 s 。

示例 1：
输入：s = "ab-cd"
输出："dc-ba"

示例 2：
输入：s = "a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"

示例 3：
输入：s = "Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-T!"

提示

1 <= s.length <= 100
s 仅由 ASCII 值在范围 [33, 122] 的字符组成
s 不含 '\"' 或 '\\'
*/

class Solution {
public:
    string reverseOnlyLetters(string s) { 
        int n = s.size();
        int left = 0, right = n - 1;
        while (true) {
            while (left < right && !isalpha(s[left])) { // 判断左边是否扫描到字母
                left++;
            }
            while (left < right && !isalpha(s[right])) { // 判断右边是否扫描到数组
                right--;
            }
            if (left >= right) {
                break;
            }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};

/* 参考leetcode题解

思路与算法
我们使用 left 指针从左边开始扫描字符串 s，right 指针从右边开始扫描字符串 s。
如果两个指针都扫描到字母，且 left<right，那么交换 s[left] 和 s[right]，
然后继续进行扫描；
否则表明反转过程结束，返回处理后的字符串。

复杂度分析
- 时间复杂度：O(n)，其中 n 是字符串 s 的长度。
反转过程需要 O(n)，C 语言计算字符串长度需要 O(n)。

- 空间复杂度：O(1) 或 O(n)。
某些语言字符串不可变，需要 O(n) 的额外空间。
*/