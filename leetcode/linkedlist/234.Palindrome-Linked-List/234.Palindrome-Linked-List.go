package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/* 234. 回文链表
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
如果是，返回 true ；否则，返回 false 。
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 自己写的代码：通过测试用例：75 / 86 无法处理三个元素的case [1,0,0]
// 没有考虑处理链表节点为奇数时的情况，需要去除中间节点
 func isPalindrome(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}

	if head.Next.Next == nil {
		if head.Val != head.Next.Val {
			return false
		}
		return true
	}

	dummy := &ListNode{Val: 0}
	dummy.Next = head
	slow, fast := head, head
	for fast.Next != nil {
		slow = slow.Next
		fast = fast.Next
		if fast.Next != nil {
			fast = fast.Next
		}
	}
	p1 := slow.Next
	p2 := reverseList(p1)
	for head.Next != nil && p2.Next != nil {
		if head.Val != p2.Val {
			return false
		}
		head = head.Next
		p2 = p2.Next
	}
	return true
}

func reverseList(head *ListNode) *ListNode {
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

// 参考剑指offer
func isPalindrome_v1(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}

	slow, fast := head, head.Next
	for fast.Next != nil && fast.Next.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}
	secondHalf := slow.Next
	if fast.Next != nil { // 链表节点为奇数时，slow.Next 代表的是中间节点
		secondHalf = slow.Next.Next // 跳过链表节点为奇数时的中间节点
	}
	slow.Next = nil
	// 反转前半段
	node1 := reverseList(head)
	node2 := secondHalf
	for node1 != nil && node2 != nil {
		if node1.Val != node2.Val {
			return false
		}
		node1 = node1.Next
		node2 = node2.Next
	}
	return node1 == nil && node2 == nil // 更加严谨的判断
}

/* 思路
尝试把链表分成前后两半，然后把其中一半反转。
对于链表节点是奇数的情况要去除中间节点。
*/

