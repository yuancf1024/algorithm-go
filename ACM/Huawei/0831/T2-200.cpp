/**
 * @file T2-200.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * 第二题：士兵的任务2
题目描述
士兵在迷宫中执行任务，迷宫中危机重重，
他需要在在最短的时间内到达指定的位害。
你可以告诉上兵他最少需要多长时间吗?

输入一个n*m的迷宫中，迷宫中0为路，1为墙，2为起点，3为终点，4为陷阱，6为炸弹。
士兵只能向上下左右四个方向移动，如果路径上为墙，不能移动。
已知每走一步需要花费1个单位的时间，走到陷阱上需要花费3个单位的时间，
走到炸弹上将会激活炸弹将炸弹上下左右的墙炸为路。(wc😂还能这样出题)

注意点:

炸弹只能炸聚地，不会炸掉陷阱
炸弹、陷阱只能发挥一次作用
迷宫最大为25*25
用例保证士兵一定有方法能到达终点

输入描述

第一行:n和m 
第二行开始:n*m的矩阵
4 4
1 1 1 1
1 6 2 1
1 1 0 1
1 3 1 1

输出描述

最少需要的单位时间

3

解释：

士兵在位置2，向左移动到炸弹上，会将炸弹周围的墙炸掉，向下走两步 即可到达终点

样例2：
8 4
1 6 2 1
1 1 0 1
1 1 0 1
1 1 0 1
1 1 0 1
1 1 0 1
1 1 0 1
1 1 3 1

7

 */

/*
思路：参考大佬TechGuide

非常标准的迷宫模板题，如果要找最短路径，最短时间或者最短消耗，
均可采用BFS。

1. 构造节点Node记录地图每个位置的坐标和耗时；
2. 定义数组dx,dy方便广度搜索，使用vis记录位置是否以访问
3. 使用<运算符重载，配合大顶堆，使耗时最少的Node堆化到top位置
4. 读取矩阵地图，记录起点
5. BFS广度优先遍历(上下左右搜索)，然后进行判断
    - 如果超出地图，访问过，遇到墙，那么continue结束该次搜索
    - 如果遇到终点，break跳出循环
    - 标记搜索位置已访问
    - 如果遇到陷阱，那么将该节点入堆，该节点耗时为3
    - 如果遇到炸弹，那么将炸弹周围的墙炸掉
    - 剩下的只剩下路和起点(由于有vis标记是否访问，只需考虑路即可)，将该节点(路)入堆
> ans不为0，break出循环

迷宫路径，最少时间，建议BFS
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, t;
    Node() {}
    Node(int a, int b, int c) : x(a), y(b), t(c) {}
    bool operator<(const Node& a) const { 
        return t > a.t; // 使用<运算符重载，配合大顶堆，使耗时最少的Node堆化到top位置
    }
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int g[30][30], vis[30][30];
int n, m, ans = 0;
priority_queue<Node> q; // C++优先队列默认是大顶堆

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 2) {
                vis[i][j] = 1; // 记录起点
                q.push(Node(i, j, 0));
            }
        }
    }
    while (!q.empty()) {
        Node cur = q.top();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = cur.x + dx[i];
            int ty = cur.y + dy[i];
            // 如果广度遍历时超出地图or访问地点以访问过or遇到墙，结束本次循环，开始下一轮循环
            if (tx < 0 || ty < 0 || tx >= n || ty >= m || vis[tx][ty] || g[tx][ty] == 1) {
                continue;
            }
            // 遇到终点3，ans+1跳出循环
            if (g[tx][ty] == 3) {
                ans = cur.t + 1;
                break;
            }
            vis[tx][ty] = 1; // 将(tx,ty)标记已访问
            // 遇到陷阱4
            if (g[tx][ty] == 4) {
                q.push(Node(tx, ty, cur.t + 3));
            }
            else if (g[tx][ty] == 6) { // 遇到炸弹6
                q.push(Node(tx,ty,cur.t+1));
                for (int j = 0; j < 4; ++j) {
                    int xx = tx + dx[j];
                    int yy = ty + dy[j];
                    if (g[xx][yy] == 1) { // 周围遇到墙1
                        g[xx][yy] = 0; // 将炸弹周围的墙炸掉
                    }
                }
            }
            else { // 剩下的只剩下路和起点(由于有vis标记是否访问，只需考虑路即可)
                q.push(Node(tx, ty, cur.t + 1));
            }
        }
        if (ans) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}