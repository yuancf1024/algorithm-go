/**
 * @file 31.Next-Permutation.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * leetcode-31.下一个排列
 * 
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：
[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。
更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，
那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。
如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列
（即，其元素按升序排列）。

- 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
- 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
- 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，
因为 [3,2,1] 不存在一个字典序更大的排列。

给你一个整数数组 nums ，找出 nums 的下一个排列。

必须 原地 修改，只允许使用额外常数空间。

示例 1：
输入：nums = [1,2,3]
输出：[1,3,2]

示例 2：
输入：nums = [3,2,1]
输出：[1,2,3]

示例 3：
输入：nums = [1,1,5]
输出：[1,5,1]
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 100

 */

// 模拟
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = nums.size() - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[j], nums[i]);
                    reverse(nums.begin() + i + 1, nums.end()); // 后面是降序的，反转一下即可成为升序
                    return;
                }
            }
        }
        // 到了到这里了说明整个数组都是倒序的，翻转一下即可
        reverse(nums.begin(), nums.end());
    }
};

/**
 * @brief 
 * 思路
一些同学可能手动写排列的顺序，都没有写对，
那么写程序的话思路一定是有问题的了，我这里以1234为例子，
把全排列都列出来。可以参考一下规律所在：

1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
如图：

以求1243为例，流程如图：

数组1243  
          1  2  4  3
             i     j

从后向前遍历，发现nums[j]>nums[i]，进行交换

          1  3  4  2
             i     j

对i+1到数据结束的区间进行排序

          1  3  2  4
             i     j

所得即为1243的下一个排列

对应的C++代码如下：
 */