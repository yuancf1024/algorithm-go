/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 * 情报
时间限制： 3000MS
内存限制： 589824KB
题目描述：
定义函数f(x)表示 x 在二进制表示下 1 的个数。
例如，9的二进制表示为1001，则f(9)=2。

一个特工获取了一个重要情报，
这个情报为一个非负整数x。
他在传递情报的时候对这个数进行了处理，
他将这个整数x乘上f(x) 后再发送出去。
现在你得到了这份情报，你想知道处理前的数可能为多少？

输入描述
输入一个非负整数y，表示处理后的数。

0 ≤ y ≤ 10^18，数据保证处理前的数
至少存在一种可能的取值。

输出描述
第一行输出一个整数 n，表示处理前的数
所有可能取值的个数。

第二行输出 n 个整数，表示 x 可能的取值。
这些数按递增顺序输出，相邻两个数用空格隔开。


样例输入
54054

样例输出
3
6006 7722 9009

提示
6006二进制表示含有9个1，
处理后为6006 * 9 = 54054。

7722二进制表示含有7个1，
处理后为7722 * 7 = 54054。

9009二进制表示含有6个1，
处理后为9009 * 6 = 54054。

其它的数均不可能通过上述处理得到54054。
 */

/*
第一次只能过 64% 显示超时
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int f(ll x) {
    int num = 0, t;
    // 计算整数x含有1的个数
    while (x != 0) {
        t = x % 2;
        x = x / 2;
        if (t == 1) {
            num++;
        }
    }
    return num;
}

int main() { 
    ll n;
    cin >> n;

    // 核心代码
    // cout << f(n) << endl;
    vector<ll> nums;
    for (ll i = 1; i < n; ++i) {
        if (i * f(i) == n) {
            nums.push_back(i);
        }
        // i *= 2;
    }
    cout << nums.size() << endl;
    for (auto& x : nums) {
        cout << x << " ";
    }
    return 0;
}