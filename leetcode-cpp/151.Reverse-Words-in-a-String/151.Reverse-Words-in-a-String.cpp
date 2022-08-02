/**
 * @file 151.Reverse-Words-in-a-String.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 151. 颠倒字符串中的单词
 * 给你一个字符串 s ，颠倒字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 
单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。
返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

 
示例 1：

输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：

输入：s = "  hello world  "
输出："world hello"
解释：颠倒后的字符串中不能存在前导空格和尾随空格。

示例 3：

输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，颠倒后的字符串需要将单词间的空格减少到仅有一个。
 
提示：

1 <= s.length <= 10^4
s 包含英文大小写字母、数字和空格 ' '
s 中 至少存在一个 单词
 

进阶：如果字符串在你使用的编程语言中是一种可变数据类型，
请尝试使用 O(1) 额外空间复杂度的 原地 解法。

 */

// 参考代码随想录 版本一
class Solution {
public:
    // 反转字符串s中左闭右闭的区间[start, end]
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    // 移除冗余空格：使用双指针(快慢指针法)O(n)的算法
    void removeExtraSpaces(string& s) { 
        int slowIndex = 0, fastIndex = 0; // 定义快慢指针
        // 去掉字符串前面的空格
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            // 去掉字符串中间部分的冗余空格
            if (fastIndex - 1 > 0 && s[fastIndex-1] == s[fastIndex] && s[fastIndex] == ' ') {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex-1] == ' ') {
            // 去掉末尾字符串的空格
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); // 重新设置字符串大小
        }
    }

    string reverseWords(string s) { 
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            // 查找单词间的空格，翻转单词
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            reverse(s, i, j - 1);
            i = j;
        }
        return s;
    }
};

// 方法1的简洁实现
class Solution {
public:
    void reverse(string& s, int start, int end) { // 翻转，区间写法: 闭区间 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    // 是实现的非常巧妙
    void removeExtraSpaces(string& s) { // 去除所有空格并在相邻单词之间添加空格，快慢指针
        int slow = 0; // 整体思想参考 Leetcode: 27. 移除元素：https://leetcode.cn/problems/remove-element/
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') { // 遇到非空格就处理，即删除所有空格
                if (slow != 0) {
                    s[slow++] = ' '; // 手动控制空格，给单词之间添加空格。slow != 0 说明不是第一个单词，需要在单词前添加空格
                }
                while (i < s.size() && s[i] != ' ') { // 补上该单词，遇到空格说明单词结束
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); // slow的大小即为去除多余空格后的大小
    }

    string reverseWords(string s) { 
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0; // removeExtraSpaces 后保证第一个单词的开始下标一定是0
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { // 到达空格或者串尾，说明一个单词结束。进行翻转
                reverse(s, start, i - 1); // 翻转，注意是左闭右闭的翻转
                start = i + 1; // 更新下一个单词的开始下标start
            }
        }
        return s;
    }
};

/**
 * @brief 
 * 思路
这道题目可以说是综合考察了字符串的多种操作。

一些同学会使用split库函数，分隔单词，然后定义一个新的string字符串，
最后再把单词倒序相加，那么这道题题目就是一道水题了，失去了它的意义。

所以这里我还是提高一下本题的难度：不要使用辅助空间，空间复杂度要求为O(1)。

不能使用辅助空间之后，那么只能在原字符串上下功夫了。

想一下，我们将整个字符串都反转过来，那么单词的顺序指定是倒序了，
只不过单词本身也倒序了，那么再把单词反转一下，单词不就正过来了。

所以解题思路如下：

- 移除多余空格
- 将整个字符串反转
- 将每个单词反转

举个例子，源字符串为："the sky is blue "

- 移除多余空格 : "the sky is blue"
- 字符串反转："eulb si yks eht"
- 单词反转："blue is sky the"

这样我们就完成了翻转字符串里的单词。

思路很明确了，我们说一说代码的实现细节，就拿移除多余空格来说，
一些同学会上来写如下代码：
void removeExtraSpaces(string& s) {
    for (int i = s.size() - 1; i > 0; i--) {
        if (s[i] == s[i - 1] && s[i] == ' ') {
            s.erase(s.begin() + i);
        }
    }
    // 删除字符串最后面的空格
    if (s.size() > 0 && s[s.size() - 1] == ' ') {
        s.erase(s.begin() + s.size() - 1);
    }
    // 删除字符串最前面的空格
    if (s.size() > 0 && s[0] == ' ') {
        s.erase(s.begin());
    }
}

逻辑很简单，从前向后遍历，遇到空格了就erase。

如果不仔细琢磨一下erase的时间复杂度，还以为以上的代码
是O(n)的时间复杂度呢。

想一下真正的时间复杂度是多少，一个erase本来就是O(n)的操作，

erase操作上面还套了一个for循环，那么以上代码移除冗余空格的代码时间复杂度为O(n^2)。

那么使用双指针法来去移除空格，最后resize（重新设置）一下字符串的大小，
就可以做到O(n)的时间复杂度。

那么使用双指针来移除冗余空格代码如下： fastIndex走的快，
slowIndex走的慢，最后slowIndex就标记着移除多余空格后新字符串的长度。


有的同学可能发现用erase来移除空格，在leetcode上性能也还行。
主要是以下几点；：

1. leetcode上的测试集里，字符串的长度不够长，
如果足够长，性能差距会非常明显。
2. leetcode的测程序耗时不是很准确的。

此时我们已经实现了removeExtraSpaces函数来移除冗余空格。

还做实现反转字符串的功能，支持反转字符串子区间，
这个实现我们分别在344.反转字符串 和541.反转字符串II 里已经讲过了。
代码如下：

// 反转字符串s中左闭又闭的区间[start, end]
void reverse(string& s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}
 */