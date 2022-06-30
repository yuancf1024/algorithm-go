package leetcode

/* 729. 我的日程安排表 I
实现一个 MyCalendar 类来存放你的日程安排。如果要添加的日程安排不会造成 
重复预订 ，则可以存储这个新的日程安排。

当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），
就会产生 重复预订 。

日程可以用一对整数 start 和 end 表示，这里的时间是半开区间，
即 [start, end), 实数 x 的范围为，  start <= x < end 。

实现 MyCalendar 类：
MyCalendar() 初始化日历对象。
boolean book(int start, int end) 如果可以将日程安排成功添加到日历中
而不会导致重复预订，返回 true 。否则，返回 false 并且不要将该日程安排
添加到日历中。

请按照以下步骤调用 MyCalendar 类: 
MyCalendar cal = new MyCalendar(); 
MyCalendar.book(start, end)

说明:
每个测试用例，调用 MyCalendar.book 函数最多不超过 100次。
调用函数 MyCalendar.book(start, end) 时， start 和 end 的
取值范围为 [0, 10^9]。

示例：
输入：
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
输出：
[null, true, false, true]

解释：
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False ，这个日程安排不能添加到日历中，因为时间 15 已经被另一个日程安排预订了。
myCalendar.book(20, 30); // return True ，这个日程安排可以添加到日历中，因为第一个日程安排预订的每个时间都小于 20 ，且不包含时间 20 。
*/

// 解法一 二叉排序树
// Event define
type Event struct {
	start, end int
	left, right *Event
}

// Insert define
func (e *Event) Insert(curr *Event) bool {
	// 在插入树中先排除不能插入的情况，例如区间有重合
	if e.end > curr.start && curr.end > e.start {
		return false
	}
	// 然后以区间左值为依据，递归插入，每次插入依次会继续判断区间是否重合。
	if curr.start < e.start {
		if e.left == nil {
			e.left = curr
		} else {
			return e.left.Insert(curr)
		}
	} else {
		if e.right == nil {
			e.right = curr
		} else {
			return e.right.Insert(curr)
		}
	}
	return true
}

// MyCalender define
type MyCalendar struct {
	root *Event
}

// Constructor729 define
func Constructor729() MyCalendar {
	return MyCalendar{
		root: nil,
	}
}

// book define
func (this *MyCalendar) Book(start int, end int) bool {
	curr := &Event{start: start, end: end, left: nil, right: nil}
	if this.root == nil {
		this.root = curr
		return true
	}
	return this.root.Insert(curr)
}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Book(start,end);
 */

/*
解题思路
- 要求实现一个日程安排的功能，如果有日程安排冲突了，就返回 false，
如果不冲突则返回 ture
- 这一题有多种解法，第一种解法可以用类似第 34 题的解法。
先排序每个区间，然后再这个集合中用二分搜索找到最后一个区间的左值
比当前要比较的区间左值小的，如果找到，再判断能否插入进去
(判断右区间是否比下一个区间的左区间小)，此方法时间复杂度 O(n log n)
- 第二种解法是用生成一个 BST 树。在插入树中先排除不能插入的情况，
例如区间有重合。然后以区间左值为依据，递归插入，
每次插入依次会继续判断区间是否重合。直到不能插入，则返回 fasle。
整个查找的时间复杂度是 O(log n)。
*/