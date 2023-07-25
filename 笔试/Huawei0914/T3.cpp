#include <bits/stdc++.h>

using namespace std;

/*
样例1：
10 1 7 255
1 2 3
1 5 2
1 8 5
2 3 3
2 5 3
3 4 3
4 7 3
5 6 2
6 7 2
8 7 6


*/

int main() { 
    int N, start, end, TTL_s;
    cin >> N >> start >> end >> TTL_s;
    // 构造图
    vector<vector<int>> g(N, vector<int>(2));
    for (int i = 0; i < N; ++i) {
        int a1, a2, a3;
        cin >> a1 >> a2 >> a3;
        g[a1][a2] = a3;
        g[a2][a1] = a3;
    }
    return 0;
}