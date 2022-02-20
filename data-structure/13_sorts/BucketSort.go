package LinearSort

import (
	"fmt"
	"algorithm-go/data-structure/12_sorts"
)
// 	// "algorithm/Sort"
// 	// "github.com/yuancf1024/algorithm-go/data-structure/_2_sorts"

// )
// 桶排序

// 获取待排序数组中的最大值
func getMax(a []int) int {
	max := a[0]
	for i := 1; i < len(a); i++ {
		if a[i] > max {
			max = a[i]
		}
	}
	return max
}

func BucketSort(a []int) {
	num := len(a)
	if num < 1 {
		return
	}
	max := getMax(a)
	buckets := make([][]int, num) // 二维切片

	index := 0
	for i := 0; i < num; i++ {
		index = a[i]*(num-1) / max // 桶序号
		buckets[index] = append(buckets[index], a[i]) // 加入对应的桶中
	}

	tmpPos := 0 // 标记数组位置
	for i := 0; i < num; i++ {
		bucketLen := len(buckets[i])
		if bucketLen > 0 {
			_2_sorts.QuickSort(buckets[i]) // 桶内做快速排序
			copy(a[tmpPos:], buckets[i])
			tmpPos += bucketLen
		}
	}
}

// 桶排序简单实现
func BucketSortSimple(source []int) {
	if len(source) <= 1 {
		return
	}
	array := make([]int, getMax(source)+1)
	for i := 0; i < len(source); i++ {
		array[source[i]] ++
	}
	fmt.Println(array)
	c := make([]int, 0)
	for i := 0; i < len(array); i++ {
		for array[i] != 0 {
			c = append(c, i)
			array[i] --
		}
	}
	copy(source, c)
}


// 下列代码理论上不该出现，但是没有把Go的导包给弄清楚
// TODO：fix bug：实现对algorithm-go里代码的复用
// 快速排序 QuickSort
// func QuickSort(a []int) []int

// func QuickSort(arr []int) {
// 	separateSort(arr, 0, len(arr)-1)
// }

// // 快速排序递归函数，start、end为下标
// func separateSort(arr []int, start, end int) {
// 	// 递归终止条件
// 	if start >= end {
// 		return
// 	}
// 	// 获取分区点
// 	i := partition(arr, start, end)
// 	separateSort(arr, start, i-1)
// 	separateSort(arr, i+1, end)
// }

// // 分区函数
// func partition(arr []int, start, end int) int {
// 	// 选取最后一位当对比数字
// 	pivot := arr[end]

// 	var i = start
// 	for j := start; j < end; j++ {
// 		if arr[j] < pivot {
// 			if !(i == j) { // i、j不相等才需要交换
// 				// 交换位置
// 				arr[i], arr[j] = arr[j], arr[i]
// 			}
// 			i++
// 		}
// 	}
// 	arr[i], arr[end] = arr[end], arr[i]
// 	return i
// }