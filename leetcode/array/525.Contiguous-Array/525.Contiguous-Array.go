package leetcode

/* 525. 连续数组
给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 
的最长连续子数组，并返回该子数组的长度。

示例 1:

输入: nums = [0,1]
输出: 2
说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
*/

func findMaxLength(nums []int) int {
	dict := map[int]int{}
	dict[0] = -1
	count, res := 0, 0
	for i := 0; i < len(nums); i++ { // 累加前缀和
		if nums[i] == 0 { // 将0替换成-1
			count--
		} else {
			count++
		}
		if idx, ok := dict[count]; ok { // 将每个前缀和存入 map 中
			res = max(res, i-idx) // 扫描过程中动态更新最大区间长度
		} else {
			dict[count] = i // 哈希表的键是从第1个数字开始累加到当前扫描到的数字之和，而值是当前扫描的数字的下标
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

/*
解题思路
0 和 1 的数量相同可以转化为两者数量相差为 0，
如果将 0 看作为 -1，那么原题转化为求最长连续子数组，
其元素和为 0 。又变成了区间内求和的问题，
自然而然转换为前缀和来处理。假设连续子数组是 [i,j] 区间，
这个区间内元素和为 0 意味着 
prefixSum[j] - prefixSum[i] = 0，
也就是 prefixSum[i] = prefixSum[j]。
不断累加前缀和，将每个前缀和存入 map 中。
一旦某个 key 存在了，代表之前某个下标的前缀和和当前下标构成的区间，
这段区间内的元素和为 0 。这个区间是所求。
扫完整个数组，扫描过程中动态更新最大区间长度，
扫描完成便可得到最大区间长度，即最长连续子数组。

函数findMaxLength中只有一个循环，显然时间复杂度是O（n）。
由于需要一个哈希表sumToIndex保存数组中前面若干数字的累加之和，
因此空间复杂度也是O（n）
*/