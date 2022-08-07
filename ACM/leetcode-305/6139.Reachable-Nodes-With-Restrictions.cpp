/**
 * @file 6139.Reachable-Nodes-With-Restrictions.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * 
 * @copyright Copyright (c) 2022
 * leetcode-6139.受限条件下可到达节点的数目
 * 
现有一棵由 n 个节点组成的无向树，节点编号从 0 到 n - 1 ，
共有 n - 1 条边。

给你一个二维整数数组 edges ，长度为 n - 1 ，其中 
edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。
另给你一个整数数组 restricted 表示 受限 节点。

在不访问受限节点的前提下，返回你可以从节点 0 到达的 最多 节点数目。

注意，节点 0 不 会标记为受限节点。

示例 1：

输入：n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], 
restricted = [4,5]
输出：4

解释：上图所示正是这棵树。
在不访问受限节点的前提下，只有节点 [0,1,2,3] 可以从节点 0 到达。

示例 2：

输入：n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
输出：3

解释：上图所示正是这棵树。
在不访问受限节点的前提下，只有节点 [0,5,6] 可以从节点 0 到达。
 

提示：

2 <= n <= 10^5
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges 表示一棵有效的树
1 <= restricted.length < n
1 <= restricted[i] < n
restricted 中的所有值 互不相同
 */


const int N = 1e5 + 10;
vector<int> graph[N];
// 大佬@return up; 的解法
class Solution {
public:

    // 用来实现O(1)的时间复杂度，查询受限节点
    unordered_set<int> r;
    // 建图+dfs搜索 从节点0出发能访问到的所有节点
    int reachableNodes(int n, vector<vector<int>>& edges,
                       vector<int>& restricted) {
        fill(graph, graph + n, vector<int>());
        for (auto x : restricted) {
            r.insert(x);
        }
        // 建立无向图
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return dfs(0, -1);
    }

    // 参数fa用来记录父节点，避免将无向图走成循环
    int dfs(int x, int fa) {
        // 受限节点不能访问，所有受限节点阻拦的节点也不能访问
        if (r.count(x)) {
            return 0;
        }
        int res = 1;
        // 访问当前节点的所有邻接点，同时不能反方向走
        // 比如父节点为1，那么此时访问节点2时，就不能继续访问节点2的邻接点1了
        // 所以使用fa来标记访问过的节点，避免走回路
        for (int y : graph[x]) {
            if (y != fa) {
                res += dfs(y, x);
            }
        }
        return res;
    }
};

/**
 * @brief 参考大佬@灵茶山艾府 的题解
 * 
DFS + 哈希表
用哈希表记录哪些节点是受限的，然后 DFS 这棵树，仅访问没有受限的子节点。
统计访问过的节点个数，即为答案。
 */