#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) { 
        // return "1"; 
    }
};

int main() {
    // int res = 0;
    // int k;
    string s;
    vector<vector<int>> shifts;

    // cin >> k;
    cin >> s;

    Solution solution;
    string res = solution.shiftingLetters(s, shifts);
    cout << res << endl;
    return 0;
}

/*
Case1:
abc
0,1,0
1,2,1
0,2,1

zac
zbd
ace

Case2:
dztz
0,0,0
1,1,1

cztz
catz
*/

/**
 * @brief 思路
 * 
 * leetcode竞赛也太难啦😂
 * 
 */