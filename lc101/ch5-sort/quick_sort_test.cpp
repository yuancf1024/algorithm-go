#include <bits/stdc++.h>

using namespace std;

void quick_sort(vector<int>& nums, int l, int r) {
    if (l + 1 >= r) {
        return;
    }
    int first = l, last = r - 1, key = nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key) { // nums[first] > nums[last] 跳出循环
            --last; // 向左收缩
        }
        nums[first] = nums[last]; // 需要被移动前面的数
        while (first < last && nums[first] <= key) { // 
            ++first;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}

// 遍历vector - 计数器
void print_nums(vector<int>& nums) { 
    vector<int>::iterator it = nums.begin();
    for (int i = 0; i < nums.size(); i++) {
        printf("%d ", *(it + i));
        // cout << nums[i] << ' ';
    }
}

// 遍历vector - 使用迭代器
void print_nums1(vector<int>& nums) {
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) { 
        printf("%d ", *it);
        // cout << nums[i] << ' ';
    }
}


int main() {
    vector<int> nums = {1, 3, 5, 7, 6, 4, 8, 9, 2};
    print_nums1(nums);
    printf("\n");
    quick_sort(nums, 0, nums.size());
    print_nums1(nums);
    return 0;
}