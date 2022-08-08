/**
 * @file 547.Number-of-Provinces.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * 
 * @copyright Copyright (c) 2022
 * leetcode-547.省份数量
 * 
有 n 个城市，其中一些彼此相连，另一些没有相连。
如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，
那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 
表示第 i 个城市和第 j 个城市直接相连，
而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。

示例 1：
输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
输出：2

示例 2：
输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
输出：3
 
提示：

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] 为 1 或 0
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
 */

// 方法一：深度优先搜索
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<int> visited(cities); // 记录城市是否已被遍历过
        int provinces = 0;
        for (int i = 0; i < cities; ++i) { // 遍历所有城市
            if (!visited[i]) { // 之前没有被访问过
                dfs(isConnected, visited, cities, i); // 开始DFS
                provinces++; 
            }
        }
        return provinces;
    }
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int cities, int i) {
        for (int j = 0; j < cities; ++j) { // 遍历与城市i直接相连的城市
            if (isConnected[i][j] == 1 && !visited[j]) { // i、j相连 且 j未被访问过
                visited[j] = 1; // 标记该次DFS访问过的城市
                dfs(isConnected, visited, cities, j); // 继续DFS
            }
        }
    }
};

// 方法二：广度优先搜索
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<int> visited(cities);
        int provinces = 0;
        queue<int> q;
        for (int i = 0; i < cities; ++i) { // 遍历每个城市
            if (!visited[i]) { // 如果该城市尚未被访问过
                q.push(i); // 入队
                while (!q.empty()) { // 队列不为空
                    int j = q.front(); // 队首出队
                    q.pop();
                    visited[j] = 1; // 标记该次访问的城市
                    for (int k = 0; k < cities; ++k) {
                        if (isConnected[j][k] == 1 && !visited[k]) { // j、k相连 且k未被访问过
                            q.push(k); // k入队
                        }
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};

/**
 * @brief 
 * 
前言
可以把 n 个城市和它们之间的相连关系看成图，
城市是图中的节点，相连关系是图中的边，给定的矩阵 isConnected 
即为图的邻接矩阵，省份即为图中的连通分量。

计算省份总数，等价于计算图中的连通分量数，
可以通过深度优先搜索或广度优先搜索实现，也可以通过并查集实现。


方法一：深度优先搜索


深度优先搜索的思路是很直观的。遍历所有城市，对于每个城市，
- 如果该城市尚未被访问过，则从该城市开始深度优先搜索，通过矩阵isConnected
得到与该城市直接相连的城市有哪些，这些城市和该城市属于同一个连通分量，
然后对这些城市继续深度优先搜索，直到同一个连通分量的所有城市都被访问到，
即可得到一个省份。

遍历完全部城市以后，即可得到连通分量的总数，即省份的总数。
复杂度分析

时间复杂度：O(n^2)，其中 n是城市的数量。需要遍历矩阵 n 中的每个元素。

空间复杂度：O(n)，其中 n 是城市的数量。
需要使用数组 visited 记录每个城市是否被访问过，
数组长度是 n，递归调用栈的深度不会超过 n。


方法二：广度优先搜索


也可以通过广度优先搜索的方法得到省份的总数。
对于每个城市，如果该城市尚未被访问过，则从该城市开始广度优先搜索，
直到同一个连通分量中的所有城市都被访问到，即可得到一个省份。

复杂度分析
时间复杂度：O(n^2)，其中 n 是城市的数量。需要遍历矩阵 isConnected 中的每个元素。

空间复杂度：O(n)，其中 n 是城市的数量。
需要使用数组 visited 记录每个城市是否被访问过，数组长度是 n，
广度优先搜索使用的队列的元素个数不会超过 n。


 */