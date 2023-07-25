/**
 * @file T4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 小红的子树权值和 35分
 * 
 * 小红拿到了一棵有根树，根节点为1号节点。
 * 已知i节点的权值为ai。
 * 小红定义每个节点为根的子树权值
 * 为该子树所有节点权值乘积的因子数量。
 * 小红想知道，所有子树权值之和是多少？
 * 
 * 答案请对10^9+7取模
 * (请注意是权值取模，而不是乘积取模后求因子数量！)
 * 
输入描述：
第一行输入一个正整数n，代表节点的数量。
第二行输入n个正整数ai，代表每个节点的权值。
接下来的n-1行，每行输入两个正整数u和v，
代表点u和v有一条边相连
1<=n,ai<=10^5

输出描述：
所有子树的权值之和

TestCase1:

3
1 2 3
1 2
1 3

8

说明：
1为根的子树，所有节点乘积为6，因子数量是4.
2为根的子树，所有节点乘积为2，因子数量是2.
3为根的子树，所有节点乘积为3，因子数量是2.
 */

/*
因子数量没有太理解
为什么给的测试案例里面2、3为根的子树的因子数量都是2
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // 建图
    vector<int> graph(n-1);
    int t = n - 1;
    int x1, x2;
    while (t > 0) {
        cin >> x1 >> x2;
        graph[x1] = x2;
    }

    // 核心代码
    

    return 0;
}