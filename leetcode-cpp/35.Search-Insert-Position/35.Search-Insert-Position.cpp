/**
 * @file 35.Search-Insert-Position.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-09
 * 
 * @copyright Copyright (c) 2022
 * leetcode-35. 搜索插入位置
 * 
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

 

示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2
示例 2:

输入: nums = [1,3,5,6], target = 2
输出: 1
示例 3:

输入: nums = [1,3,5,6], target = 7
输出: 4
 

提示:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums 为 无重复元素 的 升序 排列数组
-104 <= target <= 104
 */


// // 在有序数组中找到最后一个比 target 小的元素
// // 这种方法不是特别好理解
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int res = 0;
//         // 按顺序插入位置，最后一个大于target的元素
//         int left = 0, right = nums.size() - 1;
//         while (left <= right) {
//             int middle = left + ((right - left) >> 1);
//             if (nums[middle] < target) {
//                 if (middle == nums.size()-1 || nums[middle+1] >= target) {
//                     res = middle+1;
//                 }
//                 left = middle + 1;
//             } else {
//                 right = middle - 1;
//             }
//         }
//         return res;
//     }
// };

// 参考代码随想录
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle;
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        // 目标值在数组所有元素之后的情况 [left, right]， 因为是右闭区间，所以 return right + 1
        return right + 1;
    }
};
