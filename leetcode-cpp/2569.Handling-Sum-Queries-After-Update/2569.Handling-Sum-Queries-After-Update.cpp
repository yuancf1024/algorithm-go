/**
 * @file 2569.Handling-Sum-Queries-After-Update.cpp
 * @author your name (you@domain.com)
 * @brief 2569.更新数组后处理求和查询
 * @version 0.1
 * @date 2023-07-26
 * 
 * @copyright Copyright (c) 2023
 * 给你两个下标从 0 开始的数组 nums1 和 nums2，
和一个二维数组 queries 表示一些操作。
总共有 3 种类型的操作：

操作类型 1 为 queries[i] = [1, l, r] 。
你需要将 nums1 从下标 l 到下标 r 的所有 0 
反转成 1 或将 1 反转成 0 。l 和 r 下标都
从 0 开始。

操作类型 2 为 queries[i] = [2, p, 0] 。
对于 0 <= i < n 中的所有下标，
令 nums2[i] = nums2[i] + nums1[i] * p 。

操作类型 3 为 queries[i] = [3, 0, 0] 。
求 nums2 中所有元素的和。

请你返回一个数组，包含所有第三种操作类型的答案。

 

示例 1：
输入：nums1 = [1,0,1], nums2 = [0,0,0], 
queries = [[1,1,1],[2,1,0],[3,0,0]]
输出：[3]
解释：第一个操作后 nums1 变为 [1,1,1] 。
第二个操作后，nums2 变成 [1,1,1] ，
所以第三个操作的答案为 3 。所以返回 [3] 。

示例 2：

输入：nums1 = [1], nums2 = [5], 
queries = [[2,0,0],[3,0,0]]
输出：[5]
解释：第一个操作后，nums2 保持不变为 [5] ，
所以第二个操作的答案是 5 。所以返回 [5] 。
 

提示：

1 <= nums1.length,nums2.length <= 10^5
nums1.length = nums2.length
1 <= queries.length <= 10^5
queries[i].length = 3
0 <= l <= r <= nums1.length - 1
0 <= p <= 10^6
0 <= nums1[i] <= 1
0 <= nums2[i] <= 10^9

 */

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

struct SegNode {
    int l, r, sum;
    bool lazytag;
    SegNode() {
        this->l = 0;
        this->r = 0;
        this->sum = 0;
        this->lazytag = false;
    }
};

class SegTree {
private:
    vector<SegNode> arr;

public:
    SegTree(vector<int>& nums) {
        int n = nums.size();
        arr = vector<SegNode> (n * 4 + 1);
        build(1, 0, n - 1, nums);
    }

    int sumRange(int left, int right) {
        return query(1, left, right);
    }

    void reverseRange(int left, int right) {
        modify(1, left, right);
    }

    void build(int id, int l, int r, const vector<int>& nums) {
        arr[id].l = l;
        arr[id].r = r;
        arr[id].lazytag = false;
        if (l == r) {
            arr[id].sum = nums[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * id, l, mid, nums);
        build(2 * id + 1, mid + 1, r, nums);
        arr[id].sum = arr[2 * id].sum + arr[2 * id + 1].sum;
    }

    // pushdown函数：下传懒标记，即将当前区间的修改
    // 情况下传到其左右孩子节点
    void pushdown(int x) {
        if (arr[x].lazytag) {
            arr[2 * x].lazytag = !arr[2 * x].lazytag;
            arr[2 * x].sum = arr[2 * x].r - arr[2 * x].l + 1 - arr[2 * x].sum;
            arr[2 * x + 1].lazytag = !arr[2 * x + 1].lazytag;
            arr[2 * x + 1].sum = arr[2 * x + 1].r - arr[2 * x + 1].l + 1 - arr[2 * x + 1].sum;
            arr[x].lazytag = false;
        }
    }

    // 区间修改
    void modify(int id, int l, int r) {
        if (arr[id].l >= l && arr[id].r <= r) {
            arr[id].sum = (arr[id].r - arr[id].l + 1) - arr[id].sum;
            arr[id].lazytag = !arr[id].lazytag;
            return;
        }
        pushdown(id);
        int mid = (arr[id].l + arr[id].r) >> 1;
        if (arr[2 * id].r >= l) {
            modify(2 * id, l, r);
        }
        if (arr[2 * id + 1].l <= r) {
            modify(2 * id + 1, l, r);
        }
        arr[id].sum = arr[2 * id].sum + arr[2 * id + 1].sum;
    }

    // 区间查询
    int query(int id, int l, int r) {
        if (arr[id].l >= l && arr[id].r <= r) {
            return arr[id].sum;
        }
        if (arr[id].r < l || arr[id].l > r) {
            return 0;
        }
        pushdown(id);
        int res = 0;
        if (arr[2 * id].r >= l) {
            res += query(2 * id, l , r);
        }
        if (arr[2 * id + 1].l <= r) {
            res += query(2 * id + 1, l ,r);
        }
        return res;
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        int m = queries.size();
        SegTree tree(nums1);

        long long sum = accumulate(nums2.begin(), nums2.end(), 0LL);
        vector<long long> ans;
        for (int i = 0; i < m; ++i) {
            if (queries[i][0] == 1) {
                int l = queries[i][1];
                int r = queries[i][2];
                tree.reverseRange(l, r);
            } else if (queries[i][0] == 2) {
                sum += (long long) tree.sumRange(0, n-1) * queries[i][1];
            } else if (queries[i][0] == 3) {
                ans.emplace_back(sum);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 0, 1};
    vector<int> nums2 = {0, 0, 0};
    vector<vector<int>> queries = {{1,1,1},{2,1,0},{3,0,0}};

    vector<long long> res = Solution().handleQuery(nums1, nums2, queries);

    for (auto &x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

/**
 * @brief 
 * 线段树是一个稍微复杂的数据结构，可以参考洛谷文章和
 halfrost神的文章一起整理一篇技术文章。
 */