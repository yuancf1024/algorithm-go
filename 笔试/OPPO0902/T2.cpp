/*
输入一个字符串和一个匹配的子串，
从字符串末尾往起始方向查找子串；
如果匹配成功，就返回最后一次匹配到字符串的位置，
即相对于字符串首字母的偏移，如果没有匹配到，则返回-1，
注意字符串中出现"*"，则它表示的任意一个字符。
*/

/*
"Hello world","ow"
7

"Hello world","l*o"
9

"Hello world Hello world","l**"
2

*/

#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * findStr从反方向查找子串，返回最后一次匹配成功时，子串的偏移位置，如果没有匹配成功返回-1
     * @param str string字符串 待匹配的字符串
     * @param mod string字符串 匹配模式字符串
     * @return int整型
     */
    int findStr(string str, string mod) {
        // write code here
        // 双重for循环+标记
        int res = -1;
        int n = str.size();
        int l = mod.size();
        for (int i = n - 1; i >= 0; --i) {
            int t = l-1;
            bool flag = true;
            for (int j = i; j + l > i ; j--) {
                if (str[j] != mod[l-t-1] && mod[l-t-1] != '*') {
                    flag = false;
                }
                t--;
            }
            if (flag) {
                res = i;
            }
        }
        return res;
    }
};

int main() {
    string str = "Hello world";
    string mod = "l**";
    Solution s;
    int res = s.findStr(str, mod);
    cout << res << endl;
    return 0;
}