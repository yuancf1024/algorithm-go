package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/* 206. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 方法1：迭代
func reverseList(head *ListNode) *ListNode {
    var behind *ListNode
	cur := head
	for cur != nil {
		next := cur.Next // 存储后一个节点
		cur.Next = behind // 当前节点指向前一个节点
		behind = cur // 前一个节点为cur
		cur = next // 当前节点后移一位
	}
	return behind
}

/*
假设链表为 1→2→3→∅，我们想要把它改成 ∅←1←2←3。
在遍历链表时，将当前节点的 next 指针改为指向前一个节点。
由于节点没有引用其前一个节点，因此必须事先存储其前一个节点。
在更改引用之前，还需要存储后一个节点。最后返回新的头引用。

复杂度分析
时间复杂度：O(n)，其中 n 是链表的长度。需要遍历链表一次。
空间复杂度：O(1)。

执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：2.4 MB, 在所有 Go 提交中击败了100.00%的用户
*/

// 方法2：递归
func reverseList_v2(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	newHead := reverseList_v2(head.Next)
	head.Next.Next = head
	head.Next = nil
	return newHead
}
/*
递归版本稍微复杂一些，其关键在于反向工作。
假设链表的其余部分已经被反转，现在应该如何反转它前面的部分？
假设链表为：n1→…→nk−1→nk→nk+1→…→nm→∅
若从节点nk+1到nm已经被反转，而我们正处于nk。
n1→…→nk−1→nk→nk+1←…←nm
我们希望 nk+1的下一个节点指向nk。

所以，nk.next.next=nk。

需要注意的是 n1的下一个节点必须指向 ∅。如果忽略了这一点，
链表中可能会产生环。

复杂度分析
时间复杂度：O(n)，其中 n 是链表的长度。需要对链表的每个节点进行反转操作。
空间复杂度：O(n)，其中 n 是链表的长度。
空间复杂度主要取决于递归调用的栈空间，最多为 n 层。
*/

// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？