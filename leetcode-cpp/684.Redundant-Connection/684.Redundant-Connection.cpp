/**
 * @file 684.Redundant-Connection.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * leetcode-684.冗余连接
 * 
树可以看成是一个连通且 无环 的 无向 图。

给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。
添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。
图的信息记录于长度为 n 的二维数组 edges ，
edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。

请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。
如果有多个答案，则返回数组 edges 中最后出现的边。
 
示例 1：

输入: edges = [[1,2], [1,3], [2,3]]
输出: [2,3]

示例 2：
输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]

输出: [1,4]
 
提示:
n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
edges 中无重复元素
给定的图是连通的 
 */

class Solution {
public:
    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2); // 合并这两个顶点的连通分量
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        for (auto& edge : edges) { // 遍历每一条边
            int node1 = edge[0], node2 = edge[1];
            if (Find(parent, node1) != Find(parent, node2)) { // 如果两个顶点属于不同的连通分量
                Union(parent, node1, node2); // 合并这两个顶点的连通分量
            } else { // 如果两个顶点属于相同的连通分量
                return edge; // 将当前的边作为答案返回
            }
        }
        return vector<int>{};
    }
};

/**
 * @brief 
 * 
方法一：并查集
在一棵树中，边的数量比节点的数量少 1。如果一棵树有 n 个节点，
则这棵树有 n-1 条边。这道题中的图在树的基础上多了一条附加的边，
因此边的数量也是 n。

树是一个连通且无环的无向图，在树中多了一条附加的边之后就会出现环，
因此附加的边即为导致环出现的边。

可以通过并查集寻找附加的边。初始时，每个节点都属于不同的连通分量。
遍历每一条边，判断这条边连接的两个顶点是否属于相同的连通分量。

- 如果两个顶点属于不同的连通分量，则说明在遍历到当前的边之前，
这两个顶点之间不连通，因此当前的边不会导致环出现，
合并这两个顶点的连通分量。

- 如果两个顶点属于相同的连通分量，则说明在遍历到当前的边之前，
这两个顶点之间已经连通，因此当前的边导致环出现，为附加的边，
将当前的边作为答案返回。
 */