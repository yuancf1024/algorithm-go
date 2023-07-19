/**
 * @file 874.Walking-Robot-Simulation.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-874.模拟行走机器人
 * @version 0.1
 * @date 2023-07-19
 * 
 * @copyright Copyright (c) 2023
 * 
机器人在一个无限大小的 XY 网格平面上行走，
从点 (0, 0) 处开始出发，面向北方。
该机器人可以接收以下三种类型的命令 commands ：

-2 ：向左转 90 度
-1 ：向右转 90 度
1 <= x <= 9 ：向前移动 x 个单位长度
在网格上有一些格子被视为障碍物 obstacles 。
第 i 个障碍物位于网格点 obstacles[i] = (xi, yi) 。

机器人无法走到障碍物上，它将会停留在障碍物的
前一个网格方块上，但仍然可以继续尝试进行该路线的
其余部分。

返回从原点到机器人所有经过的路径点（坐标为整数）
的最大欧式距离的平方。
（即，如果距离为 5 ，则返回 25 ）

 
注意：

北表示 +Y 方向。
东表示 +X 方向。
南表示 -Y 方向。
西表示 -X 方向。
 

示例 1：
输入：commands = [4,-1,3], obstacles = []
输出：25

解释：
机器人开始位于 (0, 0)：
1. 向北移动 4 个单位，到达 (0, 4)
2. 右转
3. 向东移动 3 个单位，到达 (3, 4)
距离原点最远的是 (3, 4) ，距离为 32 + 42 = 25

示例 2：
输入：commands = [4,-1,4,-2,4], obstacles = [[2,4]]
输出：65
解释：机器人开始位于 (0, 0)：

1. 向北移动 4 个单位，到达 (0, 4)
2. 右转
3. 向东移动 1 个单位，然后被位于 (2, 4) 的障碍物
阻挡，机器人停在 (1, 4)
4. 左转
5. 向北走 4 个单位，到达 (1, 8)
距离原点最远的是 (1, 8) ，距离为 12 + 82 = 65
 

提示：

1 <= commands.length <= 10^4
commands[i] is one of the values in the list 
[-2,-1,1,2,3,4,5,6,7,8,9].
0 <= obstacles.length <= 10^4
-3 * 104 <= xi, yi <= 3 * 10^4
答案保证小于 2^31

 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int px = 0, py = 0, d = 1;
        unordered_set<int> mp;
        for (auto &obstacle : obstacles) {
            mp.emplace(obstacle[0] * 60001 + obstacle[1]);
        }

        int ans = 0;
        for (int c : commands) {
            if (c < 0) {
                d += c == -1 ? 1 : -1;
                d %= 4;
                if (d < 0) {
                    d += 4;
                }
            } else {
                for (int i = 0; i < c; i++) {
                    if (mp.count((px + dirs[d][0]) * 60001 + py + dirs[d][1])) {
                        break;
                    }
                    px += dirs[d][0];
                    py += dirs[d][1];
                    ans = max(ans, px * px + py * py);
                }
            }
        }
        return ans;
    }
};

int main() {

    vector<int> commands = {4,-1,3};
    vector<vector<int>> obstacles; // 初始化默认为空

    int res = Solution().robotSim(commands, obstacles);

    cout << res << endl;

    return 0;
}

/**
 * @brief leetcode官方题解
 *
方法一：哈希表
思路与算法

题目给出一个在点(0,0) ，并面向北方的机器人。
现在有一个大小为n的命令数组 commands来操作机器人
的移动，和一个大小为m的障碍物数组obstacles。
现在我们通过commands来模拟机器人的移动，
并用一个哈希表来存储每一个障碍物放置点。
当机器人的指令为向前移动时，我们尝试往前移动对应的
次数——若往前一个单位不为障碍物放置点
（即不在哈希表中），则机器人向前移动一个单位，
否则机器人保持原位不变。

在机器人移动的过程中记录从原点到机器人所有经过的
整数路径点的最大欧式距离的平方即为最后的答案。

在代码实现的过程中，对于机器人转向和向前移动的操作，
我们可以用一个方向数组
dirs={[−1,0],[0,1],[1,0],[0,−1]} 来现实。
若当前机器人的坐标为(x,y)，当前方向的标号为d，
则往前移动一单位的操作为x=x+dirs[d][0]，
y=y+dirs[i][1]。向左转的操作为 d=(d+3)mod4，
向右转的操作为 d=(d+1)mod4。

复杂度分析

时间复杂度：O(C×n+m)，其中n为数组commands的大小，
C 为每次可以向前的步数最大值，在该题目中C=9，
m为数组 obstacles 的大小。
时间开销主要为模拟机器人移动和哈希表存储
每一个障碍物的坐标的开销。

空间复杂度：O(m)，其中m为数组obstacles的大小，
主要为哈希表存储obstacles的空间开销。
 */