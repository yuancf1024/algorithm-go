/**
 * @file 1450.Number-of-Students-Doing-Homework-at-a-Given-Time.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1450.在既定时间做作业的学生人数
 * 
给你两个整数数组 startTime（开始时间）和 endTime（结束时间），
并指定一个整数 queryTime 作为查询时间。

已知，第 i 名学生在 startTime[i] 时开始写作业并于 endTime[i] 时完成作业。

请返回在查询时间 queryTime 时正在做作业的学生人数。
形式上，返回能够使 queryTime 处于区间 [startTime[i], endTime[i]]（含）的学生人数。

示例 1：
输入：startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
输出：1

解释：一共有 3 名学生。
第一名学生在时间 1 开始写作业，并于时间 3 完成作业，在时间 4 没有处于做作业的状态。
第二名学生在时间 2 开始写作业，并于时间 2 完成作业，在时间 4 没有处于做作业的状态。
第三名学生在时间 3 开始写作业，预计于时间 7 完成作业，这是是唯一一名在时间 4 时正在做作业的学生。

示例 2：
输入：startTime = [4], endTime = [4], queryTime = 4
输出：1

解释：在查询时间只有一名学生在做作业。

示例 3：
输入：startTime = [4], endTime = [4], queryTime = 5
输出：0

示例 4：
输入：startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
输出：0

示例 5：
输入：startTime = [9,8,7,6,5,4,3,2,1], endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
输出：5
 
提示：
startTime.length == endTime.length
1 <= startTime.length <= 100
1 <= startTime[i] <= endTime[i] <= 1000
1 <= queryTime <= 1000

 */

// 2022-08-19first
/*
思路：
同时遍历2个数组，判断第i名学生的开始时间和截止时间段是否包含queryTime
- 如果包含，+1
- 如果不包含，continue，继续下一个遍历

复杂度分析
时间复杂度：O(n)，其中n 为 数组的长度。只需遍历一遍数组即可。
空间复杂度：O(1)。
*/
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
                res++;
            }
        }
        return res;
    }
};

// 方法二：差分数组
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int maxEndTime = *max_element(endTime.begin(), endTime.end());
        if (queryTime > maxEndTime) {
            return 0;
        }
        vector<int> cnt(maxEndTime + 2); // ?
        for (int i = 0; i < n; ++i) {
            cnt[startTime[i]]++;
            cnt[endTime[i] + 1]--;
        }
        int ans = 0;
        for (int i = 0; i <= queryTime; ++i) {
            ans += cnt[i];
        }
        return ans;
    }
};

/**
 * @brief 本题主要是用来体会方法2-差分和方法3-二分查找
 * 方法二：差分数组
利用差分数组的思想，对差分数组求前缀和，可以得到统计出t 时刻正在做作业的人数。
我们初始化差分数组cnt 每个元素都为0，在每个学生的起始时间处
cnt[startTime[i]] 加1，在每个学生的结束时间处cnt[endTime[i]+1] 减1，
因此我们可以统计出queryTime 时刻正在做作业的人数为 
∑ cnt[j]
j=0
queryTime

复杂度分析
时间复杂度：O(n+queryTime)，其中n 为数组的长度，
queryTime 为给定的查找时间。首先需要遍历一遍数组，需要的时间为 O(n)，
然后需要查分求和求出queryTime 时间点正在作业的学生总数，
需要的时间为 O(queryTime)，因此总的时间为O(n+queryTime)。
空间复杂度：O(max(endTime))。

方法三：二分查找
对于每个学生的作业时间 [\textit{startTime}[i], \textit{endTime}[i]][startTime[i],endTime[i]]，一定满足 \textit{startTime}[i]\le \textit{endTime}[i]startTime[i]≤endTime[i]。如果第 ii 名学生在 \textit{queryTime}queryTime 时正在作业，则一定满足 \textit{startTime}[i] \le \textit{queryTime} \le \textit{endTime}[i]startTime[i]≤queryTime≤endTime[i]。设起始时间小于等于 \textit{queryTime}queryTime 的学生集合为 \textit{lessStart}lessStart，设结束时间小于 \textit{queryTime}queryTime 的学生集合为 \textit{lessEnd}lessEnd，则根据上述推理可以知道 \textit{lessEnd} \in \textit{lessStart}lessEnd∈lessStart，我们从 \textit{lessStart}lessStart 去除 \textit{lessEnd}lessEnd 的子集部分即为符合条件的学生集合。因此我们通过二分查找找到始时间小于等于 \textit{queryTime}queryTime 的学生人数，然后减去结束时间小于 \textit{queryTime}queryTime 的学生人数，最终结果即为符合条件要求。

复杂度分析

时间复杂度：O(n \log n)O(nlogn)，其中 nn 为 数组的长度。排序需要的时间为 O(n \log n)O(nlogn)，二分查找的时间复杂度为 O(\log n)O(logn)。

空间复杂度：O(\log n)O(logn)。排序需要的栈空间为 O(\log n)O(logn)。

 */