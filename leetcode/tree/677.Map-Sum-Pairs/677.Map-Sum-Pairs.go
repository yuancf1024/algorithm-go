package leetcode

/* 677. 键值映射
设计一个 map ，满足以下几点:
- 字符串表示键，整数表示值
- 返回具有前缀等于给定字符串的键的值的总和

实现一个 MapSum 类：
- MapSum() 初始化 MapSum 对象
- void insert(String key, int val) 插入 key-val 键值对，
字符串表示键 key ，整数表示值 val 。如果键 key 已经存在，
那么原来的键值对 key-value 将被替代成新的键值对。
- int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。
 

示例 1：
输入：
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
输出：
[null, null, 3, null, 5]

解释：
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // 返回 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // 返回 5 (apple + app = 3 + 2 = 5)
 

提示：

1 <= key.length, prefix.length <= 50
key 和 prefix 仅由小写英文字母组成
1 <= val <= 1000
最多调用 50 次 insert 和 sum
*/

type MapSum struct {
	keys map[string]int
}

/** Initialize your data structure here. */
func Constructor() MapSum {
	return MapSum{make(map[string]int)}
}


func (this *MapSum) Insert(key string, val int)  {
	this.keys[key] = val
}


func (this *MapSum) Sum(prefix string) int {
	prefixAsRunes, res := []rune(prefix), 0
	for key, val := range this.keys { // 遍历哈希表中的key字符串
		if len(key) >= len(prefix) { // 只判断key字符串长度大于等于条件前缀的情况
			shouldSum := true
			for i, char := range key { // 遍历当前字符串的每个字母
				if i >= len(prefixAsRunes) { // 遍历到的序号超过了给定条件前缀的长度
					break
				}
				if prefixAsRunes[i] != char { // 遍历到的字母和条件前缀对应位置处的字母不一样
					shouldSum = false
					break
				}
			}
			if shouldSum { // 累加满足条件前缀对应的 value
				res += val
			}
		}
	}
	return res
}


/**
 * Your MapSum object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(key,val);
 * param_2 := obj.Sum(prefix);
 */

/*
解题思路
简单题。用一个 map 存储数据，Insert() 方法即存储 key-value。
Sum() 方法即累加满足条件前缀对应的 value。判断是否满足条件，
先根据前缀长度来判断，只有长度大于等于 prefix 长度才可能满足要求。
如果 key 是具有 prefix 前缀的，那么累加上这个值。最后输出总和即可。
*/
