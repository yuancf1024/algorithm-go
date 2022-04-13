package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 
Node.val == val 的节点，并返回 新的头节点 。
*/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// // 2022-04-13 自己写的
// func removeElements(head *ListNode, val int) *ListNode {
//     if head == nil {
//         return nil
//     }

//     preHead := &ListNode{Val: 0}
//     cur := preHead // 这里没有把cur 和 head联系起来
//     cur := head

//     for cur != nil {
//         if cur.Val == val {
//             cur.Next = cur.Next.Next // 犯错点：没有把preHead 和 cur 连接起来，而PreHead又不能直接使用
//             // 因此需要使用一个中间指针过渡一下
//         }
//         cur = cur.Next
//     }

//     return preHead.Next
// }

func removeElements(head *ListNode, val int) *ListNode {
    if head == nil {
        return head
    }

    newHead := &ListNode{Val: 0, Next: head}
    pre := newHead
    cur := head
    for cur != nil {
        if cur.Val == val {
            pre.Next = cur.Next // 跳过cur节点
        } else {
            pre = cur
        }
        cur = cur.Next
    }
    return newHead.Next
}