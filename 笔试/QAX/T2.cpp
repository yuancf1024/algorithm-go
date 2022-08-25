#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    // // 这种读取数据 [4,1,2,7] 格式会有潜在bug,无法正常读取2位数字
    // vector<int> nums;
    // string s;
    // cin >> s;
    // for (int i = 0; i < s.size(); ++i) {
    //     if (i % 2 == 1) {
    //         nums.push_back(int(s[i]-'0'));
    //     } 
    // } 

    // [4,1,2,7]
    vector<int> nums;
    int temp;
    char c;
    cin >> c; // 读取无用字符'['
    while (cin >> temp) {
        nums.push_back(temp);
        cin >> c; // 读取 ','
        if (c == ']') {
            break;
        }
    }

    // int res = 0;

    // 核心函数
    // int W = 0, L = 0;
    int n = nums.size();
    int area = 0;
    // int temp = 0;
    // 暴力搜索 计算任意两点组成的面积 更新max
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            area = max(area, (j - i) * (min(nums[i], nums[j])));
        }
    }

        // 打印nums
        // for (auto& n : nums) {
        //     cout << n << endl;
        // }

    cout << area << endl;

    return 0; 
}
// 64 位输出请用 printf("%lld")

/*
TestCase1
[4,1,2,7]
0 1 2 3 4 5 6 7

12

*/