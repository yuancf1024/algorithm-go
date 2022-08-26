/**
 * @brief 微软笔试热身习题1
 * 大意：给定一个N行M列的矩阵，找到该矩阵中的平衡点数量。
 * 满足平衡点(P, Q)的条件：
 * - 0<=P<=N
 * - 0<=Q<=M
 * - 第P行上面所有元素之和与第P行下面所有元素之和相等
 * - 第Q行左面所有元素之和与第Q行右面所有元素之和相等

N、M的范围[1...30]
矩阵A元素数量的范围[1...900]
矩阵A元素大小的范围[-2,147,483,648...2,147,483,647]

 */

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <bits/stdc++.h>

using namespace std;

// 暴力搜索 
// 微软题目也提示比起性能会更加关注正确性
int solution(vector< vector<int> > &A) {
    // write your code in [LANGVER]
    // cout << "this is a debug message" << endl;
    int n = A.size(), m = A[0].size();
    vector<int> row(n);
    vector<int> column(m);
    // 注意考虑边界案例
    int equiRow = 0, equiColmun = 0;

    int position = 0;
    int num = 0;
    for (int i = 0; i < row.size(); ++i) {
        for (int j = 0; j < column.size(); ++j) {
            num += A[i][j];
        }
        row[position++] = num; // 计算每一行的总和，保存在row
        num = 0;
    }

    position = 0;
    for (int i = 0; i < column.size(); ++i) {
        for (int j = 0; j < row.size(); ++j) {
            num += A[j][i];
        }
        column[position++] = num; // 计算每一列的总和，保存在column
        num = 0;
    }

    for (int i = 0; i < row.size(); ++i) {
        int leftSum = 0, rightSum = 0;

        for (int j = 0; j < i; ++j) {
            leftSum += row[j];
        }

        for (int k = i + 1; k < row.size(); ++k) {
            rightSum += row[k];
        }

        if (leftSum == rightSum) {
            equiRow++;
        }
    }

    for (int i = 0; i < column.size(); ++i) {
        int leftSum = 0, rightSum = 0;

        for (int j = 0; j < i; ++j) {
            leftSum += column[j];
        }

        for (int k = i + 1; k < column.size(); ++k) {
            rightSum += column[k];
        }

        if (leftSum == rightSum) {
            equiColmun++;
        }
    }
    return equiRow * equiColmun;
}

int main() {
    vector<vector<int>> A = {{2, 7, 5}, {3,1,1},{2,1,-7},{0,2,1},{1,6,8}};

    int res = solution(A);
    cout << res << endl;
    return 0;
}

/*
Test output

Run tests
Example test: example

Test result: OK
*/