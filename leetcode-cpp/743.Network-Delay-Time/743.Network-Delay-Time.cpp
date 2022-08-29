/**
 * @file 743.Network-Delay-Time.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-30
 * 
 * @copyright Copyright (c) 2022
 * leetcode-743.网络延迟时间
 * 
 * 有 n 个网络节点，标记为 1 到 n。

给你一个列表 times，表示信号经过 有向 边的传递时间。
 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点，
 wi 是一个信号从源节点传递到目标节点的时间。

现在，从某个节点 K 发出一个信号。
需要多久才能使所有节点都收到信号？
如果不能使所有节点收到信号，返回 -1 。

示例 1：
输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
输出：2

示例 2：
输入：times = [[1,2,1]], n = 2, k = 1
输出：1

示例 3：
输入：times = [[1,2,1]], n = 2, k = 2
输出：-1
 
提示：

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
所有 (ui, vi) 对都 互不相同（即，不含重复边）
 * 
 */

// 方法一：Dijkstra算法 + 枚举
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (auto& t : times) { // 给图节点赋权值
            int x = t[0] - 1, y = t[1] - 1;
            g[x][y] = t[2];
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0; // 节点k距离为0
        vector<int> used(n); // 已确定节点
        for (int i = 0; i < n; ++i) {
            int x = -1;
            for (int y = 0; y < n; ++y) {
                if (!used[y] && (x == -1 || dist[y] < dist[x])) { // 从未确定节点中找到一个与起点距离最短的点x
                    x = y;
                }
            }
            used[x] = true;
            for (int y = 0; y < n;++y) { // 用x「更新」从起点到其他所有「未确定节点」的距离
                dist[y] = min(dist[y], dist[x] + g[x][y]); // 用起点到节点x的最短路长度加上从节点x到节点y的边的长度，去比较起点到节点y的最短路长度，如果前者小于后者，就用前者更新后者
            } 
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};

// 方法一：Dijkstra算法 + 小根堆
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<pair<int, int>>> g(n);
        for (auto& t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].emplace_back(y, t[2]); // 目的点 & x到y所花时间
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q; // 小根堆first存时间 second存节点 
        q.emplace(0, k - 1);
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int time = p.first, x = p.second;
            if (dist[x] < time) {
                continue;
            }
            for (auto& e : g[x]) {
                int y = e.first, d = dist[x] + e.second; // 目的点y 和 k到x的时间+x到y的时间
                if (d < dist[y]) { // 比较k到x的时间+x到y的时间 与 k到y的时间
                    dist[y] = d;
                    q.emplace(d, y);
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};

/**
 * @brief 
 * 前言
本题需要用到单源最短路径算法Dijkstra，
现在让我们回顾该算法，其主要思想是贪心。

将所有节点分成两类：
- 已确定从起点到当前点的最短路长度的节点，
- 以及未确定从起点到当前点的最短路长度的节点
（下面简称「未确定节点」和「已确定节点」）。

每次从「未确定节点」中取一个与起点距离最短的点，
将它归类为「已确定节点」，
并用它「更新」从起点到其他所有「未确定节点」的距离。
直到所有点都被归类为「已确定节点」。

用节点A「更新」节点B的意思是，用起点到节点A的最短路长度
加上从节点A到节点B的边的长度，去比较起点到节点B的最短路长度，
如果前者小于后者，就用前者更新后者。这种操作也被叫做「松弛」。

这里暗含的信息是：每次选择「未确定节点」时，
起点到它的最短路径的长度可以被确定。

可以这样理解，因为我们已经用了每一个「已确定节点」更新过了当前节点，
无需再次更新（因为一个点不能多次到达）。
而当前节点已经是所有「未确定节点」中与起点距离最短的点，
不可能被其它「未确定节点」更新。
所以当前节点可以被归类为「已确定节点」。

方法一：Dijkstra算法
根据题意，从节点k发出的信号，到达节点x的时间
就是节点k到节点x的最短路的长度。
因此我们需要求出节点k到其余所有点的最短路，
其中的最大值就是答案。
若存在从k出发无法到达的点，则返回−1。

下面的代码将节点编号减小了1，从而使节点编号位于[0,n−1]范围。


除了枚举，我们还可以使用一个小根堆来寻找
「未确定节点」中与起点距离最近的点。


复杂度分析

枚举写法的复杂度如下：

时间复杂度：O(n^2+m)，其中m是数组times 的长度。
空间复杂度：O(n^2)。邻接矩阵需占用 O(n^2)的空间。

堆的写法复杂度如下：

时间复杂度：O(mlogm)，其中m是数组times 的长度。
空间复杂度：O(n+m)。

值得注意的是，由于本题边数远大于点数，
是一张稠密图，因此在运行时间上，枚举写法要略快于堆的写法。

 */