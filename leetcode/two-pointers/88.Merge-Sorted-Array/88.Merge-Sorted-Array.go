package leetcode

import "sort"

// 方法1：直接合并后排序
func merge1(nums1 []int, m int, nums2 []int, n int)  {
    copy(nums1[m:], nums2)
	sort.Ints(nums1)
}
/*
最直观的方法是先将数组nums2放进数组nums1的尾部，
然后直接对整个数组进行排序。

- 时间复杂度：O((m+n)log(m+n))。
排序序列长度为 m+n，套用快速排序的时间复杂度即可，平均情况为 O((m+n)log(m+n))。

- 空间复杂度：O(log(m+n))。
排序序列长度为 m+n，套用快速排序的空间复杂度即可，平均情况为 O(log(m+n))。
*/

// 方法二：双指针
func merge2(nums1 []int, m int, nums2 []int, n int)  {
    sorted := make([]int, 0, m + n)
	p1, p2 := 0, 0
	for {
		if p1 == m {
			sorted = append(sorted, nums2[p2:]...)
			break
		}
		if p2 == n {
			sorted = append(sorted, nums1[p1:]...)
			break
		}
		if nums1[p1] < nums2[p2] {
			sorted = append(sorted, nums1[p1])
			p1++
		} else {
			sorted = append(sorted, nums2[p2])
			p2++
		}
	}
	copy(nums1, sorted)
}

/*
将两个数组看作队列，
每次从两个数组头部取出比较小的数字放到结果中

- 时间复杂度：O(m+n)。
指针移动单调递增，最多移动 m+n 次，因此时间复杂度为 O(m+n)。

- 空间复杂度：O(m+n)。
需要建立长度为 m+n 的中间数组 sorted。
*/

// 方法三 逆向双指针
func merge(nums1 []int, m int, nums2 []int, n int)  {
    for p := m + n; m > 0 && n > 0; p-- {
		if nums1[m-1] <= nums2[n-1] {
			nums1[p-1] = nums2[n-1]
			n--
		} else {
			nums1[p-1] = nums1[m-1]
			m--
		}
	}
	for ; n > 0; n-- {
		nums1[n-1] = nums2[n-1]
	}
}
/*
为了不大量移动元素，就要从2个数组长度之和的最后一个位置开始，
依次选取两个数组中大的数，从第一个数组的尾巴开始往头放，
只要循环一次以后，就生成了合并以后的数组了。

时间复杂度：O(m+n)。
指针移动单调递减，最多移动 m+n 次，因此时间复杂度为 O(m+n)。

空间复杂度：O(1)。
直接对数组nums1原地修改，不需要额外空间。
*/
