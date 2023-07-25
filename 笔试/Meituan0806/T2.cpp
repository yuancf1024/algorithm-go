/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-06
 *
 * @copyright Copyright (c) 2022
 *
第二题 最小错误
题目：
小美做实验，有一个纸带上有若干个数字，在纸带上选择一个位置k，
k是分割点（比如k选3，那么左边是123，右边是456），
k左边大于等于0的点为异常点，k右边小于等于0的点为异常点。

现在给一个纸带，由0，1，-1组成，不给k，问你最乐观情况下异常点最少个数为多少
（选哪个k异常点最少吧）

思路：

用前缀数组，记录每个点左边的异常点，再从右边计算异常点回来，
每次左右异常点个数相加，取最小一个。

方法1：前缀和 (思路不太容易想到)
理解：
- 大意 k前面的必须为负 否则错误++；k后面的必须为正，否则错误++
- 思路 先统计0 必然是错误 再使用前缀和判断即可

方法2：依题意模拟
- 采用 left 数组保存 i 之前的小于等于0的数量
- 采用 right 数组保存 i 之后大于等于0的数量
遍历即可

Input:
5
-1 1 0 -1 -1

Output:

2

反思：

本题看起来简单，但是有一些小细节需要注意，不然就会出错。

1)输入数组
- 如果确切的知道数组大小，可直接采用索引赋值输入，即cin >> nums[i]
- 如果不知道数组大小，那么采用push_back()添加进数组末尾,即
cin >>num;
nums.push_back(num);

2)对于前缀数组的边界处理要非常的小心，最好模拟一个例子，以免出错。
根据题目的提示：k是分割点（比如k选3，那么左边是123，右边是456）

所以遍历到的数字，只能被一侧被加进去判断。
什么意思呢？数组有5个数，但是有6种分割方案，分割方案N+1
此处

index:  0 1 2  3  4  5
nums:  -1 1 0 -1 -1
// 正确的前缀数组应该是这样
left:   0 0 1  2  2  2
right:  4 3 3  2  1  0
// 然而我们遍历得到的前缀数组是下面这样
left:  0 1 2 2 2
right: 4 3 3 2 1

显然，遍历得到的结果是按照包括分界点来算的，然而实际上应该不包括；
因此，需要将left数组整体右移，并在第一个位置补0，
需要将right数组整体最后一个位置补0
就像下面这样：
left:    0 0 1 2 2 2
right:   4 3 3 2 1 0

5
-1 1 0 -1 -1
2
0 0 1 2 2 2
4 3 3 2 1 0
 */

#include <bits/stdc++.h>

using namespace std;

// 方法2：依题意模拟
int main() { 
    int N;
    cin >> N;
    vector<int> nums(N);
    // int num;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        // nums.push_back(num); // 不确定输入数目时采用
    }

    // 核心处理
    vector<int> left(N+1, 0); // 分割方案数为数组数+1
    vector<int> right(N+1, 0);
    int res = INT_MAX, count = 0;
    for (int i = 0; i < N; ++i) {
        if (nums[i] >= 0) {
            ++count; // 分割点左面>=0的个数
        }
        left[i+1] = count; // left前缀数组整体右移
    }
    count = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (nums[i] <= 0) {
            ++count; // // 分割点右面<=0的个数
        }
        right[i] = count;
    }
    for (int i = 0; i <= N; ++i) {
        res = min(res, left[i]+right[i]);
    }
    cout << res << endl;

    // for (int i = 0; i <= N; ++i) {
    //     cout << left[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i <= N; ++i) {
    //     cout << right[i] << " ";
    // }
    return 0;
}

// // 方法1：前缀和 (思路不太容易想到)
// int main() { 
//     int N; // 纸袋上的数据
//     cin >> N;
//     vector<int> nums;
//     int sum = 0, num, mis = 0;
//     for (int i = 0; i < N; ++i) {
//         cin >> num;
//         if (num == 0) { // 0必然是异常点，统计0
//             ++mis;
//         } else {
//             nums.push_back(num); // 使用vector保存数组
//             sum += num; // 统计数组总和
//         }
//     }

//     int mis1 = INT_MAX;
//     int preSum = 0;
//     int n = nums.size();
//     for (int i = 0; i < n; ++i) {
//         int p1 = (i + preSum) / 2; // ?
//         int p2 = ((n - i) - (sum - preSum)) / 2; // ?
//         preSum += nums[i];
//         mis1 = min(mis1, p1 + p2);
//     }
//     mis1 = min(mis1, (n + preSum) / 2);
//     cout << mis1 + mis << endl;
//     return 0;
// }
// /**
//  * @brief 该实现还有bug 2022-08-06
//  * 
//  */