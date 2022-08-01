#include<bits/stdc++.h>

using namespace std;

/**
 * @brief HJ2 计算某字符出现次数
 * 描述
写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，
然后输出输入字符串中该字符的出现次数。（不区分大小写字母）

数据范围： 1≤n≤1000 

输入描述：

第一行输入一个由字母和数字以及空格组成的字符串，第二行输入一个字符。

输出描述：

输出输入字符串中含有该字符的个数。（不区分大小写字母）

示例1

输入：
ABCabc
A

输出：

2

特殊Case：
8 8 8  8A i i OOI              IIIaa
A

 */

// int main() {
//     string s;
//     char c;
//     unordered_map<char, int> map;
//     while (cin >> s) { // 不能处理输入的字符串中含有空格的问题
//         cin >> c;
//         if (cin.get() == '\n') {
//             break;
//         }
//     }
//     // 核心代码
//     for (int i = 0; i < s.size(); i++) {
//         map[tolower(s[i])]++;
//     }
//     cout << map[tolower(c)] <<endl;
//     return 0;
// }

/*
12/13 组用例通过
运行时间
3ms
占用内存
424KB
*/

// 参考大佬的解法
// 简洁的写法 遍历字符的时候直接统计
// int main() { string s;
//     getline(cin, s);

//     char c = tolower(getchar());

//     uint16_t n = 0;
//     for (auto i : s) {
//         if (tolower(i) == c) {
//             ++n;
//         }
//     }
//     cout << n << endl;
//     return 0;
// }

// 解法2 哈希表
int main() { string s;
    char c;
    getline(cin, s);
    c = getchar();

    unordered_map<char, size_t> umap;
    for (auto i : s) {
        ++umap[tolower(i)];
    }
    cout << umap[tolower(c)] << endl;
    return 0;
}
