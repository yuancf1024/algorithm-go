/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 
 * 松鼠存坚果(回忆版)
 * 一只松鼠在一颗二叉树上存坚果，每个节点可储存5个坚果；
 * 输入数组和坚果数量，判断数组能否构成一颗完全二叉树，
 * 返回剩余坚果数量
 */

/*
2022-09-05复盘
字节第一题应该是AC了的

*/

#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isBinaryTree(vector<int>& nums) {
    bool flag = true;
    int n = nums.size();
    // 考虑仅有1个节点的情况
    if (n == 1) {
        return flag;
    }

    if (n == 2 && nums[0] != -1) {
        return flag;
    }

    for (int i = 0; i < n/2; ++i) {
        if (nums[i] == -1 && (nums[2*i+1] != -1 || nums[2*(i+1)] != -1)) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    vector<int> nums;
    int numNuts = 0;
    int res = 0;

    int temp;
    while (cin >> temp) {
        nums.push_back(temp);
        if (cin.get() == '\n') {
            break;
        }
    }

    cin >> numNuts;

    // 核心代码

    // 判断输入的二叉树是否合法

    if (isBinaryTree(nums) && (numNuts >= 1 && numNuts <= 100)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    // 返回剩余干果数量
    int numNode = 0;
    int sumNut = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != -1) {
            numNode++;
            sumNut += nums[i];
        }
    }
    res = numNuts - (numNode * 5 - sumNut);
    if (res < 0) {
        cout << 0 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}

/*
TestCase1:
1 3 2
5

true
0

TestCase2:
1 3 2
20

true
11

TestCas3:
1 -1 3 -1 -1 2 5
12

true
3

TestCas4:
1 3 2
-1

false
0

TestCas5:
1 -1 3 2 0
10

false
0
*/