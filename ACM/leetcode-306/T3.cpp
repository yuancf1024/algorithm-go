#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) { 
        string res;
        int n = pattern.size();
        for (auto& s : pattern) {
            if (s == 'I') {

            }
        }
    }

    // 辅函数
    string func(string pattern, int start, int k) {
        string nums;

        return nums;
    }
};

/*
思路：
需要对字符串pattern分成连续子字符串，
- 遇到I，从最小的数字1开始；
- 遇到D，需要判断后面的连续状况；
    - 如果是连续的I，那么从1累加即可；
    - 如果遇到连续的D，那么在前一个的基础上先加上连续D的数量，再递减。

注意数字1-9最多使用一次。


上面的逻辑很好理解，关键是怎么找到连续的子串"II" "DDD"之类的
*/

int main() {
    stirng pattern = "IIIDIDDD";
    Solution solution;
    string ans = solution.smallestNumber(pattern);
    cout << ans << endl;
    return 0;
}