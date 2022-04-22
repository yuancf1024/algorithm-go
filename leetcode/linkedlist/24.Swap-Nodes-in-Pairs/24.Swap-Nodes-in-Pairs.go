package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/* 24. Swap Nodes in Pairs
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

两两相邻的元素，翻转链表
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
//

// 方法1：直接按照题意做 不太好理解
func swapPairs(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
	dummy := &ListNode{Next: head} // 哨兵节点
	for pt := dummy; pt != nil && pt.Next != nil && pt.Next.Next != nil; {
		pt, pt.Next, pt.Next.Next, pt.Next.Next.Next = pt.Next, pt.Next.Next, pt.Next.Next.Next, pt.Next
	}
	return dummy.Next
}

/* 按照题意做即可。
*/

// 方法2：递归实现
func swapPairs_v2(head *ListNode) *ListNode {
	// 思路：将链表翻转转化为一个子问题，然后通过递归的方式依次解决
	// 先翻转两个，然后将后面的节点继续这样反转，然后将这些翻转后的节点连接起来
	return helper(head)
}

func helper(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	// 保存下一阶段的头指针
	nextHead := head.Next.Next
	// 翻转当前阶段指针
	next := head.Next
	next.Next = head
	head.Next = helper(nextHead)
	return next
}
