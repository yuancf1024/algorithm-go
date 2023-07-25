/**
 * @file T3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 一对一
时间限制： 3000MS
内存限制： 589824KB
题目描述：
某公司正在组织新员工团建，
其中一项活动是两两配对进行石头剪刀布。

因为新员工来自不同的学校和专业，
他们许多人之间并不熟悉，
但他们之间的朋友关系形成了一棵树。

即若将朋友关系描述为一张无向图，
则这张无向图中任意两点之间有且仅有一条路径。
为了避免尴尬，组织者希望互为朋友的配对数量尽可能多。

现在他希望你求出互为朋友的配对数量最多能有多少。

输入描述
第一行有一个偶数n(2<=n<=1000)，
代表有n个新员工。

第二行有n-1个空格隔开的数，
第i个数ai代表编号为i+1的新员工
与编号为ai的员工互为朋友。

输入保证新员工之间的朋友关系形成了一棵树

输出描述
输出在所有可能的配对方案中，
互为朋友的配对数量最多是多少。


样例输入
6
1 2 2 3 3
样例输出
2

提示
如样例中，一共有6个新员工，
朋友关系有以下五个(1,2),(2,3),(2,4),(3,5),(3,6)。

可以证明无论如何匹配这6个人， 
最多只能有两对是互为朋友的，因此输出2。
 */

/*
没有想到考图算法😂
直戳盲区

*/

#include <bits/stdc++.h>

using namespace std;

void removeGraph(vector<int>& graph, int n) {
    for (int i = 2; i < graph.size(); ++i) {
        if (graph[i] == n) {
            graph[i] = 0;
        }
    } 
}

int main() {
    int n;
    vector<int> nums;

    cin >> n;
    int t;
    while(cin >> t) {
        // cin >> t;
        nums.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }

    // 核心代码
    // 建图
    vector<int> graph(2);
    for (int i = 0; i < nums.size(); ++i) {
        graph.push_back(nums[i]);
    }

    /*
    不成熟的思路：
    1 找到该图中路径最长的一条路径，路径长度/2即为最多能配对的数量
        这样不对，可能有的配对在边缘
    2 不断在图中拆除相邻的两个节点，同时计数，最大可拆除次数
    即为最大配对数

    遍历graph的方式只能是一种固定方式，可能会稍有偏颇
    多次遍历，取能拆除的最大值

    增加了倒序的遍历方式也不起作用
    pass27%
    说明不仅仅是没有考虑到边界特殊情况，还有其他的常见情况也没有考虑到
    
    */
    int res = 0;
    vector<int> ans;
    // graph
    // 正序
    for (int i = 2; i < graph.size(); ++i) {
        if (graph[i] != 0) {
            // 擦除graph中值为i的节点
            removeGraph(graph, i);
            removeGraph(graph, graph[i]);
            res++;
        }
    }
    ans.push_back(res);

    // // 倒序
    // int res1 = 0;
    // for (int i = graph.size()-1; i > 2; i--) {
    //     if (graph[i] != 0) {
    //         // 擦除graph中值为i的节点
    //         removeGraph(graph, i);
    //         removeGraph(graph, graph[i]);
    //         res1++;
    //     }
    // }
    // ans.push_back(res1);

    cout << *max_element(ans.begin(), ans.end()) << endl;

    // for (int i = 0; i < graph.size(); ++i) {
    //     cout << i << " " << graph[i] << endl;
    // }

    // 朋友配对数量最多

    // // 测试读入数据
    // cout << n << endl;

    // for (int i = 0; i < nums.size(); ++i) {
    //     // cin >> t;
    //     cout << nums[i] << " ";
    // }
    return 0;
}

/*
6
1 2 2 3 3
0 0
1 0
2 1  下标和值对应着的朋友关系 从2开始遍历
3 2
4 2
5 3  
6 3
*/

/*
第一次提交
说明：
所有测试数据正确率为 27%！
可以尝试再次完善代码，并调试，争取全部AC通过

第二次提交


*/