package leetcode

/* 167. 两数之和 II - 输入有序数组
找出两个数之和等于 target 的两个数字，
要求输出它们的下标。注意一个数字不能使用 2 次。
下标从小到大输出。假定题目一定有一个解。
*/

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
			return []int{idx + 1, i + 1} // 注意索引的起点
		}
		m[numbers[i]] = i
	}
	return nil
}

/* 复杂度分析：
最直观的解法：先在数组中固定一个数字，
再依次判断数组中其余的数字与它的和是不是等于k。
如果数组的长度是n，由于需要对每个数字和其他n-1个数字求和，
因此这种解法的时间复杂度是O（n^2）

使用二分查找优化:
上述解法可以用二分查找来优化。假设扫描到数字i，
如果数组中存在另一个数字k-i，那么就找到了一对和为k的数字。
我们没有必要通过从头到尾逐个扫描数组中的每个数字来判断数组中是否存在k-i。
由于数组是递增排序的，因此可以用二分查找在数组中搜索k-i。
二分查找的时间复杂度是O（logn），
因此优化之后的解法的时间复杂度是O（nlogn）

使用哈希表，空间换时间：
上述解法还可以用空间换时间进行优化。可以先将数组中的所有数字都放入一个哈希表，
然后逐一扫描数组中的每个数字。假设扫描到数字i，
如果哈希表中存在另一个数字k-i，那么就找到了一对和为k的数字。
判断哈希表中是否存在一个数字的时间复杂度是O（1），
因此新解法的时间复杂度是O（n），同时它需要一个大小为O（n）的哈希表，
空间复杂度也是O（n）。

双指针解法：
时间复杂度是O（n）、空间复杂度是O（1）的解法
*/
