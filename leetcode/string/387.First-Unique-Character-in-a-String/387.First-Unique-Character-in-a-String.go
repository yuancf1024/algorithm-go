package leetcode

// 解法1 使用哈希表存储频数
// 使用哈希表记录26个字符出现的次数
// 执行用时：4 ms
// 内存消耗：5.1 MB
func firstUniqChar(s string) int {
	n := len(s)
	res := make([]int, 26)
	for i := 0; i < n; i++ {
		res[s[i] - 'a']++ // 'a' = 97
	}
	for j := 0; j < n; j++ {
		if res[s[j] - 'a'] == 1 {
			return j
		}
	}
	return -1
}

/* 使用哈希表存储频数
我们可以对字符串进行两次遍历。

在第一次遍历时，我们使用哈希映射统计出字符串中每个字符出现的次数。
在第二次遍历时，我们只要遍历到了一个只出现一次的字符，
那么就返回它的索引，否则在遍历结束后返回 −1。

复杂度分析
时间复杂度：O(n)，其中 n 是字符串 s 的长度。我们需要进行两次遍历。

空间复杂度：O(∣Σ∣)，其中 Σ 是字符集，在本题中 s 只包含小写字母，
因此 ∣Σ∣≤26。我们需要 O(∣Σ∣) 的空间存储哈希映射。
*/

// 解法2 使用哈希表存储索引
// 执行用时：4 ms
// 内存消耗：5.1 MB
func firstUniqChar_v2(s string) int {
	n := len(s)
	charMap := make([][2]int, 26)
	for i := 0; i < 26; i++ {
		charMap[i][0] = -1
		charMap[i][1] = -1
	}

	for i := 0; i < n; i++ {
		if charMap[s[i] - 'a'][0] == -1 {
			charMap[s[i] - 'a'][0] = i
		} else { // 已经出现过
			charMap[s[i] - 'a'][1] = i
		}
	}
	res := len(s)
	for i := 0; i < 26; i++ {
		// 只出现了1次
		if charMap[i][0] >= 0 && charMap[i][1] == -1 {
			if charMap[i][0] < res {
				res = charMap[i][0]
			}
		}
	}
	if res == len(s) { // 字符串s 中全为相同字符
		return -1
	}
	return res
}

/* 使用哈希表存储索引
建立一个‘二维’哈希表，每个key对应2个序号依次为0、1的value，初始化全部赋值为-1；
第一个值存储索引，第二个值标记是否出现过（第一个值>=0且第二个值=-1代表只出现1次）
遍历字符串s，更新value[0]、value[1];
遍历哈希表，找到只出现1次的字符
在第一次遍历结束后，我们只需要再遍历一次哈希映射中的所有值，
找出其中满足value[i][0] >= 0 && value[i][1] = −1 的值，value[i][0]即为第一个不重复字符的索引。

复杂度同解法1
*/

// 解法3 哈希映射 + 额外的队列，借助队列找到第一个满足某个条件的元素。
// TODO