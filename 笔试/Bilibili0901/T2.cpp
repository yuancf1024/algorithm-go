#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 
 * 第一行数字n，代表数组n个元素
 * 第二行n个数字，代表数组元素值
 * 第三行Q，代表变换次数
 * 第四行Q个数字，代表每次变换数组所有元素增加的值(注意是累加)
 * 返回每次累加的结果的绝对值
 * 
 * 题目大意是给一个序列{a1, a2, ... , an}, 
 * 每次可以给这个序列上所有的数加上一个xi，
 * 问每次加完以后序列所有数的绝对值和是多少
 */

/*
pass 66.7%

有牛友说要改成long long
可是我就是long long

这题我考虑得还不够周到，因为最终返回的是累加结果的绝对值
所以数组元素要分正负处理


*/

/*
TestCase1:
5
1 2 3 4 5
3
3 2 1

30
40
45

TestCase2:
5
1 1 1 1 1
3
-3 -2 -1

10
20
25
*/

int main() {
    int n;
    cin >> n;
    vector<long> nums;
    long t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        nums.push_back(t);
    }

    int Q;
    cin >> Q;

    vector<long> x;
    long temp;
    for (int i = 0; i < Q; ++i) {
        cin >> temp;
        x.push_back(temp);
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
    }
    // long long a=0;
    for (int i = 0; i < Q; ++i) {
        sum += x[i] * n;
        cout << abs(sum) << endl;
    }
    return 0;
}