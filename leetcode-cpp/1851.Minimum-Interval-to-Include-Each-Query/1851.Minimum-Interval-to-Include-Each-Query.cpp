/**
 * @file 1851.Minimum-Interval-to-Include-Each-Query.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-1851.包含每个查询的最小区间
 * @version 0.1
 * @date 2023-07-18
 * 
 * @copyright Copyright (c) 2023
 * 
给你一个二维整数数组 intervals ，其中
intervals[i] = [lefti, righti] 表示第i个区间
开始于 lefti 、结束于 righti（包含两侧取值，闭区间）。
区间的长度定义为区间中包含的整数数目，
更正式地表达是 righti - lefti + 1 。

再给你一个整数数组queries 。第j个查询的答案是满足
lefti <= queries[j] <= righti 的长度最小区间 i 
的长度 。如果不存在这样的区间，那么答案是 -1 。

以数组形式返回对应查询的所有答案。

示例 1：
输入：intervals = [[1,4],[2,4],[3,6],[4,4]], 
queries = [2,3,4,5]
输出：[3,3,1,4]

解释：查询处理如下：
- Query = 2 ：区间 [2,4] 是包含 2 的最小区间，
答案为 4 - 2 + 1 = 3 。
- Query = 3 ：区间 [2,4] 是包含 3 的最小区间，
答案为 4 - 2 + 1 = 3 。
- Query = 4 ：区间 [4,4] 是包含 4 的最小区间，
答案为 4 - 4 + 1 = 1 。
- Query = 5 ：区间 [3,6] 是包含 5 的最小区间，
答案为 6 - 3 + 1 = 4 。

示例 2：
输入：intervals = [[2,3],[2,5],[1,8],[20,25]], 
queries = [2,19,5,22]
输出：[2,-1,4,6]
解释：查询处理如下：
- Query = 2 ：区间 [2,3] 是包含 2 的最小区间，
答案为 3 - 2 + 1 = 2 。
- Query = 19：不存在包含 19 的区间，答案为 -1 。
- Query = 5 ：区间 [2,5] 是包含 5 的最小区间，
答案为 5 - 2 + 1 = 4 。
- Query = 22：区间 [20,25] 是包含 22 的最小区间，
答案为 25 - 20 + 1 = 6 。
 

提示：
1 <= intervals.length <= 10^5
1 <= queries.length <= 10^5
intervals[i].length == 2
1 <= lefti <= righti <= 10^7
1 <= queries[j] <= 10^7

 */

#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> qindex(queries.size());
        iota(qindex.begin(), qindex.end(), 0);
        sort(qindex.begin(), qindex.end(), [&](int i, int j) -> bool {
            return queries[i] < queries[j];
        });
        sort(intervals.begin(), intervals.end(), [](const vector<int>& it1, const vector<int>& it2) -> bool {
            return it1[0] < it2[0];
        });

        priority_queue<vector<int>> pq;

        vector<int> res(queries.size(), -1);

        int i = 0;
        for (auto qi : qindex) {
            while (i < intervals.size() && intervals[i][0] <= queries[qi]) {
                int l = intervals[i][1] - intervals[i][0] + 1;
                pq.push({-l, intervals[i][0], intervals[i][1]});
                i++;
            }

            while (!pq.empty() && pq.top()[2] < queries[qi]) {
                pq.pop();
            }

            if (!pq.empty()) {
                res[qi] = -pq.top()[0];
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
    vector<int> queries = {2,3,4,5};

    vector<int> res = Solution().minInterval(intervals, queries);

    for (auto x : res) {
        cout << x << endl;
    }

    return 0;
}

/**
 * @brief leetcode官方题解
 * 
方法一：离线算法 + 优先队列
首先我们对问题进行分析，对于第j个查询，可以遍历
intervals，找到满足 
left_i≤queries_j≤right_i的长度最小区间i的长度。
以上思路对于每个查询，都需要重新遍历 
intervals。

如果查询是递增的，那么我们可以对intervals按左端点 
left从小到大进行排序，使用一个指针i记录下一个要访问
的区间intervals[i]，初始时i=0，使用优先队列pq
保存区间（优先队列的比较key为区间的长度，
队首元素为长度最小的区间）。对于第j个查询，
我们执行以下步骤：

1. 如果i等于intervals的长度或left_i>queries[j]，
终止步骤；
2. 将intervals[i] 添加到优先队列pq，将i的值加1，
继续执行步骤1。

此时所有符合left≤queries_j≤right 的区间都在pq，
我们不断地获取优先队列pq 的队首区间：

- 如果队首区间的右端点right<queries[j]，
那么说明该区间不满足条件，从pq中出队；
- 如果队首区间的右端点right≥queries[j]，
那么该区间为第j个查询的最小区间，终止过程。

对于第j+1个查询，因为查询是递增的，所以有 
queries[j+1]≥queries[j]，那么此时pq中的区间都满足 
left≤queries[j+1]。在第j个查询中丢弃的区间有 
right<queries[j]≤queries[j+1]，因此丢弃的区间
不满足第j+1个查询。同样在第j+1个查询执行与第j个
查询类似的步骤，将可能满足条件的区间加入优先队列pq
中，那么此时所有满足条件的区间都在优先队列pq中，
执行类似第j个查询的出队操作。

由以上分析，如果查询满足递增的条件，
那么可以利用优先队列进行优化。题目一次性提供所有的
查询，基于离线原理，我们对所有查询从小到大进行排序，
然后执行以上算法。


复杂度分析

时间复杂度：O(mlogm+nlogn)，其中m和n分别为 
intervals和queries的长度。排序需要O(mlogm+nlogn)，
最多执行m次入队和出队操作，需要O(mlogm)。

空间复杂度：O(m+n)。保存qindex需要O(m)，
保存pq需要O(n)。
 */