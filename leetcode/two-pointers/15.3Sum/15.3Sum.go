package leetcode

import "sort"

func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	res := [][]int{}
	for i := 0; i < len(nums) - 2; i++ {
		n := nums[i]
		if n > 0 { // 如果开始的最小都大于0，直接退出
			break
		}
		if i > 0 && nums[i] == nums[i-1] { // 产生了重复
			continue
		}

		// 此时我们已经选出了第一个数，其实接下来的步骤和两数之和是一样的
		l := i + 1
		r := len(nums) - 1
		for l < r {
			n1 := nums[l]
			n2 := nums[r]
			if n1 + n2 + n == 0 {
				res = append(res, []int{n1, n2, n})
				// 去重
				for l < r && nums[l] == n1 {
					l++
				}
				for l < r && nums[r] == n2 {
					r--
				}
			} else if n1 + n2 + n < 0 {
				l++
			} else {
				r--
			}
		}
	}
	return res
}

/* 参考思路1：
如果暴力去做，那么需要找所有3元组合，需要三层嵌套for循环，复杂度O(N^3)

因为是算和问题，有序肯定比无序好做，我们可以先排序，得到一个有序的数组。

然后每一个元素去找可以组队的另外两个元素，因为是有序，所以可以用双指针：

左指针从当前位置+1开始，右指针从最后一个元素开始，这样根据三数之和，往中间收拢，最终得到结果。

时间复杂度O(n^2)

空间复杂度O(n)​
*/