package leetcode

/* 876. 链表的中间结点
给定一个头结点为 head 的非空单链表，返回链表的中间结点。
如果有两个中间结点，则返回第二个中间结点。

示例 1：
输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])

返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。

注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5,
以及 ans.next.next.next = NULL.

示例 2：

输入：[1,2,3,4,5,6]

输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。

提示：
给定链表的结点数介于 1 和 100 之间。

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

func middleNode(head *ListNode) *ListNode {
	if head == nil || head.Next == nil { // 边界条件，链表为空和仅有一个元素的case
		return head
	}

	p1, p2 := head, head
	for p2.Next != nil && p2.Next.Next != nil { // 避免p2走两步，超出链表范围
		p1 = p1.Next // p1 每次走1步
		p2 = p2.Next.Next // p2 每次走2步
	}
	length := 0
	cur := head
	for cur != nil { // 遍历链表以统计链表长度
		length++
		cur = cur.Next
	}
	if length % 2 == 0 { // 链表长度为偶数，饭会第二个中间节点
		return p1.Next
	}
	return p1
}

/*
题目大意
输出链表中间结点。这题在前面题目中反复出现了很多次了。
如果链表长度是奇数，输出中间结点是中间结点。
如果链表长度是双数，输出中间结点是中位数后面的那个结点。

解题思路
这道题有一个很简单的做法，用 2 个指针只遍历一次就可以找到中间节点。
一个指针每次移动 2 步，另外一个指针每次移动 1 步，
当快的指针走到终点的时候，慢的指针就是中间节点。
*/
