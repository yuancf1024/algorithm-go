/**
 * @file T3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * 小心地滑
 * 
识宝发现冰原上的一个位置有一个宝箱，她很想拿到这个宝箱，
当她在宝箱相邻格子停下时，他就可以拿到宝箱。

识宝在冰原上滑行时会选择一个坐标轴方向直线前进，
直到触碰到地图边界或障碍物时才会停下
(宝箱也属于障碍物，触碰到障碍物必须停下，无法穿过障碍物)。

现在，识宝在地图左上角，她想知道她至少需要滑行几次才可以拿到宝箱。

但是识宝觉得这题好难，所以她去问米小游，但米小游也解决不了这个问题，
所以来问你了。

输入描述：
第一行输出两个整数n,m(1<=n,m<=300)表示地图大小。

接下来n行，每行一个字符串表示地图，
其中：
'#' 表示障碍物，
'.' 表示冰面，
'@' 表示宝箱，数据保证地图上有且只有一个宝箱，
保证宝箱和其他障碍物不会在地图左上角。


输出描述：
一个整数表示识宝拿到宝箱的最少滑行次数，
若无法拿到宝箱，则输出-1.

示例1：
4 4
...#
.@..
....
#...

4

示例2：
4 4
....
.@..
....
...#

-1
 */

/*
这一题较难，考察图。

感觉可以用加限制的深度优先搜索来实现。

和华为机试——疫情期间员工落座非常相似
都是考察图类型的题目，图的学习，我现在还很薄弱，
后期复盘要重点加强这方面的练习。
华为机试必考

2022-09-05复盘
这一题实际上是leetcode上的迷宫系列，可以用dfs/bfs

*/

// 自己写的数据读入
// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<char>> map(n, vector<char>(m));
//     // char t;
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             cin >> map[i][j];
//         }
//     }

//     // 核心代码
//     int res = 0;


//     cout << res << endl;

//     return 0;
// }

// 参考牛客大佬@牛客用户xwybs
// bfs的时候上下左右找到底或者找到障碍物或者宝箱就行
// #include <bits/stdc++.h>

// using namespace std;

// // 检查是否碰到障碍物or宝箱、是否出界
// bool check(int x, int y, int n, int m, vector<vector<char>>& map) {
//     // 是否出界
//     if (x < 1 || x > n || y < 1 || y > m) {
//         return false;
//     }
//     // 是否遇到宝箱
//     if (map[x][y] == '@') {
//         return true;
//     }
//     // 遇到障碍物
//     return false;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<char>> map(n + 1, vector<char>(m + 1));
//     vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= m; ++j) {
//             cin >> map[i][j];
//         }
//     }

//     // 核心代码
//     queue<pair<int, int>> q;
//     q.push(make_pair(1, 1)); // 初始位置
//     visited[1][1] = true;
//     int res = 0;
//     bool getBox = false;

//     while (!q.empty()) {
//         int size = q.size();
//         for (int i = 0; i < size; ++i) {
//             auto now = q.front();
//             int now_x = now.first, now_y = now.second;
//             q.pop();
//             // check
//             if (check(now_x-1,now_y,n,m,map) 
//             || check(now_x+1,now_y,n,m,map)
//             || check(now_x,now_y-1,n,m,map)
//             || check(now_x,now_y+1,n,m,map)) {
//                 cout << res << endl;
//                 return 0;
//             }
//             // 四个方向
//             // 上
//             for (int x = now_x - 1; x > 0;--x) {
//                 // 向上的过程中遇到障碍物直接跳出循环
//                 if (map[x][now_y] == '#') {
//                     break;
//                 }
//                 // 到达上边界，将该点入队同时标记已访问
//                 if (x == 1 && !visited[x][now_y]) {
//                     q.push(make_pair(x, now_y));
//                     visited[x][now_y] = true;
//                 } else if (x > 1 && map[x-1][now_y] == '#' && !visited[x][now_y]) { // 上面一个点是障碍物，将该点入队同时标记已访问
//                     q.push(make_pair(x, now_y));
//                     visited[x][now_y] = true;
//                     break; // 跳出循环(换个方向遍历)
//                 } else if (x > 1 && map[x-1][now_y] == '@' && !visited[x][now_y]) { // 上面一个点是宝箱，直接+1输出结果，结束程序
//                     cout << res + 1 << endl;
//                     return 0;
//                 }
//             }

//             // 下
//             for (int x = now_x + 1; x <= n;++x) {
//                 // 向下的过程中遇到障碍物直接跳出循环
//                 if (map[x][now_y] == '#') {
//                     break;
//                 }
//                 // 到达下边界，将该点入队同时标记已访问
//                 if (x == n && !visited[x][now_y]) {
//                     q.push(make_pair(x, now_y));
//                     visited[x][now_y] = true;
//                 } else if (x < n && map[x+1][now_y] == '#' && !visited[x][now_y]) { // 下面一个点是障碍物，将该点入队同时标记已访问
//                     q.push(make_pair(x, now_y));
//                     visited[x][now_y] = true;
//                     break; // 跳出循环(换个方向遍历)
//                 } else if (x < n && map[x+1][now_y] == '@' && !visited[x][now_y]) { // 下面一个点是宝箱，直接+1输出结果，结束程序
//                     cout << res + 1 << endl;
//                     return 0;
//                 }
//             }
//             // 左
//             for (int y = now_y - 1; y > 0;--y) {
//                 // 向左的过程中遇到障碍物直接跳出循环
//                 if (map[now_x][y] == '#') {
//                     break;
//                 }
//                 // 到达左边界，将该点入队同时标记已访问
//                 if (y == 1 && !visited[now_x][y]) {
//                     q.push(make_pair(now_x, y));
//                     visited[now_x][y] = true;
//                 } else if (y > 1 && map[now_x][y-1] == '#' && !visited[now_x][y-1]) { // 左面一个点是障碍物，将该点入队同时标记已访问
//                     q.push(make_pair(now_x, y));
//                     visited[now_x][y] = true;
//                     break; // 跳出循环(换个方向遍历)
//                 } else if (y > 1 && map[now_x][y-1] == '@' && !visited[now_x][y-1]) { // 左面一个点是宝箱，直接+1输出结果，结束程序
//                     cout << res + 1 << endl;
//                     return 0;
//                 }
//             }
//             // 右
//             for (int y = now_y + 1; y <= m; ++y) {
//                 // 向右的过程中遇到障碍物直接跳出循环
//                 if (map[now_x][y] == '#') {
//                     break;
//                 }
//                 // 到达右边界，将该点入队同时标记已访问
//                 if (y == m && !visited[now_x][y]) {
//                     q.push(make_pair(now_x, y));
//                     visited[now_x][y] = true;
//                 } else if (y < m && map[now_x][y+1] == '#' && !visited[now_x][y+1]) { // 右面一个点是障碍物，将该点入队同时标记已访问
//                     q.push(make_pair(now_x, y));
//                     visited[now_x][y] = true;
//                     break; // 跳出循环(换个方向遍历)
//                 } else if (y < m && map[now_x][y+1] == '@' && !visited[now_x][y+1]) { // 右面一个点是宝箱，直接+1输出结果，结束程序
//                     cout << res + 1 << endl;
//                     return 0;
//                 }
//             }
//         }
//         res++;
//     }

//     cout << "-1" << endl;
//     return 0;
// }

// 参考牛客大佬@牛客775465491号
// DP
#include <bits/stdc++.h>

using namespace std;

