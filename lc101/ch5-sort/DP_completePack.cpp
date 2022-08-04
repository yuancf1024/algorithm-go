#include <bits/stdc++.h>

using namespace std;

// 先遍历物品，再遍历背包
void test_completePack(vector<int>& weight, vector<int>& value, int bagweight) {
    // 初始化
    vector<int> dp(bagweight + 1, 0);

    for (int i = 0; i < weight.size(); i++) { // 遍历物品
        for (int j = weight[i]; j <= bagweight; j++) { // 遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[bagweight] << endl;
}

int main() { 
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagweight = 4;

    cout << "完全背包: " << endl;
    test_completePack(weight, value, bagweight);
    return 0; }