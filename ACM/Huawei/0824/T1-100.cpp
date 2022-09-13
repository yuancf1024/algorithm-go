/**
 * @file T1-100.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 * 1、分配捐款
某村共有m个村民，所有村民的资产均不相同，村长收到笔n元的捐款，
村长计划把该捐款分给民，使尽可能多的村民拥有相同的资产，
剩余的捐款将保留做为集体资产。
请帮村长分配捐款，使得在最多村民刚好拥有相同资产的前提下，
并剩余尽可能少的捐款，如果某村民不能通过分配捐款拥有相同资产，则不予分配，
如三个村民的资产是10，3，1，待分配捐款为8,则分配结果为10,10,1，
剩余1的捐款无法使第3个村民的资产达到10,所以不子分配。

解答要求:
时间限制C/C++1000ms,其他语言: 2000ms
内存限制C/C++ 256MB,其他语言: 512MB

输入:
第一行:村民数目m
第二行:大小为m的数组a,表示第1~m个村民的资产金额，以空格分隔，
数组a的所有元素均不相同
第三行:捐款数目n
2<=m<=10000
1<=n<= 100000000
0<=a[i]<= 1000000

用例的输入保证是合法的，数组a的数据个数一定是m个，
a[i]代表的是数组a的一个成员

输出:
返回拥有相同资产的村民数以及剩余捐款数，以空格分隔。

样例1:

输入:
5
2 9 3 1 6
4
输出:
3 1
解释:分配后的结果为3 9 3 3 6

样例2:
输入:
3
5 1 20
2

输出:
1 2
解释:捐款无法使任何村民拥有相同的资产，
所有捐款保留为集体资产，拥有相同资产村民的数目为1.

 */

/*
思路：
以下实现含有bug
无法通过样例2
- 不能处理极端case，捐款无法使任何村民拥有相同的资产

可以引入一个计数器解决，如果计数器为0，
则
cout << 1 << " " << n << endl;

*/

#include <bits/stdc++.h>

using namespace std;

int main() { 
    int m;
    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    int n;
    cin >> n;

    // 核心代码
    int people_max = 0;
    sort(a.begin(), a.end());

    for (int i = 0; i < m - 1; ++i) {
        int money_count = n;
        int people_num = 0;
        int standard = a[i]; // 选择当前村民基准
        for (int j = i; j >= 0;j--) { // 基准往左走
            if (money_count > (standard-a[j])) { // 可以发的钱可以弥补钱少的村民合基准的差距，距离最近发的最少
                money_count -= (standard - a[j]);
            } else { // 不够就跳出
                break;
            }
            people_num++; // 多一个村民够基准
        }
        people_max = max(people_max, people_num);
    }
    cout << people_max << " " << n % people_max << endl;
    return 0;
}