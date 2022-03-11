package _4_sorts

import "math"

// 计数排序，a 是数组，n 是数组大小。假设数组中存储的都是非负整数
func CountingSort(a []int, n int) {
	if n <= 1 {
		return
	}

	// 查找数组中数据的范围
	var max int = math.MinInt32
	for i := range a {
		if a[i] > max {
			max = a[i]
		}
	}

	// 申请一个计数数组c，下标大小 [0, max]
	c := make([]int, max+1)
	for i := range a {
		c[a[i]]++ // 计算每个元素的个数，放入c中
	}

	// 依次累加
	for i := 1; i <= max; i++ {
		c[i] += c[i-1]
	}

	// 临时数组r，存储排序之后的结果
	r := make([]int, n)

	// 计算排序的关键步骤，有点难理解
	for i := n - 1; i >= 0; i-- {
		index := c[a[i]] - 1 // 计数数组c：索引代表原数组元素大小，值代表元数数量
		r[index] = a[i]
		c[a[i]]--
	}

	// 将结果拷贝给 a 数组
	// copy(a, r)
	for i := 0; i < n; i++ {
		a[i] = r[i]
	}
}
