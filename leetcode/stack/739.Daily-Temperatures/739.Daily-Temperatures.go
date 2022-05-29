package leetcode

/* 739. 每日温度
给定一个整数数组 temperatures ，表示每天的温度，
返回一个数组 answer ，其中 answer[i] 是指在第 i 天之后，才会有更高的温度。如果气温在这之后都不会升高，
请在该位置用 0 来代替。

示例 1:
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]

示例 2:
输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]

示例 3:
输入: temperatures = [30,60,90]
输出: [1,1,0]

提示：
1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

// 解法一 普通做法 2个for循环嵌套 时间复杂度O(n^2)
func dailyTemperatures(temperatures []int) []int {
	res, j := make([]int, len(temperatures)), 0
	for i := 0; i < len(temperatures); i++ {
		for j = i + 1; j < len(temperatures); j++ {
			if temperatures[j] > temperatures[i] {
				res[i] = j - i
				break
			}
		}
	}
	return res
}

// 解法二 单调栈
func dailyTemperatures_stack(temperatures []int) []int {
	res := make([]int, len(temperatures))
	var toCheck []int
	for i, t := range temperatures {
		// 栈不为空且栈顶元素(下标)对应的温度数组元素小于遍历到的温度t
		for len(toCheck) > 0 && temperatures[toCheck[len(toCheck)-1]] < t {
			idx := toCheck[len(toCheck)-1] // 取栈顶元素(下标)
			res[idx] = i - idx // 根据题目要求的返回值
			toCheck = toCheck[:len(toCheck)-1] // 栈顶出栈
		}
		toCheck = append(toCheck, i)
	}
	return res
}

/*
这道题根据题意正常处理就可以了。2 层循环。另外一种做法是单调栈，
维护一个单调递减的单调栈即可。
*/