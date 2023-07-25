/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-04
 * 
 * @copyright Copyright (c) 2022
 * 小红的整数操作 15分 
 * 
 * 小红拿到了一个数组，她每次可以进行如下操作：
 * 任选一个数，使其加k。
 * 小红可以进行任意次这样的操作。
 * 她想知道，最终数组有多少个数相同？
 * 
输入描述：
第一行n k 分别代表数组的长度、每次相加的值
第二行输入n个正整数ai
1<=n<=10^5
1<=k, ai<=10^9

输出描述
最终相同数的数量最大值

Test：

5 2
1 4 2 3 5

3


 */

/*
用例通过率9.09% 
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // 核心代码
    int res = 0;
    // 先排序
    sort(nums.begin(), nums.end());

    // 暴力枚举
    for (int i = 0; i < n; ++i) {
        int num = 0;
        for (int j = 0; j < n - i; ++j) {
            long long t = nums[0];
            if ((nums[n-1-j] - t)%k == 0) {
                num++;
            }
//             while (t < nums[n - 1 - i]) {
//                 t += k;
//                 if (t == nums[n-1-i]) {
//                     num++;
//                 }
//             }
        res = max(res, num);
        } 
    }
    cout << res << endl;
    return 0;
}