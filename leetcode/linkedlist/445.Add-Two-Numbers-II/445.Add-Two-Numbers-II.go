package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/* 445. 两数相加 II
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。
它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// 参考halfrost 
// 解法1：先反转链表，再逐个相加
func addTwoNumbers445(l1 *ListNode, l2 *ListNode) *ListNode {
	reservedL1, reservedL2 := reverseList(l1), reverseList(l2)

	dummyHead := &ListNode{} // 新建哨兵结点，默认值为0
	head := dummyHead
	carry := 0 // 保存节点间相加的进位值
	for reservedL1 != nil || reservedL2 != nil || carry > 0 {
		val := carry // val 存储进位值
		if reservedL1 != nil {
			val = reservedL1.Val + val
			reservedL1 = reservedL1.Next
		}
		if reservedL2 != nil {
			val = reservedL2.Val + val
			reservedL2 = reservedL2.Next
		}
		carry = val / 10 // val的十位，保存进位值
		head.Next = &ListNode{Val: val % 10} // val的个位添加进当前结点
		head = head.Next
	}
	return reverseList(dummyHead.Next)
}

func reverseList(head *ListNode) *ListNode {
	var prev *ListNode
	for head != nil {
		tmp := head.Next
		head.Next = prev
		prev = head
		head = tmp
	}
	return prev
}

/*
题目大意
这道题是第 2 题的变种题，第 2 题中的 2 个数是从个位逆序排到高位，
这样相加只用从头交到尾，进位一直进位即可。这道题目中强制要求不能把链表逆序。
2 个数字是从高位排到低位的，这样进位是倒着来的。

解题思路
思路也不难，加法只用把短的链表依次加到长的链表上面来就可以了，
最终判断一下最高位有没有进位，有进位再往前进一位。
加法的过程可以用到递归。
*/

// TODO 递归实现 + 栈的实现（后进先出）