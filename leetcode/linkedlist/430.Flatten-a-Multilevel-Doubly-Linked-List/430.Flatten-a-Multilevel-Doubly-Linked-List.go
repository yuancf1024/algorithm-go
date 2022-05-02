package leetcode

/* 430. 扁平化多级双向链表
问题：在一个多级双向链表中，节点除了有两个指针分别指向前后两个节点，
还有一个指针指向它的子链表，并且子链表也是一个双向链表，
它的节点也有指向子链表的指针。请将这样的多级双向链表展平成普通的双向链表，
即所有节点都没有子链表。
*/

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Prev *Node
 *     Next *Node
 *     Child *Node
 * }
 */

type Node struct {
	Val   int
	Prev  *Node
	Next  *Node
	Child *Node
}

func flatten(root *Node) *Node {
	flattenGetTail(root) 
	return root
}

func flattenGetTail(head *Node) *Node {
	node := head
	var tail *Node // 定义空的尾节点
	for node != nil {
		next := node.Next
		if node.Child != nil { // 存在子链表
			child := node.Child
			childTail := flattenGetTail(node.Child) // 递归获取子链表的尾节点

			node.Child = nil // 递归到最深层的子链表，将该层Child置为nil
			node.Next = child // node尾指针 指向 child
			child.Prev = node // child前指针 指向 node
			childTail.Next = next // 子链表尾节点尾指针指向 第一层链表node的下一个节点
			if next != nil { 
				next.Prev = childTail // next不为空时，next的前指针 指向子链表的尾节点
			}
			tail = childTail // 更新链表的尾节点
		} else {
			tail = node // 没有子链表时，尾节点后移一位
		}
		node = next // 没有子链表，node后移一位
	}
	return tail // 返回展平后的链表尾节点
}
