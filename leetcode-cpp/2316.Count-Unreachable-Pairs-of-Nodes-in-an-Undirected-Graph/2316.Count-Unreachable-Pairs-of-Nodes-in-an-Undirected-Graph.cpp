/**
 * @file 2316.Count-Unreachable-Pairs-of-Nodes-in-an-Undirected-Graph.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-2316.统计无向图中无法互相到达点对数
 * @version 0.1
 * @date 2023-10-21
 * 
 * @copyright Copyright (c) 2023
 * 给你一个整数 n ，表示一张 无向图 中有 n 个节点，
 * 编号为 0 到 n - 1 。同时给你一个二维整数数组 edges ，
 * 其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 无向 边。

请你返回 无法互相到达 的不同 点对数目 。

示例 1：
输入：n = 3, edges = [[0,1],[0,2],[1,2]]
输出：0
解释：所有点都能互相到达，意味着没有点对无法互相到达，所以我们返回 0 。

示例 2：
输入：n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
输出：14
解释：总共有 14 个点对互相无法到达：
[[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]]
所以我们返回 14 。

提示：

1 <= n <= 10^5
0 <= edges.length <= 2 * 10^5
edges[i].length == 2
0 <= ai, bi < n
ai != bi
不会有重复边。
 */

#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
    vector<int> parents;
    vector<int> sizes;
public:
    UnionFind(int n) : parents(n), sizes(n, 1) {
        iota(parents.begin(), parents.end(), 0);
    }

    int Find(int x) {
        if (parents[x] == x) {
            return x;
        }
        return parents[x] = Find(parents[x]);
    }

    void Union(int x, int y) {
        int rx = Find(x), ry = Find(y);
        if (rx != ry) {
            if (sizes[rx] > sizes[ry]) {
                parents[ry] = rx;
                sizes[rx] += sizes[ry];
            } else {
                parents[rx] = ry;
                sizes[ry] += sizes[rx];
            }
        }
    }

    int GetSize(int x) {
        return sizes[x];
    }
};

class Solution {
public:

    // 方法一：并查集
    long long countPairs(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (const auto &edge : edges) {
            uf.Union(edge[0], edge[1]);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += n - uf.GetSize(uf.Find(i));
        }
        return ans / 2;
    }

    // 方法二：DFS
    long long countPairs1(int n, vector<vector<int>>& edges) {
        vector<int> g[n];
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        function<int(int)> dfs = [&](int i) {
            if (vis[i]) {
                return 0;
            }
            vis[i] = true;
            int cnt = 1;
            for (int j : g[i]) {
                cnt += dfs(j);
            }
            return cnt;
        };
        long long ans = 0, s = 0;
        for (int i = 0; i < n; ++i) {
            int t = dfs(i);
            ans += s * t;
            s += t;
        }
        return ans;
    }
};

int main() {
    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}};
    long long res = Solution().countPairs1(n, edges);
    cout << res << endl;
    return 0;
}

/**
 * @brief 
 * 方法一：并查集
思路

部分点通过 edges 连接，可以组成连通分量。
同属于同一个连通分量的两个点可以互相到达，
不属于同一个连通分量的点一定无法互相到达。
我们可以利用并查集，找到图中所有的连通分量和每个连通分量的点数 size。
再遍历每个点，并查询它所在的连通分量的点数 size，
而 n−size就是与这个点无法互相到达的点数。
对每个点进行这样的计算后求和，但这样的方法计算，每个点对会被计算两次，
因此最后结果需要除以 2。

在使用并查集时，为了提高效率，我们可以使用路径压缩的方法。
因为计算点对数目的时候我们需要用到连通分量的点数，
我们也可以使用按点数大小合并的优化。

复杂度分析

时间复杂度：O((m+n)×α(n))，其中 m 是边数，
α 表示阿克曼函数的反函数。

空间复杂度：O(n)。


方法二：DFS

对于无向图中的任意两个节点，如果它们之间存在一条路径，
那么它们之间就是互相可达的。

因此，我们可以通过深度优先搜索的方式，找出每一个连通分量中的节点个数 t，
然后将当前连通分量中的节点个数 t 与之前所有连通分量中的节点个数 s 相乘，
即可得到当前连通分量中的不可达点对数目 s×t，然后将 t 加到 s 中。
继续搜索下一个连通分量，直到搜索完所有连通分量，即可得到答案。
时间复杂度 O(n+m)，
空间复杂度 O(n+m)。
其中 n 和 m 分别是节点数和边数。
 */