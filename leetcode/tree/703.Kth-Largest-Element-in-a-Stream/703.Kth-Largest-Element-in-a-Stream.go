package leetcode

/* 703. 数据流中的第 K 大元素
设计一个找到数据流中第 k 大元素的类（class）。
注意是排序后的第 k 大元素，不是第 k 个不同的元素。

请实现 KthLargest 类：
KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
int add(int val) 将 val 插入数据流 nums 后，
返回当前数据流中第 k 大的元素。
 

示例：
输入：
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
输出：
[null, 4, 5, 5, 8, 8]

解释：
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
 

提示：
1 <= k <= 10^4
0 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
-10^4 <= val <= 10^4
最多调用 add 方法 10^4 次
题目数据保证，在查找第 k 大元素时，数组中至少有 k 个元素
*/

import (
	"container/heap"
	"sort"
)

type KthLargest struct {
	sort.IntSlice // 标准库里现成的最小堆
	k int
}


func Constructor(k int, nums []int) KthLargest {
	kl := KthLargest{k: k}
	for _, val := range nums {
		kl.Add(val)
	}
	return kl
}

func (kl *KthLargest) Push(v interface{}) {
	kl.IntSlice = append(kl.IntSlice, v.(int))
}

func (kl *KthLargest) Pop() interface{} {
	a := kl.IntSlice
	v := a[len(a)-1]
	kl.IntSlice = a[:len(a)-1]
	return v
}

func (kl *KthLargest) Add(val int) int {
	heap.Push(kl, val)
	if kl.Len() > kl.k {
		heap.Pop(kl)
	}
	return kl.IntSlice[0]
}


/**
 * Your KthLargest object will be instantiated and called as such:
 * obj := Constructor(k, nums);
 * param_1 := obj.Add(val);
 */

/*
解题思路
- 读完题就能明白这一题考察的是最小堆。
构建一个长度为 K 的最小堆，每次 pop 堆首(堆中最小的元素)，
维护堆首即为第 K 大元素。
- 这里有一个简洁的写法，常规的构建一个 pq 优先队列需要自己新建一个类型，
然后实现 Len()、Less()、Swap()、Push()、Pop() 这 5 个方法。
在 sort 包里有一个现成的最小堆，sort.IntSlice。
可以借用它，再自己实现 Push()、Pop()就可以使用最小堆了，节约一部分代码。
*/