/**
 * @file T3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-27
 * 
 * @copyright Copyright (c) 2022
 * 
 * 有一个n*m的草坪，地图可近似n*m的小方格组成，
 * 每个方格有ai,j高度的草。
 * 
 * 小红有一个十字架除草机，每次可选择一个点(xi,yi)
 * 为中心，除掉该点以及上、下、左、右方向各两个单位，
 * 共9个单位格子的点的草，每个格子内的草除掉hi高度
 * (不够hi的全部除掉)。
 * 
 * 地图上的草会随着时间生长，每一秒草会生长1个单位高度。
 * 
 * 现在给定小红每次除草操作的时间ti,位置(xi,yi)
 * 以及除草高度hi,请你计算小红最终除了多少草。
 * 
输入描述：
第一行输入一个正整数n,m,代表地图的行数和列数。
接下来的n行，每行输入m个正整数ai,j，
代表草的初始高度(时刻1时的高度)

接下来的一行输入一个正整数q，代表小红的除草操作次数。

接下来q行，每行输入四个正整数ti,xi,yi,hi
代表小红在ti时刻，选择以第xi行、第yi为中心放置十字架
除草机，除掉hi的草。
1<=n,m<=500
1<=q<=10^5
0<=ai,j<=10^9
1<=ti,hi<=10^9
1<=xi<=n
1<=yi<=m

输出描述：

示例1：
3 3
1 2 1
0 2 0
1 2 1
2
1 2 2 2
3 2 3 1

11

说明：
第一次除草共可以除6单位。
第二次除草共可以除5单位。
共除草11单位。
 */

#include <bits/stdc++.h>

using namespace std;

int main() { 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int q;
    cin >> q;
    vector<vector<int>> th(q, vector<int>(4));

    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> th[i][j];
        }
    }

    // 核心代码
    

    // 打印输出
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < q; ++i) {
    //     for (int j = 0; j < 4; ++j) {
    //         cout << th[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
