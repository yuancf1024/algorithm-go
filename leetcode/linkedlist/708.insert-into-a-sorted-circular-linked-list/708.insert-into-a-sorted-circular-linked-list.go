package leetcode

/* 708.排序的循环链表
给定循环单调非递减列表中的一个点，写一个函数
向这个列表中插入一个新元素 insertVal ，使这个列表仍然是循环升序的。

给定的可以是这个列表中任意一个顶点的指针，
并不一定是这个列表中最小元素的指针。

如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，
插入后整个列表仍然保持有序。

如果列表为空（给定的节点是 null），
需要创建一个循环有序列表并返回这个节点。
否则。请返回原先给定的节点。
 */

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 * }
 */

type Node struct {
	Val  int
	Next *Node
}

// 参考剑指offer
func insert(aNode *Node, x int) *Node {
	node := &Node{Val: x}
	head := aNode
	if head == nil { // 链表为空的边界情况
		head = node
		head.Next = head
	} else if head.Next == head { // 链表只有一个节点的边界情况
		head.Next = node // 节点和插入节点互指
		node.Next = head
	} else {
		insertCore(head, node) // 核心插入代码
	}
	return head
}

func insertCore(head, node *Node) {
	cur := head
	next := head.Next
	biggest := head
	for !(cur.Val <= node.Val && next.Val >= node.Val) && 
	(next != head) { // cur未到达要求插入点 并且没有遍历完
		cur = next
		next = next.Next
		if cur.Val >= biggest.Val { // 如果cur到达最大节点，更新最大节点biggest
			biggest = cur
		}
	}

	if cur.Val <= node.Val && next.Val >= node.Val { // cur到达适合插入node的节点 cur.Val <= node.Val <= next.Val
		cur.Next = node
		node.Next = next
	} else { // 边界区，node比链表中所有节点都要大或者都要小
		node.Next = biggest.Next // node指向最小节点
		biggest.Next = node // biggest指向node节点
	}
}

/* 思路：
总结在排序的循环链表中插入新节点的规则。
先试图在链表中找到相邻的两个节点，
如果这两个节点的前一个节点的值比待插入的值小
并且后一个节点的值比待插入的值大，
那么就将新节点插入这两个节点之间。

如果找不到符合条件的两个节点，
即待插入的值大于链表中已有的最大值或小于已有的最小值，
那么新的节点将被插入值最大的节点和值最小的节点之间。
在上面的规则中，总是先试图从链表中找到符合条件的相邻的两个节点。
如果开始的时候链表中的节点数小于2，
那么应该有两种可能。

第1种可能是开始的时候链表是空的，一个节点都没有。
此时插入一个新的节点，该节点成为循环链表中的唯一节点，
那么next指针指向节点自己。

2种可能是开始的时候链表中只有一个节点，
插入一个新的节点之后，两个节点的next指针互相指向对方。
*/