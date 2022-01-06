package _9_queue

import "fmt"

// 链表队列的实现
// 注意和数组队列的一个区别：链表队列的实现中没有容量限制

// 定义链表节点
type ListNode struct {
	val interface{}
	next *ListNode
}

// 定义链表队列
type LinkedListQueue struct {
	head *ListNode
	tail *ListNode
	length int
}

// 新建链表队列，返回指向ta的指针
func NewLinkedListQueue() *LinkedListQueue {
	return &LinkedListQueue{nil, nil, 0}
}

// 链表队列的入队
func (this *LinkedListQueue) EnQueue(v interface{}) {
	node := &ListNode{v, nil}
	if this.tail == nil {
		this.tail = node
		this.head = node
	} else {
		this.tail.next = node
		this.tail = node
	}
	this.length++
}

// 链表的队列的出队
func (this *LinkedListQueue) DeQueue() interface{} {
	if this.head == nil {
		return nil
	}

	v := this.head.val
	this.head = this.head.next
	this.length--
	return v
}

// 打印链表队列的所有元素
func (this *LinkedListQueue) String() string {
	if this.head == nil {
		return "empty queue"
	}

	result := "head"
	for cur := this.head; cur != nil; cur = cur.next {
		result += fmt.Sprintf("<-%+v", cur.val)
	}

	result += "<-tail"
	return result
}