/**
 * @brief 
 * 剑指 Offer 03. 数组中重复的数字
 * 
找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

限制：

2 <= n <= 100000

 */


//这里放你的代码// 哈希表
/*
1. 建立一个哈希表，遍历数组；
2. 先判断遍历到的数是否存在于哈希表中
	- 如果存在，更新返回值res，break结束遍历；
    - 如果不存在，将num插入哈希表，继续遍历
3. 返回所求结果
执行用时：64 ms, 在所有 C++ 提交中击败了8.66%的用户
内存消耗：36.3 MB, 在所有 C++ 提交中击败了5.03%的用户
通过测试用例：
26 / 26

*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int res = 0;
        unordered_set<int> num_set;
        for (const int& num : nums) {
            if (num_set.count(num)) {
                res = num;
                break; // 很有用
            }
            num_set.insert(num);
        }
        return res;
    }
};
//注意图片要挪到```的外部才能正常显示~