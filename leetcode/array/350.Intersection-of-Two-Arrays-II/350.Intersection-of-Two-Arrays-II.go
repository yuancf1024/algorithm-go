package leetcode

/*
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。
返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致
（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
*/

func intersect(nums1 []int, nums2 []int) []int {
	res := make([]int, 0)
	m := make(map[int]int, len(nums1))

	for _, v := range nums1 {
		m[v]++
	}

	for _, i := range nums2 {
		if m[i] > 0 {
			res = append(res, i)
			m[i]--
		}
	}
	return res
}

/* Solution：使用map
这一题还是延续第 349 题的思路。把数组一中的数字都放进字典中，
另外字典的 key 是数组中的数字，value 是这个数字出现的次数。
在扫描数组二的时候，每取出一个存在的数字，把字典中的 value 减一，
把数字添加进返回的数组中。
如果 value 是 0 代表不存在这个数字。
*/


/*
进阶：

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小，哪种方法更优？
如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
*/