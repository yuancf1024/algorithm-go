package leetcode

import "sort"

/* 933. 最近的请求次数
写一个 RecentCounter 类来计算特定时间范围内最近的请求。
请你实现 RecentCounter 类：
RecentCounter() 初始化计数器，请求数为 0 。
int ping(int t) 在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的
某个时间，并返回过去 3000 毫秒内发生的所有请求数（包括新请求）。
确切地说，返回在 [t-3000, t] 内发生的请求数。
保证 每次对 ping 的调用都使用比之前更大的 t 值。

示例 1：
输入：
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
输出：
[null, 1, 2, 3, 3]

解释：
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1]，范围是 [-2999,1]，返回 1
recentCounter.ping(100);   // requests = [1, 100]，范围是 [-2900,100]，返回 2
recentCounter.ping(3001);  // requests = [1, 100, 3001]，范围是 [1,3001]，返回 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002]，范围是 [2,3002]，返回 3
 
提示：

1 <= t <= 10^9
保证每次对 ping 调用所使用的 t 值都 严格递增
至多调用 ping 方法 104 次
*/

type RecentCounter struct {
	list []int
}


func Constructor933() RecentCounter {
	return RecentCounter{
		list : []int{},
	}
}

// 参考halfrost
func (this *RecentCounter) Ping(t int) int {
	this.list = append(this.list, t)
	index := sort.Search(len(this.list), func(i int) bool {
		return this.list[i] >= t-3000
	})
	if index < 0 {
		index = -index - 1
	}
	return len(this.list) - index
}


/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */

/*
解题思路
要求设计一个类，可以用 ping(t) 的方法，
计算 [t-3000, t] 区间内的 ping 数。t 是毫秒。
这一题比较简单，ping() 方法用二分搜索即可。
*/