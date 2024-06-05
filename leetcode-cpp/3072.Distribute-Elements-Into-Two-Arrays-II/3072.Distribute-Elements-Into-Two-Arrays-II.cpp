/**
 * @file 3072.Distribute-Elements-Into-Two-Arrays-II.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-3072.将元素分配到两个数组中II
 * @version 0.1
 * @date 2024-06-05
 * 
 * @copyright Copyright (c) 2024
 * 给你一个下标从 1 开始、长度为 n 的整数数组 nums 。

现定义函数 greaterCount ，使得 greaterCount(arr, val) 返回数组 arr 中 严格大于 val 的元素数量。

你需要使用 n 次操作，将 nums 的所有元素分配到两个数组 arr1 和 arr2 中。
在第一次操作中，将 nums[1] 追加到 arr1 。在第二次操作中，将 nums[2] 追加到 arr2 。
之后，在第 i 次操作中：
- 如果 greaterCount(arr1, nums[i]) > greaterCount(arr2, nums[i]) ，将 nums[i] 追加到 arr1 。
- 如果 greaterCount(arr1, nums[i]) < greaterCount(arr2, nums[i]) ，将 nums[i] 追加到 arr2 。
- 如果 greaterCount(arr1, nums[i]) == greaterCount(arr2, nums[i]) ，将 nums[i] 追加到元素数量较少的数组中。
- 如果仍然相等，那么将 nums[i] 追加到 arr1 。
连接数组 arr1 和 arr2 形成数组 result 。例如，如果 arr1 == [1,2,3] 且 arr2 == [4,5,6] ，那么 result = [1,2,3,4,5,6] 。

返回整数数组 result 。

示例 1：
输入：nums = [2,1,3,3]
输出：[2,3,1,3]
解释：在前两次操作后，arr1 = [2] ，arr2 = [1] 。
在第 3 次操作中，两个数组中大于 3 的元素数量都是零，并且长度相等，因此，将 nums[3] 追加到 arr1 。
在第 4 次操作中，两个数组中大于 3 的元素数量都是零，但 arr2 的长度较小，因此，将 nums[4] 追加到 arr2 。
在 4 次操作后，arr1 = [2,3] ，arr2 = [1,3] 。
因此，连接形成的数组 result 是 [2,3,1,3] 。

示例 2：
输入：nums = [5,14,3,1,2]
输出：[5,3,1,2,14]
解释：在前两次操作后，arr1 = [5] ，arr2 = [14] 。
在第 3 次操作中，两个数组中大于 3 的元素数量都是一，并且长度相等，因此，将 nums[3] 追加到 arr1 。
在第 4 次操作中，arr1 中大于 1 的元素数量大于 arr2 中的数量（2 > 1），因此，将 nums[4] 追加到 arr1 。
在第 5 次操作中，arr1 中大于 2 的元素数量大于 arr2 中的数量（2 > 1），因此，将 nums[5] 追加到 arr1 。
在 5 次操作后，arr1 = [5,3,1,2] ，arr2 = [14] 。
因此，连接形成的数组 result 是 [5,3,1,2,14] 。

示例 3：
输入：nums = [3,3,3,3]
输出：[3,3,3,3]
解释：在 4 次操作后，arr1 = [3,3] ，arr2 = [3,3] 。
因此，连接形成的数组 result 是 [3,3,3,3] 。
 

提示：

3 <= n <= 10^5
1 <= nums[i] <= 10^9
 */

#include <bits/stdc++.h>

using namespace std;

class Fenwick {
    vector<int> tree;

public:
    Fenwick(int n) : tree(n) {}

    // 把下标为 i 的元素增加1
    void add(int i) {
        while (i < tree.size()) {
            tree[i]++;
            i += i & -i;
        }
    }

    // 返回下标在 [1,i] 的元素之和
    int pre(int i) {
        int res = 0;
        while (i > 0) {
            res += tree[i];
            i &= i - 1;
        }
        return res;
    }
};

class Solution {
public:
    // 写法1: 两棵树状数组
    vector<int> resultArray(vector<int>& nums) {
        auto sorted = nums;
        ranges::sort(sorted);
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();

        vector<int> a{nums[0]}, b{nums[1]};
        Fenwick t1(m + 1), t2(m + 1);
        t1.add(ranges::lower_bound(sorted, nums[0]) - sorted.begin() + 1);
        t2.add(ranges::lower_bound(sorted, nums[1]) - sorted.begin() + 1);
        for (int i = 2; i < nums.size(); i++) {
            int x = nums[i];
            int v = ranges::lower_bound(sorted, x) - sorted.begin() + 1;
            int gc1 = a.size() - t1.pre(v); // greaterCount(a, v)
            int gc2 = b.size() - t2.pre(v); // greaterCount(b, v)
            if (gc1 > gc2 || gc1 == gc2 && a.size() <= b.size()) {
                a.push_back(x);
                t1.add(v);
            } else {
                b.push_back(x);
                t2.add(v);
            }
        }
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};

int main() {
    vector<int> nums = {2,1,3,3};
    vector<int> res = Solution().resultArray(nums);

    for (auto x : res) {
        cout << x << endl;
    }

    return 0;
}

/**
 * @brief 参考大佬@灵茶山艾府 树状数组
 * 将元素离散化成[1,m]中的元素，其中m为nums中的不同元素个数。
这可以对nums排序去重后，在数组中二分查找得到。

记arr1为a，记arr2为b。用两棵树状数组分别维护a和b中的每个元素的出现次数，
即可快速计算 greaterCount。
然后按照题目要求模拟即可。

写法一：两棵树状数组

写法二：一棵树状数组
把元素 vvv 添加到 t2\textit{t}_2t 
2
​
  的操作，可以改成把元素 vvv 在 t1\textit{t}_1t 
1
​
  中的出现次数减一。

也就是说，用一棵树状数组维护 aaa 和 bbb 元素出现次数的差值。

同时，为了方便调用 pre\texttt{pre}pre，离散化的 vvv 改成 m−jm-jm−j，其中 jjj 是二分的下标。这样问题就转换成了求小于 vvv 的元素个数（之差）。

复杂度分析
时间复杂度：O(nlog⁡n)\mathcal{O}(n\log n)O(nlogn)，其中 nnn 为 nums\textit{nums}nums 的长度。
空间复杂度：O(n)\mathcal{O}(n)O(n)。


 */