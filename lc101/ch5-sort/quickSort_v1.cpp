#include <iostream>
#include <vector>

using namespace std;

/*
* 快速排序
* 思路：选择中轴元素，比它小的放左，比它大的放右(代码过程很像，小丑在扔三个小球)
* 特点：时间：O(nlogn)、空间：O(logn)、非稳定
* 适用：广泛(最快)
*/

void quickSort(vector<int>& a, int low, int high) {
    if (low >= high) // 结束标志
        return;
    int first = low; // 低位下标
    int last = high; // 高位下标
    int key = a[first]; // 设第一个为基准

    while (first < last) {
        // 从后往前走，将比第一个小的移到前面
        while (first < last && a[last] > key) {
            last--;
        }
        // if (first < last)
        //     a[first++] = a[last];
        
        // 从前往后走，将比第一个大的移到后面
        while (first < last && a[first] < key) {
            first++;
        }
        // if (first < last) {
        //     a[last--] = a[first];
        // }
        swap(a[first], a[last]);
    }
    // a[first] = key;
    swap(a[first], key); 
    // 前半递归
    quickSort(a, low, first-1);
    quickSort(a, first + 1, high);
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 6, 4, 8, 9, 2};
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