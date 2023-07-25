/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 * 黄金国的历险 15分
 * 
城市A到达城市C，必须先经过相连的城市B，
再从城市B到达相连的城市C，每两个相连的城市之间花费
能量为wuv,A到C的花费被定义为(wab+wbc)^2
求起点到所有其他点的最小花费
如果不存在道路，那么认为就是"no"
 * 
 * 
输入描述：
第一行数字n(1 <= n <= 10^5)和数字m(1 <= m <= 2*10^5)
表示共n个城市和m条道路。
接下来m行每行有3个数字vi,ui,wi
(1<=vi,ui<=n, 1<=wi<=50, ui = vi)
代表从城市v出发到达城市u之间的传送带花费wi

输出描述：
一行包含n个整数，代表从起点1到达其他所有点所花费的最少能量

示例1：
输入：
5 6
1 2 3
2 3 4
3 4 5
4 5 6
1 5 1
2 4 2

0 98 49 25 114

示例2：
3 2
1 2 1
2 3 2

0 no 9
 */

#include <bits/stdc++.h>

using namespace std;

int main() { 
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> g;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(b);
        g[a].push_back(c);
    }

    // TODO
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            res[0] = 0;
        }
        
    }
    return 0;
}