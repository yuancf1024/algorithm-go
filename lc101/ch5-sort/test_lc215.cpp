#include <bits/stdc++.h>

using namespace std;

// 2022-08-03 复写 快速选择
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low, high = nums.size()-1, target = nums.size()-k;
        while (low < high) {
            int mid = quickSelection(nums, low, high);
            if (mid == target) {
                return nums[mid];
            }
            if (mid < target) {
                low = mid + 1;
            } else {
                high = mid -1;
            }
        }
        return nums[low];
    }

    int quickSelection(vector<int>& nums, int low, int high) {
        int first = low;
        int last = high;
        int key = nums[first];
        while (first < last) {
            // 从后往前遍历，将比第一个小的移动到前面
            while (first < last && nums[last] > key) {
                last--;
            }
            nums[first] = nums[last];
            // 从前往后遍历，将比第一个大的移动到后面
            while (first < last && nums[first] < key) {
                first++;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        return last;
    }
};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    // print_nums1(nums);
    // printf("\n");
    // for (auto i : nums) {
    //     cout << i << " ";
    // }
    // cout << endl;

    int x = Solution().findKthLargest(nums, k); // 哪里有bug？
    cout << x << endl;
    for (auto i : nums) {
        cout << i << " ";
    }
    return 0;
}

/*
2022-08-03 有bug 无法正常输出!
*/