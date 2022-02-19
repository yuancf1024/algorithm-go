package _2_sorts

// 归并排序起点
func MergeSort(arr []int) {
	arrLen := len(arr)
	// 处理数组只有一个元素的情况
	if arrLen <= 1 {
		return
	}

	mergeSort(arr, 0, arrLen-1)
}

// 递归调用函数
func mergeSort(arr []int, start, end int) {
	// 递归终止条件
	if start >= end {
		return
	}

	// 取中间位置
	mid := (start + end) / 2
	// 分治递归
	mergeSort(arr, start, mid)
	mergeSort(arr, mid+1, end)
	// 合并函数
	merge(arr, start, mid, end)
}

func merge(arr []int, start, mid, end int) {
	// 申请和原始数组一样大小的临时数组（此处为Go语言的切片）
	tmpArr := make([]int, end-start+1)

	// 初始化变量i、j、k
	i := start
	j := mid + 1
	k := 0
	for ; i <= mid && j <= end; k++ {
		if arr[i] <= arr[j] { // 将更小的元素复制到临时数组
			tmpArr[k] = arr[i]
			i++
		} else {
			tmpArr[k] = arr[j]
			j++
		}
	}

	// 将剩余的数据拷贝到临时数组 tmp
	for ; i <= mid; i++ {
		tmpArr[k] = arr[i]
		k++
	}

	for ; j <= end; j++ {
		tmpArr[k] = arr[j]
		k++
	}
	// 将 tmp 中的数组拷贝回原始数组
	copy(arr[start:end+1], tmpArr)
}