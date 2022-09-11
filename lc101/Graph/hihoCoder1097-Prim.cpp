/**
 * @file hihoCoder1097.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 
 * 1097 : 最小生成树一·Prim算法 描述
最近，小Hi很喜欢玩的一款游戏模拟城市开放出了新Mod，
在这个Mod中，玩家可以拥有不止一个城市了！
但是，问题也接踵而来——小Hi现在手上拥有N座城市，
且已知这N座城市中任意两座城市之间建造道路所需要的费用，
小Hi希望知道，最少花费多少就可以使得任意两座城市都可以
通过所建造的道路互相到达（假设有A、B、C三座城市，
只需要在AB之间和BC之间建造道路，那么AC之间也是可以通过这两条道路连通的）。

提示：不知道为什么Prim算法和Dijstra算法很像呢Σ(っ °Д °;)っ 。

输入
每个测试点（输入文件）有且仅有一组测试数据。
在一组测试数据中：
第1行为1个整数N，表示小Hi拥有的城市数量。
接下来的N行，为一个N*N的矩阵A，描述任意两座城市之间建造道路所需要的费用，
其中第i行第j个数为Aij，表示第i座城市和第j座城市之间建造道路所需要的费用。

对于100%的数据，满足N<=10^3，对于任意i，满足Aii=0，
对于任意i, j满足Aij=Aji, 0<Aij<10^4.
输出
对于每组测试数据，输出1个整数Ans，
表示为了使任意两座城市都可以通过所建造的道路互相到达至少需要的建造费用。


Sample Input

5
0 1005 6963 392 1182 
1005 0 1599 4213 1451 
6963 1599 0 9780 2789 
392 4213 9780 0 5236 
1182 1451 2789 5236 0 
Sample Output
4178

 */


/*
Prim算法思路：
1）以某一个点开始，寻找当前该点可以访问的所有的边；
2）在已经寻找的边中发现最小边，这个边必须有一个点还没有访问过，将还没有访问的点加入我们的集合，记录添加的边；
3）寻找当前集合可以访问的所有边，重复2的过程，直到没有新的点可以加入；
4）此时由所有边构成的树即为最小生成树。
*/

#include <bits/stdc++.h>

using namespace std;

int main() { 
    // 读取数据
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    vector<int> lowest(n), vertex(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m[i][j];
            if (!i) {
                lowest[j] = m[i][j]; // 将0号节点插入最小构造树中
            }
        }
    }

    // 核心代码
    vertex[0] = 1; // 标记0号节点
    int totalCost = 0;
    for (int i = 0; i < n; ++i) {
        int minCost = INT_MAX, index = 0;
        for (int j = 0; j < n; ++j) { // 寻找与树中已有节点相连的最短边
            if (!vertex[j] && lowest[j] && lowest[j] < minCost) { // 节点j未访问 && lowest[j]不为0
                minCost = lowest[j];
                index = j;
            }
        }
        vertex[index] = 1; // 标记新加入树的点
        totalCost += lowest[index];
        for (int j = 0; j < n; ++j) {
            if (m[index][j] && !vertex[j] && (m[index][j] < lowest[j] || !lowest[j])) { //利用新加入树的点刷新最短边
                lowest[j] = m[index][j];
            }
        } 
    }

    cout << totalCost << endl;

    return 0;
}