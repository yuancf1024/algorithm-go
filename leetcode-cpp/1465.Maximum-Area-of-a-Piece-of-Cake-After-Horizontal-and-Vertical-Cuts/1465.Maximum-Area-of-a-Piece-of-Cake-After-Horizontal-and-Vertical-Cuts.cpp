/**
 * @file 1465.Maximum-Area-of-a-Piece-of-Cake-After-Horizontal-and-Vertical-Cuts.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-1465.切割后面积最大的蛋糕
 * @version 0.1
 * @date 2023-10-27
 * 
 * @copyright Copyright (c) 2023
 * 矩形蛋糕的高度为 h 且宽度为 w，给你两个整数数组 horizontalCuts 和 verticalCuts，其中：

 horizontalCuts[i] 是从矩形蛋糕顶部到第  i 个水平切口的距离
verticalCuts[j] 是从矩形蛋糕的左侧到第 j 个竖直切口的距离
请你按数组 horizontalCuts 和 verticalCuts 中提供的水平和竖直位置切割后，
请你找出 面积最大 的那份蛋糕，并返回其 面积 。
由于答案可能是一个很大的数字，因此需要将结果 对 109 + 7 取余 后返回。

示例 1：
输入：h = 5, w = 4, 
horizontalCuts = [1,2,4], verticalCuts = [1,3]
输出：4 
解释：上图所示的矩阵蛋糕中，红色线表示水平和竖直方向上的切口。切割蛋糕后，绿色的那份蛋糕面积最大。

示例 2：
输入：h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
输出：6
解释：上图所示的矩阵蛋糕中，红色线表示水平和竖直方向上的切口。切割蛋糕后，绿色和黄色的两份蛋糕面积最大。

示例 3：
输入：h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
输出：9
 

提示：

2 <= h, w <= 10^9
1 <= horizontalCuts.length <= min(h - 1, 10^5)
1 <= verticalCuts.length <= min(w - 1, 10^5)
1 <= horizontalCuts[i] < h
1 <= verticalCuts[i] < w
题目数据保证 horizontalCuts 中的所有元素各不相同
题目数据保证 verticalCuts 中的所有元素各不相同
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 贪心
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1e9 + 7;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        auto calMax = [](vector<int> &arr, int boardr) -> int {
            int res = 0, pre = 0;
            for (int i : arr) {
                res = max(i - pre, res);
                pre = i;
            }
            return max(res, boardr - pre);
        };
        return (long long)calMax(horizontalCuts, h) * calMax(verticalCuts, w) % mod;
    }
};

int main() {
    int h  = 5, w = 4;
    vector<int> horizontalCuts = {1, 2, 4};
    vector<int> verticalCuts = {1, 3};
    int res = Solution().maxArea(h, w, horizontalCuts, verticalCuts);
    cout << res << endl;
    return 0;
}