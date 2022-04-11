package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/*
给定一个头结点为 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
    if head == nil || head.Next == nil { // 特殊情况
		return head
	}

	slow, fast := head, head
	for fast.Next != nil && fast.Next.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	length := 0
	cur := head
	for cur != nil {
		length++
		cur = cur.Next
	}
	if length % 2 == 0 {
		return slow.Next
	}
	return slow
}

// 头节点很容易，怎么一开始就指向尾节点呢？
// 果然很巧妙，利用两个指针的速度差

/*
这道题有一个很简单的做法，用 2 个指针只遍历一次就可以找到中间节点。
一个指针每次移动 2 步，另外一个指针每次移动 1 步，
当快的指针走到终点的时候，慢的指针就是中间节点。
*/