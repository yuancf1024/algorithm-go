// 实现1 : 纯C语法
// #include <bits/stdc++.h>

// using namespace std;

// string s[111111], t[11];
// int a[101010];

// int main() {
//     int n, i, j;
//     cin >> n; // 读入第一行数字
//     for (i = 0; i < n; i++) {
//         cin >> t[i]; // 读入n行，以字符串的形式
//     }
//     for (i = 0; i < n; ++i) {
//         for (j = 0; j < t[i].length(); j++) {
//             s[j] += t[i][j]; // 动态更新，然后覆盖
//             // cout << s[j] << ' ';
//         }
        
//     }
//     // 调试
//     // for (i = 0; i < n; ++i) {
//     //     cout << s[i] << ' ';
//     // }

//     for (i = 0; i < t[0].length(); ++i) {
//         a[i] = stoi(s[i]); // 字符串转数字，自动去掉前缀0
//         // cout << a[i] << ' '; 
//     }
//     sort(a, a+t[0].length()); // 数组起始地址，终点地址
//     for (i = 0; i < t[0].length(); ++i) { // 打印输出
//         cout << a[i] << ' ';
//     }
// }

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

// 实现2：add C++容器特性
/*
给n个数字字符串，每个字符串长度都为m，
然后按照每一列从上往下读构成m个字符串，
求这m个排序后的字符串，排序输出。

直接按列存储，然后将其转换为long long类型的值，
排序即可，顺便解决了前导0问题
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s, val) memset(s, val, sizeof(s))
const int inf = INT_MAX;
const int MAXN = 1e5 + 10;
int T;

int main(int argc, char * argv[]) {
    int n, len;
    cin >> n;
    vector<string> g(MAXN);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        len = str.size(); 
        for (int j = 0; j < len; j++) {
            g[j].push_back(str[j]); // 逐行将字符串中的单个字符添加进来，从''累积添加，
            // cout << g[j] << " "; // 0 1 2 3 01 12 23 34 012 123 234 345
        }
    }
    vector<ll> nums;
    for (int i = 0; i < len; i++) {
        nums.push_back(stoll(g[i])); // 字符串转数字，默认去除前置0
    }
    sort(nums.begin(), nums.end()); // 排序
    for (int i = 0; i < len; i++) {
        cout << nums[i];
        if (i != len-1) cout << " "; // 最后一个数字后面是没有空格的
    }
    return 0;
}