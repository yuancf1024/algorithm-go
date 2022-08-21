#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minimumRecolors(string blocks, int k) { 
        // return 1; 

    }
};

int main() {
    // int res = 0;
    int k;
    string blocks;

    cin >> k;
    cin >> blocks;

    Solution solution;
    int res = solution.minimumRecolors(blocks, k);
    cout << res << endl;
    return 0;
}

/**
 * @brief 
 *
Case1:
7
WBBWWBBWBW

3

case2:
2
WBWBBBW

0
 */

/*
思路：

既然要求最少，那么肯定是贪心。😂

关键是怎么贪心呢？

求最长连续子串，可以遍历一次得到。

关键是怎么确定修改次数最少的涂色方案。

首先获得blocks中最长的连续黑色子块长度l，
如果l>=k，那么返回0；
如果l<k，那么开始操作；


*/