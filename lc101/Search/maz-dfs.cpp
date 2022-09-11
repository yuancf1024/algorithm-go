/**
 * @file maz-dfs.cpp
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
主题：
深搜迷宫问题 求最短路径的详细走法

思路：
深搜 将路径存储在数组book中 
求得最短路径长度时 现在的这个数组存储的路径就是最短路径的走法 
将现在的最优可行解保存在ans数组中（这个过程好像有一个很高级的名字
叫做保存现场） 最后等深搜函数结束运行之后 ans数组中存储的就是最短路径 
只需要再次使用简单的深搜将ans数组中的路径走一遍并且打印出每个点的位置即可
*/

// dfs解法 参考大佬@我是一颗大白菜~~
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> maze;

// 当从(0,0)到(n-1,m-1)有多条通路时，best_path记录最小的temp_path
// 本题只有一条通路，所以到达(n-1,m-1)时，让best_path=temp_path即可
vector<vector<int>> best_path;
vector<vector<int>> temp_path;

void dfs(int i, int j) {
    // 边界条件：(1)数组越界,(2)遇到墙壁或已走过
    if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == 1) {
        return;
    }
    maze[i][j] = 1; // 将走过的位置标记为1，以后就不能走了
    temp_path.push_back({i, j}); // 将搜索的到位置(i,j)加入路径
    if (i == n-1 && j == m-1) { // 判断是否走到终点
        // 多条路径时best_path记录最小的
        // if (temp_path.size() < best_path.size() || best_path.empty()) {
        //     best_path = temp_path;
        // }
        // 本题只有一条通路，到达终点(n-1,m-1)时，让best_path = temp_path即可
        best_path = temp_path;
    }
    dfs(i - 1, j); // 上
    dfs(i + 1, j); // 下
    dfs(i, j - 1); // 左
    dfs(i, j + 1); // 右
    maze[i][j] = 0; // 该节点走不通时，恢复原场面
    temp_path.pop_back(); // 从路径中删除节点
}

int main() { 
    while (cin >> n >> m) {
        maze = vector<vector<int>>(n, vector<int>(m, 0)); // 设置地图的大小并初始化
        best_path.clear();
        temp_path.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> maze[i][j];
            }
        }

        dfs(0, 0);
        for (auto it = best_path.begin(); it != best_path.end(); it++) {
            cout << '(' << (*it)[0] << ',' << (*it)[1] << ')' << endl;
        }
    }
    return 0; 
}