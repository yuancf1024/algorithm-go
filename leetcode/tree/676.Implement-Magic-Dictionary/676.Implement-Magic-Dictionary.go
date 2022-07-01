package leetcode

/* 676. 实现一个魔法字典
设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。 
如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，
使得所形成的新单词存在于你构建的字典中。

实现 MagicDictionary 类：
- MagicDictionary() 初始化对象
- void buildDict(String[] dictionary) 使用字符串数组 dictionary 
设定该数据结构，dictionary 中的字符串互不相同
- bool search(String searchWord) 给定一个字符串 searchWord ，
判定能否只将字符串中 一个 字母换成另一个字母，
使得所形成的新字符串能够与字典中的任一字符串匹配。
如果可以，返回 true ；否则，返回 false 。
 

示例：
输入
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
输出
[null, null, false, true, false, false]

解释
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // 返回 False
magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
magicDictionary.search("hell"); // 返回 False
magicDictionary.search("leetcoded"); // 返回 False
 

提示：
1 <= dictionary.length <= 100
1 <= dictionary[i].length <= 100
dictionary[i] 仅由小写英文字母组成
dictionary 中的所有字符串 互不相同
1 <= searchWord.length <= 100
searchWord 仅由小写英文字母组成
buildDict 仅在 search 之前调用一次
最多调用 100 次 search
*/

type MagicDictionary struct {
	rdict map[int]string
}


/** Initialize your data structure here. */
func Constructor676() MagicDictionary {
	return MagicDictionary{rdict: make(map[int]string)}
}

/** Build a dictionary through a list of words */
func (this *MagicDictionary) BuildDict(dictionary []string)  {
	for k, v := range dictionary {
		this.rdict[k] = v
	}
}

/** Returns if there is any word in the trie that equals 
to the given word after modifying exactly one character */
func (this *MagicDictionary) Search(searchWord string) bool {
	for _, v := range this.rdict {
		n := 0
		if len(searchWord) == len(v) {
			for i := 0; i < len(v); i++ {
				if searchWord[i] != v[i] {
					n += 1
				}
			}
			if n == 1 {
				return true
			}
		}
	}
	return false
}


/**
 * Your MagicDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.BuildDict(dictionary);
 * param_2 := obj.Search(searchWord);
 */

/*
题目大意
实现一个带有 buildDict, 以及 search 方法的魔法字典。
对于 buildDict 方法，你将被给定一串不重复的单词来构建一个字典。
对于 search 方法，你将被给定一个单词，并且判定能否只将这个单词中
一个字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。

解题思路
实现 MagicDictionary 的数据结构，这个数据结构内会存储一个字符串数组，
当执行 Search 操作的时候要求判断传进来的字符串能否只改变一个字符
(不能增加字符也不能删除字符)就能变成 MagicDictionary 中存储的字符串，
如果可以，就输出 true，如果不能，就输出 false。
这题的解题思路比较简单，用 Map 判断即可。
*/