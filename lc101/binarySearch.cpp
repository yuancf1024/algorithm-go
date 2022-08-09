// 二分法第一种写法 左闭右闭即[left, right]
// 版本1
class Solution {
public:
    int search(vector<int>& nums, int target) { 
        int left = 0;
        int right = nums.size() - 1;
        // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) {
            // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle - 1; // // target在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // // target在右区间，所以[middle + 1, right]
            } else {
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        return -1; // 未找到目标值
    }
};


// 二分法第二种写法 左闭右开即[left, right)
// 版本2
class Solution {
public:
    int search(vector<int>& nums, int target) { 
        int left = 0;
        int right = nums.size(); // 注意此处和版本1的区别
        // 定义target在左闭右开的区间里，即：[left, right)
        while (left < right) { // // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，在[left, middle)中
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在[middle + 1, right)中
            } else {
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        return -1; // 未找到目标值
    }
};

/**
 * @brief 二分的几种变形
 * 
1. 查找第一个值等于给定值的元素
2. 查找最后一个值等于给定值的元素
3. 查找第一个大于等于给定值的元素
4. 查找最后一个小于等于给定值的元素 leetcode-35 搜索插入位置
 */

// 1. 查找第一个值等于给定值的元素
// 二分查找第一个与target相等的元素，时间复杂度O(logn)


// 2. 查找最后一个值等于给定值的元素

// 3. 查找第一个大于等于给定值的元素

// 4. 查找最后一个小于等于给定值的元素 
// leetcode-35 搜索插入位置

