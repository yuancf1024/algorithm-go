package template

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

/*
总结，LRU 是由一个 map 和一个双向链表组成的数据结构。
map 中 key 对应的 value 是双向链表的结点。
双向链表中存储 key-value 的 pair。
双向链表表首更新缓存，表尾淘汰缓存。
*/

/*#####################解法二 Get O(1) / Put O(1) ############################*/

// 手写双向链表

// LRUCache结构体定义
type LRUCache struct {
	head, tail *Node // 头、尾节点
	keys map[int]*Node
	capacity int
}

// 节点定义
type Node struct {
	key, val int
	prev, next *Node
}

// 初始化
func ConstructorLRU(capacity int) LRUCache {
	return LRUCache{keys: make(map[int]*Node), capacity: capacity}
}

// 查
func (this *LRUCache) Get(key int) int {
	if node, ok := this.keys[key]; ok { // 在 map 中直接读取双向链表的结点
		this.Remove(node) // 如果 map 中存在，将它移动到双向链表的表头
		this.Add(node) // 先删除，再添加(会自动排到链表头部)
		return node.val // 返回节点的值
	}
	return -1
}

// 增改
func (this *LRUCache) Put(key int, value int) {
	if node, ok := this.keys[key]; ok { // 先查询 map 中是否存在 key
		node.val = value // 如果存在，更新它的 value 然后 移动到双向链表的表头
		this.Remove(node)
		this.Add(node)
		return
	} else { // 如果 map 中不存在
		node = &Node{key: key, val: value} // 新建这个结点加入到双向链表中
		this.keys[key] = node // 加入到map中
		this.Add(node)
	}
	if len(this.keys) > this.capacity { // 维护双向链表的 cap，如果超过 cap，需要淘汰最后一个结点，双向链表中删除这个结点
		delete(this.keys, this.tail.key)
		this.Remove(this.tail)
	}
}

// 增 (将节点插入链表头部)
func (this *LRUCache) Add(node *Node) {
	node.prev = nil // 插入节点的前驱指针为空
	node.next = this.head // 插入节点的后继指针 指向链表头节点
	if this.head != nil { // 如果链表头节点不为空，则头节点的前驱指向被插入节点
		this.head.prev = node
	}
	this.head = node // 将链表头节点更新为被插入节点
	if this.tail == nil { // 如果链表尾节点为空
		this.tail = node // 将链表尾节点更新为被插入节点
		this.tail.next = nil // 尾节点指向空
	}
}

// 删
func (this *LRUCache) Remove(node *Node) {
	if node == this.head { // 如果被删节点是双向链表的头节点
		this.head = node.next // 链表头节点指向被删节点指向的下一个节点
		if node.next != nil { // 如果被删节点指向的下一个节点不为空
			node.next.prev = nil // 被删节点指向的下一个节点的前驱指针为空
		}
		node.next = nil // 被删节点的后继指针置为空
		return
	}
	if node == this.tail { // 如果被删节点是双向链表的尾节点
		this.tail = node.prev // 链表的尾节点为被删节点的前一个结点
		node.prev.next = nil // new链表尾节点的后继指针指向空
		node.prev = nil // 被删节点的前驱指针为空
		return
	}
	node.prev.next = node.next // 被删节点の前驱节点的后继指针指向 被删节点的下一个节点
	node.next.prev = node.prev // 被删节点の后继节点的前驱指针指向 被删节点的前一个节点
}

/*#####################解法一 Get O(1) / Put O(1) ############################*/

// 22%
// import "container/list"

// // 定义 LRUCache 的数据结构
// type LRUCache struct {
// 	Cap int
// 	Keys map[int]*list.Element
// 	List *list.List
// }

// type pair struct {
// 	K, V int
// }

// func Constructor(capacity int) LRUCache {
// 	return LRUCache{
// 		Cap: capacity,
// 		Keys: make(map[int]*list.Element),
// 		List: list.New(),
// 	}
// }

// /*
// type Element struct {
// 	// Next and previous pointers in the doubly-linked list of elements.
// 	// To simplify the implementation, internally a list l is implemented
// 	// as a ring, such that &l.root is both the next element of the last
// 	// list element (l.Back()) and the previous element of the first list
// 	// element (l.Front()).
// 	next, prev *Element

// 	// The list to which this element belongs.
// 	list *List

// 	// The value stored with this element.
// 	Value interface{}
// }
// */

// /* LRUCache 的 Get 操作很简单，在 map 中直接读取双向链表的结点。
// 如果 map 中存在，将它移动到双向链表的表头，并返回它的 value 值，
// 如果 map 中不存在，返回 -1。
// */ 
// func (c *LRUCache) Get(key int) int {
// 	if el, ok := c.Keys[key]; ok { // 在 map 中直接读取双向链表的结点
// 		c.List.MoveToFront(el) // 如果 map 中存在，将它移动到双向链表的表头
// 		return el.Value.(pair).V // 返回它的 value 值
// 	}
// 	return -1 // 如果 map 中不存在，返回 -1
// }

// /* LRUCache 的 Put 操作也不难。先查询 map 中是否存在 key，如果存在，
// 更新它的 value，并且把该结点移到双向链表的表头。
// 如果 map 中不存在，新建这个结点加入到双向链表和 map 中。
// 最后别忘记还需要维护双向链表的 cap，如果超过 cap，
// 需要淘汰最后一个结点，双向链表中删除这个结点，map 中删掉这个结点对应的 key。
// */
// func (c *LRUCache) Put(key int, value int) {
// 	if el, ok := c.Keys[key]; ok { // 先查询 map 中是否存在 key
// 		el.Value = pair{K: key, V: value} // 如果存在，更新它的 value
// 		c.List.MoveToFront(el) // 并且把该结点移到双向链表的表头。
// 	} else { // 如果 map 中不存在
// 		el := c.List.PushFront(pair{K: key, V: value}) // 新建这个结点加入到双向链表中
// 		c.Keys[key] = el // 加入到map中
// 	}
// 	if c.List.Len() > c.Cap { // 维护双向链表的 cap
// 		el := c.List.Back()
// 		c.List.Remove(el) // 如果超过 cap，需要淘汰最后一个结点，双向链表中删除这个结点
// 		delete(c.Keys, el.Value.(pair).K) // map 中删掉这个结点对应的 key
// 	}
// }



