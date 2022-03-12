package _4_sorts

func HeapSort2(arr []int) []int {
	arrLen := len(arr)
	buildMaxHeap(arr,arrLen)
	for i := arrLen-1; i >= 0; i-- {
		arr[0], arr[i] = arr[i], arr[0]
		arrLen--
		heapify(arr, 0, arrLen)
	}
	return arr
}

func buildMaxHeap(arr []int, arrLen int) {
	for i := arrLen/2; i >= 0; i-- {
		heapify(arr, i, arrLen)
	}
}

func heapify(arr []int, i, arrLen int) {
	left := 2*i + 1
	right := 2*i + 2
	largest := i
	if left < arrLen && arr[left] > arr[largest] {
		largest = left
	}

	if right < arrLen && arr[right] > arr[largest] {
		largest = right
	}

	if largest != i {
		arr[i], arr[largest] = arr[largest], arr[i]
		heapify(arr, largest, arrLen)
	}
}