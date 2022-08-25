/**
 * @file 253.Meeting-Rooms-II.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-24
 * 
 * @copyright Copyright (c) 2022
 * 253.Meeting-Rooms-II
 * 
Given an array of meeting time intervals consisting of 
start and end times [[s1,e1],[s2,e2],...] (si < ei), 
find the minimum number of conference rooms required.

Example 1:
Input: 
[[0, 30],[5, 10],[15, 20]]
Output: 2

Example 2:
Input: [[7,10],[2,4]]
Output: 1

NOTE: input types have been changed on April 15, 2019. 
Please reset to default code definition to get new method signature.
 */

// 解法1：TreeMap 不太好理解
class Solution {
public:
    int minMeetingRooms(vector<int>& intervals) { 
        map<int, int> m;
        for (auto a : intervals) {
            ++m[a[0]];
            --m[a[1]];
        }
        int rooms = 0, res = 0;
        for (auto it : m) {
            res = max(res, res += it.second);
        }
        return res;
    }
};

// 解法2：先排序再比较 手动模拟一下比较好理解
class Solution {
public:
    int minMeetingRooms(vector<int>& intervals) { 
        vector<int> starts, ends;
        int res = 0, endpos = 0;
        for (auto& a : intervals) {
            starts.push_back(a[0]);
            ends.push_back(a[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        for (int i = 0; i < intervals.size(); ++i) {
            if (starts[i] < ends[endpos]) {
                res++;
            } else {
                endpos++;
            }
        }
        return res;
    }
};

// 解法3：使用最小堆 很巧妙
class Solution {
public:
    int minMeetingRooms(vector<int>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        priority_queue<int, vector<int>, greater<int>> q;
        for (auto& interval : intervals) {
            if (!q.empty() && q.top() <= interval[0]) {
                q.pop();
            }
            q.push(interval[1]);
        }
        return q.size();
    }
};

/**
 * @brief 
 * 解法1：
 * 这道题是之前那道 Meeting Rooms 的拓展，那道题只问我们是否能参加所有的会，
 * 也就是看会议之间有没有时间冲突，而这道题让求最少需要安排几个会议室，
 * 有时间冲突的肯定需要安排在不同的会议室。
 * 
 * 这道题有好几种解法，先来看使用 TreeMap 来做的，
 * 遍历时间区间，对于起始时间，映射值自增1，
 * 对于结束时间，映射值自减1，
 * 然后定义结果变量 res，和房间数 rooms，
 * 遍历 TreeMap，时间从小到大，房间数每次加上映射值，然后更新结果 res，
 * 遇到起始时间，映射是正数，则房间数会增加，如果一个时间是一个会议的结束时间，
 * 也是另一个会议的开始时间，则映射值先减后加仍为0，并不用分配新的房间，
 * 而结束时间的映射值为负数更不会增加房间数，利用这种思路可以写出代码如下:
 * 
 * 
 * 第二种方法是用两个一维数组来做，分别保存起始时间和结束时间，
 * 然后各自排个序，定义结果变量 res 和结束时间指针 endpos，
 * 然后开始遍历，如果当前起始时间小于结束时间指针的时间，则结果自增1，
 * 反之结束时间指针自增1，这样可以找出重叠的时间段，
 * 从而安排新的会议室，参见代码如下：
 * 
 * 
 * 再来一看一种使用最小堆来解题的方法，这种方法先把所有的时间区间按照起始时间排序，
 * 然后新建一个最小堆，开始遍历时间区间，
 * 如果堆不为空，且首元素小于等于当前区间的起始时间，
 * 去掉堆中的首元素，把当前区间的结束时间压入堆，由于最小堆是小的在前面，
 * 那么假如首元素小于等于起始时间，说明上一个会议已经结束，
 * 可以用该会议室开始下一个会议了，所以不用分配新的会议室，
 * 遍历完成后堆中元素的个数即为需要的会议室的个数，参见代码如下；
 */

