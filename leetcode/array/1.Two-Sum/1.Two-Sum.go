package leetcode

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

func twoSum(nums []int, target int) []int {
    m := make(map[int]int) // key 对应数组元素，value 对应 元素在数组的下标
    for k, v := range nums {
        if idx, ok := m[target-v]; ok {
            return []int{idx, k}
        }
        m[v] = k // 数字v 对应的 target-v 没有出现在map中，于是把v存入map
    }
    return nil
}

/*
这道题最优的做法时间复杂度是 O(n)。

顺序扫描数组，对每一个元素，在 map 中找能组合给定值的另一半数字，
如果找到了，直接返回 2 个数字的下标即可。如果找不到，
就把这个数字存入 map 中，等待扫到“另一半”数字的时候，再取出来返回结果。
*/