package leetcode

/* 23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]

解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]

将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6

示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]

提示：
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4

*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

// ListNode define
type ListNode = structures.ListNode

func mergeKLists(lists []*ListNode) *ListNode {
	length := len(lists)
	if length < 1 { // 考虑边界case：链表数组为空
		return nil
	}
	if length == 1 { // 考虑边界case：链表数组为1
		return lists[0]
	}
	num := length / 2

	left := mergeKLists(lists[:num])
	right := mergeKLists(lists[num:])
	return mergeTwoLists1(left, right)
}

func mergeTwoLists1(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	if l1.Val < l2.Val {
		l1.Next = mergeTwoLists1(l1.Next, l2)
		return l1
	}
	l2.Next = mergeTwoLists1(l1, l2.Next)
	return l2
}

/*
题目大意
合并 K 个有序链表

解题思路
借助分治的思想，把 K 个有序链表两两合并即可。
相当于是第 21 题的加强版。
*/