/**
 * @file 822.Card-Flipping-Game.cpp
 * @author your name (you@domain.com)
 * @brief 822.翻转卡片游戏
 * @version 0.1
 * @date 2023-08-02
 * 
 * @copyright Copyright (c) 2023
 * 
在桌子上有 N 张卡片，每张卡片的正面和背面都写着一个正数（
正面与背面上的数有可能不一样）。

我们可以先翻转任意张卡片，然后选择其中一张卡片。

如果选中的那张卡片背面的数字 X 与任意一张卡片的正面的数字
都不同，那么这个数字是我们想要的数字。

哪个数是这些想要的数字中最小的数（找到这些数中的最小值）呢？
如果没有一个数字符合要求的，输出 0。

其中, fronts[i] 和 backs[i] 分别代表第 i 张卡片的正面和
背面的数字。

如果我们通过翻转卡片来交换正面与背面上的数，
那么当初在正面的数就变成背面的数，背面的数就变成正面的数。

示例：

输入：fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
输出：2
解释：假设我们翻转第二张卡片，那么在正面的数变成了 [1,3,4,4,7] ， 
背面的数变成了 [1,2,4,1,3]。
接着我们选择第二张卡片，因为现在该卡片的背面的数是 2，
2 与任意卡片上正面的数都不同，所以 2 就是我们想要的数字。
 

提示：

1 <= fronts.length == backs.length <= 1000
1 <= fronts[i] <= 2000
1 <= backs[i] <= 2000
 */
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int ans = 3000, n = fronts.size();
        unordered_set<int> same;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }
        for (int &x : fronts) {
            if (x < ans && same.count(x) == 0) {
                ans = x;
            }
        }
        for (int &x : backs) {
            if (x < ans && same.count(x) == 0) {
                ans = x;
            }
        }

        return ans % 3000;
    }
};

int main() {
    // 针对 Non-aggregate type 'vector<int>' cannot be initialized with an initializer listclang
    // 可采用如下两种方法解决
    // push_back
    vector<int> fronts; // = {1,2,4,4,7};
    fronts.push_back(1);
    fronts.push_back(2);
    fronts.push_back(4);
    fronts.push_back(4);
    fronts.push_back(7);
    // 使用assign()函数将数组的范围复制到vector中
    vector<int> backs;
    int arr[] = {1,3,4,1,3};
    backs.assign(arr, arr + sizeof(arr) / sizeof(arr[0]));

    int res = Solution().flipgame(fronts, backs);

    cout << res << endl;

    return 0;
}

/**
 * @brief 参考leetcode官方题解
 * 方法一：哈希集
思路与算法

如果一张卡片正反两面有相同的数字，
那么这张卡片无论怎么翻转，正面都是这个数字，
这个数字即不能是最后所选的数字x。

按照这个思路，我们首先遍历所有卡片，
如果卡片上的两个数字相同，则加入哈希集合same中，
除此集合外的所有数字，都可以被选做x， 
我们只需要再次遍历所有数字，找到最小值即可。

最后，我们返回找到的最小值，如果没有则返回0。

复杂度分析

时间复杂度：O(n)，其中 n 是卡片个数。

空间复杂度：O(n)，其中 n 是卡片个数。
 */