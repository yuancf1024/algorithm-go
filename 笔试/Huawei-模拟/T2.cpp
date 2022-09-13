/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-13
 *
 * @copyright Copyright (c) 2022
 * 2. Vowel
 * 元音字母大写，辅音字母小写
样例1：
Who Love Solo
whO lOvE sOlO
 */

/*
以下代码会有bug
辅音大写转小写 ok
元音小写转大写 no

Pass 100%
*/
#include <bits/stdc++.h>

using namespace std;

bool isa(char x) {
    bool flag = false;
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
        flag = true;
    }
    return flag;
}

bool isNotA(char x) {
    bool flag = false;
    if ( x != 'A' && x != 'E' && x != 'I' && x != 'O' && x != 'U') {
        flag = true;
    }
    return flag;
}

int main() {
    string s;
    getline(cin, s);
    // string res;
    for (int i = 0; i < s.size(); ++i) {
        // 小写元音变大写
        if (isa(s[i])) {
            s.at(i) = toupper(s[i]); // 
            // res += s[i];
        }

        // 大写辅音变小写 转换思路-> 只要不是大写的元音，全部换成小写
        if (isNotA(s[i])) {
            s.at(i) = tolower(s[i]);
            // res += s[i];
        }
    }
    cout << s << endl;
    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int main() { 
//     char str[10010];
//     char temp[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
//     getline(cin, str);
//     int len = strlen(str);
//     for (int i = 0; i < len; ++i) {
//         int flag = 1;
//         for (int j = 0; j < 10; ++j) {
//             if (str[i] == temp[j]) {
//                 flag = 0;
//                 if (str[i] >= 'a' && str[i] <= 'z') {
//                     str[i] = str[i] - 32;
//                 }
//                 break;
//             }
//         }
//         if (flag != 0) {
//             if (str[i] >= 'A' && str[i] <= 'Z') {
//                 str[i] = str[i] + 32;
//             }
//         }
//     }
//     cout << str << endl;
//     return 0;
// }