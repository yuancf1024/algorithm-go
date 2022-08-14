#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        // map<int, int> mp;
        int n = edges.size();
        vector<long> nums(n, 0);

        int edgeScore = 0;
        long res = 0;
        for (int i = 0; i < n; ++i) {
            nums[edges[i]] += i;
        }
        res = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == res) {
                ans = i;
                break;
            }
        } return ans;
    }
};
/*
遍历一遍边数组edges，使用有序哈希表记录指向edges[i]节点的index之和，更新edgeScore;
最后返回edgeScore最大的节点index。
如果多个节点的 边积分 相同，返回编号 最小 的那个。
*/

int main() {
    vector<int> edges = {1, 0, 0, 0, 0, 7, 7, 5};
    Solution solution;
    int ans = solution.edgeScore(edges);
    cout << ans << endl;
    return 0;
}

/*
2022-08-14 2次罚时

没有考虑到nums[i] 和i的相加会导致int类型的溢出，
因此需要long定义nums 和 res
*/