/* 435. 无重叠区间
给定一个区间的集合 intervals ，
其中 intervals[i] = [starti, endi] 。
返回 需要移除区间的最小数量，使剩余区间互不重叠 。

Input: [[1,2], [2,4], [1,3]]
Output: 1
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
        {
            return a[1] < b[1]; // 为什么是1？便于判断是否重叠
        });
        int removed = 0, prev = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < prev) {
                ++removed;
            } else {
                prev = intervals[i][1];
            }
        }
        return removed;
    }
};

/* 435. 无重叠区间
给定一个区间的集合 intervals ，
其中 intervals[i] = [starti, endi] 。
返回 需要移除区间的最小数量，使剩余区间互不重叠 。

Input: [[1,2], [2,4], [1,3]]
Output: 1
*/