/**
 * @file 1151.minimum-swaps-to-group-all-1s-together.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-29
 * 
 * @copyright Copyright (c) 2022
 * leetcode-1151. 最少交换次数来组合所有的 1
 * 
 * 给出一个二进制数组 data，你需要通过交换位置，
将数组中 任何位置 上的 1 组合到一起，并返回所有可能中所需 最少的交换次数。

示例 1：
输入：[1,0,1,0,1]
输出：1

解释：
有三种可能的方法可以把所有的 1 组合在一起：
[1,1,1,0,0]，交换 1 次；
[0,1,1,1,0]，交换 2 次；
[0,0,1,1,1]，交换 1 次。
所以最少的交换次数为 1。

示例 2：
输入：[0,0,0,1,0]
输出：0

解释：
由于数组中只有一个 1，所以不需要交换。

示例 3：
输入：[1,0,1,0,1,0,0,1,1,0,1]
输出：3

解释：
交换 3 次，一种可行的只用 3 次交换的解决方案是 [0,0,0,0,0,1,1,1,1,1,1]。
提示：
1 <= data.length <= 10^5
0 <= data[i] <= 1

 */

/*
思路：
没有必要真的进行swap交换，
本题的目的只要得到最少的交换次数就好，
所以用数组中1和0的翻转来代替交换

把问题转变为：一个长度等于数组中1的个数的滑窗，
这个滑窗中0的个数最少

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& data) {
        // 1.统计数组中元素值等于1的个数
        int k = 0;
        for (auto& i : data) {
            if (i == 1) {
                k++;
            }
        }
        // 维护窗口大小为k的滑动窗口
        int left = 0, right = 0;
        // 存储每个窗口中0的数量
        int windowZeros = 0;
        // 所有窗口中最少的0的数量
        int minZeros = INT_MAX;
        while (right < data.size()) {
            if (data[right] == 0) { // 0的个数+1，
                windowZeros++; 
            }
            if (right-left+1 == k) { // 如果滑窗等于k，更新最小0的数量
                minZeros = min(minZeros, windowZeros);
                if (data[left] == 0) { // 缩短窗口
                    windowZeros--;
                }
                left++;
            }
            right++;
        }

        // 考虑特殊情况：数组中没有0 不用额外考虑也可
        return minZeros;
    }
};

int main() {
    vector<int> data = {1,0,1,0,1,0,0,1,1,0,1};
    Solution s;
    int res = s.minSwaps(data);
    cout << res << endl;
    return 0;
}