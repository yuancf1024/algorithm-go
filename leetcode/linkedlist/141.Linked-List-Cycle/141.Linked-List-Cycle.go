package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/*
给你一个链表的头节点 head ，判断链表中是否有环。
如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，
则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来
表示链表尾连接到链表中的位置（索引从 0 开始）。
注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
如果链表中存在环 ，则返回 true 。 否则，返回 false 。
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    fast := head
	slow := head
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
		if fast == slow {
			return true
		}
	}
	return false
}

// 进阶：你能用 O(1)（即，常量）内存解决此问题吗？

/*解题思路：
给 2 个指针，一个指针是另外一个指针的下一个指针。
快指针一次走 2 格，慢指针一次走 1 格。
如果存在环，那么前一个指针一定会经过若干圈之后追上慢的指针。
*/