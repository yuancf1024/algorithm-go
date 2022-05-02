package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/* 143. 重排链表
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

//  参考剑指offer实现
func reorderList(head *ListNode) *ListNode {
	dummy := &ListNode{Val: 0}
	dummy.Next = head
	slow, fast := dummy, dummy
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next
		if fast.Next != nil {
			fast = fast.Next
		}
	}
	tmp := slow.Next
	slow.Next = nil
	link(head, reverseList(tmp), dummy)
	return head
}

func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil  {
		return head
	}
	var prev *ListNode
	cur := head
	for cur != nil {
		tmp := cur.Next
		cur.Next = prev
		prev = cur
		cur = tmp
	}
	return prev
}

func link(node1, node2, head *ListNode) {
	prev := head
	for node1 != nil && node2 != nil {
		tmp := node1.Next

		prev.Next = node1
		node1.Next = node2
		prev = node2

		node1 = tmp
		node2 = node2.Next
	}
	if node1 != nil {
		prev.Next = node1 // 奇数情况下，前半段比后半段多1个节点
	}
}

/* 剑指offer 参考思路：
将链表分成两半，反转后半段链表，然后交替拼接两段链表
- 1. 使用双链表寻找到中间节点
- 2. 反转链表
- 3. 考虑链表节点奇偶数的问题。链表节点为奇数时，要确保链表的前半段
比后半段多一个节点。
*/