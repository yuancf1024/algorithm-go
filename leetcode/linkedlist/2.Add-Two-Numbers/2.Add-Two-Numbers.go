package leetcode

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

//  精简、巧妙的实现
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{Val: 0} // 新建虚拟头结点
	n1, n2, carry, current := 0, 0, 0, head
	for l1 != nil || l2 != nil || carry != 0 {
		if l1 == nil {
			n1 = 0
		} else {
			n1 = l1.Val
			l1 = l1.Next
		}

		if l2 == nil {
			n2 = 0
		} else {
			n2 = l2.Val
			l2 = l2.Next
		}

		current.Next = &ListNode{Val: (n1 + n2 + carry) % 10} // 当前位相加的取余，保留在本位上
		current = current.Next
		carry = (n1 + n2 + carry) / 10 // 当前位相加的进位，下一个高位需要加上
	}
	return head.Next
}


/*
参考大佬halfrost:

需要注意的是各种进位问题。

极端情况，例如

Input: (9 -> 9 -> 9 -> 9 -> 9) + (1 -> )
Output: 0 -> 0 -> 0 -> 0 -> 0 -> 1
为了处理方法统一，可以先建立一个虚拟头结点，这个虚拟头结点的 Next 指向真正的 head，
这样 head 不需要单独处理，直接 while 循环即可。
另外判断循环终止的条件不用是 p.Next ！= nil，
这样最后一位还需要额外计算，循环终止条件应该是 p != nil。

上述代码已被优化和调整得非常精简、巧妙！👍
面试过程中，很难实现这种，需要勤加练习！💪
*/

// 原始实现
func addTwoNumbers1(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil || l2 == nil {
		return nil
	}
	head := &ListNode{Val: 0, Next: nil}
	current := head
	carry := 0
	for l1 != nil || l2 != nil {
		var x, y int
		if l1 == nil {
			x = 0
		} else {
			x = l1.Val
		}
		if l2 == nil {
			y = 0
		} else {
			y = l2.Val
		}
		current.Next = &ListNode{Val: (x + y + carry) % 10, Next: nil}
		current = current.Next
		carry = (x + y + carry) / 10
		if l1 != nil {
			l1 = l1.Next
		}
		if l2 != nil {
			l2 = l2.Next
		}
	}
	if carry > 0 {
		current.Next = &ListNode{Val: carry % 10, Next: nil}
	}
	return head.Next
}