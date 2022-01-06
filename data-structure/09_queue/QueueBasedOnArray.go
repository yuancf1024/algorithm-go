package _9_queue

import (
	"fmt"
)

// 定义数组队列，包含队列元素、容量、头下标、尾下标
type ArrayQueue struct {
	q        []interface{}
	capacity int
	head     int
	tail     int
}

// 新建数组队列，返回ta的指针
func NewArrayQueue(n int) *ArrayQueue {
	return &ArrayQueue{make([]interface{}, n), n, 0, 0}
}

// 数组队列的入队
func (this *ArrayQueue) EnQueue(v interface{}) bool {
	// 需要考虑队列满了的情况
	if this.tail == this.capacity {
		return false
	}

	this.q[this.tail] = v
	this.tail++
	return true
}

// 数组队列的出队
func (this *ArrayQueue) DeQueue() interface{} {
	if this.head == this.tail {
		return nil
	}

	v := this.q[this.head]
	this.head++
	return v
}

// 打印队列的字符串
func (this *ArrayQueue) String() string {
	if this.head == this.tail {
		return "empty queue"
	}

	result := "head"
	for i := this.head; i <= this.tail-1; i++ {
		result += fmt.Sprintf("<-%+v", this.q[i])
	}
	result += "<=tail"
	return result
}