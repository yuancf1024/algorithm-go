package circular_LinkedList

import "fmt"

// 循环链表的是实现

// 链表节点定义
type ListNode struct {
	val interface{}
	next *ListNode
}

// 新建节点
func newNode(val interface{}) *ListNode {
	return &ListNode{val, nil}
}

// 循环链表定义
type LinkedList struct {
	head *ListNode
	tail *ListNode
	size int
}

// 新建链表
func New() *LinkedList {
	return &LinkedList{nil, nil, 0}
}

// 查找链表中值为val的节点，并返回该节点
func (lis *LinkedList) Find(val interface{}) *ListNode {
	p := lis.head
	for i := 0; i < lis.size && p.val != val; i++ {
		p = p.next
	}
	return p
}

// 添加节点至链表末尾, 并返回插入的节点
func (lis *LinkedList) PushBack(val interface{}) *ListNode {
	node := newNode(val)
	if lis.head == nil {
		lis.head = node
	} else {
		node.next = lis.head
		lis.tail.next = node
	}

	lis.tail = node
	lis.size++
	return node
}

// 在某个节点之后插入数据，并返回插入的节点
func (lis *LinkedList) PushAfter(p *ListNode, val interface{}) *ListNode {
	if p == nil {
		return nil
	}

	node := newNode(val)
	node.next = p.next
	p.next = node
	if p == lis.tail { // 循环链表中多了对尾节点的检查
		lis.tail = node
	}
	lis.size++
	return node
}

// 在某个节点之前插入数据，并返回插入的节点
func (lis *LinkedList) PushBefore(p *ListNode, val interface{}) *ListNode {
	if p == nil || lis.head == nil {
		return nil
	}

	if p == lis.head {
		return lis.PushBack(val)
	}

	prev := lis.head
	for i := 0; i < lis.size && prev.next != p; i++ {
		prev = prev.next
	}
	return lis.PushAfter(prev, val)
	// 找到要插入节点位置的前一个节点prev，然后在prev后面插入val节点
}

// 求链表长度
func (lis *LinkedList) Size() int {
	return lis.size
}

// 删除节点，返回删除操作结果的bool
func (lis *LinkedList) Delete(p *ListNode) bool {
	if p == nil || lis.head == nil {
		return false
	}

	if p == lis.head {
		lis.head = p.next
	} else {
		prev := lis.head
		for i := 0; i < lis.size && prev.next != p; i++ {
			prev = prev.next
		}
		prev.next = p.next
	}
	lis.size--
	return true
}

// 根据值删除节点
func (lis *LinkedList) DeleteVal(val interface{}) bool {
	return lis.Delete(lis.Find(val))
}

// 打印所有节点
func (lis *LinkedList) PrintData() {
	p := lis.head
	for i := 0; i < lis.size; i++ {
		fmt.Print(p.val, " ")
		p = p.next
	}
	fmt.Println()
}
