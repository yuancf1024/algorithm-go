/* 18. 四数之和

给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
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
