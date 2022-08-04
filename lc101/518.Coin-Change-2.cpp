#include <bits/stdc++.h>

using namespace std;

// 参考代码随想录
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) { // 遍历物品
            for (int j = coins[i]; j <= amount; j++) { // 遍历背包
                dp[j] += dp[j - coins[i]];
                cout << dp[j] << " ";
            }
            cout << endl;
        }
        return dp[amount];
    }

    int change1(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= amount; j++) { // 遍历物品
            for (int i = 0; i < coins.size(); i++) { // 遍历背包
                if (j - coins[i] >= 0) {
                    dp[j] += dp[j - coins[i]];
                    cout << dp[j] << " ";
                }
            }
            cout << endl;
        }
        return dp[amount];
    }

    // void print(vector<int>& dp) {
    //     for 
    // }
};

int main() { 
    // vector<int> weight = {1, 3, 4};
    // vector<int> value = {15, 20, 30};
    // int bagweight = 4;
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << "先遍历物品再遍历背包: " << endl;
    int res = Solution().change(amount, coins);

    cout << "先遍历背包再遍历物品: " << endl;
    int res1 = Solution().change1(amount, coins);
    return 0; 
}

/**
 * @brief 
 * 先遍历物品再遍历背包: 
1 1 1 1 1 
2 2 3 3 
4 
 * 先遍历背包再遍历物品: 
1 
1 2 
2 3 
3 5 
5 8 9 
 * 

先遍历物品再遍历背包

假设：coins[0] = 1，coins[1] = 5。

那么就是先把1加入计算，然后再把5加入计算，得到的方法数量只有{1, 5}这种情况。而不会出现{5, 1}的情况。

所以这种遍历顺序中dp[j]里计算的是组合数！


先遍历背包再遍历物品

背包容量的每一个值，都是经过 1 和 5 的计算，包含了{1, 5} 和 {5, 1}两种情况。

此时dp[j]里算出来的就是排列数！
 */