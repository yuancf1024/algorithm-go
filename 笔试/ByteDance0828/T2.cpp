/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-08-28
 *
 * @copyright Copyright (c) 2022
 *
 * 数字乘积
 * 有n个元素的数组，元素由[0,1,2,4,8,16,32,64,128,256,512,1024]组成；
 * 现在想从数组中选择一段连续的区间，得到尽可能大的乘积；
 *
 * 输入描述：
 * 第一行t(1<=t<=100)，表示接下来有t个样例；
 * 每个样例有2行；
 * 第一行是整数n，表示数组长度；(1<=n<=10000)
 * 第二行是n个整数，整数取值为[0,1,2,4,8,16,32,64,128,256,512,1024];
 *
 * 输出描述：
 * 每个样例一行，输出整数x和y，表示乘积最大区间[x,y];
 * 如果有多个答案，输出x尽可能小的答案；
 * 如果仍有多个答案，输出y尽可能小的答案。
 *
 */

/*
TestCase:
2
5
1 2 4 0 8
7
1 2 4 8 0 256 0

1 3
6 6

*/

/*
哭死，为什么给的测试样例通过，提交后却通过0%


*/

#include <bits/stdc++.h>

using namespace std;



int main() {
    int t;
    cin >> t;
    while (t > 0) {
        t--;
        // 读取数组
        int l;
        cin >> l;
        vector<int> nums;
        int temp;
        vector<int> zeros; // 记录0的下标
        vector<int> ones; // 记录1的下标
        for (int i = 0; i < l; ++i) {
            cin >> temp;
            if (temp == 0) {
                zeros.push_back(i);
            }
            if (temp == 1) {
                ones.push_back(i);
            }
            nums.push_back(temp);
        }

        // 核心代码

        // 考虑及其特殊的情况
        // 全为0
        if (zeros.size() == l) {
            cout << 1 << " " << 1 << endl;
            continue;
        }
        if (ones.size() == l) {
            cout << 1 << " " << 1 << endl;
            continue;
        }

            int left = 0, right = 0;
        // int maxProduct = 1;
        int maxM = 1;
        int tempT = 0;
        vector <pair<int, int>> pair;

        for (int i = 0; i < zeros.size(); ++i) {
            int maxProduct = 1;
            for (int j = tempT+0; j < zeros[i]; ++j) {
                maxProduct *= nums[j];
            }
            
            if (maxProduct > maxM) {
                left = tempT+1;
                // 增加该区间末尾段有1的回退操作
                int a = zeros[i] - 1;
                while (nums[a]<=1) {
                    a--;
                }
                right = a+1;
                maxM = maxProduct;
            }
            if (nums[tempT] > maxM) {
                left = tempT + 1;
                right = tempT + 1;
                maxM = nums[tempT];
            }
            tempT += zeros[i]+1;
        }
        cout << left << " " << right << endl;
    }

    return 0;
}

