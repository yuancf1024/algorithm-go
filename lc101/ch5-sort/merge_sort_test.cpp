#include <bits/stdc++.h>

using namespace std;

// 归并排序 (MergeSort)
void merge_sort(vector<int>& nums, int l, int r, vector<int>& temp) {
    if (l + 1 >= r) { // 递归终止条件
        return;
    }
    // divide
    int m = l + ((r - l) >> 1);
    // int m = l + (r - l) / 2;
    merge_sort(nums, l, m, temp);
    merge_sort(nums, m, r, temp);
    // conquer
    int p = l, q = m, i = l;
    while (p < m || q < r) {
        if (q >= r || (p < m && nums[p] <= nums[q])) {
            temp[i++] = nums[p++];
        } else {
            temp[i++] = nums[q++];
        }
    }
    for (i = l; i < r; ++i) {
        nums[i] = temp[i];
    }
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
    vector<int> tmp(nums.size());
    print_nums(nums);
    printf("\n");
    merge_sort(nums, 0, nums.size(), tmp);
    print_nums(nums);
    return 0;
}

/*
2022-07-19 GDB调试发现：程序代码段定位到第18行
出现异常。
Segmentation fault

错误原因：代码段第48行 vector<int> tmp声明时未指定vector数量
*/