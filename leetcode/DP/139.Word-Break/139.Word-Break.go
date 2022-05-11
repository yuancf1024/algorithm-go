package leetcode

/* 139. 单词拆分
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
请你判断是否可以利用字典中出现的单词拼接出 s 。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true

解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/

// 参考算法模板 不好理解
func wordBreak(s string, wordDict []string) bool {
	// f[i] 表示前i个字符是否可以被切分
	// f[i] = f[j] && s[j+1~i] in wordDict
	// f[0] = true
	// return f[len]

	if len(s) == 0 { // 给定字符为空的边界情况
		return true
	}
	f := make([]bool, len(s)+1)
	f[0] = true
	max, dict := maxLen(wordDict) // 记录字符串列表中最长字符串数量，以及哈希表
	for i := 1; i <= len(s); i++ {
		l := 0
		if i - max > 0 {
			l = i - max
		}
		for j := l; j < i; j++ {
			if f[j] && inDict(s[j:i], dict) {
				f[i] = true
				break
			}
		}
	}
	return f[len(s)]
}

func maxLen(wordDict []string) (int, map[string]bool) {
	dict := make(map[string]bool)
	max := 0
	for _, v := range wordDict {
		dict[v] = true
		if len(v) > max {
			max = len(v)
		}
	}
	return max, dict
}

func inDict(s string, dict map[string]bool) bool {
	_, ok := dict[s]
	return ok
}
/*

*/