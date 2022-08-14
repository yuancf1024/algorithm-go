#include <bits/stdc++.h>

using namespace std;


// 哪里有bug 一直运行不出正确结果
class Solution {
public:
    int countSpecialNumbers(int n) { 
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (i >= 1 && i <= 19) {
                res++;
            } else if (isAllEqual(i)) {
                res++;
            }
        }
        return res;
    }

    // 辅函数
    bool isAllEqual(int num) {
        bool flag = true;
        int one = 0;
        unordered_set<int> numSet;
        while (true) {
            one = num % 10; // 取个位数
            num = num / 10;
            if (numSet.count(one) >= 2) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

/*
思路：模拟
从1遍历到n，对每个数字的各个数位进行判断：
- 如果每一个数位都是 互不相同 的，res++
- 否则，跳出循环，遍历下一个数
*/

int main() {
    // stirng pattern = "IIIDIDDD";
    int n = 135;
    Solution solution;
    int ans = solution.countSpecialNumbers(n);
    cout << ans << endl;
    return 0;
}