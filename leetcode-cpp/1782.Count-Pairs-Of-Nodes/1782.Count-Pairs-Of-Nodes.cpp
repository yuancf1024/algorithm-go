/**
 * @file 1782.Count-Pairs-Of-Nodes.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-1782.统计点对的数目
 * @version 0.1
 * @date 2023-08-23
 * 
 * @copyright Copyright (c) 2023
 * 
 * 给你一个无向图，无向图由整数 n ，
 * 表示图中节点的数目，和 edges 组成，
 * 其中 edges[i] = [ui, vi] 
 * 表示 ui 和 vi 之间有一条无向边。
 * 同时给你一个代表查询的整数数组 queries 。

第 j 个查询的答案是满足如下条件的点对 (a, b) 
的数目：

a < b
cnt 是与 a 或者 b 相连的边的数目，且 
cnt 严格大于 queries[j] 。

请你返回一个数组 answers ，其中 
answers.length == queries.length 且 
answers[j] 是第 j 个查询的答案。

请注意，图中可能会有 重复边 。

示例 1：
点对     与点对中至少一个点相连的边的数目
1,2     5
1,3     4
1,4     4
2,3     5
2,4     4
3,4     3

输入：n = 4, edges = [[1,2],[2,4],[1,3],
[2,3],[2,1]], queries = [2,3]
输出：[6,5]
解释：每个点对中，与至少一个点相连的边的数目
如上图所示。
answers[0] = 6。所有的点对(a, b)中边数和
都大于2，故有6个；
answers[1] = 5。所有的点对(a, b)中除了(3,4)
边数等于3，其它点对边数和都大于3，故有5个。
示例 2：

输入：n = 5, edges = [[1,5],[1,5],[3,4],
[2,5],[1,3],[5,1],[2,3],[2,5]], 
queries = [1,2,3,4,5]
输出：[10,10,9,8,6]
 

提示：

2 <= n <= 2 * 104
1 <= edges.length <= 105
1 <= ui, vi <= n
ui != vi
1 <= queries.length <= 20
0 <= queries[j] < edges.length
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n);
        unordered_map<int, int> cnt;
        for (auto edge : edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            if (x > y) {
                swap(x, y);
            }
            degree[x]++;
            degree[y]++;
            cnt[x * n + y]++;
        }

        vector<int> arr = degree;
        vector<int> ans;
        sort(arr.begin(), arr.end());
        for (int bound : queries) {
            int total = 0;
            for (int i = 0, j = n - 1; i < n; i++) {
                while (j > i && arr[i] + arr[j] > bound) {
                    j--;
                }
                total += n - 1 - max(i, j);
            }
            for (auto &[val, freq] : cnt) {
                int x = val / n;
                int y = val % n;
                if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound) {
                    total--;
                }
            }
            ans.emplace_back(total);
        }

        return ans;
    }
};

int main() {
    return 0;
}

/**
 * @brief 
 * 
 */