package leetcode

// import "sort"

/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

// 最喜欢版本一的二分实现
func firstBadVersion(n int) int {
	low, high := 0, n-1
	for low <= high {
		mid := low + ((high - low) >> 1)
		if isBadVersion(mid) {
			high = mid - 1
			// return mid+1
		} else {
			low = mid + 1
		}
	}
	return low
}

/* 寻找第一个错误版本，类似于寻找下面数组中的第一个 1的下标（元素下标从1开始）
0, 0, 0, ..., 1, 1, 1, 1, .. 
*/

// 二分法
// func firstBadVersion(n int) int {
// 	left, right := 1, n
// 	for left < right {
// 		mid := left + ((right - left)>> 1)
// 		if isBadVersion(mid) {
// 			right = mid
// 		} else {
// 			left = mid + 1
// 		}
// 	}
// 	return left
// }

// 本题主要是理解思想，这种方法有点讨巧
// 对应的测试文件有问题😂
// func firstBadVersion(n int) int {
// 	return sort.Search(n, func(version int) bool {
// 		return isBadVersion(version)
// 	})
// }

func isBadVersion(version int) bool {
	return true
}

/*
我们知道开发产品迭代的版本，如果当一个版本为正确版本，
则该版本之前的所有版本均为正确版本；
当一个版本为错误版本，则该版本之后的所有版本均为错误版本。
利用这个性质就可以进行二分查找。
利用二分搜索，也可以满足减少对调用 API 的次数的要求。
时间复杂度：O(logn)，其中 n 是给定版本的数量。空间复杂度：O(1)。
*/
