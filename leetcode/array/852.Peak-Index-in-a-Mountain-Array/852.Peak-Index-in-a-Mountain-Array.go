package leetcode

/* 852. 山脉数组的峰顶索引
符合下列属性的数组 arr 称为 山脉数组 ：
- arr.length >= 3
- 存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
给你由整数组成的山脉数组 arr ，
返回任何满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > 
arr[i + 1] > ... > arr[arr.length - 1] 的下标 i 。

示例 1：
输入：arr = [0,1,0]
输出：1

示例 2：
输入：arr = [0,2,1,0]
输出：1

示例 3：
输入：arr = [0,10,5,2]
输出：1

示例 4：
输入：arr = [3,4,5,1]
输出：2

示例 5：
输入：arr = [24,69,100,99,79,78,67,36,26,19]
输出：2
 
提示：
3 <= arr.length <= 10^4
0 <= arr[i] <= 10^6
题目数据保证 arr 是一个山脉数组

进阶：很容易想到时间复杂度 O(n) 的解决方案，
你可以设计一个 O(log(n)) 的解决方案吗？
*/

// 解法1 简单的遍历一次
func peakIndexInMountainArray(arr []int) int {
	for i := 1; i < len(arr) - 1; i++ {
		if arr[i] > arr[i-1] && arr[i] > arr[i+1] {
			return i
		}
	}
	return 0
}

// 解法2 标准的二分搜索
func peakIndexInMountainArray1(arr []int) int {
	low, high := 0, len(arr) - 1
	for low < high {
		mid := low + ((high - low) >> 1)
		// 如果 mid 较大，则左侧存在峰值，high = m，如果 mid + 1 较大，则右侧存在峰值，low = mid + 1
		if arr[mid] > arr[mid+1] {
			high = mid
		} else {
			low = mid + 1
		}
	}
	return low
}

// 解法3 变形的二分搜索
func  peakIndexInMountainArray2(arr []int) int {
	low, high := 0, len(arr)-1
	for low <= high {
		mid := low + ((high - low) >> 1)
		if arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1] {
			return mid
		}
		if arr[mid] > arr[mid+1] && arr[mid] < arr[mid-1] {
			high = mid - 1
		}
		if arr[mid] < arr[mid+1] && arr[mid] > arr[mid-1] {
			low = mid + 1
		}
	}
	return 0
}

/*
解题思路
- 给出一个数组，数组里面存在有且仅有一个“山峰”，(山峰的定义是，
	下标 i 比 i-1、i+1 位置上的元素都要大)，找到这个“山峰”，
	并输出其中一个山峰的下标。
- 这一题直接用二分搜索即可，数组中的元素算基本有序。
判断是否为山峰的条件为比较左右两个数，如果当前的数比左右两个数都大，
即找到了山峰。其他的情况都在山坡上。这一题有两种写法，
第一种写法是标准的二分写法，第二种写法是变形的二分写法。
*/