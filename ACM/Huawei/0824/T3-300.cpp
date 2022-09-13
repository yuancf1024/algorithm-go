/**
 * @file T3-300.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * 3、最大面积黑像素
某产品使用黑白摄像头采集图像摄像头采集完每帧图像后都会输出个
m*n的二维数组二维数组中的每个元素表示一个像素。
元表值1则表示黑色，0则表示白色。
要求最多只能改动2个白色像素使整个图像中互相连通的黑色像素区域面积最大。
其中"黑色像表区域面积"是指黑色像素互相连通的个数，
“连通"是指任意两个黑色像表水平相邻或垂直相邻。

解答要求:
时间限制C/C++ 1000ms,其他语言:2000ms
内存限制C/C++ 256MB,其他语言:512MB
输入:
(1输入第一行固定为两个数字表示维数组的m行和n列。
(2接着输入为个m*n的二维数组数组中的每个元素值为1或0。
(3输入二维数组的行m和列n取值范围1<=m<=100,1<=n<=100。
(4)输入的每行的数字之间有空格间隔。

输出:
输出在最多改动2个白色像素限制下，最大的互相连通黑色区域面积。

参考leetcode827题

样例1:
输入:
4 4
1 1 0 1
1 1 0 1
0 0 0 0
1 1 1 1

输出:
12

解释:修改两个白色像素后可能是下面这种状态
1 1 1 1
1 1 0 1
1 0 0 0
1 1 1 1

黑色区域面积12

样例2:
输入:
6 4
1 1 0 1
0 0 0 0
0 0 0 0
0 0 0 0
1 1 1 1
1 1 1 1

输出:
10

解释:修改两个白色像素后可能是下面这种状态，
1 1 0 1
0 0 0 0
0 0 0 0
1 1 0 0
1 1 1 1
1 1 1 1

最大黑色像素面积为10

 */

/*
思路：参考leetcode827题

leetcode827题要求修改一个点，而本题要求修改2个点；
根据其遍历的思路，先任选一个白点遍历，然后再任选一个白点遍历
可能会有超时的风险！！！

本题怎么实现把两个0变成1，有leetcode同学建议：把0变成1的逻辑再进行1次


*/

#include <bits/stdc++.h>

using namespace std;

// 2022-09-12复写
class Solution {
    int count;
    vector<int> dir = {-1, 0, 1, 0, -1}; // 搜索的四个方向
    // 辅函数dfs
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int x, int y, int mark) {
        if (vis[x][y] || grid[x][y] == 0) { // 终止条件：访问过的节点或遇到海水
            return;
        }
        vis[x][y] = true; // 标记已访问
        grid[x][y] = mark; // 给陆地标记新标签 ！！！这里非常重要 为后面作铺垫
        count++;
        for (int i = 0; i < 4; ++i) {
            int dx = x + dir[i];
            int dy = y + dir[i + 1];
            if (dx < 0 || dx >= grid.size() || dy < 0 || dy >= grid[0].size()) {
                // 超出地图 跳过
                continue;
            }
            dfs(grid, vis, dx, dy, mark);
        }
    }

public:
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        unordered_map<int, int> gridNum;
        int mark = 2; // 记录每个岛屿的编号
        bool isAllGrid = true; // 标记是否整个地图都是陆地
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0) {
                    isAllGrid = false;
                }
                if (!vis[i][j] && grid[i][j] == 1) { // (i,j)未访问过并且是陆地
                    count = 0; // 初始化为0
                    dfs(grid, vis, i, j, mark); // 将与其连接的陆地都标记上true
                    gridNum[mark] = count; // 记录每一个岛屿的面积(根据mark映射)
                    mark++; // 记录下一个岛屿编号
                }
            } 
        }

        // 如果都是陆地，返回全面积
        if (isAllGrid) {
            return n * m;
        }
        
        // 以下逻辑是根据添加陆地的位置，计算周边岛屿面积之和
        int res = 0;
        unordered_set<int> visGrid; // 标记已访问过的岛屿
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int count = 1; // 记录连接之后的岛屿数量
                visGrid.clear(); // 每次使用时，清空
                if (grid[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int neari = i + dir[k]; // 计算相邻坐标
                        int nearj = j + dir[k + 1];
                        // 越界就跳过
                        if (neari < 0 || neari >= grid.size() || nearj < 0 || nearj >= grid[0].size()) {
                            continue;
                        }
                        // 添加过的岛屿不要重复添加
                        if (visGrid.count(grid[neari][nearj])) {
                            continue;
                        }
                        // 把相邻四面的岛屿数量加起来
                        count += gridNum[grid[neari][nearj]];
                        visGrid.insert(grid[neari][nearj]); // 标记该岛屿已经添加过
                    }
                }
                res = max(res, count);
            }
        }
        return res;
    }
};

int main() { 
    int n, m;

    // 读取数据
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    // 核心代码
    Solution s;
    int ans = s.largestIsland(grid);
    cout << ans << endl;
    return 0;
}