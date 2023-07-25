#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 
 * 
题目大意是给一个序列{a1, a2, ... , an}, 
每次可以给这个序列上所有的数加上一个xi，
问每次加完以后序列所有数的绝对值和是多少
我的思路是二分+前缀和。

代码如下，只能过20%，
不知道是哪里有问题，求各位大佬帮忙看看
ps：我图省事没用long long，
提交的代码里使用的是long long
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
    vector<int> vec(n);
    vector<int> pre(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    // 排序
    sort(vec.begin(), vec.end());

    // 前缀和
    for (int i = 0; i < n; ++i) {
        pre[i + 1] += pre[i] + vec[i];
    }

    // 有bug待寻找
    int q;
    cin >> q;
    int his = 0;
    while (q--) {
        int xi = 0;
        cin >> xi;
        his += xi;
        auto pos = lower_bound(vec.begin(), vec.end(), -his) - vec.begin();
        int lp = pos;
        int rp = n - pos;
        int cursum = pre[pos] * -1 - lp * his + pre[n] - pre[pos] + his * rp;
        cout << cursum << endl;
    }
    return 0;
}