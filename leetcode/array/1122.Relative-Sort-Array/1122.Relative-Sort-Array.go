package leetcode

/* 1122. 数组的相对排序
给你两个数组，arr1 和 arr2，arr2 中的元素各不相同，
arr2 中的每个元素都出现在 arr1 中。

对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。
未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

示例 1：
输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]

示例  2:
输入：arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
输出：[22,28,8,6,17,44]

提示：

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i]  各不相同 
arr2 中的每个元素 arr2[i] 都出现在 arr1 中
*/

import "sort"

// 参考halfrost 模拟，时间复杂度 O(n^2)
func relativeSortArray(arr1 []int, arr2 []int) []int {
	leftover, m, res := []int{}, make(map[int]int), []int{}
	for _, v := range arr1 { // 统计数组arr1的频次
		m[v]++
	}
	for _, s := range arr2 { // 按照arr2中数字的顺序，arr1中的数量逐一添加进res
		count := m[s]
		for i := 0; i < count; i++ {
			res = append(res, s)
		}
		m[s]=0
	}
	for v, count := range m { // 遍历剩下的哈希表map
		for i := 0; i < count; i++ {
			leftover = append(leftover, v) // 把剩下的元素添加进res
		}
	}
	sort.Ints(leftover) // 排序
	res = append(res, leftover...)
	return res
}

// 解法2 桶排序，时间复杂度 O(n^2)
func relativeSortArray1(arr1 []int, arr2 []int) []int {
	count := [1001]int{} // 用 1001 个桶装所有的数，把数都放在桶里
	for _, a := range arr1 {  // 统计数组arr1的频次
		count[a]++
	}
	res := make([]int, 0, len(arr1))
	for _, b := range arr2 {  // 按照arr2中数字的顺序，arr1中的数量逐一添加进res
		for count[b] > 0 {
			res = append(res, b)
			count[b]--
		}
	}
	for i := 0; i < 1001; i++ { // B 中以外的元素就按照桶的顺序依次输出即可。
		for count[i] > 0 {
			res = append(res, i)
			count[i]--
		}
	}
	return res
}

/*
解题思路
- 给出 2 个数组 A 和 B，A 中包含 B 中的所有元素。
要求 A 按照 B 的元素顺序排序，B 中没有的元素再接着排在后面，从小到大排序。
- 这一题有多种解法。一种暴力的解法就是依照题意，先把 A 中的元素都
统计频次放在 map 中，然后 按照 B 的顺序输出，接着再把剩下的元素排序
接在后面。还有一种桶排序的思想，由于题目限定了 A 的大小是 1000，
这个数量级很小，所以可以用 1001 个桶装所有的数，把数都放在桶里，
这样默认就已经排好序了。接下来的做法和前面暴力解法差不多，按照频次输出。
B 中以外的元素就按照桶的顺序依次输出即可。
*/