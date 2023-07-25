/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 典型的贪心
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 最少要分发多少颗苹果？
     * @param scores int整型vector 得分
     * @return int整型
     */
    int apple(vector<int>& scores) {
        // write code here
        /*
        思路：贪心
        从左到右遍历，
        从右到左遍历，然后取max
        */
        int ans = 0;
        int n = scores.size();
        vector<int> nums(n,1);
        // int num = 1;
        // 考虑边界Case
        if (scores.size() == 1) {
            return 1;
        }

        for (int i = 1; i < scores.size(); ++i) {
            if (scores[i] > scores[i-1]) {
                nums[i] = nums[i - 1] + 1;
            }
        }

        for (int i = n - 1; i >= 1; --i) {
            if (scores[i] > scores[i-1]) {
                nums[i] = max(nums[i], nums[i - 1] + 1);
            }
        }

        for (int i = 0; i < n; ++i) {
            ans += nums[i];
        }
            // for (int i = 0)
            return ans;
    }
};


int main() {
    // vector<int> scores = {1, 2, 2};
    vector<int> scores = {1, 2, 1, 2,1};

    Solution s;
    int res = s.apple(scores);

    cout << res << endl;

    return 0;
}