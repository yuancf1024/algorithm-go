package leetcode

// 参考大神halfrost
// https://github.com/halfrost/LeetCode-Go/blob/master/leetcode/0001.Two-Sum/1.%20Two%20Sum_test.go
func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for k, v := range nums {
		if idx, ok := m[target-v]; ok {
			return []int{idx, k}
		}
		m[v] = k
	}
	return nil
}