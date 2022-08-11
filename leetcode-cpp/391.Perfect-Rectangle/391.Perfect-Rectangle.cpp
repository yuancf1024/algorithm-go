/**
 * @file 391.Perfect-Rectangle.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * leetcode-391. 完美矩形

给你一个数组 rectangles ，其中 rectangles[i] = [xi, yi, ai, bi] 
表示一个坐标轴平行的矩形。这个矩形的左下顶点是 (xi, yi) ，
右上顶点是 (ai, bi) 。

如果所有矩形一起精确覆盖了某个矩形区域，则返回 true ；
否则，返回 false 。

 
示例 1：
输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
输出：true
解释：5 个矩形一起可以精确地覆盖一个矩形区域。 

示例 2：
输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
输出：false
解释：两个矩形之间有间隔，无法覆盖成一个矩形。

示例 3：
输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
输出：false
解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
 
提示：

1 <= rectangles.length <= 2 * 10^4
rectangles[i].length == 4
-10^5 <= xi, yi, ai, bi <= 10^5

 */

// 二维差分
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> mp;
        for (auto &item: rectangles) {
            int x = item[0], y = item[1], a = item[2], b = item[3];
            if (++mp[{x, y}] == 0) {
                mp.erase({x, y});
            }
            if (--mp[{x, b}] == 0) {
                mp.erase({x, b});
            }
            if (++mp[{a, b}] == 0) {
                mp.erase({a, b});
            }
            if (--mp[{a, y}] == 0) {
                mp.erase({a, y});
            }
        }
        return mp.size() == 4 && mp.begin()->second == 1;
    }
};

/**
 * @brief 
 * 方法一：哈希表
精确覆盖意味着：

- 矩形区域中不能有空缺，即矩形区域的面积等于所有矩形的面积之和；
- 矩形区域中不能有相交区域。

我们需要一个统计量来判定是否存在相交区域。
由于精确覆盖意味着矩形的边和顶点会重合在一起，
我们不妨统计每个矩形顶点的出现次数。

同一个位置至多只能存在四个顶点，
在满足该条件的前提下，如果矩形区域中有相交区域，
这要么导致矩形区域四角的顶点出现不止一次，
要么导致非四角的顶点存在出现一次或三次的顶点；

因此要满足精确覆盖，除了要满足矩形区域的面积等于所有矩形的面积之和，
还要满足矩形区域四角的顶点只能出现一次，
且其余顶点的出现次数只能是两次或四次。

在代码实现时，我们可以遍历矩形数组，计算矩形区域四个顶点的位置，
以及矩形面积之和，并用哈希表统计每个矩形的顶点的出现次数。
遍历完成后，检查矩形区域的面积是否等于所有矩形的面积之和，
以及每个顶点的出现次数是否满足上述要求。

复杂度分析

时间复杂度：O(n)，其中 n 是数组 rectangles 的长度。

空间复杂度：O(n)。我们需要用哈希表存储矩形的顶点及其出现次数。
 */