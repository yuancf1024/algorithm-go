#include <bits/stdc++.h>

using namespace std;

/*
样例1：
5 2
5 3
1 4 5 2 3
1 6 10 3 4

16

样例2：
3 2
6 13
2 11 5
3 25 14

25

思路：
求输出所有数据包需要的最短时长

建立pair，然后根据传输时长排序，优先让传输时长
长的包进入大通道
*/

// bool cmp1(int a, int b) { return a > b; }
typedef pair<int, int> PII;

bool cmp1(PII a, PII b) { return a.second > b.second; }

int main() { 
    int M, N; // 队列长度 通道数
    cin >> M >> N;
    vector<int> P(N); // 每个通道大小
    vector<int> Q(M); // 每个数据包大小
    vector<int> S(M); // 每个数据包传输时长

    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> Q[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> S[i];
    }

    // 核心代码
    vector<pair<int, int>> nums;
    for (int i = 0; i < M; ++i) {
        nums.push_back(make_pair(Q[i], S[i]));
    }
    sort(nums.begin(), nums.end(), cmp1);
    // cout << nums[0].first << nums[0].second;

    int res = 0;
    int sum = 0;
    for (auto& x : S) {
        sum += x;
    }
    for (int i = 0; i < P.size(); ++i) {
        int time1 = 0;
        for (int j = 0; j < Q.size(); ++j) {
            if (P[i] > Q[j]) {
                time1 += S[j];
            }
        }
        res = min(time1, sum - time1);
    }
    cout << res << endl;
    return 0;
}