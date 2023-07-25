#include <bits/stdc++.h>

using namespace std;

/*
样例1：
2 2 1
2

4

样例2：
1 3 2
1 3

1

*/

/*
思路：DP
先不考虑空木板
直接回溯
*/
class Solution {
    vector <vector<int>> res;
    vector<int> path;
    vector<int> A = {1, 2, 3};
public:
    int calSum(vector<int>& a) {
        int sum = 0;
        for (auto& x : a) {
            sum += x;
        }
        return sum;
    }
    // 辅函数
    void backtracking(vector<int>& nums, int N, int M, int k) {
        if (calSum(path) == N+1 && M > 0) {
            res.push_back(path);
            return;
        }
        if (k > N) {
            return;
        }

        for (int i = 0; i < A.size(); ++i) {
            path.push_back(A[i]);
            if (nums[k] == 1) {
                M--;
            }
            backtracking(nums, N, M, k+1);
            path.pop_back();
        }
    }
    int getAll(vector<int>& nums, int N, int M) { 
        res.clear();
        path.clear();
        // vector<bool> used(nums.size())
        backtracking(nums, N, M, 0);
        return res.size();
    }
};

int main() { 
    // 读取数据
    int M, N, K; // 生命 长度 缺失木板
    cin >> M >> N >> K;
    vector<int> nums(N+1); // 缺失木板
    for (int i = 0; i < K;++i) {
        int t;
        cin >> t;
        nums[t] = 1; // 第t块木板空缺
    }

    // 核心代码
    // vector<int> dp(N + 1);
    // int res = 0;
    // for (int i = 3; i <= N + 1; ++i) {

    // }
    Solution s;
    int res = s.getAll(nums, N, M);
    cout << res << endl;
    return 0;
}