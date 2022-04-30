package leetcode

/* 724. 寻找数组的中心下标
给你一个整数数组 nums ，请计算数组的 中心下标 。
数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
如果中心下标位于数组最左端，那么左侧数之和视为 0 ，
因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
如果数组有多个中心下标，应该返回 最靠近左边 的那一个。
如果数组不存在中心下标，返回 -1 。

示例 1：

输入：nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
中心下标是 3 。
*/

func pivotIndex(nums []int) int {
	if len(nums) <= 0 {
		return -1
	}
	sum, leftSum := 0, 0
	for _, num := range nums {
		sum += num
	}
	for index, num := range nums {
		if leftSum*2 + num == sum {
			return index
		}
		leftSum += num
	}
	return -1
}

/*
解题思路
在数组中，找到一个数，使得它左边的数之和等于它的右边的数之和，
如果存在，则返回这个数的下标索引，否作返回 -1。
这里面存在一个等式，只需要满足这个等式即可满足条件：
leftSum + num[i] = sum - leftSum => 
2 * leftSum + num[i] = sum
题目提到如果存在多个索引，则返回最左边那个，因此从左开始求和，而不是从右边

// 时间: O(n)
// 空间: O(1)
*/