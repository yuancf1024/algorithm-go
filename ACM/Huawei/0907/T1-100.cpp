/**
 * @file T1-100.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-11
 * 
 * @copyright Copyright (c) 2022
 * 
 * 猪的亲戚关系
 * 
农场里有n条猪，编号为0..n-1

给定m个列表，首元素是其余所有元素的母亲,每个元素只有一个母亲

给定两个编号x，y，求x，y的距离（如不联通输出-1，相同为0）

数据范围：

0<n<1e9
0<m<1e4

样例：
n = 10
a[0] = 0,1,2
表示0是1，2的母亲
a[1] = 1,3,4
表示1是3，4的母亲

求2，4的距离

存在路径2-0-1-4 
答案为3

样例1：
输入：
10 3
0 1 2
1 3 4
8 5 6 7
2 4

输出：
3

 */

/*
思路：参考大佬@愤怒的野猪 实现两个节点分到最近公共祖先的距离(求最近公共祖先)
事实上就是找一条x到y的路径，一个简单的dfs就可以了

需要注意，因为n的范围很大，需要用哈希表存储边

但是我只过了90%，也不知道是为什么

复盘：
1. 本题考察了哈希表建图的方法 unordered_map<int, vector<int>> g
2. dfs的思路：其实很简单
    - 从点x一直深度遍历到y然后返回路径长度即可
3. 要十分的注意边界条件

*/

// #include <bits/stdc++.h>

// using namespace std;

// // 图的范围很大，因此使用哈希表存储边
// unordered_map<int, vector<int>> g;


// // 深度优先搜索
// int dfs(int x, int fa, int res, int m2) { // 起始点x
//     for (auto& y : g[x]) { // fa是x的父节点，遍历与x相连的边
//         if (y != fa) { // 避免遍历到父节点，防止转圈
//             if (y == m2) { // 遍历到终点 直接返回路径长度
//                 return res + 1;
//             }
//             int tmp = dfs(y, x, res + 1, m2); // x是y的父节点，深度遍历与y相连的边
//             if (tmp != -1) { // tmp不是x的父节点，可以直接返回
//                 return tmp;
//             }
//         }
//     }
//     return -1;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> nums(m);

//     // 读取数据
//     for (int i = 0; i < m; ++i) {
//         int t;
//         while (cin >> t) {
//             nums[i].push_back(t);
//             if (cin.get() == '\n') {
//                 break;
//             }
//         }
//     }
//     int m1, m2;
//     cin >> m1 >> m2;

//     // 核心代码
//     // 建图 - 无向图
//     for (int i = 0; i < m; ++i) {
//         int fa = nums[i][0];
//         for (int j = 1; j < nums[i].size(); ++j) {
//             g[fa].push_back(nums[i][j]);
//             g[nums[i][j]].push_back(fa); 
//         }
//     }

//     int ans = dfs(m1, -1, 0, m2); // fa用于记录上一个值防止两个数相互找，即如果从1找到母亲2，从母亲2又找回1
//     cout << ans << endl;

//     // 测试输出
//     // for (int i = 0; i < m; ++i) {
//     //     for (auto& x : nums[i]) {
//     //         cout << x << " ";
//     //     }
//     // } 
//     return 0;
// }


/*
思路：参考大佬@战不退
大佬的实现思路其实就是最简单的那种，
两个节点分别往上走，记录路径，走到公共祖先节点，
即为最近公共祖先节点

大佬的实现还存在不足，就是本题的节点数量0<n<1e9
如果单纯使用vector会爆栈内存，
因此最好使用哈希表建图的方式
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, par, chi;

int main() { 
    // 读取数据
    cin >> n;
    vector<int> pre(n, -1);
    vector<int> dep(n, 0);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &par); // 每一行的第一个元素即为父亲节点
        if (pre[par] == -1) {
            pre[par] = par;
            dep[par] = 0;
        }
        while (1) {
            scanf("%d", &chi); // 每一行第一个元素后的全为子节点
            pre[chi] = par;
            dep[chi] = dep[par] + 1;
            if (getchar() == '\n') {
                break;
            }
        }
    }

    // 核心代码
    int x, y, dx, dy, ans = 0;
    cin >> x >> y;
    dx = dep[x], dy = dep[y];
    while (dx > dy) { // 将x、y移动到相同层深度
        x = pre[x];
        dx--;
        ans++;
    }
    while (dx < dy) { // 将x、y移动到相同层深度
        y = pre[y];
        dy--;
        ans++;
    }
    while (x != y && dx != 0) { // x，y同时往上遍历，如果x==y即找到最近公共祖先
        x = pre[x];
        y = pre[y];
        ans += 2;
        dx--;
    }
    if (x == y) { // 如果x==y即找到最近公共祖先
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}