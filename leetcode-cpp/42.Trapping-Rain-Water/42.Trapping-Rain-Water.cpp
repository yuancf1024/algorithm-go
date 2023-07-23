/**
 * @file 42.Trapping-Rain-Water.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * leetcode-42.接雨水
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

#include <bits/stdc++.h>

using namespace std;

// 算法1 (三次线性扫描) O(n)
class Solution {
public:
    int trap(vector<int>& height) { 
        int n = height.size(), ans = 0;
        if (n == 0) {
            return 0;
        }
        vector<int> left_max(n), right_max(n);

        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }
        for (int i = 0; i < n; ++i) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }

    // 双指针优化
    int trap_v2(vector<int>& height) {
        if (height.size() <= 2) return 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int size = maxRight.size();

        // 记录每个柱子左边柱子最大高度
        maxLeft[0] = height[0];
        for (int i = 1; i < size; i++) {
            maxLeft[i] = max(height[i], maxLeft[i- 1]);
        }

        // 记录每个柱子右边柱子最大高度
        maxRight[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            maxRight[i] = max(height[i], maxRight[i + 1]);
        }

        // 求和
        int sum = 0;
        for (int i = 0; i < size; i++) {
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if (count > 0) {
                sum += count;
            }
        }
        return sum;
    }
};

// 单调栈 O(n)
class Soltuion2 {
public:
    int trap(vector<int>& height) { 
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = Solution().trap(height);
    cout << res << endl;
    return 0;
}

/**
 * @brief 
算法1 (三次线性扫描) O(n) 参考acwing@wzc1995

1. 观察整个图形，考虑对水的面积按 列 进行拆解
2. 注意到，每个矩形条上方所能接受的水的高度，
是由它左边 最高的 矩形，和右边 最高的 矩形决定的。
具体地，假设第 i 个矩形条的高度为 height[i]，
且矩形条左边 最高的 矩形条的高度为 left_max[i]，
右边 最高的 矩形条高度为 right_max[i]，
则该矩形条上方能接受水的高度为 
min(left_max[i], right_max[i]) - height[i]。
3. 需要分别从左向右扫描求 left_max，从右向左求 right_max，
最后统计答案即可。
4. 注意特判 n 为 0。

时间复杂度
三次线性扫描，故只需要O(n) 的时间。

空间复杂度
需要额外O(n) 的空间记录每个位置左边最高的高度和右边最高的高度。


**不太容易理解**

算法2(单调栈) O(n)
1. 换一种思路，考虑每个位置左边和右边 第一个 比自身不低的矩形条，
以及三个矩形条构成的 U 型，相当于对水的面积按 行 进行拆解。
2. 维护严格单调递减的单调栈。在每次检查栈顶要出栈时，
i 为右边第一个比 st.top() 不低的矩形，st.top() 弹出栈顶，并将其记为 top。
3. 假设此时栈中仍然存在矩形，现在 st.top()（弹栈后的栈顶）、
top 与 i 三个位置构成一个 U 型，其中 top 位置代表 U 型的底部，
此时可以计算出该 U 型所能接受的水的面积为 
(i - st.top() - 1) * (min(height[st.top()], height[i]) - height[top])。
最后当前矩形进栈。

时间复杂度
每个元素最多进栈一次出栈一次，故只需要O(n) 的时间。

空间复杂度
需要额外 O(n) 的空间存储单调栈。


方法一：动态规划 参考leetcode官方题解 和三次线性扫描的实现一样

对于下标i，下雨后水能到达的最大高度等于下标 i 两边的最大高度的最小值，
下标i 处能接的雨水量等于下标i 处的水能到达的最大高度减去height[i]。

朴素的做法是对于数组height 中的每个元素，分别向左和向右扫描并记录
左边和右边的最大高度，然后计算每个下标位置能接的雨水量。
假设数组height 的长度为n，该做法需要对每个下标位置使用O(n) 的时间
向两边扫描并得到最大高度，因此总时间复杂度是 O(n^2)。

上述做法的时间复杂度较高是因为需要对每个下标位置都向两边扫描。
如果已经知道每个位置两边的最大高度，则可以在O(n) 的时间内得到能接
的雨水总量。使用动态规划的方法，可以在O(n) 的时间内预处理得到每个位置
两边的最大高度。

创建两个长度为n 的数组leftMax 和rightMax。
对于0≤i<n，leftMax[i] 表示下标i 及其左边的位置中，height 的最大高度，
rightMax[i] 表示下标i及其右边的位置中，height 的最大高度。

显然，leftMax[0]=height[0]，rightMax[n−1]=height[n−1]。
两个数组的其余元素的计算如下：

- 当1≤i≤n−1 时，leftMax[i]=max(leftMax[i−1],height[i])；

- 当0≤i≤n−2 时，rightMax[i]=max(rightMax[i+1],height[i])。

因此可以正向遍历数组height 得到数组leftMax 的每个元素值，
反向遍历数组height 得到数组rightMax 的每个元素值。

在得到数组leftMax 和rightMax 的每个元素值之后，
对于0≤i<n，下标i 处能接的雨水量等于 min(leftMax[i],rightMax[i])−height[i]。
遍历每个下标位置即可得到能接的雨水总量。

动态规划做法可以由下图体现。

复杂度分析

时间复杂度：O(n)，其中 n是数组height 的长度。
计算数组leftMax 和rightMax 的元素值各需要遍历数组 height 一次，
计算能接的雨水总量还需要遍历一次。

空间复杂度：O(n)，其中 n是数组height 的长度。
需要创建两个长度为n 的数组leftMax 和rightMax。


方法二：单调栈
除了计算并存储每个位置两边的最大高度以外，
也可以用单调栈计算能接的雨水总量。

维护一个单调栈，单调栈存储的是下标，
满足从**栈底到栈顶**的下标对应的数组height 中的元素递减。

从左到右遍历数组，遍历到下标i 时，如果栈内至少有两个元素，
记栈顶元素为top，top 的下面一个元素是left，
则一定有height[left] ≥ height[top]。
如果height[i]>height[top]，则得到一个可以接雨水的区域，
该区域的宽度是i−left−1，高度是min(height[left],height[i])−height[top]，
根据宽度和高度即可计算得到该区域能接的雨水量。

为了得到left，需要将top 出栈。在对top 计算能接的雨水量之后，
left 变成新的top，重复上述操作，直到栈变为空，
或者栈顶下标对应的height 中的元素大于或等于height[i]。

在对下标i 处计算能接的雨水量之后，将i 入栈，继续遍历后面的下标，
计算能接的雨水量。遍历结束之后即可得到能接的雨水总量。

下面用一个例子height=[0,1,0,2,1,0,1,3,2,1,2,1] 来帮助读者理解单调栈的做法。

复杂度分析
时间复杂度：O(n)，其中n 是数组height 的长度。
从0 到n−1 的每个下标最多只会入栈和出栈各一次。
空间复杂度：O(n)，其中n 是数组height 的长度。
空间复杂度主要取决于栈空间，栈的大小不会超过n。
 */