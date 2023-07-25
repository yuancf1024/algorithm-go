/**
 * @file T1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-09
 * 
 * @copyright Copyright (c) 2022
 * 
 * 15分
 * 请编写程序，计算数组中指定元素的出现次数。
 * 输入一个整型数组和一个索引值，
 * 计算并返回该索引值所对应的元素在数组中出现的次数。
 * 
示例1：
输入：数组 [100,200,300,100] 目标索引值 0
输出：2
 */


#include <stdio.h>

int CountArrayElement(int arr[], int arrLen, int dstIndex) { 
    int ans = 0;
    // 遍历数组arr
    for (int i = 0; i < arrLen; ++i) {
        if (arr[i] == arr[dstIndex]) { // 判断是否与目标索引值的元素相等
            ans++; // 记录目标值出现次数
        }
    }
    return ans;
}

int main() {
    int arr[] = {100, 200, 300, 100};
    int dstIndex = 0;

    int n = sizeof(arr) / sizeof(arr[0]);

    // 核心代码
    int res = CountArrayElement(arr,n,dstIndex); // 记录索引值所对应的元素在数组中出现的次数
    printf("%d\n", res);
    return 0;
}