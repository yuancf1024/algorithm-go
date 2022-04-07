package leetcode

import "sort"

// 解法一 最优解，双指针 + 排序
func threeSum(nums []int) [][]int {
	sort.Ints(nums)
	result, start, end, index, addNum, length := make([][]int, 0), 0, 0, 0, 0, len(nums)

	for index = 1; index < length - 1; index++ {
		start, end = 0, length - 1
		if index > 1 && nums[index] == nums[index-1] {
			start = index - 1
		}
		for start < index && end > index {
			if start > 0 && nums[start] == nums[start-1] {
				start++
				continue
			}
			if end < length-1 && nums[end] == nums[end+1] {
				end--
				continue
			}
			addNum = nums[start] + nums[end] + nums[index]
			if addNum == 0 {
				result = append(result, []int{nums[start], nums[end], nums[index]})
				start++
				end--
			} else if addNum > 0 {
				end--
			} else {
				start++
			}
		}
	}
	return result
}

/* 解题思路：
用 map 提前计算好任意 2 个数字之和，保存起来，
可以将时间复杂度降到 O(n^2)。这一题比较麻烦的一点在于，
最后输出解的时候，要求输出不重复的解。数组中同一个数字可能出现多次，
同一个数字也可能使用多次，但是最后输出解的时候，不能重复。
例如 [-1，-1，2] 和 [2, -1, -1]、[-1, 2, -1] 这 3 个解是重复的，
即使 -1 可能出现 100 次，每次使用的 -1 的数组下标都是不同的。

这里就需要去重和排序了。map 记录每个数字出现的次数，
然后对 map 的 key 数组进行排序，最后在这个排序以后的数组里面扫，
找到另外 2 个数字能和自己组成 0 的组合。
*/

// 参考牛牛码特
func threeSum2(nums []int) [][]int {
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

/* 参考思路：
如果暴力去做，那么需要找所有3元组合，需要三层嵌套for循环，复杂度O(N^3)

因为是算和问题，有序肯定比无序好做，我们可以先排序，得到一个有序的数组。

然后每一个元素去找可以组队的另外两个元素，因为是有序，所以可以用双指针：

左指针从当前位置+1开始，右指针从最后一个元素开始，这样根据三数之和，往中间收拢，最终得到结果。

时间复杂度O(n^2)

空间复杂度O(n)​
*/