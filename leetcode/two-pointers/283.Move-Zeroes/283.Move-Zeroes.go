package leetcode

/* 283.移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，
同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

进阶：你能尽量减少完成的操作次数吗？
*/

// 易于理解的双指针实现
func moveZeroes_v1(nums []int) {
	if len(nums) < 2 {
		return
	}
	slow, fast := 0, 0
	for ; fast < len(nums); fast++ {
		if nums[fast] != 0 {
			if fast != slow {
				nums[slow], nums[fast] = nums[fast], nums[slow]
			}
			slow++
		}
	}
}

// 双指针（很巧妙）
func moveZeroes(nums []int) {
	n := len(nums)

	if n < 2 {
		return 
	}

	p2 := 0
	for p1 := 0; p1 < n; p1++ {
		if nums[p1] != 0 { // 如果第一个元素等于0，p1指针右移
			if p1 != p2 {
				nums[p1], nums[p2] = nums[p2], nums[p1]
			}
			p2++
		}
	}
	// 该实现中，p1相当于右指针，p2相当于左指针
	// p2 左边均为非零数，p1左边直到p2指针处均为零
}

/*Solution：
这一题可以只扫描数组一遍，不断的用 i，j 标记 0 和非 0 的元素，
然后相互交换，最终到达题目的目的。
与这一题相近的题目有第 26 题，第 27 题，第 80 题。
*/