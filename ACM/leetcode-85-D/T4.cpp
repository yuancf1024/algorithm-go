#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        
    }
};

int main() {
    // int res = 0;
    // int k;
    // string s;

    // cin >> k;
    // cin >> s;

    vector<int> nums;
    vector<int> removeQueries;

    Solution solution;
    vector<long long> res = solution.maximumSegmentSum(nums, removeQueries);
    // cout << res << endl; // 遍历输出vector
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}

/*
Case1:
1,2,5,6,1
0,3,2,4,1

14,7,2,2,0

Case2:
3,2,11,1
3,2,1,0

16,5,3,0

*/

/**
 * @brief 思路
 * 
 * 这就是Hard难度吗？爱了爱了😂
 * 
 */