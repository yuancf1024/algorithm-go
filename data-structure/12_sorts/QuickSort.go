package _2_sorts

// QuickSort is quicksort methods for golang
func QuickSort(arr []int) {
	separateSort(arr, 0, len(arr)-1)
}

// 快速排序递归函数，start、end为下标
func separateSort(arr []int, start, end int) {
	// 递归终止条件
	if start >= end {
		return
	}
	// 获取分区点
	i := partition(arr, start, end)
	separateSort(arr, start, i-1)
	separateSort(arr, i+1, end)
}

// 分区函数
func partition(arr []int, start, end int) int {
	// 选取最后一位当对比数字
	pivot := arr[end]

	var i = start
	for j := start; j < end; j++ {
		if arr[j] < pivot {
			if !(i == j) { // i、j不相等才需要交换
				// 交换位置
				arr[i], arr[j] = arr[j], arr[i]
			}
			i++
		}
	}
	arr[i], arr[end] = arr[end], arr[i]
	return i
}