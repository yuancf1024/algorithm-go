#include <bits/stdc++.h>

using namespace std;

void quick_sort(vector<int>& nums, int l, int r) {
    if (l + 1 >= r) { // 递归的结束条件
        return;
    }
    // 低位下标和高位小标，设第一个为基准
    int first = l, last = r - 1, key = nums[first]; // first、last可直接放进数组索引
    while (first < last) {
        // 从后往前走，将比第一个小的移到前面
        while (first < last && nums[last] >= key) { // nums[first] >= nums[last] 跳出循环
            --last; // 向左收缩
        }
        nums[first] = nums[last]; // 需要被移动前面的数
        // 从前往后走，将比第一个大的移到后面
        while (first < last && nums[first] <= key) {
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

// 遍历vector 便捷写法
void print(vector<int>& nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

// 第一次复写
void quickSort(vector<int>& nums, int low, int high) {
    if (low + 1 >= high) {
        return;
    }
    int first = low, last = high - 1, key = nums[first];
    while (first < last) {
        // 从后往前遍历，将比第一个小的移动到前面
        while (first < last && nums[last] >= key) {
            last--;
        }
        nums[first] = nums[last];
        // 从前往后遍历，将比第一个大的移动到后面
        while (first < last && nums[first] <= key) {
            first++;
        }
        nums[last] = nums[first];
    }
    nums[first] = key;
    quickSort(nums, low, first);
    quickSort(nums, first + 1, high);
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 6, 4, 8, 9, 2};
    print(nums);
    // print_nums1(nums);
    // printf("\n");
    quickSort(nums, 0, nums.size());
    print(nums);
    // print_nums1(nums);
    return 0;
}