// 哈希表
// 双向链表

package main

import (
	"container/list";
	
)

struct LRUCace {
	Cache map[string]string
	Dlist list// 双向链表

}

func get(key string) {
	if Cache[key] {
		return 
	} else {
		return null
	}
}

func put(key, value string) {
	// 如果存在直接移到表头
	
	// 不在，向链表头插入新节点

}

func del() {

}