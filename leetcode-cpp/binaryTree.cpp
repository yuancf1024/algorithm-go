#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 根据数组构造二叉树
TreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<TreeNode*> vecTree(vec.size(), NULL);
    TreeNode* root = NULL;
    for (int i = 0; i < vec.size(); i++) {
        TreeNode* node = NULL;
        if (vec[i] != -1)
            node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if (i == 0)
            root = node;
    }

    for (int i = 0; i * 2 + 2 < vec.size(); i++) {
        if (vecTree[i] != NULL) {
            vecTree[i]->left = vecTree[i * 2 + 1];
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

// 层序打印二叉树
void print_binary_tree(TreeNode* root) { 
    queue<TreeNode*> que; 
    if (root != NULL)
        que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) { // 队列为空就退出循环
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node != NULL) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            } else { // 这里的处理逻辑是为了把null节点打印出来，用-1表示null
                vec.push_back(-1);
            }
        }
        result.push_back(vec);
    }
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // 注意本代码没有考虑输入异常数据的情况
    // 用 -1 来表示 NULL
    vector<int> vec = {4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8};
    TreeNode* root = construct_binary_tree(vec);
    print_binary_tree(root);
    return 0;
}