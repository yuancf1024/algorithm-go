package leetcode

import (
	// "math"
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/* 160. 相交链表
给你两个单链表的头节点 headA 和 headB ，
请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 。

图示两个链表在节点 c1 开始相交：

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// 参考剑指offer
func getIntersectionNode(headA, headB *ListNode) *ListNode {
    countA, countB := countList(headA), countList(headB)
	delta := abs((countA - countB))
	var longer, shorter *ListNode
	if countA > countB {
		longer = headA
		shorter = headB
	} else {
		longer = headB
		shorter = headA
	}
	node1 := longer
	for i := 0; i < delta; i++ {
		node1 = node1.Next
	}
	node2 := shorter
	for node1 != node2 {
		node2 = node2.Next
		node1 = node1.Next
	}
	return node1
}

func countList(head *ListNode) int {
	count := 0
	for head != nil {
		count++
		head = head.Next
	}
	return count
}

func abs(value int) int {
	if value >= 0 {
		return value
	}
	return -value
}

/* 解题思路
首先遍历两个链表得到它们的长度，这样就能知道哪个链表比较长，
以及长的链表比短的链表多几个节点。在第2次遍历时，
第1个指针P1在较长的链表中先移动若干步，
再把第2个指针P2初始化到较短的链表的头节点，
然后这两个指针按照相同的速度在链表中移动，直到它们相遇。
两个指针相遇的节点就是两个链表的第1个公共节点。

复杂度分析：
上述代码将两个链表分别遍历两次，第1次得到两个链表的节点数，
第2次找到两个链表的第1个公共节点，这种方法的时间复杂度是O（m+n）。
由于不需要保存链表的节点，因此这种方法的空间复杂度是O（1）。
*/

// 参考halfrost 非常巧妙的拼接
func getIntersectionNode_v1(headA, headB *ListNode) *ListNode {
	// 边界检查
	if headA == nil || headB == nil {
		return nil
	}

	a := headA
	b := headB

	// 如果a、b长度不一样，那么在第二次迭代后会停止
	for a != b {
		if a == nil {
			a = headB
		} else {
			a = a.Next
		}

		if b == nil {
			b = headA
		} else {
			b = b.Next
		}
	}
	return a
}

/*
解题思路
这道题的思路其实类似链表找环。
给定的 2 个链表的长度如果一样长，都从头往后扫即可。
如果不一样长，需要先“拼成”一样长。把 B 拼接到 A 后面，把 A 拼接到 B 后面。
这样 2 个链表的长度都是 A + B。
再依次扫描比较 2 个链表的结点是否相同。
*/