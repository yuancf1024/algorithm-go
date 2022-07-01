package leetcode

/* 820. 单词的压缩编码
单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices 组成，
且满足：

- words.length == indices.length
- 助记字符串 s 以 '#' 字符结尾
- 对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#'
字符结束（但不包括 '#'）的 子字符串 恰好与 words[i] 相等

给你一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s
的长度 。

示例 1：
输入：words = ["time", "me", "bell"]
输出：10
解释：一组有效编码为 s = "time#bell#" 和 indices = [0, 2, 5] 。

words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#' 结束的子字符串，
如加粗部分所示 "time#bell#"
words[1] = "me" ，s 开始于 indices[1] = 2 到下一个 '#' 结束的子字符串，
如加粗部分所示 "time#bell#"
words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#' 结束的子字符串，
如加粗部分所示 "time#bell#"

示例 2：
输入：words = ["t"]
输出：2
解释：一组有效编码为 s = "t#" 和 indices = [0] 。

提示：

1 <= words.length <= 2000
1 <= words[i].length <= 7
words[i] 仅由小写字母组成
*/

// 解法1 暴力解法
func minimumLengthEncoding(words []string) int {
	res, m := 0, map[string]bool{}
	for _, w := range words { // 先将所有的单词放入字典中
		m[w] = true
	}
	for w := range m { // 针对字典中的每个单词，逐一从字典中删掉自己的子字符串
		for i := 1; i < len(w); i++ {
			delete(m, w[i:])
		}
		/*这样有相同后缀的字符串被删除了，字典中剩下的都是没有共同前缀的*/
	}
	for w := range m { // 最终的答案是剩下所有单词用 # 号连接之后的总长度
		res += len(w) + 1
	}
	return res
}

// 解法2 Trie 字典树
type node struct {
	value byte
	sub   []*node
}

func (t *node) has(b byte) (*node, bool) {
	if t == nil {
		return nil, false
	}
	for i := range t.sub {
		if t.sub[i] != nil && t.sub[i].value == b {
			return t.sub[i], true
		}
	}
	return nil, false
}

func (t *node) isLeaf() bool {
	if t == nil {
		return false
	}
	return len(t.sub) == 0
}

func (t *node) add(s []byte) {
	now := t
	for i := len(s) - 1; i > -1; i-- {
		if v, ok := now.has(s[i]); ok {
			now = v
			continue
		}
		temp := new(node)
		temp.value = s[i]
		now.sub = append(now.sub, temp)
		now = temp
	}
}

func (t *node) endNodeOf(s []byte) *node {
	now := t
	for i := len(s) - 1; i > -1; i-- {
		if v, ok := now.has(s[i]); ok {
			now = v
			continue
		}
		return nil
	}
	return now
}

func minimumLengthEncoding1(words []string) int {
	res, tree, m := 0, new(node), make(map[string]bool)
	for i := range words {
		if !m[words[i]] {
			tree.add([]byte(words[i]))
			m[words[i]] = true
		}
	}
	for s := range m {
		if tree.endNodeOf([]byte(s)).isLeaf() {
			res += len(s)
			res++
		}
	}
	return res
}

/*
解题思路

- 暴力解法。先将所有的单词放入字典中。然后针对字典中的每个单词，
逐一从字典中删掉自己的子字符串，这样有相同后缀的字符串被删除了，
字典中剩下的都是没有共同前缀的。最终的答案是剩下所有单词用 # 号连接之后的总长度。

- Trie 解法。构建 Trie 树，相同的后缀会被放到从根到叶子节点中的某个路径中。
最后依次遍历一遍所有单词，如果单词最后一个字母是叶子节点，
说明这个单词是要选择的，因为它可能是包含了一些单词后缀的最长单词。
累加这个单词的长度并再加 1(# 字符的长度)。
最终累加出来的长度即为题目所求的答案。

leetcode提交

- 暴力解法
	执行用时：8 ms, 在所有 Go 提交中击败了100.00%的用户
	内存消耗：6.5 MB, 在所有 Go 提交中击败了65.08%的用户
	通过测试用例：
	38 / 38

- Trie 解法
	执行用时：32 ms, 在所有 Go 提交中击败了58.73%的用户
	内存消耗：6.9 MB, 在所有 Go 提交中击败了52.38%的用户
	通过测试用例：
	38 / 38

*/
