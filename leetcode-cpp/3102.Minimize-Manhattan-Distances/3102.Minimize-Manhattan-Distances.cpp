/**
 * @file 3102.Minimize-Manhattan-Distances.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-3102.Minimize-Manhattan-Distances 
 * @version 0.1
 * @date 2024-07-09
 * 给你一个下标从 0 开始的数组 points ，它表示二维平面上一些点的整数坐标，
 * 其中 points[i] = [xi, yi] 。

两点之间的距离定义为它们的曼哈顿距离。
两个单元格 (xi, yi) 和 (xj, yj) 之间的曼哈顿距离为 |xi - xj| + |yi - yj|。

请你恰好移除一个点，返回移除后任意两点之间的 最大 距离可能的 最小 值。

示例 1：
输入：points = [[3,10],[5,15],[10,2],[4,4]]
输出：12
解释：移除每个点后的最大距离如下所示：
- 移除第 0 个点后，最大距离在点 (5, 15) 和 (10, 2) 之间，为 |5 - 10| + |15 - 2| = 18 。
- 移除第 1 个点后，最大距离在点 (3, 10) 和 (10, 2) 之间，为 |3 - 10| + |10 - 2| = 15 。
- 移除第 2 个点后，最大距离在点 (5, 15) 和 (4, 4) 之间，为 |5 - 4| + |15 - 4| = 12 。
- 移除第 3 个点后，最大距离在点 (5, 15) 和 (10, 2) 之间的，为 |5 - 10| + |15 - 2| = 18 。
在恰好移除一个点后，任意两点之间的最大距离可能的最小值是 12 。

示例 2：
输入：points = [[1,1],[1,1],[1,1]]
输出：0
解释：移除任一点后，任意两点之间的最大距离都是 0 。

提示：
3 <= points.length <= 10^5
points[i].length == 2
1 <= points[i][0], points[i][1] <= 10^8
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 方法一：有序集合
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> xs, ys;
        for (auto& p : points) {
            xs.insert(p[0]+p[1]);
            ys.insert(p[1]-p[0]);
        }

        int ans = INT_MAX;
        for (auto& p : points) {
            int x = p[0] + p[1], y = p[1] - p[0];
            xs.erase(xs.find(x)); // 移除一个x
            ys.erase(ys.find(y)); // 移除一个y

            int dx = *xs.rbegin() - *xs.begin();
            int dy = *ys.rbegin() - *ys.begin();
            ans = min(ans, max(dx, dy));

            xs.insert(x);
            ys.insert(y);
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> points = {{3, 10}, {5, 15}, {10, 2}, {4, 4}};
    int res = Solution().minimumDistance(points);
    cout << res << endl;

    return 0;
}

/**
 * @brief 参考大佬@灵茶山艾府 曼哈顿距离转切比雪夫距离
 * 这两种投影长度，其中较大者为曼哈顿距离（较小者是两段折线的投影长度之差，不合法），
 * 即如下恒等式

∣x_1−x_2∣+∣y_1−y_2∣=max(∣x_1′−x_2′∣, ∣y_1′−y_2′∣)
其中等式左侧为 (x_1, y_1) 和 (x_2, y_2) 的曼哈顿距离，
等式右侧 (x′,y′)=(x+y,y−x)，计算的是 
(x_1′, y_1′) 和 (x_2′, y_2′) 两点的曼哈顿距离投影到 x 轴和 y 轴的线段长度的最大值，
即切比雪夫距离。

所以要求任意两点曼哈顿距离的最大值，根据上面的恒等式，
我们只需要计算任意两个 (x′,y′) 切比雪夫距离的最大值，
即横纵坐标差的最大值
max{max(x′)−min(x′),max(y′)−min(y′)}

方法一：有序集合
枚举要移除的点，用两个有序集合维护其他 n−1 个点的x′和y′，
用 max{max(x′)−min(x′),max(y′)−min(y′)} 更新答案的最大值。

复杂度分析
时间复杂度：O(nlogn)，其中 n 为 points 的长度。
空间复杂度：O(n)。

方法二：维护最大次大、最小次小
优化：如果把最大的 x′移除，那么次大的 x′就是剩下 n−1 个 x′中的最大值了，
对于最小值也同理。

所以只需维护 x′和 y′的最大次大、最小次小，一共 8 个数。

注意最大次大可能是相同的，最小次小可能是相同的。

 */