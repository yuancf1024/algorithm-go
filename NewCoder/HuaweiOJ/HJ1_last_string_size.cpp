#include <iostream>
#include <string>
using namespace std;

int main() { 
    string a; 
    while (cin >> a) {
        if (cin.get() == '\n') {
            break;
        }
        // cout << a.size() << endl;
    }
    cout << a.size();
    return 0;
}

/**
 * @brief HJ1 字符串最后一个单词的长度
 * 描述
计算字符串最后一个单词的长度，单词以空格隔开，字符串长度小于5000。
（注：字符串末尾不以空格为结尾）

输入描述：
输入一行，代表要计算的字符串，非空，长度小于5000。

输出描述：
输出一个整数，表示输入字符串最后一个单词的长度。

示例1
输入：
hello nowcoder

输出：
8

说明：最后一个单词为nowcoder，长度为8 
 * 
 */


/*
#include <iostream>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        cout << a + b << endl;
    }
}
// 64 位输出请用 printf("%lld")
*/