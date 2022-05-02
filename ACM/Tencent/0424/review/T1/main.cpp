// 实现1
#include <bits/stdc++.h>

using namespace std;

string s[111111], t[11];
int a[101010];

int main() {
    int n, i, j;
    cin >> n; // 读入第一行数字
    for (i = 0; i < n; i++) {
        cin >> t[i]; // 读入n行，以字符串的形式
    }
    for (i = 0; i < n; ++i) {
        for (j = 0; j < t[i].length(); j++) {
            s[j] += t[i][j]; // 动态更新，然后覆盖
            // cout << s[j] << ' ';
        }
        
    }
    // 调试
    // for (i = 0; i < n; ++i) {
    //     cout << s[i] << ' ';
    // }

    for (i = 0; i < t[0].length(); ++i) {
        a[i] = stoi(s[i]); // 字符串转数字，自动去掉前缀0
        // cout << a[i] << ' '; 
    }
    sort(a, a+t[0].length()); // 数组起始地址，终点地址
    for (i = 0; i < t[0].length(); ++i) { // 打印输出
        cout << a[i] << ' ';
    }
}

/* 1. 竖着读

只需竖着把字符放进去，转数字去掉前导零排序即可

case

3
0123
1234
2345


12 123 234 345

4
0000
0101
1011
0111

10 11 101 111
*/