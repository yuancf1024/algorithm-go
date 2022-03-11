package _4_sorts

import "testing"

func TestRadixSort(t *testing.T) {
	arr := []int{5, 4}
	RadixSort(arr, len(arr))
	t.Log(arr)

	arr = []int{5, 4, 3, 2, 1}
	RadixSort(arr, len(arr))
	t.Log(arr)

	arr = []int{15, 34, 43, 52, 13}
	RadixSort(arr, len(arr))
	t.Log(arr)
}