package leetcode

import (
	// "strconv"
	"container/heap"
	"github.com/yuancf1024/algorithm-go/structures"
)

// TreeNode define
type TreeNode = structures.TreeNode

/* 173. 二叉搜索树迭代器
实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。
BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于
 BST 中的数字，且该数字小于 BST 中的任何元素。
boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
int next()将指针向右移动，然后返回指针处的数字。
注意，指针初始化为一个不存在于 BST 中的数字，
所以对 next() 的首次调用将返回 BST 中的最小元素。

你可以假设 next() 调用总是有效的，也就是说，
当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。
*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// BSTIterator define
type BSTIterator struct {
	pq PriorityQueueOfInt
	count int
}

// Constructor173 define
func Constructor173(root *TreeNode) BSTIterator {
	result, pq := []int{}, PriorityQueueOfInt{}
	postorder(root, &result)
	for _, v := range result {
		heap.Push(&pq, v)
	}
	bs := BSTIterator{pq: pq, count: len(result)}
	return bs
}

// 后序遍历
func postorder(root *TreeNode, output *[]int) {
	if root != nil {
		postorder(root.Left, output)
		postorder(root.Right, output)
		*output = append(*output, root.Val)
	}
}

/** @return the next smallest number */
func (this *BSTIterator) Next() int {
	this.count--
	return heap.Pop(&this.pq).(int)
}

/** @return whether we have a next smallest number */
func (this *BSTIterator) HasNext() bool {
	return this.count != 0
}

/*
解题思路
用优先队列解决即可
*/

/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */

type PriorityQueueOfInt []int

func (pq PriorityQueueOfInt) Len() int {
	return len(pq)
}

func (pq PriorityQueueOfInt) Less(i, j int) bool {
	return pq[i] < pq[j]
}

func (pq PriorityQueueOfInt) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueueOfInt) Push(x interface{}) {
	item := x.(int)
	*pq = append(*pq, item)
}

func (pq *PriorityQueueOfInt) Pop() interface{} {
	n := len(*pq)
	item := (*pq)[n-1]
	*pq = (*pq)[:n-1]
	return item
}