/**
 * @file 240.Search-a-2D-Matrix-II.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * leetcode-240. 搜索二维矩阵 II
 * 
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。
该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

示例 1：
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],
[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true

示例 2：
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],
[10,13,14,17,24],[18,21,23,26,30]], target = 20
输出：false

提示：

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-10^9 <= matrix[i][j] <= 10^9
每行的所有元素从左到右升序排列
每列的所有元素从上到下升序排列
-10^9 <= target <= 10^9
 */

// 方法一：直接查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            for (int num : row) {
                if (num == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

// 方法二：二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};

// 方法三：Z 字形查找
class Solution {
public:
    int searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] > target) {
                y--;
            } else {
                x++;
            }
        }
        return false;
    }
};

/**
 * @brief 
 * 
 * 方法一：直接查找
思路与算法

我们直接遍历整个矩阵 matrix，判断 target 是否出现即可。
复杂度分析
时间复杂度：O(mn)。
空间复杂度：O(1)。

方法二：二分查找
思路与算法

由于矩阵 matrix 中每一行的元素都是升序排列的，
因此我们可以对每一行都使用一次二分查找，判断 target 是否在该行中，
从而判断 target 是否出现。

复杂度分析

时间复杂度：O(mlogn)。对一行使用二分查找的时间复杂度为 O(logn)，
最多需要进行 m 次二分查找。

空间复杂度：O(1)。

方法三：Z 字形查找
思路与算法

我们可以从矩阵 matrix 的右上角 (0,n−1) 进行搜索。
在每一步的搜索过程中，如果我们位于位置 (x,y)，
那么我们希望在以 matrix 的左下角为左下角、以 (x,y) 为右上角的矩阵中
进行搜索，即行的范围为 [x,m−1]，列的范围为 [0,y]：

- 如果 matrix[x,y]=target，说明搜索完成；

- 如果 matrix[x,y]>target，由于每一列的元素都是升序排列的，
那么在当前的搜索矩阵中，所有位于第 y 列的元素都是严格大于target 的，
因此我们可以将它们全部忽略，即将 y 减少 1；

- 如果 matrix[x,y]<target，由于每一行的元素都是升序排列的，
那么在当前的搜索矩阵中，所有位于第 x 行的元素都是严格小于 target 的，
因此我们可以将它们全部忽略，即将 x 增加 1。

在搜索的过程中，如果我们超出了矩阵的边界，那么说明矩阵中不存在target。

复杂度分析
时间复杂度：O(m+n)。在搜索的过程中，如果我们没有找到 target，
那么我们要么将 y 减少 1，要么将 x 增加 1。
由于 (x,y) 的初始值分别为 (0,n−1)，因此 y 最多能被减少 n 次，
x 最多能被增加 m 次，总搜索次数为 m+n。
在这之后，x 和 y 就会超出矩阵的边界。
空间复杂度：O(1)。
 */