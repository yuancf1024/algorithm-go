package leetcode

/* 648. 单词替换
有许多可以形成它的词根，则用最短的词根替换它。
你需要输出替换之后的句子。

示例 1：
输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"

示例 2：
输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
输出："a a b c"
 
提示：
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] 仅由小写字母组成。
1 <= sentence.length <= 10^6
sentence 仅由小写字母和空格组成。
sentence 中单词的总量在范围 [1, 1000] 内。
sentence 中每个单词的长度在范围 [1, 1000] 内。
sentence 中单词之间由一个空格隔开。
sentence 没有前导或尾随空格。
*/

import "strings"

// 解法1 哈希表
func replaceWords(dictionary []string, sentence string) string {
	roots := make(map[byte][]string) // 建立map哈希表
	for _, root := range dictionary {
		b := root[0]
		roots[b] = append(roots[b], root) // 建立首字母到前缀字符串的映射关系
	}
	words := strings.Split(sentence, " ") // 将句子按照空格
	for i, word := range words { // 遍历 
		b := []byte(word)
		for j := 1; j < len(b) && j <= 100; j++ {
			if findWord(roots, b[0:j]) { // 找到了最短的词根
				words[i] = string(b[0:j]) // 用字符串前缀代替原sentence里面的单词
				break
			}
		}
	}
	return strings.Join(words, " ")
}

// 寻找当前遍历到的词根word是否和字典中的词根相匹配
func findWord(roots map[byte][]string, word []byte) bool {
	if roots[word[0]] == nil {
		return false
	}
	for _, root := range roots[word[0]] { // 根据word的首字母找到map里映射的前缀字符串
		if root == string(word) {
			return true
		}
	}
	return false
}

/*
执行用时：20 ms, 在所有 Go 提交中击败了81.25%的用户
内存消耗：7.6 MB, 在所有 Go 提交中击败了93.75%的用户通过测试用例：
126 / 126
*/

// 解法2 Trie
func replaceWords1(dict []string, sentence string) string {
	trie := Constructor208()
	for _, v := range dict {
		trie.Insert(v)
	}
	words := strings.Split(sentence, " ")
	var result []string
	word := ""
	i := 0
	for _, value := range words {
		word = ""
		for i = 1; i < len(value); i++ {
			if trie.Search(value[:i]) {
				word = value[:i]
				break
			}
		}

		if len(word) == 0 {
			result = append(result, value)
		} else {
			result = append(result, word)
		}

	}
	return strings.Join(result, " ")
}

type Trie struct {
	isWord   bool
	children map[rune]*Trie
}

/** Initialize your data structure here. */
func Constructor208() Trie {
	return Trie{isWord: false, children: make(map[rune]*Trie)}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	parent := this
	for _, ch := range word {
		if child, ok := parent.children[ch]; ok {
			parent = child
		} else {
			newChild := &Trie{children: make(map[rune]*Trie)}
			parent.children[ch] = newChild
			parent = newChild
		}
	}
	parent.isWord = true
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	parent := this
	for _, ch := range word {
		if child, ok := parent.children[ch]; ok {
			parent = child
			continue
		}
		return false
	}
	return parent.isWord
}

/*
执行用时：40 ms, 在所有 Go 提交中击败了36.72%的用户
内存消耗：17.6 MB, 在所有 Go 提交中击败了50.78%的用户
通过测试用例：
126 / 126
*/

/*
题目大意
在英语中，我们有一个叫做 词根(root)的概念，
它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 
继承词(successor)。例如，词根an，跟随着单词 other(其他)，
可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典和一个句子。
你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，
则用最短的词根替换它。要求输出替换之后的句子。

解题思路
- 给出一个句子和一个可替换字符串的数组，如果句子中的单词和可替换
列表里面的单词，有相同的首字母，那么就把句子中的单词替换成可替换列表里面的
单词。输入最后替换完成的句子。
- 这一题有 2 种解题思路，第一种就是单纯的用 Map 查找。
第二种是用 Trie 去替换。

根据leetcode提交结果来看，哈希表的效率更高
*/