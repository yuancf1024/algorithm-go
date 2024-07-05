/**
 * @file 3033.Modify-the-Matrix.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-3033.Modify-the-Matrix 模拟
 * @version 0.1
 * @date 2024-07-06
 * 
 * @copyright Copyright (c) 2024
 * 给你一个下标从 0 开始、大小为 m x n 的整数矩阵 matrix ，
 * 新建一个下标从 0 开始、名为 answer 的矩阵。使 answer 与 matrix 相等，
 * 接着将其中每个值为 -1 的元素替换为所在列的 最大 元素。

返回矩阵 answer 。

示例 1：
输入：matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
输出：[[1,2,9],[4,8,6],[7,8,9]]
解释：上图显示了发生替换的元素（蓝色区域）。
- 将单元格 [1][1] 中的值替换为列 1 中的最大值 8 。
- 将单元格 [0][2] 中的值替换为列 2 中的最大值 9 。

示例 2：
输入：matrix = [[3,-1],[5,2]]
输出：[[3,2],[5,2]]
解释：上图显示了发生替换的元素（蓝色区域）。

提示：

m == matrix.length
n == matrix[i].length
2 <= m, n <= 50
-1 <= matrix[i][j] <= 100
测试用例中生成的输入满足每列至少包含一个非负整数。
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> answer = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> max; // 如果初始化含有参数，则默认为0
        // 求出每列最大值
        for (int i = 0; i < n; i++) {
            int t = matrix[0][i];
            for (int j = 1; j < m; j++) {
                /*
                if (matrix[j][i] > t) {
                    t = matrix[j][i];
                }
                */
               t = matrix[j][i] > t ? matrix[j][i] : t;
            }
            max.push_back(t);
        }
        // 逐列判断是否为-1，如果是，则改为列最大值
        for (int i = 0; i < n; i++) {
            for (int j =0; j < m; j++) {
                /*if (matrix[j][i] == -1) {
                    answer[j][i] = max[i];
                }*/
                answer[j][i] = matrix[j][i] == -1 ? max[i]: answer[j][i];
            }
        }
        return answer;
    }

    // leetcode官方题解
    /**
     * @brief 
     * 思路使用列遍历，先扫一遍找到每一列的最大值，
     * 再扫一遍把 −1 替换成这一列的最大值即可。
     */
    vector<vector<int>> modifiedMatrix_v2(vector<vector<int>>& matrix) {
        int n = matrix.size(); // 行数
        int m = matrix[0].size(); // 列数
        for (int j = 0; j < m; j++) {
            int zd = -1;
            for (int i = 0; i < n; i++) {
                zd = max(zd, matrix[i][j]);
            }
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = zd;
                }
            }
        }
        return matrix;
    }

    // 大佬@灵茶山艾府 简洁写法
    vector<vector<int>> modifiedMatrix_v3(vector<vector<int>>& matrix) {
        for (int j = 0; j < matrix[0].size(); j++) {
            int mx = 0;
            for (auto& row : matrix) {
                mx = max(mx, row[j]);
            }
            for (auto& row : matrix) {
                if (row[j] == -1) {
                    row[j] = mx;
                }
            }
        }
        return matrix;
    }

};

int main() {
    vector<vector<int>> matrix = {{1,2,-1}, {4,-1,6},{7,8,9}};

    vector<vector<int>> res = Solution().modifiedMatrix_v3(matrix);

    for (auto& x : res) {
        for (auto&y : x) {
            cout << y;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}