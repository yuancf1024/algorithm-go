package leetcode

/* 318. 最大单词长度乘积
给你一个字符串数组 words ，找出并返回 
length(words[i]) * length(words[j]) 的最大值，
并且这两个单词不含有公共字母。
如果不存在这样的两个单词，返回 0 。
*/

// 二进制编码字符串
func maxProduct318(words []string) int {
	// 边界条件的处理
	if words == nil || len(words) == 0 {
		return 0
	}
	length, value, maxProduct := len(words), make([]int, len(words)), 0
	for i := 0; i < length; i++ { // 遍历数组中的每个字符串
		tmp := words[i]
		value[i] = 0
		for j := 0; j < len(tmp); j++ { // 对字符串编码成二进制数
			value[i] |= 1 << (tmp[j] - 'a') // 与运算可以保留已遍历过的j位上面的符号
		}
	}
	for i := 0; i < length; i++ {
		for j := i + 1; j < length; j++ { // 遍历相邻字符串，判断他们之间是否有相同公共字母，以及2个字符串长度的乘积
			if (value[i] & value[j]) == 0 && (len(words[i]) * len(words[j]) > maxProduct) {
				maxProduct = len(words[i]) * len(words[j])
			}
		}
	}
	return maxProduct
}

// 使用哈希表记录字符串中出现的字符
func maxProduct318_v2(words []string) int {

	// 边界条件的处理
	if len(words) == 0 || words == nil {
		return 0
	}
	// 生成二维切片
	length := len(words)
	flags := make([][]bool, length) // 行
	for i := range flags {
		flags[i] = make([]bool, 26) // 列
	}
	for i := 0; i < length; i++ { // 遍历words中每个字符串，使用一个哈希表记录字符串中a-z字符是否出现
		tmp := words[i]
		for j := 0; j < len(tmp); j++ {
			flags[i][tmp[j] - 'a'] = true
		}
	}

	res := 0
	for i := 0; i < length; i++ {
		for j := i + 1; j < length; j++ {
			k := 0
			for ; k < 26; k++ {
				if flags[i][k] && flags[j][k] { // 判断字符串words[i] words[j] 是否有相同字母
					break;
				}
			}

			if k == 26 { // 更新最大值
				maxProduct := len(words[i]) * len(words[j])
				res = max(res, maxProduct)
			}
		}
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

/* 解题思路
在字符串数组中找到 2 个没有公共字符的字符串，
并且这两个字符串的长度乘积要是最大的，求这个最大的乘积。
这里需要利用位运算 & 运算的性质，如果 X & Y = 0，
说明 X 和 Y 完全不相同。那么我们将字符串都编码成
二进制数，进行 & 运算即可分出没有公共字符的字符串，
最后动态维护长度乘积最大值即可。
将字符串编码成二进制数的规则比较简单，
每个字符相对于 'a' 的距离，根据这个距离将 1 左移多少位。
    a 1->1  
    b 2->10  
    c 4->100  
    ab 3->11  
    ac 5->101  
    abc 7->111  
    az 33554433->10000000000000000000000001  
*/