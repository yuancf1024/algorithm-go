/**
 * @file T2-200.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * 2、防疫就餐
受疫情影响，员工到食堂吃饭需要隔位就坐，
也就是前后左右相邻两个位置不能同时坐人。
假设食堂座位按长方形网格排列，部分位置上已经坐了人，
就坐的人符合隔位就餐限制。问在满足隔位就餐限制下最多还能容纳的就格人数。

解答要求:
时间限制C/C++ 1000ms,其他语言: 
2000ms内存限制C/C++ 256MB,其他语言:512MB

输入:
第一行输入m, n表示矩阵长宽，满足1<m, n<=20;
后面输入m行，每行有n个0或1的整数，整数间使用一个空格隔开，
表示食堂座位就坐情况，其中0表示空位，1表示已经有人就坐。

输出:
返回在满足隔位就餐限制下，最多还能容纳的就餐的人数

样例1:
输入:
2 4
1 0 0 0
0 0 0 1

输出:
2

解释:

样例2:

输入:
4 6
1 0 0 0 0 1
0 0 0 0 0 0
0 1 0 0 0 1
0 0 0 0 0 0

输出:
7

解释:

 */

/*
本题看起来不难，实际上处理也不难
但是真正完全靠自己想出来，还是有点难的

记忆状态的DP
*/

#include <bits/stdc++.h>

using namespace std;

int maxEat(vector<vector<int>>& seats) {
    int m = seats.size(), n = seats[0].size();

    vector<int> Seat(m); // 用于预处理每行已经就坐的人，用二进制码表示
    for (int i = 0; i < m; ++i) {
        int temp = 0;
        for (int j = 0; j < n; ++j) {
            if (seats[i][j] == 1) { // 左移加1
                temp = temp << 1;
                ++temp;
            }
            else {
                temp = temp << 1; // 左移加0
            }
        }
        Seat[i] = temp; // 第一行
        // 调试信息
        // cout << Seat[i] << endl;
    }

    int status = (1 << n);  // 每一行的状态数pow(2, n)-1;
    vector<vector<int>> dp(m + 1, vector<int>(status, -1));

    for (int i = 0; i < status; ++i) { // 初始化0行
        dp[0][i] = 0; 
    }

    for (int i = 1; i <= m; ++i) { // 从第一行开始遍历
        for (int j = 0; j < status; ++j) {
            // 当前状态和不包含题目已经坐了人的位置，或者左右有人，则不满足
            if ((j & Seat[i-1]) != Seat[i-1] || (j & (j << 1)) != 0 || (j & (j >> 1)) != 0) {
                dp[i][j] = -1;
                continue;
            }

            for (int k = 0; k < status; ++k) { // 遍历上一行
                // 上一行不满足则跳过
                if (dp[i-1][k] == -1) {
                    continue;
                }

                // 上一行和当前行出现上下邻居则跳过，即本行包含了上一行的部分座位
                if ((j & k) != 0) {
                    continue;
                }

                int count = 0; // 计算当前行还能坐的人
                int temp = (j ^ Seat[i - 1]); // temp用于排除最开始已经就坐的人
                for (int i = 0; i < n; ++i) {
                    if ((temp & (1 << i)) != 0) { // 每一位作位运算，判断是不是1
                        ++count;
                    }
                }
                // cout << "count = " << count << endl;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + count); // 前一行的k状态下人数，加上本行的人数
            }
        }
    }

    int res = 0;
    for (int i = 0; i < status; ++i) {
        res = max(res, dp[m][i]); // 最后一行，所有状态下最大人数
    }

    return res;
}

int main() { 
    int m, n;
    cin >> m >> n;
    vector<vector<int>> seats(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> seats[i][j];
        }
    }

    int res = maxEat(seats);
    cout << res << endl;
    return 0;
}

// 分割线

// #include<iostream>
// #include<vector>
// using namespace std;


// int maxEat(vector<vector<int>>& seats) {
//     int m = seats.size();
//     int n = seats[0].size();


//     vector<int> Seat(m); // 用于预处理每行已经就坐的人，用二进制码表示
//     for (int i = 0; i < m; ++i) {
//         int temp = 0;
//         for (int j = 0; j < n; ++j) {   
//             if (seats[i][j] == 1) {  // 左移加一
//                 temp = temp << 1; 
//                 ++temp;
//             }
//             else {
//                 temp = temp << 1;  //左移加0
//             }
//         }
//         Seat[i] = temp;  // 第1行
//         // cout << Seat[i] << endl;    
//     }

//     int status = (1 << n);  // 每一行的状态数pow(2, n) - 1;
//     vector<vector<int>>dp(m + 1, vector<int>(status, -1));

//     for (int i = 0; i < status; ++i) {   // 初始化0行
//         dp[0][i] = 0;
//     }

//     for (int i = 1; i <= m; ++i) {   // 从第一行开始遍历
//         for (int j = 0; j < status; ++j) {
//             // 当前状态和不包含题目已经坐了人的位置， 或者左右有人，则不满足
//             if ((j & Seat[i - 1]) != Seat[i - 1] || (j & (j << 1)) != 0 || (j & (j >> 1)) != 0) {  
//                 dp[i][j] = -1;
//                 continue;
//             }
           
//             for (int k = 0; k < status; ++k) { // 遍历上一行
//                 // 上一行不满足则跳过
//                 if (dp[i - 1][k] == -1) {
//                     continue;
//                 }
//                 // 上一行和当前行出现上下邻居则跳过， 即本行包含了上一行的部分座位
//                 if ((j & k) != 0) {
//                     continue;
//                 }


//                 int count = 0; // 计算当前行还能坐的人
//                 int temp = (j ^ Seat[i - 1]); // temp用于排除最开始已经就坐的人
//                 for (int i = 0; i < n; ++i) {
//                     if ((temp & (1 << i)) != 0) {  // 每一位做位运算，判断是不是1
//                         ++count;
//                     }
//                 }
//                 //cout << "count = " << count << endl;
//                 dp[i][j] = max(dp[i][j], dp[i - 1][k] + count); // 前一行的k状态下人数，加上本行的人数
//             }
//         }
//     }

//     int res = 0;
//     for (int i = 0; i < status; ++i) {
//         res = max(res, dp[m][i]);   // 最后一行，所有状态下最大人数
//     }
//     return res;
// }



// int main() {
// 	int m;
// 	int n;
// 	cin >> m >> n;
//     vector<vector<int>> seats(m, vector<int>(n));
//     for (int i = 0; i < m; ++i) {
//         for (int j = 0; j < n; ++j) {
//             cin >> seats[i][j];
//         }
//     }


//     int res = maxEat(seats);
//     cout << res << endl;

// 	return 0;
// }