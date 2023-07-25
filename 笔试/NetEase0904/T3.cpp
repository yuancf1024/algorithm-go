/**
 * @file T3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 小红的数组操作 30分
 * 
 * 小红拿到了一个数组，她每次可以进行如下操作：
 * 选择一个数，使其减去x。
 * 小红希望k次操作之后，该数组的最大值尽可能小。
 * 
输入描述：
第一行输入三个正整数n,k,x,
代表数组长度，操作次数以及每次操作减的数
第二行输入n个正整数ai，代表小红拿到的数组。
1<=n<=10^5
1<=ai,k,x<=10^9

输出描述：
一个整数，代表k次操作后，数组尽可能小的最大值

示例1：

5 3 5
4 3 11 2 1

3

 */

/*
测试案例通过


提交通过0%
😂
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long k, x;
    cin >> n >> k >> x;
    vector<long long> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // 核心代码
    // 数组排序
    sort(nums.begin(), nums.end());

    for (int i = n - 1; i >= 1; --i) {
        while (nums[i] > nums[i-1]) {
            nums[i] -= x;
            k--;
            if (k == 0) {
                break;
            }
        }
        if (k == 0) {
                break;
        }
    }
    cout << *max_element(nums.begin(), nums.end()) << endl;
    return 0;
}