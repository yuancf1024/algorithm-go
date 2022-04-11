package leetcode

func twoSum167(numbers []int, target int) []int {
    // 双指针,首尾指针
    n := len(numbers)
    if n == 2 && numbers[0] + numbers[1] == target {
        return []int{1, 2}
    }
    res := []int{}
    slow, fast := 0, n-1
    for slow <= fast {
        if numbers[slow] + numbers[fast] > target {
            fast--
        } else if numbers[slow] + numbers[fast] < target {
            slow++
        } else {
           res = []int{slow+1, fast+1}
		   break // 忘记写break跳出，程序就是死循环
        }
    }
    return res
}

// 更简洁的实现, 利用数组有序的特性
func twoSum167_v2(numbers []int, target int) []int {
	i, j := 0, len(numbers)-1
	for i < j {
		if numbers[i] + numbers[j] == target {
			return []int{i + 1, j + 1}
		}
		if numbers[i] + numbers[j] < target {
			i++
		} else {
			j--
		}
	}
	return nil
}

// 之前的两数之和题目：数组未排序，使用哈希表解决
// 不管数组是否有序，空间复杂度比上一种解法要多O(n)
func twoSum167_v3(numbers []int, target int) []int {
	m := make(map[int]int)
	n := len(numbers)
	for i := 0; i < n; i++ {
		another := target - numbers[i]
		if idx, ok := m[another]; ok {
			return []int{idx + 1, i + 1}
		}
		m[numbers[i]] = i
	}
	return nil
}
