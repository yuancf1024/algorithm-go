#include <bits/stdc++.h>

using namespace std;



/**
 * @brief 带重复节点的前序中序二叉树 30分
 * 已知一个二叉树的先序遍历序列和中序遍历序列，
 * 但其中一些节点的值可能相同。请你返回所有满足条件的二叉树。
 * 二叉树在数组中的顺序是任意的。
 * 
 * 注意：保证二叉树有效节点数不超过10个。
 * 
示例1：
[1,1,2],[1,2,1]

[{1,1,#,#,2},{1,#,1,2}]

 */

/*
直接提交只能通过3.33%
还需要处理相等的情况
*/


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param preOrder int整型vector 
     * @param inOrder int整型vector 
     * @return TreeNode类vector
     */
    vector<TreeNode*> getBinaryTrees(vector<int>& preOrder, vector<int>& inOrder) {
        // write code here
        // 思路：本质上还是由前序+中序还原二叉树
        // preOrder有相等的元素，体现在inOrder里面就是有不同的选择
        // 只是本题有重复元素，那么就需要分情况来回溯
        // if (inOrder.size() == 0 || preOrder.size() == 0) {
        //     return NULL;
        // }
        // 把可能的结果存进数组res

        // 核心点：怎么去分别回溯相同值的根节点
        // 就是前序1，1，2 中序1，2，1 我要分2次在中序遍历来分割

        vector<TreeNode*> res;
        // 统计preOrder相同元素的索引
        map<int, int> map;
        for (auto& x : preOrder) {
            map[x]++;
        }
        for (auto& a : map) {
            if (a.second >1) {
                int t = a.second;
                while (t > 0) {
                    TreeNode* temp = traversal(inOrder, 0, inOrder.size(), preOrder, 0, preOrder.size(),t);
                    res.push_back(temp);
                    t--;
                }
            }
        }
        
        return res;
    }

    // 辅函数 
    TreeNode* traversal(vector<int>& inOrder, int inBegin, int inEnd, 
    vector<int>& preOrder,int preBegin, int preEnd, int t) {
        if (preBegin == preEnd) {
            return nullptr;
        }

        int rootValue = preOrder[preBegin];
        TreeNode* root = new TreeNode(rootValue);

        if (preEnd - preBegin == 1) {
            return root;
        }
        int idx;
        for (idx = inBegin; idx < inEnd; ++idx) {
            if (inOrder[idx] == rootValue) {
                break;
            }
        }
        // 切割inOrder
        // 中序左区间
        int leftInBegin = inBegin;
        int leftInEnd = idx;
        // 中序右区间
        int rightInBegin = idx + 1;
        int rightInEnd = inEnd;

        // 切割PreOrder
        // 前序左区间
        int leftPreBegin = preBegin + 1;
        int leftPreEnd = preBegin + 1 + idx - inBegin; 
        // 前序右区间
        int rightPreBegin = preBegin + 1 + (idx - inBegin);
        int rightPreEnd = preEnd;

        root->left = traversal(inOrder,leftInBegin,leftInEnd,preOrder,leftPreBegin,leftPreEnd);
        root-> right = traversal(inOrder,rightInBegin,rightInEnd,preOrder,rightPreBegin,rightPreEnd);
        return root;
    }
};

int main() {
    // vector<int> preOrder = {1,2,3};
    // vector<int> inOrder = {2,1,3};
    vector<int> preOrder = {1,1,2};
    vector<int> inOrder = {1,2,1};
    Solution s;
    vector<TreeNode*> res = s.getBinaryTrees(preOrder, inOrder);
    for (auto& x : res) {
        cout << x << endl;
    }
    return 0;
}
