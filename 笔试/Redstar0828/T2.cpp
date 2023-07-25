/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 法术
时间限制： 3000MS
内存限制： 589824KB
题目描述：
小明是一名魔法师，他会n种法术，
其中第i种法术的威力为ai，
他经常通过双手各自释放一种法术来提升威力，
能得到的威力值为双手各自释放的法术的威力的乘积，
但是他还不够强大，双手释放的两种法术必须是不同的，
即不能双手释放同一种法术。

这天他接到了一个任务，需要释放威力值至少为K才能完成，
他想请你帮他算一算，在两只手都释放法术的情况下，
共有多少方案能达到威力值K。
每种方案可记作（u，v），u≠v，
其威力值为au * av，
（u，v）和（v，u）会被视为不同的方案。

输入描述
第一行两个正整数n和K，表示法术数量和威力值需求。

第二行为n个正整数a1, a2,...... an，
其中ai表示第i个法术的威力为ai。

输出描述

输出威力值至少为K的方案数。

样例输入
3 3
3 2 1
样例输出
4

提示
1 ≤ n ≤30000, 1 ≤ K ≤ 10^16, 1 ≤ ai ≤10^9。
 */

/*
说明：
所有测试数据正确率为 82%！
可以尝试再次完善代码，并调试，争取全部AC通过
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, K;
    int t;
    vector<int> nums;

    cin >> n >> K;

    for (int i = 0; i < n; ++i) {
        cin >> t;
        nums.push_back(t);
    }

    // 核心代码
    int res = 0;
    int equal = 0;
    for (int i = 0; i < n; ++i) {
        // 加边界条件没有发挥到作用
        // if (n == 1 && nums[0] >= K) {
        //     res = 2;
        //     break;
        // }
        for (int j = i + 1; j < n; ++j) {
            if (nums[i]*nums[j] >= K) {
                res++;
            }
            // if (nums[i] == nums[j] && nums[i]*nums[j] >= K) {
            //     equal++;
            // }
        }
    }

    // cout << 2 * (res-equal) + equal << endl;
    cout << 2 * res << endl;

    // 测试输出
    // cout << n << " " << K;
    // for (int i = 0; i < n; ++i) {
    //     cout << nums[i] << " ";
    // }
    return 0;
}