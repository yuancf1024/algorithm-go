/**
 * @file 2103.Rings-and-Rods.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-2103.环和杆 C++ 哈希表 位计算
 * @version 0.1
 * @date 2023-11-02
 * 
 * @copyright Copyright (c) 2023
 * 总计有 n 个环，环的颜色可以是红、绿、蓝中的一种。
 * 这些环分别穿在 10 根编号为 0 到 9 的杆上。

给你一个长度为 2n 的字符串 rings ，表示这 n 个环在杆上的分布。
rings 中每两个字符形成一个 颜色位置对 ，用于描述每个环：

第 i 对中的 第一个 字符表示第 i 个环的 颜色（'R'、'G'、'B'）。
第 i 对中的 第二个 字符表示第 i 个环的 位置，也就是位于哪根杆上（'0' 到 '9'）。
例如，"R3G2B1" 表示：共有 n == 3 个环，红色的环在编号为 3 的杆上，绿色的环在编号为 2 的杆上，蓝色的环在编号为 1 的杆上。

找出所有集齐 全部三种颜色 环的杆，并返回这种杆的数量。

示例 1：
输入：rings = "B0B6G0R6R0R6G9"
输出：1
解释：
- 编号 0 的杆上有 3 个环，集齐全部颜色：红、绿、蓝。
- 编号 6 的杆上有 3 个环，但只有红、蓝两种颜色。
- 编号 9 的杆上只有 1 个绿色环。
因此，集齐全部三种颜色环的杆的数目为 1 。

示例 2：
输入：rings = "B0R0G0R9R0B0G0"
输出：1
解释：
- 编号 0 的杆上有 6 个环，集齐全部颜色：红、绿、蓝。
- 编号 9 的杆上只有 1 个红色环。
因此，集齐全部三种颜色环的杆的数目为 1 。

示例 3：
输入：rings = "G4"
输出：0
解释：
只给了一个环，因此，不存在集齐全部三种颜色环的杆。
 
提示：

rings.length == 2 * n
1 <= n <= 100
如 i 是 偶数 ，则 rings[i] 的值可以取 'R'、'G' 或 'B'（下标从 0 开始计数）
如 i 是 奇数 ，则 rings[i] 的值可以取 '0' 到 '9' 中的一个数字（下标从 0 开始计数）
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static constexpr int POLE_NUM = 10;
    int countPoints(string rings) {
        vector<int> state(POLE_NUM);
        int n = rings.size();
        for (int i = 0; i < n; i += 2) {
            char color = rings[i];
            int pole_index = rings[i+1] - '0';
            if (color == 'R') {
                state[pole_index] |= 1;
            } else if (color == 'G') {
                state[pole_index] |= 2;
            } else {
                state[pole_index] |= 4;
            }
        }
        int ans = 0;
        for (int i = 0; i < POLE_NUM; i++) {
            ans += state[i] == 7;
        }
        return ans;
    }
};

int main() {
    string rings = "B0B6G0R6R0R6G9";
    int res = Solution().countPoints(rings);
    cout << res << endl;
    return 0;
}

/**
 * @brief leetcode官方题解-非常巧妙的方法
 * 状态压缩优化
 * 思路与算法：
 * 我们也可以用一个 3 位二进制整数来表示每个杆的状态。
 * 具体的，在二进制表示中，从低到高的第 0,1,2位分别表示是否有红、绿、蓝色。
 * 每一位为 1 则表示当前杆上有对应颜色的环，为 0 则表示没有。

因此当遇到一个在 3 号杆，颜色为红色的环时，需要将 state[3] 的第 0 位置为 1。
在代码中，将 state[3]与 1 做位或运算即可（因为 2^0 = 1）。

最后，遍历 state，统计状态值为 (111)_2 = 7的个数，并返回该个数作为答案。

复杂度分析
时间复杂度：O(nk+m)，其中 n 为 rings 的长度，k 为颜色的数量（在本题中固定为 3），
m 为杆的数量（在本题中固定为 10），如果使用哈希表代替掉 if
，时间复杂度可以降低为 O(n+m)。

空间复杂度：O(m)。
 */