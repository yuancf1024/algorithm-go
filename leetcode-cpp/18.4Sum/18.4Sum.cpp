/* 18. 四数之和

给你一个由n个整数组成的数组nums ，和一个目标值target 。
请你找出并返回满足下述全部条件且不重复的四元组 
[nums[a], nums[b], nums[c], nums[d]] 
（若两个四元组元素一一对应，则认为两个四元组重复）：

- 0 <= a, b, c, d < n

- a、b、c 和 d 互不相同

- nums[a] + nums[b] + nums[c] + nums[d] == target

你可以按 任意顺序 返回答案 。

示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
 
提示：

1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9

*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 剪枝处理
            if (nums[k] > target && nums[k] >= 0 && target >= 0) {
                break; // 这里使用break，统一通过最后的return返回
            }
            // 对nums[k]去重
            if (k > 0 && nums[k] == nums[k-1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 2级剪枝处理
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0 && target >= 0) {
                    break;
                }

                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i-1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    } else if ((long) nums[k] + nums[i] + nums[left] + nums[right] < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i],
                                                     nums[left], nums[right]});
                        // 对nums[left]和nums[right] 去重
                        while (right > left && nums[right] == nums[right-1]) {
                            right--;
                        }
                        while (right > left && nums[left] == nums[left + 1]) { 
                            left++; 
                        }

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};

/*
思路

四数之和，和15.三数之和是一个思路，都是使用双指针法, 
基本解法就是在15.三数之和 的基础上再套一层for循环。

但是有一些细节需要注意，例如： 不要判断nums[k] > target 就返回了，
三数之和 可以通过 nums[i] > 0 就返回了，因为 0 已经是确定的数了，
四数之和这道题目 target是任意值。比如：数组是[-4, -3, -2, -1]，
target是-10，不能因为-4 > -10而跳过。但是我们依旧可以去做剪枝，
逻辑变成nums[i] > target && (nums[i] >=0 || target >= 0)就可以了。

15.三数之和 的双指针解法是一层for循环num[i]为确定值，
然后循环内有left和right下标作为双指针，
找到nums[i] + nums[left] + nums[right] == 0。

四数之和的双指针解法是两层for循环nums[k] + nums[i]为确定值，
依然是循环内有left和right下标作为双指针，
找出nums[k] + nums[i] + nums[left] + nums[right] == target的情况，
三数之和的时间复杂度是O(n^2)，四数之和的时间复杂度是O(n^3) 。

那么一样的道理，五数之和、六数之和等等都采用这种解法。

对于15.三数之和 双指针法就是将原本暴力O(n^3)的解法，
降为O(n^2)的解法，四数之和的双指针解法就是将原本暴力O(n^4)的解法，
降为O(n^3)的解法。

之前我们讲过哈希表的经典题目：454.四数相加II ，相对于本题简单很多，
因为本题是要求在一个集合中找出四个数相加等于target，同时四元组不能重复。

而454.四数相加II 是四个独立的数组，
只要找到A[i] + B[j] + C[k] + D[l] = 0就可以，
不用考虑有重复的四个元素相加等于0的情况，
所以相对于本题还是简单了不少！
*/


class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        if (nums.size() < 4) {
            return quadruplets;
        }
        sort(nums.begin(), nums.end());
        
        int length = nums.size();

        for (int i = 0 ; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            if ((long) nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }
            if ((long) nums[i] + nums[length-3] + nums[length-2] + nums[length-1] < target) {
                continue;
            }
            
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }

                if ((long) nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {
                    break;
                }

                if ((long) nums[i] + nums[j] + nums[length-2] + nums[length-1] < target) {
                    continue;
                }

                int left = j + 1, right = length - 1;
                while (left < right) {
                    long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right-1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return quadruplets;
    }
};

int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res = Solution2().fourSum(nums, target);

    // 打印数组输出
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/**
 * @brief leetcode官方题解
 * 
本题与「15. 三数之和」相似，解法也相似。

方法一：排序 + 双指针
思路与算法

最朴素的方法是使用四重循环枚举所有的四元组，
然后使用哈希表进行去重操作，得到不包含重复四元组的
最终答案。假设数组的长度是n，则该方法中，
枚举的时间复杂度为O(n^4)，去重操作的时间复杂度和空间复杂度也很高，
因此需要换一种思路。

为了避免枚举到重复四元组，则需要保证每一重循环枚举
到的元素不小于其上一重循环枚举到的元素，且在同一重
循环中不能多次枚举到相同的元素。

为了实现上述要求，可以对数组进行排序，并且在循环过程
中遵循以下两点：

- 每一种循环枚举到的下标必须大于上一重循环枚举到的下标；

- 同一重循环中，如果当前元素与上一个元素相同，
    则跳过当前元素。

使用上述方法，可以避免枚举到重复四元组，但是由于
仍使用四重循环，时间复杂度仍是O(n^4)。注意到数组
已经被排序，因此可以使用双指针的方法去掉一重循环。

使用两重循环分别枚举前两个数，然后在两重循环枚举
到的数之后使用双指针枚举剩下的两个数。假设两重循环
枚举到的前两个数分别位于下标i和j，其中i<j。
初始时，左右指针分别指向下标j+1和下标n−1。
每次计算四个数的和，并进行如下操作：

- 如果和等于target，则将枚举到的四个数加到答案中，
然后将左指针右移直到遇到不同的数，将右指针左移直到遇到不同的数；

- 如果和小于target，则将左指针右移一位；

- 如果和大于target，则将右指针左移一位。

使用双指针枚举剩下的两个数的时间复杂度是O(n)，
因此总时间复杂度是O(n^3)，低于O(n^4)。

具体实现时，还可以进行一些剪枝操作：

- 在确定第一个数之后，如果 nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target，
说明此时剩下的三个数无论取什么值，四数之和一定大于target，因此退出第一重循环；

- 在确定第一个数之后，如果 nums[i]+nums[n−3]+nums[n−2]+nums[n−1]<target，
说明此时剩下的三个数无论取什么值，四数之和一定小于target，
因此第一重循环直接进入下一轮，枚举 nums[i+1]；

- 在确定前两个数之后，如果 nums[i]+nums[j]+nums[j+1]+nums[j+2]>target，
说明此时剩下的两个数无论取什么值，四数之和一定大于target，因此退出第二重循环；

- 在确定前两个数之后，如果 nums[i]+nums[j]+nums[n−2]+nums[n−1]<target，
说明此时剩下的两个数无论取什么值，四数之和一定小于target，
因此第二重循环直接进入下一轮，枚举nums[j+1]。
 */