package _9_queue

import "fmt"

// 定义循环队列
type CircularQueue struct {
	q        []interface{}
	capacity int // 循环队列实际的存储容量是 capacity - 1
	head     int
	tail     int
}

// 新建循环队列，返回指向ta的指针
func NewCircularQueue(n int) *CircularQueue {
	if n == 0 {
		return nil
	}
	return &CircularQueue{make([]interface{}, n), n, 0, 0}
}

/*
队列空条件：head==tail 为true
*/
// 判断循环队列是否为空
func (this *CircularQueue) IsEmpty() bool {
	if this.head == this.tail {
		return true
	}
	return false
}

/*
队列满条件: (tail+1)%capacity == head 为true
循环队列满时，tail指向的位置没有存储数据，所以循环队列会浪费一个数组的存储空间
*/
// 判断循环队列是否满
func (this *CircularQueue) IsFull() bool {
	if (this.tail+1)%this.capacity == this.head {
		return true
	}
	return false
}

// 循环队列的入队
func (this *CircularQueue) EnQueue(v interface{}) bool {
	if this.IsFull() {
		return false
	}

	this.q[this.tail] = v
	this.tail = (this.tail + 1) % this.capacity
	return true
}

// 循环队列的出队
func (this *CircularQueue) DeQueue() interface{} {
	if this.IsEmpty() {
		return nil
	}

	v := this.q[this.head]
	this.head = (this.head + 1) % this.capacity
	return v
}

// 打印循环队列，testing.Log函数会默认以string输出
// 此处修改循环队列的公用函数String()，以实现打印循环队列
func (this *CircularQueue) String() string {
	if this.IsEmpty() {
		return "empty queue"
	}

	result := "head"
	var i = this.head
	for true {
		result += fmt.Sprintf("<-%+v", this.q[i])
		i = (i + 1) % this.capacity
		if i == this.tail {
			break
		}
	}

	result += "<-tail"
	return result
}
