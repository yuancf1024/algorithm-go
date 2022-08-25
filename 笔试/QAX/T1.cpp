#include <bits/stdc++.h>

using namespace std;

// leetcode类似题解法 用栈记录路径
class Solution {

public:
    vector<vector<int>> res;
    vector<int> stk;
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算dag 路径上起始到目的节点的路径数目
     * @param nodes int整型vector<vector<>> 第 i 个数组中的单元都表示有向图中 i
     * 号节点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b
     * 你就不能从 b→a ），若为空，就是没有下一个节点了。
     * @return int整型
     */
    int DagPathNum(vector<vector<int>>& nodes) { 
        stk.push_back(0);
        dfs(nodes, 0, nodes.size() - 1);
        return res.size();
    }

    // 辅函数
    void dfs(vector<vector<int>>& nodes, int x, int n) {
        if (x == n) {
            res.push_back(stk);
            return;
        }
        for (auto& y : nodes[x]) {
            stk.push_back(y);
            dfs(nodes, y, n);
            stk.pop_back(); // 栈顶出栈
        }
    }
};

// 和自己笔试时的思路一脉相承 不用记录路径 单纯计数
// 😂笔试时自己就是这种思路,但是就是没有写出来
// 讲道理,我的实现那里只是增加了visited数组来判断该节点是否被访问过,也没其他的变化亚
class Solution2 {

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算dag 路径上起始到目的节点的路径数目
     * @param nodes int整型vector<vector<>> 第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ），若为空，就是没有下一个节点了。
     * @return int整型
     */

    int res = 0;
    int DagPathNum(vector<vector<int>>& nodes) { 
        dfs(nodes, 0);
        return res;
    }

    // 辅函数
    void dfs(vector<vector<int>>& nodes, int idx) {
        if (nodes[idx].size() == 0) {
            res++;
            return;
        }
        for (auto& i : nodes[idx]) {
            dfs(nodes, i);
        }
    }
};

/**
 * @brief leetcode题解
 * 方法一：深度优先搜索
 * 思路和算法

我们可以使用深度优先搜索的方式求出所有可能的路径。
具体地，我们从 0 号点出发，使用栈记录路径上的点。
每次我们遍历到点 n−1，就将栈中记录的路径加入到答案中。

特别地，因为本题中的图为有向无环图（DAG），
搜索过程中不会反复遍历同一个点，因此我们无需判断当前点是否遍历过。

复杂度分析
- 时间复杂度：O(n*2^n)，其中 n 为图中点的数量。我们可以找到一种最坏情况，
即每一个点都可以去往编号比它大的点。此时路径数为 O(2^n)，
且每条路径长度为 O(n)，因此总时间复杂度为 O(n*2^n)。
- 空间复杂度：O(n)，其中 n 为点的数量。
主要为栈空间的开销。注意返回值不计入空间复杂度。
 * 
 */

/**
 * @brief
 *
城市0到城市4是有向无环图，
计算0到4有多少条路径可走?

寻路径：
自然是深度优先搜索

理清思路：

DFS 用栈模拟 或者递归
要计算路径，从城市0出发，遍历每条能够到达终点的路径，
到达终点，记录一次路径 0=未搜索，1=搜索中，2=已完成

定义全局变量 res

递归函数参数及返回值dfs(int u)

递归返回条件

遇到NULL节点，

visited[u] = 1;
if (nodes[u].size() == 0) {
    // 找到1条路径
    res++;
    return;
}

// 每次挑选一个 未搜索 的节点，开始继续进行深度优先搜索
for (int i = 0; i < nodes[u].size(); ++i) {
    if (!visited[i]) {
        dfs(i);
    }
}

递归逻辑
 */

class Solution1 {
    int res = 0;
    vector<int> visited; // 0 未访问 1 搜索中 2 以访问
    vector<vector<int>> nodes;

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算dag 路径上起始到目的节点的路径数目
     * @param nodes int整型vector<vector<>> 第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ），若为空，就是没有下一个节点了。
     * @return int整型
     */
    int DagPathNum(vector<vector<int> >& nodes) {
        // write code here
        // vector<vector<int>> paths;
        int num = nodes.size(); 
         visited.resize(num);
        for (int i = 0; i < num; ++i) {
            if (!visited[i]) { // 遍历搜索节点i
                dfs(i);
                // cout << i << endl;
            }
        }
        return res;
    }

    // 辅函数
    void dfs(int u) {
        visited[u] = 1;
        if (nodes[u].empty()) { // 终点是一个空数组
            // 找到1条路径
            res++;
            return;
        }

        // 每次挑选一个 未搜索 的节点，开始继续进行深度优先搜索
        for (auto& v : nodes[u]) {
            if (visited[v] == 0) {
                dfs(v);
            } else if (visited[v] == 1) {
                return;
            }
        }
        // visited[u] = 2;
    }
};


int main() {
    vector<vector<int>> nodes = {{1,2,3},{3},{3},{4},{}};

    // // 读入数据
    // for (int i = 0; i < nodes.size(); ++i) {
    //     for (int j = 0; j < ) }
    Solution2 solution;
    int res = solution.DagPathNum(nodes);
    cout << res << endl;
    // 遍历ndoes
    // for (int i = 0; i < nodes.size(); ++i) {
    //     for (auto& v : nodes[i]) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}

/*
TestCase1
1 2 3
3
3
4
0

3

*/

