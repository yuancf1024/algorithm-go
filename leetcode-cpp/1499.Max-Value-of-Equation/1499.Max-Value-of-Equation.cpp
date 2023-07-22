/**
 * @file 1499.Max-Value-of-Equation.cpp
 * @author your name (you@domain.com)
 * @brief 1499. 满足不等式的最大值
 * @version 0.1
 * @date 2023-07-22
 * 
 * @copyright Copyright (c) 2023
 * 
给你一个数组points和一个整数k。
数组中每个元素都表示二维平面上的点的坐标，
并按照横坐标x的值从小到大排序。
也就是说points[i] = [xi, yi] ，
并且在 1 <= i < j <= points.length的前提下，
xi < xj 总成立。

请你找出 yi + yj + |xi - xj| 的最大值，
其中|xi - xj|<= k 且1 <= i < j <= points.length。

题目测试数据保证至少存在一对能够满足
|xi - xj| <= k 的点。

示例 1：

输入：points = [[1,3],[2,0],[5,10],[6,-10]], 
k = 1
输出：4

解释：前两个点满足 |xi - xj| <= 1 ，代入方程计算，
则得到值 3 + 0 + |1 - 2| = 4 。
第三个和第四个点也满足条件，得到值
10 + -10 + |5 - 6| = 1 。
没有其他满足条件的点，所以返回 4 和 1 中最大的那个。

示例 2：
输入：points = [[0,0],[3,0],[9,2]], k = 3
输出：3
解释：只有前两个点满足 |xi - xj| <= 3 ，
代入方程后得到值 0 + 0 + |0 - 3| = 3 。
 
提示：

2 <= points.length <= 10^5
points[i].length == 2
-10^8 <= points[i][0], points[i][1] <= 10^8
0 <= k <= 2 * 10^8
对于所有的1 <= i < j <= points.length ，
points[i][0] < points[j][0] 都成立。
也就是说，xi 是严格递增的。

 */

#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Solution {
public:
    using pii = pair<int, int>;
    // 堆解法   感觉不是很好想明白
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        priority_queue<pii, vector<pii>, greater<pii>> heap;
        for (auto& point : points) {
            int x = point[0], y = point[1];
            while (!heap.empty() && x - heap.top().second > k) {
                heap.pop();
            }
            if (!heap.empty()) {
                ans = max(ans, x + y - heap.top().first);
            }
            heap.emplace(x-y, x);
        }
        return ans;
    }

    // 双端队列解法
    int findMaxValueOfEquation2(vector<vector<int>>& points, int k) {
        int res = INT_MIN;
        deque<pii> qu;
        for (auto& point : points) {
            int x = point[0], y = point[1];
            while (!qu.empty() && x - qu.front().second > k) {
                qu.pop_front();
            }
            if (!qu.empty()) {
                res = max(res, x + y + qu.front().first);
            }
            while (!qu.empty() && y - x >= qu.back().first) {
                qu.pop_back();
            }
            qu.emplace_back(y-x, x);
        }
        return res;
    }

    // 数学 + 单调队列 + 滑动窗口
    int findMaxValueOfEquation3(vector<vector<int>>& points, int k) {
        deque<int> dq{points[0][1] - points[0][0]};
        int n = points.size(), ans = INT_MIN;
        for (int i = 1, j = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1];
            for (; points[j][0] + k < x || !dq.empty() && dq.front() < dq.back(); ++j) {
                dq.pop_front();
            }
            if (!dq.empty()) {
                ans = max(ans, dq.front() + x + y);
            }
            dq.push_back(y - x);
        }
        return ans;
    }

    // 双指针模拟双端队列，达到空间O(1) 好理解
    int findMaxValueOfEquation_v4(vector<vector<int>>& points, int k) {
        int n = points.size(), ans = INT_MIN;
        for (int i = 1 , j = 0; i < n; ++i) {
            int x = points[i][0], y = points[i][1], d = points[i-1][1] - points[i-1][0];
            while (i > j && (points[j][0] + k < x || points[j][1] - points[j][0] < d)) {
                ++j;
            }
            if (i > j) {
                    ans = max(ans, points[j][1] - points[j][0] + x + y);
                }
        }
        return ans;
    }
};

int main() {

    vector<vector<int>> points = {{1,3}, {2,0}, {5,10}, {6,-10}};
    int k = 1;

    int res = Solution().findMaxValueOfEquation_v4(points, k);

    cout << res << endl;

    return 0;
}

/**
 * @brief leetcode官方题解
 * 方法一：堆
思路

题目要求 
y_i+y_j+∣x_i−x_j∣，其中∣x_i−xj∣≤k 的最大值。
根据题目条件，i<j 时，x_i<=x_j ，可以拆去绝对值符号，
得到 
(−x_i+y_i)+(x_j+y_j)，其中x_j−x_i≤k。

根据这个等式，可以遍历points所有点，使每个点作为 
[xj,yj]，并且求出满足 
xj−xi≤k 的最大的(−xi+yi)，而这一步，可以用堆来完成。
用一个最小堆，堆的元素是[x−y,x]，堆顶元素的(x−y)值
最小，即(−x+y) 值最大。

每次遍历一个点时，先弹出堆顶不满足当前 
xj−xi≤k 的元素，然后用堆顶元素和当前元素计算 
(−xi+yi)+(xj+yj)，再将当前元素放入堆。
遍历完后，即得到了式子的最大值。

复杂度分析

时间复杂度：O(n×logn)，其中n是points 的长度，
每个元素最多进入并离开heap一次。

空间复杂度：O(n)，是heap的空间复杂度。

方法二：双端队列
思路

与方法一思路类似，方法一用堆来求满足 
xj−xi≤k 的最大的(−xi+yi)，而这一步可以用
双端队列来求，从而降低时间复杂度。
使用一个双端队列q，元素为[y−x,x]。
每次遍历一个点时，首先同样要弹出队列头部不满足 
xj−xi≤k 的元素，然后用队列头部元素和当前元素计算 
(yi−xi)+(xj​+yj)。在当前元素进入队列尾端时，
需要弹出队列末端小于等于当前yj−xj的元素，
这样以来，可以使得双端队列保持递减，
从而头部元素最大。然后将当前元素压入队列末端。
遍历完后，即得到了式子的最大值。

复杂度分析

时间复杂度：O(n)，其中n是points的长度，
每个元素最多进入并离开q一次。

空间复杂度：O(n)，是q的空间复杂度。
 */