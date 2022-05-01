package leetcode

/* 142. 环形链表 II
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。
如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，
则链表中存在环。 为了表示给定链表中的环，
评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。
注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。
*/

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func detectCycle(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return nil
	}
	isCycle, slow := hasCycle142(head)
	if !isCycle { // 链表没有环
		return nil
	}
	fast := head
	for fast != slow {
		fast = fast.Next
		slow = slow.Next
	}
	return fast
}

func hasCycle142(head *ListNode) (bool, *ListNode) {
	fast, slow := head, head
	for slow != nil && fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
		if fast == slow {
			return true, slow
		}
	}
	return false, nil
}

/*
解题思路
这道题是第 141 题的加强版。在判断是否有环的基础上，还需要输出环的第一个点。

分析一下判断环的原理。fast 指针一次都 2 步，slow 指针一次走 1 步。
令链表 head 到环的一个点需要 x1 步，从环的第一个点到相遇点需要 x2 步，
从环中相遇点回到环的第一个点需要 x3 步。那么环的总长度是 x2 + x3 步。

fast 和 slow 会相遇，说明他们走的时间是相同的，
可以知道他们走的路程有以下的关系：

fast 的 t = (x1 + x2 + x3 + x2) / 2
slow 的 t = (x1 + x2) / 1

x1 + x2 + x3 + x2 = 2 * (x1 + x2)

所以 x1 = x3
所以 2 个指针相遇以后，如果 slow 继续往前走，
fast 指针回到起点 head，两者都每次走一步，
那么必定会在环的起点相遇，相遇以后输出这个点即是结果。
*/
