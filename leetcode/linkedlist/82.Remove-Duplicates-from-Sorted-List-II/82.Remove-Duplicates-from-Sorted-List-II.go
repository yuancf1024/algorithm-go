package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/* 82. 删除排序链表中的重复元素 II
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，
只留下不同的数字 。返回 已排序的链表 。
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */


// 双循环简单解法 O(n*m) 建议采用
func deleteDuplicates_v2(head *ListNode) *ListNode {
	if head == nil {
		return head
	}

	nilNode := &ListNode{Val: 0, Next: head}
	head = nilNode

	lastVal := 0
	for head.Next != nil && head.Next.Next != nil { // 增加了一个哨兵节点nilNode，因此不用考虑head节点的Val
		if head.Next.Val == head.Next.Next.Val {
			lastVal = head.Next.Val
			for head.Next != nil && lastVal == head.Next.Val { // 把重复元素都跳过了
				head.Next = head.Next.Next
			}
		} else {
			head = head.Next
		}
	}
	return nilNode.Next
}

/*
双循环简单解法，通过引入哨兵节点nilNode，可以解决首节点重复的情况
通过设置双循环遍历，可删除全部重复元素
*/

// 自己写的bug程序，想要复用leetcode-83里面的程序
// func deleteDuplicates(head *ListNode) *ListNode {
//     cur := head
//     var pre *ListNode
//     pre = cur
    
//     if cur == nil {
//         return nil
//     }
//     if cur.Next == nil {
//         return head
//     }

//     // if cur.Next.Val == cur.Val {
//     //     cur = pre.Next.Next
//     // }
//     for cur.Next != nil {
//         if cur.Next.Val == cur.Val { // 如何处理头节点相同的情形,pre怎么记录cur前一个节点
//             pre.Next = cur
//             cur.Next = cur.Next.Next
//         } else {
//             cur = cur.Next
//         }
//     }
//     return head
// }

/*
本题和leetcode-83的区别：本题会把重复数字的节点全部删除，一个不留，
而83则会全部删除。
那么本题还需要多一个额外的pre指针，指向重复元素的前一个结点
*/

// 和我的思路一脉相承
// 想要复用代码，想法很好，但是无法解决核心问题：重复元素全部删除
// 被复用的代码无法解决删除第一个重复元素
func deleteDuplicates1(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	if head.Next != nil && head.Val == head.Next.Val {
		for head.Next != nil && head.Val == head.Next.Val {
			head = head.Next
		}
		return deleteDuplicates(head.Next)
	}
	head.Next = deleteDuplicates(head.Next)
	return head
}

func deleteDuplicates(head *ListNode) *ListNode {
	cur := head
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return head
	}

	for cur.Next != nil {
		if cur.Next.Val == cur.Val {
			cur.Next = cur.Next.Next
		} else {
			cur = cur.Next
		}
	}
	return head
}

// 使用front标记重复元素的前面一个节点 太麻烦
func deleteDuplicates_v1(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return head
	}
	newHead := &ListNode{Next: head, Val: -999999}
	cur := newHead
	last := newHead
	front := head
	for front.Next != nil {
		if front.Val == cur.Val {
			// fmt.Printf("相同节点front = %v | cur = %v | last = %v\n", front.Val, cur.Val, last.Val)
			front = front.Next
			continue
		} else {
			if cur.Next != front {
				// fmt.Printf("删除重复节点front = %v | cur = %v | last = %v\n", front.Val, cur.Val, last.Val)
				last.Next = front
				if front.Next != nil && front.Next.Val != front.Val {
					last = front
				}
				cur = front
				front = front.Next
			} else {
				// fmt.Printf("常规循环前front = %v | cur = %v | last = %v\n", front.Val, cur.Val, last.Val)
				last = cur
				cur = cur.Next
				front = front.Next
				// fmt.Printf("常规循环后front = %v | cur = %v | last = %v\n", front.Val, cur.Val, last.Val)

			}
		}
	}
	if front.Val == cur.Val {
		// fmt.Printf("相同节点front = %v | cur = %v | last = %v\n", front.Val, cur.Val, last.Val)
		last.Next = nil
	} else {
		if cur.Next != front {
			last.Next = front
		}
	}
	return newHead.Next
}


// 双指针+删除标志位，单循环解法 O(n) 供参考
func deleteDuplicates_v3(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	nilNode := &ListNode{Val: 0, Next: head}
	// 上次遍历有删除操作的标志位
	lastIsDel := false
	// 虚拟空结点
	head = nilNode
	// 前后指针用于判断
	pre, back := head.Next, head.Next.Next
	// 每次只删除前面的一个重复的元素，留一个用于下次遍历判重
	// pre, back 指针的更新位置和值比较重要和巧妙
	for head.Next != nil && head.Next.Next != nil {
		if pre.Val != back.Val && lastIsDel {
			head.Next = head.Next.Next
			pre, back = head.Next, head.Next.Next
			lastIsDel = false
			continue
		}

		if pre.Val == back.Val {
			head.Next = head.Next.Next
			pre, back = head.Next, head.Next.Next
			lastIsDel = true
		} else {
			head = head.Next
			pre, back = head.Next, head.Next.Next
			lastIsDel = false
		}
	}
	// 处理 [1,1] 这种删除还剩一个的情况
	if lastIsDel && head.Next != nil {
		head.Next = nil
	}
	return nilNode.Next
}