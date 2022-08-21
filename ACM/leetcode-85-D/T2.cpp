#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int secondsToRemoveOccurrences(string s) { 
        return 1;
    }
};

int main() {
    // int res = 0;
    // int k;
    string s;

    // cin >> k;
    cin >> s;

    Solution solution;
    int res = solution.secondsToRemoveOccurrences(s);
    cout << res << endl;
    return 0;
}

/**
 * @brief 
 * 

Case1:
0110101

4

Case2:
11100

0
 */

/**
 * @brief 思路
 * 字符子串的替换，连续替换，直到满足没有"01"为止。
 * 那么肯定要递归呀
 * 
 * 特殊case的考虑，假如一开始没有"01"，那么直接输出0.
 */