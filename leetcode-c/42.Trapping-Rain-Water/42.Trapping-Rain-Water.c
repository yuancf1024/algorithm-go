/**
 * @file 42.Trapping-Rain-Water.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，
在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

示例 2：
输入：height = [4,2,0,3,2,5]
输出：9

提示：

n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
 */

#include <stdio.h>
#include <math.h>

/**
 * @brief 
 * 一种更简便的双指针方法：

之前的双指针方法的原理是固定“底”的位置，
往两边找比它高的“壁”，循环若干次求和。

我们逆向思维，把“壁”用两个初始位置在数组首末位置
的指针表示，“壁”往中间推，同样可以让每个“底”都能
找到最高的“壁”

本质上就是改变了运算方向，从而减少了重复运算
 */

int trap(int* height, int heightSize){
    int ans  = 0;
    int left = 0, right = heightSize - 1; // 初始化两个指针到左右两边
    int leftMax = 0, rightMax = 0; // 这两个值用来记录左右的“壁”的最高值
    while (left < right) { // 两个指针重合就结束
        leftMax = fmax(leftMax, height[left]);
        rightMax = fmax(rightMax, height[right]);
        if (leftMax < rightMax) {
            ans += leftMax - height[left]; // 里考虑的是下标为left的“底”能装多少水
            ++left; // 指针的移动次序是这个方法的关键
            //这里左指针右移是因为左“墙”较矮，左边这一片实际情况下的盛水量是受制于这个矮的左“墙”的
        //而较高的右边在实际情况下的限制条件可能不是当前的左“墙”，比如限制条件可能是右“墙”，就能装更高的水，
        }
        else {
            ans += rightMax - height[right];  //同理，考虑下标为right的元素
            --right;
        }
    }
    return ans;
}

int main() {
    int height[10001] =  {0,1,0,2,1,0,1,3,2,1,2,1};
    int heightSize = 12;

    int res = trap(height, heightSize);
    printf("%d\n", res);
    return 0;
}