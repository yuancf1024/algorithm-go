/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 * 图象卷积 15分
 * 
示例1：
7 7 3 3
2 3 7 4 6 2 9
6 6 9 8 7 4 3
3 4 8 3 8 9 7
7 8 3 6 6 3 4
4 2 1 8 3 4 6
3 2 4 1 9 8 3
0 1 3 9 2 1 4
4 8 4
8 16 8
-4 8 -4

80 108 184 168 152 144 168
180 255 255 255 255 232 180
176 255 255 255 255 255 244
240 255 220 255 255 255 212
184 164 196 200 255 216 164
100 120 120 252 255 255 204
40 84 172 244 220 176 128

 */

/*
2022-09-19复盘
思路：
*/

#include <bits/stdc++.h>

using namespace std;

int main() { 
    int M, N, K, L;
    cin >> M >> N >> K >> L;

    vector<vector<int>> I(M, vector<int>(N));
    vector<vector<int>> kernel(K, vector<int>(L));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> I[i][j];
        }
    }

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < L; ++j) {
            cin >> kernel[i][j];
        }
    }

    // 核心代码
    vector<vector<int>> res(M, vector<int>(N));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            int sum = 0;
            for (int o = -(K / 2); o <= K / 2; ++o) {
                for (int p = -(L / 2); p <= L / 2; ++p) {
                    int x = i + o;
                    int y = j + p;
                    if (x >= 0 && x < M && y >= 0 && y < N) {
                        sum += I[x][y] * kernel[o + K / 2][p + L / 2];
                    }
                }
            }
            if (sum > 255) {
                sum = 255;
            }
            if (sum < 0) {
                sum = 0;
            }
            res[i][j] = sum;
        }
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << res[i][j];
            if (j != N-1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// // 自己的代码
// #include <bits/stdc++.h>

// using namespace std;

// int main() { 
//     int M, N, K, L;
//     cin >> M >> N >> K >> L;

//     vector<vector<int>> I(M, vector<int>(N));
//     vector<vector<int>> kernel(K, vector<int>(L));
//     for (int i = 0; i < M; ++i) {
//         for (int j = 0; j < N; ++j) {
//             cin >> I[i][j];
//         }
//     }

//     for (int i = 0; i < K; ++i) {
//         for (int j = 0; j < L; ++j) {
//             cin >> kernel[i][j];
//         }
//     }

//     // 核心代码
//     vector<vector<int>> res(M, vector<int>(N, 0));

//     // 卷积核中心
//     int x = K / 2, y = L / 2;
//     // cout << x << y;

//     // 尝试统一处理
//     // 处理中间部分
//     for (int i = 0; i < M; ++i) {
//         for (int j = 0; j < N; ++j) {
//             int t = 0;
//             for (int m = 0; m < K; ++m) {
//                 for (int n = 0; n < L; ++n) {
//                     t += I[i + m][j + n] * kernel[m][n];
//                 }
//             }
//             res[i+1][j+1] = t;
//         }
//     }


//     // 处理边缘 - 上
//     for (int i = 0; i < N; ++i) {
//         int t = 0;
//         for (int j = x; j < K; ++j) {
//             for (int k = y; k < L; ++k) {
//                 t += kernel[j][k] * I[j-x][i+k-y];
//             }
//         }
//         res[0][i] = t;
//     }
//     for (int i = 0; i < M; ++i) {
//         for (int j = 0; j < N; ++j) {
//             cout << res[i][j] << " ";
//         }
//         cout << endl;
//     }
//         // // 处理边缘 - 下
//         // for (int i = 0; i < N; ++i) {
//         //     int t = 0;
//         //     for (int j = 0; j < x; ++j) {
//         //         for (int k = 0; k < y; ++k) {
//         //             t += kernel[j][k] * I[M+j-x][i+k];
//         //         }
//         //     }
//         //     res[M-1][i] = t;
//         // }

//         // // 中间部分很简单 四重循环即可
//         // for (int i = )
//         // // 打印
//         // for (int i = 0; i < M; ++i) {
//         //     for (int j = 0; j < N; ++j) {
//         //         cout << res[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }

//         // 处理中心

//         // 打印确认
//         // for (int i = 0; i < M; ++i) {
//         //     for (int j = 0; j < N; ++j) {
//         //         cout << I[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
//         // for (int i = 0; i < K; ++i) {
//         //     for (int j = 0; j < L; ++j) {
//         //         cout << kernel[i][j] << " ";
//         //     }
//         //     cout << endl;
//         // }
//         return 0;
// }