/**
 * @file maz-bfs.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * 迷宫问题
 * 描述
定义一个二维数组 N*M ，如 5 × 5 数组下所示：

int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};


它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，
不能斜着走，要求编程序找出从左上角到右下角的路线。
入口点为[0,0],既第一格是可以走的路。

数据范围：2≤n,m≤10 ， 输入的内容只包含 0≤val≤1 

输入描述：
输入两个整数，分别表示二维数组的行数，列数。
再输入相应的数组，其中的1表示墙壁，0表示可以走的路。
数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

输出描述：
左上角到右下角的最短路径，格式如样例所示。

示例1
输入：
5 5
0 1 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

输出：
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)

示例2
输入：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 1
0 1 1 1 0
0 0 0 0 0

输出：
(0,0)
(1,0)
(2,0)
(3,0)
(4,0)
(4,1)
(4,2)
(4,3)
(4,4) 


说明：
注意：不能斜着走！！
 */

/*
思路：
利用层次遍历（bfs）寻找最短路径。
fa[ ][ ]表示当前坐标的父亲坐标。
将起点(0,0)加入队列，四个方向遍历相邻坐标，
如果相邻坐标未访问过并且可以走，则入队列，
并且将当前坐标指定父亲坐标。
以此类推，找到终点(n-1,m-1)。
再通过递归输出最短路径的线路。

时间复杂度：O(n*m), bfs每个坐标都访问一遍

空间复杂度：O(n*m),fa[][]存储当前坐标的父坐标，vis[][]标记已访问
*/

#include <bits/stdc++.h>

using namespace std;
int a[15][15], vis[15][15];
int b[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 上下左右四个方向
pair<int, int> fa[15][15]; // 记录当前下标的父亲节点

// dfs打印走过的路径
void dfs(int x, int y) {
    if (x == 0 && y == 0) { // 如果到达左上角，则退出
        return;
    }
    auto t = fa[x][y];
    dfs(t.first, t.second);
    printf("(%d,%d)\n", x, y);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j]; // 输入迷宫
            }
        }
        memset(vis, 0, sizeof(vis));
        memset(fa, 0, sizeof(fa));
        queue<pair<int, int>> q; // 队列
        q.push({0, 0}); // 左上角坐标入队列
        vis[0][0] = 1;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (u.first == n-1 && u.second == m-1) { // 到达终点
                break;
            }
            for (int i = 0; i < 4; ++i) {
                int nx = u.first + b[i][0], ny = u.second + b[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) { // 超出地图范围
                    continue;
                }
                // 如果当前坐标未访问过并且可以走，则入队列，并且将当前坐标指定父亲坐标
                if (vis[nx][ny] == 0 && a[nx][ny] == 0) {
                    fa[nx][ny] = {u.first, u.second};
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        printf("(%d,%d)\n", 0, 0);
        dfs(n - 1, m - 1);
    }
    return 0;
}