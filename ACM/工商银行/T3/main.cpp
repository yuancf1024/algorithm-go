#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// using namespace std;
// int dp[100010][3];
// int work[100010];
// int train[100010];
int query() {


	ans := 0
	a1 := nums[0]
	a2 := nums[1]
	query := make(map[int]bool)
	for i := a1-1; i < a2; i++ {
		query[pic[i]] = true
	}
	for k, _ := range query {
		ans += colorMap[k]
	}
	fmt.Println(ans)
}

int main() {
    int n, m;
    int q = 0;

    cin >> n >> m;

    int color[n];
    for (int i = 0; i < n; i++){
        cin >> color[i];

    int pic[m];
    for (int i = 0; i < m; i++){
        cin >> pic[i];

    int q;
    cin >> q;

    int nums[q][2];
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> nums[i][j];
        }
    }

    // 核心代码
    colorMap := make(map[int]int)
	for i := 0; i < n; i++ {
		colorMap[color[i]]++
	}
	for i := 0; i < q; i++ {
		Query(nums[i], pic, color, colorMap)
	}


    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }
}
// 64 位输出请用 printf("%lld")
