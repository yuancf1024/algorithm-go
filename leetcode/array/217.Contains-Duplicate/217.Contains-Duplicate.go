package leetcode

func containsDuplicate(nums []int) bool {

	// // 暴力迭代 时间复杂度O(N^2)
	// n := len(nums)
	// for i := 0; i < n - 1; i++ {
	// 	for j := 1; j < n - 1; j++ {
	// 		if nums[i] == nums[j] {
	// 			return true
	// 		}
	// 	}
	// }
	// return false

	// 使用map判断，时间复杂度O(N)
	m := make(map[int]bool, len(nums))
	for _, v := range nums {
		if _, found := m[v]; found {
			return true
		}
		m[v] = true
	}
	return false
}

/*
暴力迭代：2个for循环嵌套，依次遍历

使用map：遍历nums中的每个元素，判断元素v是否在map中，
如果在，那么返回true 给found，此时可直接返回最终包含重复元素的结果；
如果不在，把m[v]标记为true，代表元素v已经作为key放入map中了。
遍历结束后，如果没有返回，说明nums中所有元素都不同，返回false。
*/