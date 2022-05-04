package leetcode

/* 17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
*/

var (
	letterMap = []string {
		" ", // 0
		"", // 1
		"abc", // 2
		"def", // 3
		"ghi", // 4
		"jkl", // 5
		"mno", // 6
		"pqrs", // 7
		"tuv", // 8
		"wxyz", // 9
	}
	res = []string{}
	final = 0
)

// 解法一 DFS + 递归
func letterCombinations(digits string) []string {
	if digits == "" { // 边界条件：传入空字符串
		return []string{}
	}
	res = []string{}
	findCombination(&digits, 0, "") // 递归调用
	return res
}

func findCombination(digits *string, index int, s string) {
	if index == len(*digits) { // 如果索引大小和传入的字符串长度一致，那么返回s
		res = append(res, s)
		return
	}
	num := (*digits)[index]
	letter := letterMap[num - '0']
	for i := 0; i < len(letter); i++ {
		findCombination(digits, index+1,s+string(letter[i]))
	}
	// return
}

/*
解题思路
DFS 递归深搜即可
*/

// 解法二 非递归 代码有bug，暂时未跑通
// func letterCombinations_(digits string) []string {
// 	if digits == "" {
// 		return []string{}
// 	}

// 	index := digits[0] - '0'
// 	letter := letterMap[index]
// 	tmp := []string{}
// 	for i := 0; i < len(letter); i++ {
// 		if len(res) == 0 {
// 			res = append(res, "")
// 		}
// 		for j := 0; j < len(res); j++ {
// 			tmp = append(tmp, res[j]+string(letter[i]))
// 		}
// 	}
// 	res = tmp
// 	final++
// 	letterCombinations(digits[1:])
// 	final--
// 	if final == 0 {
// 		tmp = res
// 		res = []string{}
// 	}
// 	return tmp
// }

// 解法三 回溯 （参考回溯模板，类似 DFS）
var result []string
var dict = map[string][]string {
	"2": {"a", "b", "c"},
	"3": {"d", "e", "f"},
	"4": {"g", "h", "i"},
	"5": {"j", "k", "l"},
	"6": {"m", "n", "o"},
	"7": {"p", "q", "r", "s"},
	"8": {"t", "u", "v"},
	"9": {"w", "x", "y", "z"},
}

func letterCombinationsBT(digits string) []string {
	result = []string{}
	if digits == "" {
		return result
	}
	letterFunc("", digits)
	return result
}

func letterFunc(res string, digits string) {
	if digits == "" {
		result = append(result, res)
		return
	}
	k := digits[0:1]
	digits = digits[1:]
	for i := 0; i < len(dict[k]); i++ {
		res += dict[k][i]
		letterFunc(res, digits)
		res = res[0 : len(res)-1]
	}
}