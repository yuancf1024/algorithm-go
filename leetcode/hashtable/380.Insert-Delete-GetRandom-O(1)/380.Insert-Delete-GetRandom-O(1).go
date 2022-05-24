package leetcode

import "math/rand"

/* 380. O(1) 时间插入、删除和获取随机元素

实现RandomizedSet 类：

RandomizedSet() 初始化 RandomizedSet 对象
bool insert(int val) 当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
bool remove(int val) 当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
int getRandom() 随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
你必须实现类的所有函数，并满足每个函数的 平均 时间复杂度为 O(1) 。

示例：

输入
["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
[[], [1], [2], [2], [], [1], [2], []]
输出
[null, true, false, true, 2, true, false, 2]

解释
RandomizedSet randomizedSet = new RandomizedSet();
randomizedSet.insert(1); // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
randomizedSet.remove(2); // 返回 false ，表示集合中不存在 2 。
randomizedSet.insert(2); // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
randomizedSet.getRandom(); // getRandom 应随机返回 1 或 2 。
randomizedSet.remove(1); // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
randomizedSet.insert(2); // 2 已在集合中，所以返回 false 。
randomizedSet.getRandom(); // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。


*/

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */

type RandomizedSet struct {
	nums []int
	indices map[int]int
}


func Constructor() RandomizedSet {
	return RandomizedSet{[]int{}, map[int]int{}}
}


func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.indices[val]; ok {
		return false
	}
	this.indices[val] = len(this.nums)
	this.nums = append(this.nums, val)
	return true
}


func (this *RandomizedSet) Remove(val int) bool {
	id, ok := this.indices[val] // id 代表被删数字val 在数组中的索引
	if !ok { // 如果被删数字不在哈希表中，直接返回false
		return false
	}
	last := len(this.nums) - 1 // 数组nums中最后一个元素的索引
	this.nums[id] = this.nums[last] // 将最后一个元素移到被删元素的位置处
	this.indices[this.nums[id]] = id // 建立新的映射关系，被删元素的位置id，装着初始nums中的最后一个元素->key, id -> value
	this.nums = this.nums[:last] // 数组nums 中删除最后一个元素
	delete(this.indices, val) // 删除val-id 映射关系
	return true
}


func (this *RandomizedSet) GetRandom() int {
	return this.nums[rand.Intn(len(this.nums))]
}


/* 方法一：变长数组 + 哈希表
这道题要求实现一个类，满足插入、删除和获取随机元素操作的平均时间复杂度为 O(1)。

变长数组可以在 O(1) 的时间内完成获取随机元素操作，
但是由于无法在 O(1) 的时间内判断元素是否存在，因此不能在 O(1) 的时间内完成插入和删除操作。
哈希表可以在 O(1) 的时间内完成插入和删除操作，但是由于无法根据下标定位到特定元素，
因此不能在 O(1) 的时间内完成获取随机元素操作。为了满足插入、删除和获取随机元素操作的时间复杂度都是 O(1)，
需要将变长数组和哈希表结合，变长数组中存储元素，哈希表中存储每个元素在变长数组中的下标。

插入操作时，首先判断 val 是否在哈希表中，如果已经存在则返回 false，
如果不存在则插入 val，操作如下：
在变长数组的末尾添加 val；
在添加 val 之前的变长数组长度为 val 所在下标 index，将 val 和下标 index 存入哈希表；
返回 true。

删除操作时，首先判断 \val 是否在哈希表中，如果不存在则返回 false，
如果存在则删除 val，操作如下：

从哈希表中获得 val 的下标 index；

将变长数组的最后一个元素 last 移动到下标 index 处，
在哈希表中将 last 的下标更新为 index；

在变长数组中删除最后一个元素，在哈希表中删除 val；

返回 true。

删除操作的重点在于将变长数组的最后一个元素移动到待删除元素的下标处，
然后删除变长数组的最后一个元素。该操作的时间复杂度是 O(1)，
且可以保证在删除操作之后变长数组中的所有元素的下标都连续，方便插入操作和获取随机元素操作。

获取随机元素操作时，由于变长数组中的所有元素的下标都连续，
因此随机选取一个下标，返回变长数组中该下标处的元素。

*/