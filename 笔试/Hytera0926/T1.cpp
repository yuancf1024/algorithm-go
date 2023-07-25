/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-26
 * 
 * @copyright Copyright (c) 2022
 * 
 * 基础编程 20分
 * 
有1，2，3，4四个数字，能组成多少个互不相同且无重复数字
的三位数？编写一个程序，使用循环生成所有三位数，
并从大到小打印出来。



 */


/*
AC 通过全部用例
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums;
    int t = 0;
    for (int i = 4; i > 0; --i) {
        for (int j = 4; j > 0; --j) {
            for (int k = 4; k > 0; --k) {
                if (i == j || i == k || j == k ) {
                    continue;
                }
                t = i * 100 + j * 10 + k;
                nums.push_back(t);
            }
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (i == nums.size()-1) {
            cout << nums[i] << endl;
            break;
        }
        cout << nums[i] << " ";
    }
    return 0;
}