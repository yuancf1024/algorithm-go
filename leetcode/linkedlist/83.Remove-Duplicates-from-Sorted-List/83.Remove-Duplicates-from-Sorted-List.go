package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

type ListNode = structures.ListNode

/* 83. 删除排序链表中的重复元素
给定一个已排序的链表的头 head ， 删除所有重复的元素，
使每个元素只出现一次 。返回 已排序的链表 。
*/


/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func deleteDuplicates(head *ListNode) *ListNode {
    cur := head
    // var newHead  *ListNode 
    // newHead = cur 重复了

    // 特殊case
    if head == nil {
        return nil
    }

    if head.Next == nil {
        return head
    }
    for cur.Next != nil {
        if cur.Val == cur.Next.Val {// 最后一个节点重复,删去最后一个节点
            cur.Next = cur.Next.Next // cur 和cur.Next 相等，仅需要跳过一个相同节点即可
        } else { // cur 和cur.Next 不相等，cur后移一位
            cur = cur.Next
        }
    }
    return head
}

/* 一次遍历
思路与算法
由于给定的链表是排好序的，因此重复的元素在链表中出现的位置是连续的，
因此我们只需要对链表进行一次遍历，就可以删除重复的元素。
具体地，我们从指针 cur 指向链表的头节点，随后开始对链表进行遍历。
如果当前 cur 与 cur.next 对应的元素相同，那么我们就将cur.next 从链表中移除；
否则说明链表中已经不存在其它与 cur 对应的元素相同的节点，
因此可以将 cur 指向 cur.next。
当遍历完整个链表之后，我们返回链表的头节点即可。

细节
当我们遍历到链表的最后一个节点时，cur.next 为空节点，
如果不加以判断，访问 cur.next 对应的元素会产生运行错误。
因此我们只需要遍历到链表的最后一个节点，而不需要遍历完整个链表。

复杂度分析
时间复杂度：O(n)，其中 n 是链表的长度。
空间复杂度：O(1)。
执行用时：0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗：3 MB, 在所有 Go 提交中击败了68.06%的用户
*/