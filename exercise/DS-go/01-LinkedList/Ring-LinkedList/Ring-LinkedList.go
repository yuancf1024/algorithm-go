package main

import "fmt"

// 循环链表 Ring（集链表大成者），参考 Golang 标准库 container/ring
type Ring struct {
	next, prev *Ring       // 前驱和后驱节点
	Value      interface{} // 数据
}

// 初始化空的循环链表,前驱和后驱都指向自己,因为是循环的
func (r *Ring) init() *Ring { // init函数在main函数之前执行
	r.next = r
	r.prev = r
	return r
}

// 因为绑定前驱和后驱节点为自己，没有循环，时间复杂度为：O(1)。

// func main() {
// 	r := new(Ring) // new内置函数,分配内存
// 	r.init()
// }

// 创建N个节点的循环链表
func New(n int) *Ring {
	if n <= 0 {
		return nil
	}

	r := new(Ring)
	p := r
	for i := 1; i < n; i++ { // 画图理解
		// 会连续绑定前驱和后驱节点，时间复杂度为：O(n)
		p.next = &Ring{prev: p} // & 取得对象的内存地址，即指向对象的指针
		p = p.next
	}
	p.next = r
	r.prev = p
	return r
}

// 获取下一个节点
func (r *Ring) Next() *Ring {
	if r.next == nil {
		return r.init()
	}
	return r.next
}

// 获取前驱或后驱节点，时间复杂度为：O(1)。

// 获取上一个节点
func (r *Ring) Prev() *Ring {
	if r.next == nil {
		return r.init()
	}
	return r.prev
}

// 获取第n个节点
// 因为链表是循环的，当 n 为负数，表示从前面往前遍历，否则往后面遍历：
func (r *Ring) Move(n int) *Ring {
	if r.next == nil {
		return r.init()
	}
	switch {
	case n < 0:
		for ; n < 0; n++ {
			r = r.prev
		}
	case n > 0:
		for ; n > 0; n-- {
			r = r.next
		}
	}
	return r
}

// 因为需要遍历 n 次，所以时间复杂度为：O(n)。

// 添加节点
// 往节点A,链接一个节点,并且返回之前节点A的后驱节点
func (r *Ring) Link(s *Ring) *Ring {
	// 2021-12-19 下面这部分写得太复杂，不清晰
	// 我按照大话数据结构中的思路修改，后面就有些报错了
	n := r.Next()
	if s != nil {
		p := s.Prev()
		r.next = s
		s.prev = r
		n.prev = p
		p.next = n
	}
	// 配合大话数据结构的理解 p, p->next, 插入s
	// n := r.Next() // 看这里怎么优化一下，去掉n。
	// 笑哭😂, 这里写得没有问题，是参考的资料太垃圾了，没有将链表和节点分开表示，所以容易产生bug
	// if s != nil {
	// 	// r, r.next, 插入s
	// 	s.prev = r
	// 	s.next = r.next
	// 	r.next.prev = s
	// 	r.next = s
	// }
	return n
}

// 删除节点后面的n个节点
func (r *Ring) Unlink(n int) *Ring {
	if n < 0 {
		return nil
	}
	return r.Link(r.Move(n + 1)) // 此处的删除采用的是跳过n个节点，再将2个节点相连
}

// // 测试添加节点
// func linkNewTest() {
// 	// 第一个节点
// 	r := &Ring{Value: -1}

// 	// 链接新的五个节点
// 	r.Link(&Ring{Value: 1}) // Output: -1 -> 1
// 	r.Link(&Ring{Value: 2}) // Output: -1 -> 2 ->1
// 	r.Link(&Ring{Value: 3}) // Output: -1 -> 3 -> 2 ->1
// 	r.Link(&Ring{Value: 4}) // Output: -1 -> 4 ->3 -> 2 ->1

// 	node := r
// 	for {
// 		// 打印节点值
// 		fmt.Println(node.Value)

// 		// 移到下一个节点
// 		node = node.Next()

// 		//  如果节点回到了起点，结束
// 		if node == r {
// 			return
// 		}
// 	}
// }

// 测试删除节点
func deleteTest() {
	// 第一个节点
	r := &Ring{Value: -1}

	// 链接新的五个节点
	r.Link(&Ring{Value: 1}) // Output: -1 -> 1
	r.Link(&Ring{Value: 2}) // Output: -1 -> 2 ->1
	r.Link(&Ring{Value: 3}) // Output: -1 -> 3 -> 2 ->1
	r.Link(&Ring{Value: 4}) // Output: -1 -> 4 ->3 -> 2 ->1

	// 删除后面的3个节点
	temp := r.Unlink(3)

	// 打印原来的节点
	node := r
	for {
		// 打印节点值
		fmt.Println(node.Value)

		// 移到下一个节点
		node = node.Next()

		// 如果节点回到了起点，结束
		if node == r {
			break
		}
	}

	fmt.Println("------")

	// 打印被切断的节点
	node = temp
	for {
		// 打印节点值
		fmt.Println(node.Value)

		// 移到下一个节点
		node = node.Next()

		// 如果节点回到了起点，结束
		if node == temp {
			break
		}
	}
}

// 因为只要定位要删除的节点位置，然后进行链接：r.Link(r.Move(n + 1))，
// 所以时间复杂度为：O(n)+O(1)=O(n)

// ************测试主程序************

func main() {

	// r := new(Ring) // new内置函数,分配内存
	// r.init()

	// linkNewTest()
	// 每次链接的是一个新节点，那么链会越来越长，
	// 仍然是一个环。因为只是更改链接位置，时间复杂度为：O(1)。

	deleteTest()

}
