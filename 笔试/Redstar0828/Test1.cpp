/**
 * @file Test1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 求数列的和
 * 求数列的和

（编程题须知）（参考答案）

时间限制： 4000MS
内存限制： 557056KB
题目描述：
数列的定义如下： 数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。



输入描述
输入数据有多组，每组占一行，由两个整数n（n<10000）和m(m<1000)组成，n和m的含义如前所述。

输出描述
对于每组输入数据，输出该数列的和，每个测试实例占一行，要求精度保留2位小数。


样例输入
81 4
2 2

样例输出
94.73
3.41

 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;

    while (~scanf("%d %d", &n, &m)) { // 本题的类型是不确定有多少组输入
        vector<float> nums;
        nums.push_back(n);
        float sum = n;
        for (int i = 1; i < m; ++i) {
            float temp = sqrt(nums[i - 1]);
            nums.push_back(temp);
            sum += nums[i];
        }
        
        // for (int i = 0; i < m; ++i) {
        //     sum += nums[i];
        // }
        // cout << sum << endl;
        printf("%.2f\n", sum);
    }
    return 0;
}