package structures

import (
	"fmt"
)

// ListNode 是链接节点
// 这个不能复制到*_test.go文件中，会导致Travis失败
type ListNode struct {
	Val int
	Next *ListNode
}

// List2Ints convert List to []int
// 链表转换为数组切片
func List2Ints(head *ListNode) []int {
	// 链条深度限制，链条深度超出此限制，会panic
	limit := 100

	times := 0

	res := []int{}
	for head != nil {
		times++
		if times > limit {
			msg := fmt.Sprintf("链条深度超过%d，可能出现环状链条。请检查错误，或者放宽 l2s 函数中limit的限制。", limit)
			panic(msg)
		}

		res = append(res, head.Val)
		head = head.Next
	}

	return res
}

// Ints2List convert []int to List
// 数组转化为链表,返回不带头节点
func Ints2List(nums []int) *ListNode {
	if len(nums) == 0 {
		return nil
	}

	l := &ListNode{}
	t := l
	for _, v := range nums {
		t.Next = &ListNode{Val: v}
		t = t.Next
	}
	return l.Next
}

// GetNodeWith returns the first node with val
// 返回第一个带有val的节点
func (l *ListNode) GetNodeWith(val int) *ListNode {
	res := l
	for res != nil {
		if res.Val == val {
			break
		}
		res = res.Next
	}
	return res
}

// Ints2ListWithCycle returns a list whose tail point to pos-indexed node
// 返回一个尾指向 pos-indexed 节点的列表
// head's index is 0
// if pos = -1, no cycle
func Ints2ListWithCycle(nums []int, pos int) *ListNode {
	head := Ints2List(nums)
	if pos == -1 {
		return head
	}
	c := head
	for pos > 0 {
		c = c.Next
		pos--
	}
	tail := c
	for tail.Next != nil { // 找到从c开头链表的尾节点
		tail = tail.Next
	}
	tail.Next = c // 尾节点指向c，实现闭环
	return head
}