package _6_linkedlist

import "fmt"

/*
单链表基本操作
*/

type ListNode struct {
	next *ListNode
	value interface{}
}

type LinkedList struct {
	head *ListNode
	length uint
}

func NewListNode(v interface{}) *ListNode {
	return &ListNode{nil, v}
}

func (this *ListNode) GetNext() *ListNode {
	return this.next
}

func (this *ListNode) GetValue() interface{} {
	return this.value
}

func NewLinkedList() *LinkedList {
	return &LinkedList{NewListNode(0), 0}
}

// 在某个节点后面插入节点
func (this *LinkedList) InsertAfter(p *ListNode, v interface{}) bool {
	if nil == p {
		return false
	}
	newNode := NewListNode(v)

	// 自己写的
	newNode.next = p.next
	p.next = newNode

	// 参考
	// oldNext := p.next
	// p.next = newNode
	// newNode.next = oldNext
	this.length++
	return true
}

// 在某个节点前面插入节点

// cur 指向当前遍历到的节点
// pre 指向当前节点的前一个节点
// 
func (this *LinkedList) InsertBefore(p *ListNode, v interface{}) bool {
	if nil == p || p == this.head {
		return false
	}
	cur := this.head.next // 这里的cur是什么意思?
	pre := this.head // pre是前驱指针
	for nil != cur { // 移动cur、pre，直到cur指向p节点
		if cur == p { 
			break
		}
		pre = cur
		cur = cur.next
	}
	if nil == cur {
		return false
	}
	newNode := NewListNode(v) // 和在某个节点后面插入节点恰好相反
	pre.next = newNode
	newNode.next = cur // 为什么？
	this.length++
	return true
}

// 在链表头部插入节点
func (this *LinkedList) InsertToHead(v interface{}) bool {
	return this.InsertAfter(this.head, v)
}

// 在链表尾部插入节点
func (this *LinkedList) InsertToTail(v interface{}) bool {
	cur := this.head
	if nil != cur.next { // 将cur一直定位到尾节点
		cur = cur.next
	}
	return this.InsertAfter(cur, v)
}

// 通过索引查找节点
func (this *LinkedList) FindByIndex(index uint) *ListNode {
	if index >= this.length {
		return nil
	}
	cur := this.head.next
	var i uint = 0
	for ; i < index; i++ {
		cur = cur.next
	}
	return cur
}

// 删除传入的节点
func (this *LinkedList) DeleteNode(p *ListNode) bool {
	if nil == p {
		return false
	}
	cur := this.head.next
	pre := this.head
	for nil != cur {
		if cur == p {
			break
		}
		pre = cur
		cur = cur.next
	}
	if nil == cur {
		return false
	}
	pre.next = p.next
	p = nil
	this.length--
	return true
}

// 打印链表

func (this *LinkedList) Print() {
	cur := this.head.next
	format := ""
	for nil != cur {
		format += fmt.Sprintf("%+v", cur.GetValue())
		cur = cur.next
		if nil != cur {
			format += "->"
		}
	}
	fmt.Println(format)
}