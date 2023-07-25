/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * 20分 面试的分组
 * 
 * 提供一组作为seats，1表示有座位，0表示无座位；
 * 相邻位置的同学被分到一组，求一共有多少组？
 * 
示例1：

[[1,0,0,0],[0,1,1,0],[1,0,0,1],[1,0,1,1]]

4

示例2：
[[0,0,1,0,1,0],[0,1,1,1,1,0],[1,0,0,0,0,1],[1,1,0,0,0,1],[0,1,1,0,1,1]]

3

 */

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 按照输入的会议室座位排布，得到总的分组数并返回
     * @param seats int整型vector<vector<>> 会议室的座位排布图
     * @return int整型
     */
    vector<int> dir={-1,0,1,0,-1};
    int getNumberOfGroup(vector<vector<int> >& seats) {
        // write code here
        if (seats.empty() || seats[0].empty()) {
            return 0;
        }
        int res = 0;
        int n = seats.size(), m = seats[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // 扫描二维网格
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (seats[i][j] == 1 && !vis[i][j]) {
                    res++;
                    dfs(seats, vis, i, j);
                }
            }
        }
        return res;
    }
    // 辅函数
    void dfs(vector<vector<int>>& seats, vector<vector<int>>& vis, int x, int y) {
        vis[x][y] = 1;
        int dx, dy;
        for (int i = 0; i < 4; ++i) {
            dx = x + dir[i];
            dy = y + dir[i+1];
            if (isInSeats(seats, dx, dy) && seats[dx][dy] == 1 && !vis[dx][dy]) {
                dfs(seats, vis, dx, dy);
            }
        }
    }
    // 检查是否还在座位内
    bool isInSeats(vector<vector<int>>& seats, int x, int y) {
        return x >= 0 && x < seats.size() && y >= 0 && y < seats[0].size();
    }
};