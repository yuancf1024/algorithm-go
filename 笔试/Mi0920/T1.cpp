/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-20
 * 
 * @copyright Copyright (c) 2022
 * 
 * 手机运行时长
 * 
时间限制： 3000MS
内存限制： 589824KB
题目描述：
米小兔新买了一台小米mix fold 2，
配备8英寸大屏，骁龙8+处理器和12G内存，
拥有强劲性能，后台可以轻松在同一时间运行多款App。

假设当后台没有App在运行时，手机进入休眠；
否则手机处于运行状态。

第i个App的开始运行时间starti，运行结束时间endi，
组成第i个App的运行区间
intervals[i] = [starti, endi]。

数组intervals表示今天米小兔的mix fold 2的
各个App的运行区间的集合，

求今天米小兔的手机运行了多长时间

输入描述
输入所有App的运行时间区间，

每行都是一个App运行区间starti和endi

输出描述
运行时间

样例输入
1 3
2 6
8 10
15 18
样例输出
10
 */

/*
AC 50%
*/

#include <bits/stdc++.h>

using namespace std;

bool cmp (vector<int>& a, vector<int>& b) {
  return a[0] < b[0];
}

int main() { 
    vector<vector<int>> nums;
    
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        vector<int> t(2);
        t[0] = a;
        t[1] = b;
        nums.push_back(t);
    }

    // 核心代码
    // int res = 0;
    // 排序
    sort(nums.begin(), nums.end(), cmp);
    int res= nums[0][1] - nums[0][0];
    for (int i = 1; i < nums.size(); ++i) {
        int tmp = nums[i][1] - nums[i][0];
        if (nums[i][0] < nums[i - 1][1] && nums[i][1] > nums[i-1][1]) {
            res += tmp + nums[i][0] - nums[i - 1][1];
        }
        if (nums[i][0] >= nums[i - 1][0] && nums[i][1] <= nums[i-1][1]) {
          continue;
        }
        if (nums[i][0] > nums[i-1][1]) {
          res += tmp;
        }
        if (nums[i][1] < nums[i-1][0]) {
          continue;
        }
        
    }
    cout << res << endl;

    // for (auto& x : nums) {
    //     for (auto& i : x) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}