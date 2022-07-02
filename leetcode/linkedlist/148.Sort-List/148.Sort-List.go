package leetcode

/* 148. 排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5 

*/


import (
	"github.com/yuancf1024/algorithm-go/structures"
)

// ListNode define
type ListNode = structures.ListNode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func sortList(head *ListNode) *ListNode {
	length := 0
	cur := head
	for cur != nil { // 遍历链表获得链表长度
		length++
		cur = cur.Next
	}
	if length <= 1 { // 链表长度为0或1的边界case
		return head
	}

	middleNode := middleNode(head) // 获取中间节点
	cur = middleNode.Next // 临时保存中间节点后面的链表头节点
	middleNode.Next = nil // 中间节点前面的链表尾节点指向空
	middleNode = cur // 代表第二段链表头节点

	left := sortList(head)
	right := sortList(middleNode)
	return mergeTwoLists(left, right)
}

// 找到链表的中间节点
func middleNode(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	p1, p2 := head, head
	for p2.Next != nil && p2.Next.Next != nil {
		p1 = p1.Next
		p2 = p2.Next.Next
	}
	return p1
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	if l1.Val < l2.Val {
		l1.Next = mergeTwoLists(l1.Next, l2)
		return l1
	}
	l2.Next = mergeTwoLists(l1, l2.Next)
	return l2
}

/*
解题思路
这道题只能用归并排序才能符合要求。归并排序需要的 2 个操作在其他题目已经出现过了，
取中间点是第 876 题，合并 2 个有序链表是第 21 题。
*/