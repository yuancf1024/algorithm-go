package leetcode

/* 560. 和为 K 的子数组
给你一个整数数组 nums 和一个整数 k ，
请你统计并返回 该数组中和为 k 的子数组的个数 。

示例 1：
输入：nums = [1,1,1], k = 2
输出：2
示例 2：
输入：nums = [1,2,3], k = 3
输出：2
*/

// 采用滑动窗口 该方法行不通
// func subarraySum(nums []int, k int) int {
// 	length := len(nums)

// 	if length == 1 && nums[0] == k {
// 		return 1
// 	}
// 	left, right, sum, res := 0, 0, 0, 0
// 	for left < len(nums) {
// 		if right < len(nums) && sum < k {
// 			sum += nums[right]
// 			right++
// 		} else if sum == k {
// 			res++
// 		} else {
// 			sum -= nums[left]
// 			left++
// 		}
// 	}
// 	return res
// }

// 使用前缀和，很巧妙的转化
func subarraySum(nums []int, k int) int {
	count, pre := 0, 0
	m := map[int]int{} // 哈希表的键是前i个数字之和，值为每个和出现的次数。
	m[0] = 1
	for i := 0; i < len(nums); i++ {
		pre += nums[i] // 想要找的前缀和 pre-k
		if _, ok := m[pre-k]; ok { // 找到了，直接更新答案
			count += m[pre-k]
		}
		m[pre] += 1 // 没有找到，把pre加入散列表并记录出现次数
	}
	return count
}
/*
题目大意
给你一个整数数组 nums 和一个整数 k ，
请你统计并返回该数组中和为 k ****的连续子数组的个数。

解题思路
此题不能使用滑动窗口来解。因为 nums[i] 可能为负数。
前缀和的思路可以解答此题，但是时间复杂度有点高了，
O(n^2)。考虑优化时间复杂度。
题目要求找到连续区间和为 k 的子区间总数，
即区间 [i,j] 内的和为 K ⇒ prefixSum[j] - prefixSum[i-1] == k。
所以 prefixSum[j] == k + prefixSum[i-1] 。这样转换以后，题目就转换成类似 A + B = K 的问题了。
LeetCode 第一题的优化思路拿来用。用 map 存储累加过的结果。如此优化以后，时间复杂度 O(n)。
*/