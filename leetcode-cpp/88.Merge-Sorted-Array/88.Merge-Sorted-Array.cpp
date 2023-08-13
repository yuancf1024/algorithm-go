/**
 * @file 88.Merge-Sorted-Array.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-88.Merge-Sorted-Array
 * @version 0.1
 * @date 2023-08-13
 * 
 * @copyright Copyright (c) 2023
 * 给你两个按 非递减顺序 排列的整数数组 nums1
 *  和 nums2，另有两个整数 m 和 n ，
 * 分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组
同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，
而是存储在数组 nums1 中。为了应对这种情况，
nums1 的初始长度为 m + n，其中前 m 个元素
表示应合并的元素，后 n 个元素为 0 ，应忽略。
nums2 的长度为 n 。

示例 1：

输入：nums1 = [1,2,3,0,0,0], m = 3, 
nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注
的为 nums1 中的元素。

示例 2：

输入：nums1 = [1], m = 1, 
nums2 = [], n = 0
输出：[1]
解释：需要合并 [1] 和 [] 。
合并结果是 [1] 。

示例 3：

输入：nums1 = [0], m = 0, 
nums2 = [1], n = 1
输出：[1]
解释：需要合并的数组是 [] 和 [1] 。
合并结果是 [1] 。
注意，因为 m = 0 ，所以 nums1 中没有元素。
nums1 中仅存的 0 仅仅是为了确保合并结果
可以顺利存放到 nums1 中。

提示：

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-10^9 <= nums1[i], nums2[j] <= 10^9
 

进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 大佬解法：从后面开始确定
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = nums1.size() - 1;
        m--;
        n--;
        while (n >= 0) {
            while (m >= 0 && nums1[m] > nums2[n]) {
                swap(nums1[i--], nums1[m--]);
            }
            swap(nums1[i--], nums2[n--]);
        }
    }

    // 太累了，想休息了，08-14再完成leetcode官方三种方法吧
};

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    Solution().merge(nums1, 3, nums2, 3);

    // 打印nums1
    for (auto& num : nums1) {
        cout << num << endl;
    }

    return 0;
}