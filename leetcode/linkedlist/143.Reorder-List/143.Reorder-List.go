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
	link(head, reverseList(tmp), dummy) // 此处的哨兵节点处理得很妙
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
		tmp := node1.Next // 保存node1后面的节点

		prev.Next = node1
		node1.Next = node2
		prev = node2 // prev为暂时连接链表的最后一个节点

		node1 = tmp // node1后移
		node2 = node2.Next // node2后移
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

// 参考halfrost 不是很好理解
// 解法1：单链表
func reorderList_v1(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	// 寻找中间节点
	p1, p2 := head, head
	for p2.Next != nil && p2.Next.Next != nil {
		p1 = p1.Next
		p2 = p2.Next.Next
	}

	// 反转链表后半部分 1->2->3->4->5->6 to 1->2->3->6->5->4
	// preMiddle := p1
	// preCurrent := p1.Next
	// for preCurrent.Next != nil {
	// 	current := preCurrent.Next
		
	// }
	preMiddle := p1
	preCurrent := p1.Next
	for preCurrent.Next != nil {
		current := preCurrent.Next
		preCurrent.Next = current.Next
		current.Next = preMiddle.Next
		preMiddle.Next = current
	}

	// 重新拼接链表  1->2->3->6->5->4 to 1->6->2->5->3->4
	p1 = head
	p2 = preMiddle.Next // 后半段链表头节点
	for p1 != preMiddle {
		preMiddle.Next = p2.Next
		p2.Next = p1.Next
		p1.Next = p2
		p1 = p2.Next
		p2 = preMiddle.Next
	}
	return head
}
/*
参考halfrost：
最近简单的方法是先把链表存储到数组里，然后找到链表中间的结点，
按照规则拼接即可。这样时间复杂度是 O(n)，空间复杂度是 O(n)。

更好的做法是结合之前几道题的操作：链表逆序，找中间结点。
先找到链表的中间结点，然后利用逆序区间的操作，
如 第 92 题 里的 reverseBetween() 操作，
只不过这里的反转区间是从中点一直到末尾。
最后利用 2 个指针，一个指向头结点，一个指向中间结点，
开始拼接最终的结果。这种做法的时间复杂度是 O(n)，空间复杂度是 O(1)。
*/