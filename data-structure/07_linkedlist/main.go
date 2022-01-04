package _7_linkedlist

import "fmt"

// 单链表节点
type ListNode struct {
	next *ListNode
	value interface{}
}

// 单链表
type LinkedList struct {
	head *ListNode
}

// 打印链表
func (this *LinkedList) Print() {
	cur := this.head.next
	format := ""
	for nil != cur {
		format += fmt.Sprintf("%+v", cur.value)
		cur = cur.next
		if nil != cur {
			format += "->"
		}
	}
	fmt.Println(format)
}

/*
单链表反转
时间复杂度：O(N)
*/
func (this *LinkedList) Reverse() {
	if this.head == nil || this.head.next == nil || this.head.next.next == nil {
		return
	}

	var pre *ListNode = nil
	cur := this.head.next // 链表的第一个节点，this.head代表头节点or哨兵节点，哨兵节点不存值
	for cur != nil {
		tmp := cur.next // 提前保存cur节点的下一个节点
		cur.next = pre // 改变cur节点的指针，cur指向pre，第一个pre为nil
		pre = cur // pre指向cur节点
		cur = tmp // cur指向*在调整cur指针前*的后面一个节点
	}

	this.head.next = pre // 链表头节点指向原来链表的最后一个节点
}

/*
判断单链表是否有环
*/
func (this *LinkedList) HasCycle() bool {
	if this.head != nil {
		slow := this.head
		fast := this.head
		for fast != nil && fast.next != nil {
			slow = slow.next
			fast = fast.next.next
			if slow == fast {
				return true
			}
		}
	}
	return false
}

/*
两个有序单链表合并
*/
func MergeSortedList(l1, l2 *LinkedList) *LinkedList {
	if l1 == nil || l1.head == nil || l1.head.next == nil {
		return l2
	}

	if l2 == nil || l2.head == nil || l2.head.next == nil {
		return l1
	}

	l := &LinkedList{head:&ListNode{}}
	cur := l.head
	curl1 := l1.head.next
	curl2 := l2.head.next
	for curl1 != nil && curl2 != nil {
		if curl1.value.(int) > curl2.value.(int) {
			cur.next = curl2
			curl2 = curl2.next
		} else {
			cur.next = curl1
			curl1 = curl1.next
		}
		cur = cur.next
		// 注意区分下面两种表示
		// cur.next = curl1 cur的next指针指向curl1
		// cur = cur.next cur 指向cur.next
	}
	if curl1 != nil {
		cur.next = curl1
	} else if curl2 != nil {
		cur.next = curl2
	}

	return l
}

/*
删除倒数第N个节点
*/
func (this *LinkedList) DeleteBottomN(n int){
	if n <= 0 || this.head == nil || this.head.next == nil {
		return
	}

	fast := this.head
	for i := 1; i <= n && fast != nil; i++ {
		fast = fast.next // fast一直指向链表的正向第n个节点
	}

	if fast == nil {
		return
	}

	slow := this.head
	for fast.next != nil { // fast移动N-n次，slow移动N-n次
		slow = slow.next
		fast = fast.next
	}
	slow.next = slow.next.next // slow恰好跳过倒数第n个节点
}
// 删除倒数第n个节点，那么需要从第N-n个节点开始，slow跳过一个节点即可

/*
获取中间节点
*/
func (this *LinkedList) FindMiddleNode() *ListNode {
	if this.head == nil || this.head.next == nil {
		return nil
	}

	if this.head.next.next == nil {
		return this.head.next
	}

	slow, fast := this.head, this.head
	for fast != nil && fast.next != nil {
		slow = slow.next
		fast = fast.next.next
		// fast 走到尾节点，slow恰好就在中间节点位置
	}
	return slow
}
