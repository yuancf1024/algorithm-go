#include <iostream>
#include <vector>

using namespace std;

/*
* 快速排序
* 思路：选择中轴元素，比它小的放左，比它大的放右(代码过程很像，小丑在扔三个小球)
* 特点：时间：O(nlogn)、空间：O(logn)、非稳定
* 适用：广泛(最快)
*/

// void quickSort(vector<int>& a, int low, int high) {
//     if (low >= high) // 结束标志
//         return;
//     int first = low; // 低位下标
//     int last = high; // 高位下标
//     int key = a[first]; // 设第一个为基准

//     while (first < last) {
//         // 从后往前走，将比第一个小的移到前面
//         while (first < last && a[last] > key) {
//             last--;
//         }
//         // if (first < last)
//         //     a[first++] = a[last];
        
//         // 从前往后走，将比第一个大的移到后面
//         while (first < last && a[first] < key) {
//             first++;
//         }
//         // if (first < last) {
//         //     a[last--] = a[first];
//         // }
//         swap(a[first], a[last]);
//     }
//     // a[first] = key;
//     swap(a[first], key); 
//     // 前半递归
//     quickSort(a, low, first-1);
//     quickSort(a, first + 1, high);
// }

// 2022-08-03 复写1 选择排序
// 这种排序的时候，调用者的参数是nums数组的大小
// void quickSort(vector<int>& nums, int low, int high) {
//     if (low + 1 >= high) {
//         return;
//     }
//     int first = low;
//     int last = high - 1;
//     int key = nums[first];
//     while (first < last) {
//         // 从后往前遍历，将比第一个小的移动到前面
//         while (first < last && nums[last] >= key) {
//             last--;
//         }
//         nums[first] = nums[last];
//         // 从前往后遍历，经比第一个大的移动到后面
//         while (first < last && nums[first] <= key) {
//             first++;
//         }
//         nums[last] = nums[first];
//     }
//     nums[first] = key;
//     quickSort(nums, low, first);
//     quickSort(nums, first + 1, high);
// }

// 2022-08-03 复写2 选择排序
// 这种排序的时候，调用者high的参数是nums.size-1 (即数组索引)
void quickSort(vector<int>& nums, int low, int high) {
    if (low >= high) {
        return;
    }

    int first = low;
    int last = high;
    int key = nums[first];

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
    quickSort(nums, low, first - 1);
    quickSort(nums, first + 1, high);
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 6, 4, 8, 9, 2};
    // vector<int> nums = {3,2,1,5,6,4};
    // print_nums1(nums);
    // printf("\n");
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
    quickSort(nums, 0, nums.size()-1);
    for (auto i : nums) {
        cout << i << " ";
    }
    // print_nums1(nums);
    return 0;
}



// 快速排序复写 2022-08-10 + 引入随机化，避免向n-1集中递归的情况
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
    void quickSort(vector<int>&nums, int low, int high) {
        if (low >= high) {
            return;
        }
        // 加入面试官对于极端case的性能有要求，那么引入随机化避免向n-1集中递归的情况
        int r = rand() % (high - low + 1) + low;
        swap(nums[r], nums[low]);

        int first = low;
        int last = high;
        int key = nums[first];
        while (first < last) {
            // 从后往前，将比第一个小的移动到前面
            while (first < last && nums[last] >= key) {
                last--;
            }
            nums[first] = nums[last];
            // 从前往后，将比第一个大的移到后面
            while (first < last && nums[first] <= key) {
                first++;
            }
            nums[last] = nums[first];
        }
        nums[first] = key;
        quickSort(nums, low, first-1);
        quickSort(nums, first+1, high);
    }
};

