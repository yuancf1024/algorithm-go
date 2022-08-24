/**
 * @file 252.Meeting-Rooms.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-24
 * 
 * @copyright Copyright (c) 2022
 * leetcode-252.Meeting-Rooms
 * 
Given an array of meeting time intervals consisting of 
start and end times [[s1,e1],[s2,e2],...] (si < ei), 
determine if a person could attend all meetings.

Example 1:
Input: 
[[0,30],[5,10],[15,20]]
Output: false

Example 2:
Input: [[7,10],[2,4]]
Output: true

NOTE: input types have been changed on April 15, 2019. 
Please reset to default code definition to get new method signature.

 */

// 解法1：暴力比较
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); ++i) {
            for (int j = i + 1; j < intervals.size(); ++j) {
                if ((intervals[i][0] >= intervals[j][0] && intervals[i][0] < intervals[j][1]) ||
                (intervals[j][0] >= intervals[i][0] && intervals[j][0] < intervals[i][1])) {
                    return false;
                }
            }
        }
        return true;
    }
};

// 解法2：先排序再比较
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i-1][1]) {
                return false;
            }
        }
        return true;
    }
};


/**
 * @brief 
 * 解法1：暴力比较
 * 这道题给了我们一堆会议的时间，问能不能同时参见所有的会议，
 * 这实际上就是求区间是否有交集的问题，那么最简单暴力的方法就是每两个区间比较一下，
 * 看是否有 overlap，有的话直接返回 false 就行了。
 * 比较两个区间a和b是否有 overlap，可以检测两种情况，
 * - 如果a的起始位置大于等于b的起始位置，且此时a的起始位置小于b的结束位置，则一定有 overlap，
 * 
 * - 另一种情况是a和b互换个位置，如果b的起始位置大于等于a的起始位置，且此时b的起始位置小于a的结束位置，
 * 那么一定有 overlap，参见代码如下：
 
解法2：先排序再比较
 我们可以先给所有区间排个序，用起始时间的先后来排，
 然后从第二个区间开始，如果开始时间早于前一个区间的结束时间，
 则说明会议时间有冲突，返回 false，
 遍历完成后没有冲突，则返回 true，参见代码如下：
 */