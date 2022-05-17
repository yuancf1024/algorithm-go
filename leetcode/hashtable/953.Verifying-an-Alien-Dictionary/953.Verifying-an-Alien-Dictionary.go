package leetcode

/* 953. 验证外星语词典
某种外星语也使用英文小写字母，但可能顺序 order 不同。
字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，
只有当给定的单词在这种外星语中按字典序排列时，
返回 true；否则，返回 false。

示例 1：
输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
输出：true
解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。

示例 2：
输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
输出：false
解释：在该语言的字母表中，'d' 位于 'l' 之后，
那么 words[0] > words[1]，因此单词序列不是按字典序排列的。

示例 3：
输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
输出：false
解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，
因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
*/

func isAlienSorted(words []string, order string) bool {
	if len(words) < 2 {
		return true
	}
	hash := make(map[byte]int)
	for i := 0; i < len(order); i++ {
		hash[order[i]] = i // key 是字符，value对应顺序
	}
	for i := 0; i < len(words)-1; i++ {
		pointer, word, wordplus := 0, words[i], words[i+1]
		for pointer < len(word) && pointer < len(wordplus) {
			if hash[word[pointer]] > hash[wordplus[pointer]] { // 没有按照order中的字母序
				return false
			}
			if hash[word[pointer]] < hash[wordplus[pointer]] { // 按照order中的字母序，跳出该次相邻单词的遍历
				break
			} else {
				pointer = pointer + 1
			}
		}
		if pointer < len(word) && pointer >= len(wordplus) { // 这个判断的意义？
			return false
		}
	}
	return true
}

/* 
这一题是简单题。给出一个字符串数组，判断把字符串数组里面字符串是否是按照 
order 的排序排列的。order 是给出个一个字符串排序。
这道题的解法是把 26 个字母的顺序先存在 map 中，
然后依次遍历判断字符串数组里面字符串的大小。
*/