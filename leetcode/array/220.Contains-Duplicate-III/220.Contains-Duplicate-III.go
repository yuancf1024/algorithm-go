package leetcode

/* 220. 存在重复元素 III
给你一个整数数组 nums 和两个整数 k 和 t 。
请你判断是否存在 两个不同下标 i 和 j，
使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。
如果存在则返回 true，不存在返回 false。

示例 1：
输入：nums = [1,2,3,1], k = 3, t = 0
输出：true

示例 2：
输入：nums = [1,0,1,1], k = 1, t = 2
输出：true

示例 3：
输入：nums = [1,5,9,1,5,9], k = 2, t = 3
输出：false
 
提示：

0 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^4
0 <= t <= 2^31 - 1
*/

// 参考halfrost 解法1 滑动窗口 + 剪枝
func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
	if len(nums) <= 1 {
		return false
	}
	if k <= 0 {
		return false
	}
	n := len(nums)
	for i := 0; i < n; i++ {
		count := 0
		for j := i + 1; j < n && count < k; j++ {
			if abs(nums[i]-nums[j]) <= t {
				return true
			}
			count++
		}
	}
	return false
}

func abs(a int) int {
	if a > 0 {
		return a
	}
	return -a
}

// 解法2 桶排序
func containsNearbyAlmostDuplicate1(nums []int, k int, t int) bool {
	if k <= 0 || t < 0 || len(nums) < 2 {
		return false
	}
	buckets := map[int]int{}
	for i := 0; i < len(nums); i++ {
		// Get the ID of the bucket from element value nums[i] and bucket width t + 1
		key := nums[i] / (t+1)
		// -7/9 = 0, but need -7/9 = -1
		if nums[i] < 0 {
			key--
		}
		if _, ok := buckets[key]; ok {
			return true
		}
		// check the lower bucket, and have to check the value too
		// 检查前一个桶，nums[i] > v
		if v, ok := buckets[key-1]; ok && nums[i]-v <= t {
			return true
		}
		// check the upper bucket, and have to check the value too
		// 检查后一个桶，nums[i] < v
		if v, ok := buckets[key+1]; ok && v-nums[i] <= t {
			return true
		}
		// maintain k size of window
		if len(buckets) >= k {
			delete(buckets, nums[i-k]/(t+1))
		}
		buckets[key] = nums[i]
	}
	return false
}

/*
解题思路
给出一个数组，要求在数组里面找到 2 个索引，i 和 j，
使得 | nums[i] - nums[j] | ≤ t ，并且 | i - j | ≤ k 。

这是一道滑动窗口的题目。第一想法就是用 i 和 j 两个指针，针对每个 i ，
都从 i + 1 往后扫完整个数组，判断每个 i 和 j ，判断是否满足题意。
j 在循环的过程中注意判断剪枝条件 | i - j | ≤ k。
这个做法的时间复杂度是 O(n^2)。这个做法慢的原因在于滑动窗口的左边界和
右边界在滑动过程中不是联动滑动的。

于是考虑，如果数组是有序的呢？把数组按照元素值从小到大进行排序，
如果元素值相等，就按照 index 从小到大进行排序。在这样有序的数组中
找满足题意的 i 和 j，滑动窗口左边界和右边界就是联动的了。
窗口的右边界滑到与左边界元素值的差值 ≤ t 的地方，
满足了这个条件再判断 | i - j | ≤ k，
如果右边界与左边界元素值的差值 > t 了，
说明该把左边界往右移动了(能这样移动的原因就是因为我们将数组元素大小排序了，
右移是增大元素的方向)。移动左边界的时候需要注意左边界不能超过右边界。
这样滑动窗口一次滑过整个排序后的数组，就可以判断是否存在满足题意的 i 和 j 。
这个做法的时间主要花在排序上了，时间复杂度是 O(n log n)。

本题最优解是利用桶排序的思想。| i - j | ≤ k 这个条件利用一个窗口大小为 k 来维护。
重点在 | nums[i] - nums[j] | ≤ t 这个条件如何满足。
利用桶排序的思想，将 nums[i] 所有元素分为 …,[0,t],[t+1,2t+1],…。
每个区间的大小为 t + 1。每个元素现在都对应一个桶编号。
进行 3 次查找即可确定能否找到满足这个 | nums[i] - nums[j] | ≤ t 条件的
数对。如果在相同的桶中找到了元素，那么说明能找到这样的 i 和 j。
还有 2 种可能对应桶边界的情况。

- 如果存在**前一个桶**中的元素能使得相差的值也 ≤ t，这样的数对同样满足题意。
- 最后一种情况是，如果存在**后一个桶**中的元素能使得相差的值也 ≤ t，
这样的数对同样满足题意。查询 3 次，如果都不存在，
说明当前的 i 找不到满足题意的 j。继续循环寻找。
循环一遍都找不到满足题意的数对，输出 false。
*/