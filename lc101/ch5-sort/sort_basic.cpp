#include <bits/stdc++.h>

using namespace std;


// 快速排序 (QuickSort)
// 采用左闭右闭的二分写法
void quick_sort(vector<int>& nums, int l, int r) {
    if (l + 1 >= r) { // 递归终止条件
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

// 归并排序 (MergeSort)
void merge_sort(vector<int>& nums, int l, int r, vector<int>& temp) {
    if (l + 1 >= r) { // 递归终止条件
        return;
    }
    // divide
    int m = l + ((r - l) >> 1);
    merge_sort(nums, l, m, temp);
    merge_sort(nums, m, r, temp);
    // conquer
    int p = l, q = m, i = l;
    while (p < m || q < r) {
        if (q >= r || (p < m &&nums[p] <= nums[q])) {
            temp[i++] = nums[p++];
        } else {
            temp[i++] = nums[q++];
        }
    }
    for (i = l; i < r; ++i) {
        nums[i] = temp[i];
    }
}

// 插入排序(InsertionSort)
void insertion_sort(vector<int>& nums, int n) { 
    for (int i = 0; i < n; ++i) {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
            swap(nums[j], nums[j - 1]);
        }
    }
}

// 冒泡排序(BubbleSort)
void bubble_sort(vector<int>& nums, int n) { 
    bool swapped;
    for (int i = 1; i < n; ++i) {
        swapped = false;
        for (int j = 1; j < n - i + 1; ++j) {
            if (nums[j] < nums[j-1]) {
                swap(nums[j], nums[j - 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

// 选择排序(SelectionSort)
void selection_sort(vector<int>& nums, int n) { 
    int mid;
    for (int i = 0; i < n - 1; ++i) {
        mid = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[mid]) {
                mid = j;
            }
        }
        swap(nums[mid], nums[i]);
    }
}

// 以上排序调用方法
void sort() {
    vector<int> nums = {1, 3, 5, 7, 2, 6, 4, 8, 9, 2,
                        8, 7, 6, 0, 3, 5, 9, 4, 1, 0};
    vector<int> temp(nums.size());
    sort(nums.begin(), nums.end()); // 标准库的快速排序
    quick_sort(nums, 0, nums.size());
    merge_sort(nums, 0, nums.size(), temp);
    insertion_sort(nums, nums.size());
    bubble_sort(nums, nums.size());
    selection_sort(nums, nums.size());
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
    vector<int> temp(nums.size());

    print_nums1(nums);
    printf("\n");

    // printf("标准库排序:\n");
    // sort(nums.begin(), nums.end());

    // printf("快速排序结果:\n");
    // quick_sort(nums, 0, nums.size());

    // printf("归并排序结果:\n");
    // merge_sort(nums, 0, nums.size(), temp);

    // printf("插入排序结果:\n");
    // insertion_sort(nums, nums.size());

    // printf("冒泡排序结果:\n");
    // bubble_sort(nums, nums.size());

    printf("选择排序结果:\n");
    selection_sort(nums, nums.size());

    print_nums1(nums);
    printf("\n");
    return 0;
}