/**
 * @file 287.Find-the-Duplicate-Number.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * leetcode-287.寻找重复数
 * 
给定一个包含 n + 1 个整数的数组 nums ，
其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

示例 1：
输入：nums = [1,3,4,2,2]
输出：2

示例 2：
输入：nums = [3,1,3,4,2]
输出：3

提示：

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次

进阶：

如何证明 nums 中至少存在一个重复的数字?
你可以设计一个线性级时间复杂度 O(n) 的解决方案吗？
 */

#include <bits/stdc++.h>

using namespace std;

// 方法三：Floyd判圈算法(龟兔赛跑算法)
class Solution {
public:
    int findDuplicate(vector<int>& nums) { 
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/**
 * @brief 
 * 
 * 本题leetcode官方给出了二分查找、二进制，快慢指针。
 * 其中快慢指针的方法和环型链表找入环节点特别相似。
 * 
 * 方法三：Floyd判圈算法(龟兔赛跑算法)
 * 思路和算法

我们对nums 数组建图，每个位置i 连一条i→nums[i] 的边。
由于存在的重复的数字target，因此target 
这个位置一定有起码两条指向它的边，因此整张图一定存在环，
且我们要找到的target 就是这个环的入口，那么整个问题就等价于 142.环形链表 II。

我们先设置慢指针slow 和快指针fast，慢指针每次走一步，快指针每次走两步，
根据「Floyd 判圈算法」两个指针在有环的情况下一定会相遇，
此时我们再将slow 放置起点0，两个指针每次同时移动一步，相遇的点就是答案。

这里简单解释为什么后面将slow 放置起点后移动相遇的点就一定是答案了。
假设环长为L，从起点到环的入口的步数是a，从环的入口继续走b 步到达相遇位置，
从相遇位置继续走c步回到环的入口，则有b+c=L，其中L、a、b、c都是正整数。
根据上述定义，慢指针走了a+b 步，快指针走了2(a+b) 步。
从另一个角度考虑，在相遇位置，快指针比慢指针多走了若干圈，
因此快指针走的步数还可以表示成a+b+kL，其中k表示快指针在环上走的圈数。
联立等式，可以得到
2(a+b)=a+b+kL
解得 a=kL−b，整理可得

a=(k−1)L+(L−b)=(k−1)L+c

从上述等式可知，如果慢指针从起点出发，快指针从相遇位置出发，
每次两个指针都移动一步，则慢指针走了 aa 步之后到达环的入口，
快指针在环里走了k−1 圈之后又走了c 步，
由于从相遇位置继续走c 步即可回到环的入口，因此快指针也到达环的入口。
两个指针在环的入口相遇，相遇点就是答案。

复杂度分析
时间复杂度：O(n)。「Floyd 判圈算法」时间复杂度为线性的时间复杂度。
空间复杂度：O(1)。我们只需要常数空间存放若干变量。
 */