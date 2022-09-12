/**
 * @file T2-200.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * 士兵和敌人
 * 
 * 在一个MxN的街区中,有一个士兵S和一个敌人E,标识X为无法通过的街区，
 * 标识B为可以通过的街区;士兵在一个单位时间内可以从一个街区移动
 * 到相邻的街区(士兵每次只能水平或者垂直方向移动一个街区);
 * 士兵每次改变方向时,需要额外花费—个单位的时间
 * (士兵第一次移动—个街区的时候,不用考虑其初始方向，
 * 即只需要—个单位时间即可到达相邻街区).
 * 计算士兵S最少需要多少时间才能到达E所在的街区。
解答要求
时间限制:C/C++1000ms，其他语言:2000ms
内存限制:CIC++ 256MB,其他语言:512MB

输入
第一行为两个数字，表示街区的大小,M行，N列;(1年M,N <=1000,M、N不同时为1)
接下来M行,每行N个字母,字母S表示士兵所在街区,
字母E表示敌人所在街区,字母X表示障碍,字母B表示可以经过的街区。
(只有1个S,一个E)

输出
最少需要的时间,当士兵S永远无法到达敌人E所在的街区时，输出-1

样例1

输入:
6 6
SBBBBB
BXXXXB
BBXBBB
XBBXXB
BXBBXB
BBXBEB

输出：
13
 */

/*
思路：参考大佬@战不退 AC76%

依然是非常标准的迷宫模板题，要求最短时间到达敌人所在位置
采用变种广度优先搜索+vis记忆化。

1. 构造节点Node记录地图每个位置的坐标，耗时，方向；
2. 定义数组dx,dy方便广度搜索，使用vis记录位置到达该点的最短时间
3. 使用<运算符重载，配合大顶堆，使耗时最少的Node堆化到top位置
4. 读取矩阵地图，记录士兵出发起点
5. 由于更换方向需要耗时1，最开始出发选定方向，需要额外单独考虑
    向4个方向搜索，满足可达条件即加入大顶堆，然后标记已访问
6. BFS广度优先遍历
    - 弹出堆顶，
    - 如果遇到终点，记录耗时，break跳出循环
    - (上下左右搜索)，然后进行判断
    - 如果超出地图或遇到障碍，结束本轮循环
    - 使用f记录方向是否改变，tmp记录耗时
    - 如果点(tx,ty)未访问or新搜索位置的耗时比原来少，更新vis，将新搜索点入堆
*/

// 参考大佬@战不退 AC76%
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y, t, d; // t时间 d方向
    Node() {}
    Node(int a, int b, int c, int e) : x(a), y(b), t(c), d(e) {}
    bool operator<(const Node& a) const { // 使用<运算符重载，配合大顶堆，使耗时最少的Node堆化到top位置
        return t > a.t;
    }
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char g[1005][1005];
int vis[1005][1005]; // 到达该点的最短时间
int n, m, ans = -1, sx, sy;
priority_queue<Node> q; // 配合运算符重载构建

int main() { 
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'S') {
                vis[i][j] = 1;
                sx = i, sy = j;
            }
        }
    }
    // 起点加入队列
    for (int i = 0; i < 4; ++i) {
        int tx = sx + dx[i];
        int ty = sy + dy[i];
        // 超出地图或遇到障碍，结束本轮循环
        if (tx < 0 || ty < 0 || tx >= n || ty >= m || g[tx][ty] == 'X') {
            continue;
        }
        q.push(Node(tx, ty, 1, i));
        vis[tx][ty] = 1;
    }

    while (!q.empty()) {
        Node cur = q.top();
        q.pop();
        // 找到目标，结束遍历
        if (g[cur.x][cur.y] == 'E') {
            ans = cur.t;
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int tx = cur.x + dx[i];
            int ty = cur.y + dy[i];
            if (tx < 0 || ty < 0 || tx >= n || ty >= m || g[tx][ty] == 'X') {
                continue;
            }
            int f = (cur.d != i); // 改变方向，时间+1
            int tmp = cur.t + 1 + f;
            if (vis[tx][ty] == 0 || tmp < vis[tx][ty]) {
                vis[tx][ty] = tmp;
                q.push(Node(tx, ty, tmp, i));
            }
        }
    }
    cout << ans << endl;
    return 0;
}