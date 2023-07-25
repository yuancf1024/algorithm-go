#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    // 1000以内的质数
    vector<int> primes;
    vector<bool> f(1000);
    for (int i = 2; i < 1000; ++i) {
        if (not f[i]) {
            primes.push_back(i);
        }
        for (int j = i + i; j < 1000; j += i) {
            f[j] = true;
        }
    }

    int ps = primes.size(); // 1000以内一共168个质数
    // cout << ps << endl;

    // 记录每次查询，顺便找到最大值mq
    vector<int> queries(t);
    int mq = 0;
    for (int a = 0; a < t; ++a) {
        cin >> queries[a];
        mq = max(mq, queries[a]);
    }

    set<int> st;
    for (int i = 0; i < ps; ++i) {
        if (mq - pow(primes[i], 4) <= 0) {
            break;
        }
        for (int j = 0; j < ps; ++j) {
            if (mq - pow(primes[i], 4) - pow(primes[j], 3) <= 0) {
                break;
            }
            for (int k = 0; k < ps; ++k) {
                int m = pow(primes[i], 4) + pow(primes[j], 3) + pow(primes[k], 2);
                if (m > mq) {
                    break;
                }
                st.insert(m);
            }
        }
    }
    vector<int> nums(st.begin(), st.end());
    for (int q : queries) {
        cout << upper_bound(nums.begin(), nums.end(), q) - nums.begin() << endl;
    }
    return 0;
}