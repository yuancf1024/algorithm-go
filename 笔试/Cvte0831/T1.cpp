#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    vector<int> nums;
    while (cin >> t) {
        nums.push_back(t);
        if (cin.get() == '\n') {
            break;
        }
    }

    // 核心代码
    sort(nums.begin(), nums.end());
    int idx = 0.7 * nums.size();
    cout << nums[idx+1] << endl;
    // 打印数组
    // for (auto& i : nums) {
    //     cout << i << endl;
    // }
    return 0;
}

/*
TestCase1:

1 2 3 4 85 45 33 44 5
45
*/