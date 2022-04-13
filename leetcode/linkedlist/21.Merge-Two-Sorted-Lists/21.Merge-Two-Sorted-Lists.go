package leetcode

import (
	"github.com/yuancf1024/algorithm-go/structures"
)

/*
将两个升序链表合并为一个新的 升序 链表并返回。
新链表是通过拼接给定的两个链表的所有节点组成的。 
*/

type ListNode = structures.ListNode
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
// 2022-04-13 报错： panic: runtime error: invalid memory address or nil pointer dereference
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    preHead := &ListNode{Val: 0} // 哨兵头节点
	cur := preHead
    l1, l2 := list1, list2
    for l1 != nil && l2 != nil {
        if l1.Val <= l2.Val {
            cur.Next = l1
            l1 = l1.Next
        } else {
            cur.Next = l2
            l2 = l2.Next
        }
		cur = cur.Next
    }
    // 尾部如何处理
    if l1 == nil { // 如果使用l1.Next 就会报错：panic: runtime error: invalid memory address or nil pointer dereference
        cur.Next = l2
    }
    if l2 == nil {
        cur.Next = l1
    }
    return preHead.Next
}
/* 迭代
我们可以用迭代的方法来实现上述算法。当 l1 和 l2 都不是空链表时，
判断 l1 和 l2 哪一个链表的头节点的值更小，将较小值的节点添加到结果里，
当一个节点被添加到结果里之后，将对应链表中的节点向后移一位。

首先，我们设定一个哨兵节点 prehead ，这可以在最后让我们比较容易地返回
合并后的链表。我们维护一个 prev 指针，我们需要做的是调整它的 next 指针。
然后，我们重复以下过程，直到 l1 或者 l2 指向了 null ：
如果 l1 当前节点的值小于等于 l2 ，我们就把 l1 当前的节点接在 
prev 节点的后面同时将 l1 指针往后移一位。否则，我们对 l2 做同样的操作。
不管我们将哪一个元素接在了后面，我们都需要把 prev 向后移一位。

在循环终止的时候， l1 和 l2 至多有一个是非空的。由于输入的两个链表都是
有序的，所以不管哪个链表是非空的，它包含的所有元素都比前面已经合并链表中
的所有元素都要大。这意味着我们只需要简单地将非空链表接在合并链表的后面，
并返回合并链表即可。

复杂度分析
时间复杂度：O(n+m)，其中 n 和 m 分别为两个链表的长度。
因为每次循环迭代中，l1 和 l2 只有一个元素会被放进合并链表中，
因此 while 循环的次数不会超过两个链表的长度之和。
所有其他操作的时间复杂度都是常数级别的，因此总的时间复杂度为 O(n+m)。
空间复杂度：O(1)。我们只需要常数的空间存放若干变量。
*/

// 递归的实现合并2个有序列表
func mergeTwoLists_v2(list1 *ListNode, list2 *ListNode) *ListNode {
	
	l1, l2 := list1, list2
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	if l1.Val < l2.Val {
		l1.Next = mergeTwoLists_v2(l1.Next, l2)
		return l1
	}
	l2.Next = mergeTwoLists_v2(l1, l2.Next)
	return l2
}

/* 递归思路
我们可以如下递归地定义两个链表里的 merge 操作（忽略边界情况，比如空链表等）：
list1[0]+merge(list1[1:],list2) list1[0]<list2[0]
list2[0]+merge(list1,list2[1:]) otherwise
​也就是说，两个链表头部值较小的一个节点与剩下元素的 merge 操作结果合并。

我们直接将以上递归过程建模，同时需要考虑边界情况。
如果 l1 或者 l2 一开始就是空链表 ，那么没有任何操作需要合并，
所以我们只需要返回非空链表。否则，我们要判断 l1 和 l2 哪一个链表的头节点
的值更小，然后递归地决定下一个添加到结果里的节点。
如果两个链表有一个为空，递归结束。

复杂度分析
时间复杂度：O(n+m)，其中 n 和 m 分别为两个链表的长度。
因为每次调用递归都会去掉 l1 或者 l2 的头节点（直到至少有一个链表为空），
函数 mergeTwoList 至多只会递归调用每个节点一次。
因此，时间复杂度取决于合并后的链表长度，即 O(n+m)。

空间复杂度：O(n+m)，其中 n 和 m 分别为两个链表的长度。
递归调用 mergeTwoLists 函数时需要消耗栈空间，
栈空间的大小取决于递归调用的深度。结束递归调用时 mergeTwoLists 函数
最多调用 n+m 次，因此空间复杂度为 O(n+m)。
*/