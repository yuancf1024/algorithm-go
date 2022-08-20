/**
 * @file 503.Next-Greater-Element-II.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * leetcode-503.下一个更大元素 II
给定一个循环数组 nums （ nums[nums.length - 1] 
的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。

数字 x 的 下一个更大的元素 是按数组遍历顺序，
这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的
下一个更大的数。如果不存在，则输出 -1 。

示例 1:

输入: nums = [1,2,1]

输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。

示例 2:
输入: nums = [1,2,3,4,3]
输出: [2,3,4,-1,4]

提示:

1 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
 */

// 单调栈 版本一 直观
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 拼接一个新的nums
        vector<int> nums1(nums.begin(), nums.end());
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        // 用新的nums大小来初始化res
        vector<int> res(nums.size(), -1);
        if (nums.size() == 0) {
            return res;
        }

        // 开始单调栈
        stack<int> st;
        for (int i = 0; i < nums.size(); ++i) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                res[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        // 最后再把结果集即res数组resize到原数组大小
        res.resize(nums.size() / 2);
        return res;
    }
};

// 单调栈 版本二 更高雄安高效
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        if (nums.size() == 0) {
            return res;
        }
        stack<int> st;
        for (int i = 0; i < nums.size() * 2; ++i) {
            // 模拟遍历两边nums，注意一下都是i % nums.size()来操作
            while (!st.empty() &&nums[i % nums.size()] > nums[st.top()]) {
                res[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }
        return res;
    }
};

/**
 * @brief 
 * 思路
做本题之前建议先做739. 每日温度和 496.下一个更大元素 I 。

这道题和739. 每日温度 也几乎如出一辙。

不同的时候本题要循环数组了。

关于单调栈的讲解我在题解739. 每日温度中已经详细讲解了。

本篇我侧重与说一说，如何处理循环数组。

相信不少同学看到这道题，就想那我直接把两个数组拼接在一起，
然后使用单调栈求下一个最大值不就行了！

确实可以！

将两个nums数组拼接在一起，使用单调栈计算出每一个元素的下一个最大值，
最后再把结果集即result数组resize到原数组大小就可以了。




版本一这种写法确实比较直观，但做了很多无用操作，
例如修改了nums数组，而且最后还要把result数组resize回去。

resize倒是不费时间，是O(1)的操作，
但扩充nums数组相当于多了一个O(n)的操作。

其实也可以不扩充nums，而是在遍历的过程中模拟走了两边nums。

代码如下：
 */