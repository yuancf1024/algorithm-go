package leetcode

func removeElement(nums []int, val int) int {
	n := len(nums)
	if n == 0 {
		return n
	}

	left, right := 0, 0
	for ; right < n; right++ {
		if nums[right] != val { // left 指针左侧肯定没有val
			nums[left], nums[right] = nums[right], nums[left]
			left++
		}
	}
	return left
}

/*Solution:
思路可参考lc-283
*/

func removeElement1(nums []int, val int) int {
	if len(nums) == 0 {
		return 0
	}
	j := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			if i != j {
				nums[i], nums[j] = nums[j], nums[i]
			}
			j++
		}
	}
	return j
}
