package _4_sorts

import "testing"

func TestHeapSort(t *testing.T) {
	arr := []int{1, 4, 2, 6, 3, 6, 9, 0}
	HeapSort(arr)
	t.Log(arr)

	arr = []int{5, 4, 3, 2, 1}
	HeapSort(arr)
	t.Log(arr)
}