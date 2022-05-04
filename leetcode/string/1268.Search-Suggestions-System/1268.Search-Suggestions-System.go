package leetcode

import "sort"

/* 1268. 搜索推荐系统
给你一个产品数组 products 和一个字符串 searchWord ，
products  数组中每个产品都是一个字符串。

请你设计一个推荐系统，在依次输入单词 searchWord 的每一个字母后，
推荐 products 数组中前缀与 searchWord 相同的最多三个产品。
如果前缀相同的可推荐产品超过三个，请按字典序返回最小的三个。

请你以二维列表的形式，返回在输入 searchWord 每个字母后相应
的推荐产品的列表。

输入：products = ["mobile","mouse","moneypot","monitor","mousepad"], 
searchWord = "mouse"
输出：[
["mobile","moneypot","monitor"],
["mobile","moneypot","monitor"],
["mouse","mousepad"],
["mouse","mousepad"],
["mouse","mousepad"]
]
解释：按字典序排序后的产品列表是 ["mobile","moneypot","monitor","mouse","mousepad"]
输入 m 和 mo，由于所有产品的前缀都相同，
所以系统返回字典序最小的三个产品 ["mobile","moneypot","monitor"]
输入 mou， mous 和 mouse 后系统都返回 ["mouse","mousepad"]
*/

// 参考 halfrost 调用sort包 的 根据字符串排序函数 sort.SearchStrings()
func suggestedProducts(products []string, searchWord string) [][]string {
	sort.Strings(products) // 由于题目要求返回的答案要按照字典序输出，所以先排序
	searchWordBytes, res := []byte(searchWord), make([][]string, 0, len(searchWord))
	for i := 1; i <= len(searchWord); i++ {
		searchWordBytes[i-1]++
		products = products[:sort.SearchStrings(products, string(searchWordBytes[:i]))] // 第一次二分搜索先将不满足目标串前缀的字符串筛掉
		searchWordBytes[i-1]--
		products = products[sort.SearchStrings(products, searchWord[:i]):] // 第二次二分搜索再搜索出最终满足题意的字符串
		if len(products) > 3 {
			res = append(res, products[:3]) // 如果前缀相同的可推荐产品超过三个，请按字典序返回最小的三个。
		} else {
			res = append(res, products)
		}
	}
	return res
}

/*
解题思路
由于题目要求返回的答案要按照字典序输出，所以先排序。
有序字符串又满足了二分搜索的条件，于是可以用二分搜索。
sort.SearchStrings 返回的是满足搜索条件的第一个起始下标。
末尾不满足条件的字符串要切掉。所以要搜 2 次，第一次二分搜索先将不满足目标串前缀的字符串筛掉。
第二次二分搜索再搜索出最终满足题意的字符串。
*/