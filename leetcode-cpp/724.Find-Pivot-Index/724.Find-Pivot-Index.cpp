/**
 * @file 724.Find-Pivot-Index.cpp
 * @author your name (you@domain.com)
 * @brief leetcode-724.Find-Pivot-Index
 * @version 0.1
 * @date 2024-07-08
 * 
 * @copyright Copyright (c) 2024
 * 724. 寻找数组的中心下标
给你一个整数数组 nums ，请计算数组的 中心下标 。

数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。
这一点对于中心下标位于数组最右端同样适用。

如果数组有多个中心下标，应该返回 最靠近左边 的那一个。
如果数组不存在中心下标，返回 -1 。

示例 1：
输入：nums = [1, 7, 3, 6, 5, 6]
输出：3
解释：
中心下标是 3 。
左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。

示例 2：
输入：nums = [1, 2, 3]
输出：-1
解释：
数组中不存在满足此条件的中心下标。

示例 3：
输入：nums = [2, 1, -1]
输出：0
解释：
中心下标是 0 。
左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。

提示：

1 <= nums.length <= 10^4
-1000 <= nums[i] <= 1000
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (auto& x : nums) {
            sum += x;
        }
        int sumLeft = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sumLeft*2 + nums[i] == sum) {
                return i;
            }
            sumLeft += nums[i];
        }
        return -1;
        /*vector<int> sumLeft, sumRight;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sumLeft.push_back(sum);
        }
        int s = 0;
        for (int i = nums.size()-1; i >= 0; i-- ) {
            s += nums[i];
            sumRight.push_back(s);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (sumLeft[i] == sumRight[i]) {
                return i;
            }
        }
        return -1;
        */
    }
};

int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int res = Solution().pivotIndex(nums);
    cout << res << endl;
    return 0;
}

/**
 * @brief 算法思路：模拟
 * 找一个index i，使得i左边的数字和等于右边的数字和
 * 1）先遍历数组，求和sum
 * 2）然后再次遍历数组，sumLeft累加左边的数字和，判断sumLeft*2 == sum
 *      如果相等，返回i；
 *      否则，继续遍历；结束时返回-1
 */