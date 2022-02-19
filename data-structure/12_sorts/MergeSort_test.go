package _2_sorts

import "testing"

func TestMergeSort(t *testing.T) {
	arr := []int{5, 4}
	MergeSort(arr)
	t.Log(arr)

	arr1 := []int{5, 4, 3, 2, 1}
	MergeSort(arr1)
	t.Log(arr1)
}