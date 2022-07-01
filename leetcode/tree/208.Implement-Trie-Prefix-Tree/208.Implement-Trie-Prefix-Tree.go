package leetcode

/* 208. 实现 Trie (前缀树)
Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，
用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，
例如自动补完和拼写检查。

请你实现 Trie 类：
- Trie() 初始化前缀树对象。
- void insert(String word) 向前缀树中插入字符串 word 。
- boolean search(String word) 如果字符串 word 在前缀树中，
返回 true（即，在检索之前已经插入）；否则，返回 false 。
- boolean startsWith(String prefix) 如果之前已经插入的字符串 
word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 

示例：
输入
["Trie", "insert", "search", "search", "startsWith", "insert",
 "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
 
提示：

1 <= word.length, prefix.length <= 2000
word 和 prefix 仅由小写英文字母组成
insert、search 和 startsWith 调用次数 总计 不超过 3 * 10^4 次
*/

type Trie struct {
	isWord bool
	children map[rune]*Trie
}

/** Initialize your data structure here. */
func Constructor208() Trie {
	return Trie{isWord: false, children: make(map[rune]*Trie)}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
	parent := this
	for _, ch := range word {
		if children, ok := parent.children[ch]; ok {
			parent = children
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

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	parent := this
	for _, ch := range prefix {
		if child, ok := parent.children[ch]; ok {
			parent = child
			continue
		}
		return false
	}
	return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */

/*
解题思路
要求实现一个 Trie 的数据结构，具有 insert, search, startsWith 
三种操作
这一题就是经典的 Trie 实现。本题的实现可以作为 Trie 的模板。
*/