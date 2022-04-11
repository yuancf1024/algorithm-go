package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
1 <= n <= sz（链表节点数）=> 无需考虑 n 大于链表节点数的情形
*/


/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 该实现有bug，没有把所有的边界条件考虑清楚。通过测试用例：190 / 208
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 通过测试用例：190 / 208
func removeNthFromEnd_v1(head *ListNode, n int) *ListNode {
    if head == nil || head.Next == nil {
        return nil
    }

    slow, fast := head, head
    // for n > 0 { 
    //     fast = fast.Next
    //     n--
    // }

    // for fast.Next != nil { // 发生报错：panic: runtime error: invalid memory address or nil pointer dereference
    //     slow = slow.Next
    //     fast = fast.Next 
    // }

    for fast != nil { // 无法删除头节点，**因此需要新建一个头节点，其指针指向head**，参考解法1
        if n < 0 {
            slow = slow.Next
        }
        n--
        fast = fast.Next
    }
    slow.Next = slow.Next.Next
    return head
}

/*
这道题比较简单，先循环一次拿到链表的总长度，
然后循环到要删除的结点的前一个结点开始删除操作。
需要注意的一个特例是，有可能要删除头结点，要单独处理。

这道题有一种特别简单的解法。设置 2 个指针，
一个指针距离前一个指针 n 个距离。同时移动 2 个指针，
2 个指针都移动相同的距离。当一个指针移动到了终点，
那么前一个指针就是倒数第 n 个节点了。
*/

// 解法1
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	dummyHead := &ListNode{Next: head} // 包含了删除头节点的case
	preSlow, slow, fast := dummyHead, head, head
	for fast != nil {
		if n <= 0 {
			preSlow = slow
			slow = slow.Next
		}
		n--
		fast = fast.Next
	}
	preSlow.Next = slow.Next // 删除节点
	return dummyHead.Next
}

// 解法二， 对于n 大于链表节点数的特殊情形也可以通过
func removeNthFromEnd_v2(head *ListNode, n int) *ListNode {
	if head == nil {
		return nil
	}

	if n <= 0 {
		return head
	}

	current := head
	len := 0
	for current != nil {
		len++
		current = current.Next
	}
	if n > len {
		return head
	}

	if n == len {
		current := head
		head = head.Next
		current.Next = nil
		return head
	}

	current = head
	i := 0
	for current != nil {
		if i == len - n - 1 {
			deleteNode := current.Next
			current.Next = current.Next.Next
			deleteNode.Next = nil 
			break
		}
		i++
		current = current.Next
	}
	return head
}