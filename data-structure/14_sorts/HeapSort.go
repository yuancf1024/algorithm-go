package _4_sorts

func maxHeap(heap []int, start, end int) {
	var dad int = start
	var son int = dad*2 + 1
	for son <= end {
		if (son+1 <= end && heap[son] < heap[son+1]) {
			son++
		}

		if (heap[dad] > heap[son]) {
			return
		} else {
			heap[dad], heap[son] = heap[son], heap[dad]
			dad = son
			son = 2*dad + 1
		}
	}
}

func HeapSort(heap []int) {
	n := len(heap)
	// 升序排序首先构造大顶堆
	for i := n/2 - 1; i >= 0; i-- {
		maxHeap(heap, i, n - 1)
	}

	// 然后将每个最大元素放到数组的末尾，最后得到升序排序数组
	for i := n-1; i > 0; i-- {
		heap[0], heap[i] = heap[i], heap[0]
		maxHeap(heap, 0, i-1)
	}

}