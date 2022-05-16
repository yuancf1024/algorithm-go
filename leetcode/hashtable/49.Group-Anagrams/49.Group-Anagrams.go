package leetcode

/* 49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。
可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，
所有源单词中的字母通常恰好只用一次。

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

示例 2:
输入: strs = [""]
输出: [[""]]

示例 3:
输入: strs = ["a"]
输出: [["a"]]
*/

import "sort"

type sortRunes []rune

func (s sortRunes) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s sortRunes) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s sortRunes) Len() int {
	return len(s)
}

func groupAnagrams(strs []string) [][]string {
	record, res := map[string][]string{}, [][]string{}
	for _, str := range strs {
		sByte := []rune(str)
		sort.Sort(sortRunes(sByte)) // key 是排序以后的字符串
		sstrs := record[string(sByte)] // 把排序以后的字符串当做 key 存入到 map 中
		sstrs = append(sstrs, str)
		record[string(sByte)] = sstrs // value 对应的是这个排序字符串以后的 Anagrams 字符串集合
	}
	for _, v := range record {
		res = append(res, v) // 将这些 value 对应的字符串数组输出
	}
	return res
}

/*
解题思路
这道题可以将每个字符串都排序，排序完成以后，
相同 Anagrams 的字符串必然排序结果一样。
把排序以后的字符串当做 key 存入到 map 中。
遍历数组以后，就能得到一个 map，
	key 是排序以后的字符串，
	value 对应的是这个排序字符串以后的 Anagrams 字符串集合。
最后再将这些 value 对应的字符串数组输出即可。
*/

