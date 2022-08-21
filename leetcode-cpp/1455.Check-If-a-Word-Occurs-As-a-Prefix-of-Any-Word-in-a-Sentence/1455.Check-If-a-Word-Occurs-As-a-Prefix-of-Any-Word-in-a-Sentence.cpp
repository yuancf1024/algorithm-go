/**
 * @file 1455.Check-If-a-Word-Occurs-As-a-Prefix-of-Any-Word-in-a-Sentence.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1455.检查单词是否为句中其他单词的前缀
 * 
给你一个字符串 sentence 作为句子并指定检索词为 searchWord ，
其中句子由若干用 单个空格 分隔的单词组成。
请你检查检索词 searchWord 是否为句子 sentence 中任意单词的前缀。

如果 searchWord 是某一个单词的前缀，
则返回句子 sentence 中该单词所对应的下标（下标从 1 开始）。
如果 searchWord 是多个单词的前缀，则返回匹配的第一个单词的下标（最小下标）。
如果 searchWord 不是任何单词的前缀，则返回 -1 。

字符串 s 的 前缀 是 s 的任何前导连续子字符串。

示例 1：
输入：sentence = "i love eating burger", searchWord = "burg"
输出：4
解释："burg" 是 "burger" 的前缀，而 "burger" 是句子中第 4 个单词。

示例 2：
输入：sentence = "this problem is an easy problem", searchWord = "pro"
输出：2
解释："pro" 是 "problem" 的前缀，而 "problem" 是句子中第 2 个也是第 6 个单词，但是应该返回最小下标 2 。

示例 3：
输入：sentence = "i am tired", searchWord = "you"
输出：-1
解释："you" 不是句子中任何单词的前缀。

提示：

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence 由小写英文字母和空格组成。
searchWord 由小写英文字母组成。

 */

// 双指针
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size(), index = 1, start = 0, end = 0;
        while (start < n) {
            while (end < n && sentence[end] != ' ') { // 遍历完单个单词
                end++;
            }
            if (isPrefix(sentence, start, end, searchWord)) {
                return index;
            }

            index++;
            end++;
            start = end;
        }
        return -1;
    }

    // 辅函数
    bool isPrefix(const string& sentence, int start, int end, const string& searchWord) {
        for (int i = 0; i < searchWord.size(); ++i) {
            if (start + i >= end || sentence[start+i] != searchWord[i]) {
                return false;
            }
        }
        return true;
    }
};

/**
 * @brief 参考leetcode官方题解
 * 方法一：双指针
使用start 记录单词的起始，end 记录单词结尾的下一个位置。
我们遍历字符串sentence 并不断地分割单词，
对于区间[start,end) 对应的单词，判断它是否存在某一前缀等于searchWord，
如果存在直接返回该单词对应的下标index；
如果遍历完所有单词都不符合条件，返回−1。

复杂度分析
时间复杂度：O(n)，其中n 是sentence 的长度。
遍历字符串sentence 需要O(n)，
前缀判断函数isPrefix 的总时间复杂度为O(n)。

空间复杂度：O(1)，只需要额外的常数级别的空间。
 */