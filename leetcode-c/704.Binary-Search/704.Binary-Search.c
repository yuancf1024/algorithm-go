/**
 * @file 704.Binary-Search.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
给定一个 n 个元素有序的（升序）整型数组 nums 
和一个目标值 target  ，写一个函数搜索 nums 中的
 target，如果目标值存在返回下标，否则返回 -1。

示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。
 */

#include <stdio.h>



// (版本一) 左闭右闭区间[left, right]
int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    int middle = 0;
    // 若left小于等于right，说明区间中元素不为0
    while (left <= right) {
        // 更新查找下表middle的值
        middle = (left + right) / 2;
        // 此时target可能会在[left, middle-1]区间中
        if (nums[middle] > target) {
            right = middle - 1;
        }
        // 此时target可能会在[middle+1, right]区间中
        else if (nums[middle] < target) {
            left = middle + 1;
        }
        // 当前下标元素等于target值时，返回middle
        else if (nums[middle] == target) {
            return middle;
        }
    }
    // 若未找到target元素，返回-1
    return -1;
}

// (版本二) 左闭右开区间[left, right)
int search_v2(int* nums, int numsSize, int target) {
    int length = numsSize;
    int left = 0;
    int right = length; // 定义target在左闭右开的区间里，即：[left, right)
    // int middle = 0;
    while (left < right) { // left == right时，区间[left, right)属于空集，所以用<避免该情况
        int middle = left + (right - left) / 2;
        if (nums[middle] < target) {
            // target位于(middle, right)中，为保证集合区间的左闭右开性，可等价为[middle+1, right)
            left = middle + 1;
        } else if (nums[middle] > target) {
            // target位于[left, middle)中
            right = middle;
        } else { // nums[middle] == target,找到目标值target
            return middle;
        }
    }
    // 未找到目标值，返回-1
    return -1;
}

int main() {
    int nums[10] = {-1,0,3,5,9,12};
    int target = 9;

    int res = search_v2(nums, 6, target); // C语言怎么求数组有效数字的长度？

    printf("%d\n", res);

    return 0;
}

/**
 * @brief 
 * 
 */