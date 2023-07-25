/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-03
 * 
 * @copyright Copyright (c) 2022
 * 字母树
时间限制： 3000MS
内存限制： 589824KB
题目描述：
给定一棵有n个节点的树，节点用1,2, …, n编号。

1号节点为树的根节点，每个节点上有一个
用大写字母表示的标记。
求每个节点的子树中出现的字母标记种类数。

注：子树的定义：设T是有根树，a是T中的一个顶点，
由a以及a的所有后裔（后代）导出的子图
称为有根树T的子树。

输入描述
第一行输入一个正整数n, 表示树的节点数量。

第二行输入n-1个正整数，
第i个整数表示第i+1号节点的父亲节点。

第三行输入长度为n的由大写字母组成的字符串s1s2…sn，
第i个字符si表示第i号节点的标记。

3 ≤ n ≤ 50000。

数据保证形成一棵合法的树，字符串由大写字母组成。

输出描述

输出n个整数，相邻两个数之间用空格隔开，
第i个整数表示第i号节点的子树中出现不同的字母种类数。


样例输入
6
1 2 2 1 4
ABCCAD

样例输出
4 3 1 2 1 1

提示


1号节点的子树有节点{1,2,3,4,5,6}，
出现了A, B, C, D四种字母。

2号节点的子树有节点{2,3,4,6}，
出现了B, C, D三种字母。

3号节点的子树有节点{3}，出现了C一种字母。

4号节点的子树有节点{4, 6}， 出现了C，D两种字母。

5号节点的子树有节点{5}，出现了A一种字母。

6号节点的子树有节点{6}，出现了D一种字母。

 */

/*
TestCase:
6
1 2 2 1 4
ABCCAD

4 3 1 2 1 1
*/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *next;
    TreeNode(int x) : val(x),next(nullptr) {}
    TreeNode() : val(0), next(nullptr) {}
    TreeNode(int x, TreeNode* next) : val(x), next(next) {}
};

int findNumOfStr(TreeNode* cur, unordered_set<int>& set, string str) { 
    int ans;
    // 广度遍历子树cur，统计对应字母种类数目

    queue<TreeNode*> q;
    q.push(cur);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* node = q.front();
            q.pop();
            int a = node->val - 1;
            set.insert(str[a]);
            if (node->next) {
                q.push(node->next);
            }
        }
    }
    ans = set.size();
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n-1);
    int t;
    for (int i = 0; i < n - 1; ++i) {
        cin >> t;
        nums[i] = t;
    }
    string str;
    cin >> str;

    // 核心代码
    vector<int> res(n);
    /*
    思路：求每个节点的子树中出现的字母标记种类数。
    为了避免重复遍历计算，最好使用前缀树。
    这里时间和内存给的多，就先尝试暴力求解。
    这里说是树，其实更大的可能是图。😂
    一个节点可能是多个子节点的父节点。

    1. 建树，但是如何建立N叉树?
    2. 使用广度优先搜索，维护一个set集合
    */

    // 建树
    TreeNode* root = new TreeNode(1);
    for (int i = 0; i < n - 1; ++i) {
        // nums[i] 是节点i+2的父节点
        TreeNode* node2 = new TreeNode(i+2);
        if (nums[i] == 1) {
            root->next = node2;
        } else {
            TreeNode* node1 = new TreeNode(nums[i]);
            node1->next = node2;
        }
    }

    

    // 遍历统计
    unordered_set<int> set;
    // TreeNode* cur = root;
    queue<TreeNode*> que;
    que.push(root);
    // 这里也要层序遍历
    while (!que.empty()) {
        int size = que.size();
        TreeNode* node = que.front();
        que.pop();
        for (int i = 0; i < size; ++i) {
            int num = findNumOfStr(node, set, str);
            res[node->val] = num;
            if (node->next) {
                que.push(node->next);
            }
        } 
    }

    for (auto& x : res) {
        cout << x << " ";
    }

    // 测输入是否正确
    // cout << n << endl;
    // for (auto& i : nums) {
    //     cout << i << " ";
    // }
    // cout << str << endl;
    return 0;
}