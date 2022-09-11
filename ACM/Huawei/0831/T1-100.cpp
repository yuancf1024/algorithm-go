/**
 * @file T1-100.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-10
 * 
 * @copyright Copyright (c) 2022
 * 【2022-08-31】华为秋招笔试三道编程题
 * 
 * 第一题：字符串压缩
题目描述
给定一段英文句子和一个英文单词列表。
英文句子包含英文单词和标点符号，其中:
1. 英文单词只包含[a-zA-Z]范围内的字符;
2. 标点符号包括逗号、句号、双引号(双引号两边至少有一个空格)。

如果列表中有单词在句子中存在(大小写不敏感)且该单词未被双引号包含，
则使用该单词在列表中的索引值(索引值从0开始)代替句子中的该单词，
如果英文单词列表中存在重复的英文单词，
则以该单词最后一次出现的索引值进行替换。

输入描述

第一行：一段英文句子

第二行：英文单词列表

提示:

每个英文单词长度在[150]范围内。

输入的英文句子长度在[0,10000]范围内。

输入的英文单词列表长度在[0,100000]范围内。

英文句子中不会出现双引号不匹配的情况。

Hello world.
Good Hello LOOP

解释:

hello在英文句子中存在，则使用hello的索引值进行替换，得到结果为1world.

输出描述

替换后的英文句子

1world.

样例2：
输入
An introduction is "the first paragraph" of your paper
what say first Second IS introduction IS end

An 5 6 "the first paragraph" of your paper
 */


// 方法1：参考TechGuide
/*
思路：

大佬的这种方法无法通过样例2：
An introduction is "the first paragraph" of your paper
what say first Second IS introduction IS end

An 5 6 "the first paragraph" of your

复盘：
本题考察基本的模拟能力，对于一些地方的处理值得借鉴：
- 处理集合中重复元素，如果是取相同元素的最后一个，可以使用有序图map，key为元素，value为下标
- 如果字符串大小写不敏感，可以编写一个chnage函数，将要判断的字符串统一成大写形式
- 判断单词，可以写一个check函数，只要看每个字符是否都是'a'-'z'&'A'-'Z'
- 截取单词的技巧，使用substr()函数和下标索引值截取
- 标点符号(',' '.')的处理非常巧妙 ans += s[i]; 
i是单词的字母数量，i是句子中单词最后一个单词后面字符的索引下标
*/

#include <bits/stdc++.h>

using namespace std;

map<string, int> aa; // 有序map，如果存在，那么自动以最后一次出现value为k-v对

// 将小写转成大写
void change(string& s) { 
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32;
        }
    } 
}

// 检查是否是大小写字母
bool check(char aa) {
    if (aa >= 'A' && aa <= 'Z') {
        return true;
    }
    if (aa >= 'a' && aa <= 'z') {
        return true;
    }
    return false;
}

int main() {
    // 读取数据
    string s;
    getline(cin, s);
    string s1;
    int tt = 1;
    // while (cin >> s1) { // 这样写跳不出循环
    //     change(s1);
    //     aa[s1] = tt;
    //     tt++;
    // }
    while (1) {
        cin >> s1; // 读入单词字符串
        change(s1);
        aa[s1] = tt; // 存储到map，key为单词，value为索引值
        tt++;
        if (cin.get() == '\n') { // 读到换行符结束输入
            break;
        }
    }

    string ans;
    int begin1 = 0;
    for (int i = 0; i < s.length(); ++i) {
        // 被双引号包含的字符串要跳过
        if (s[i] == '"') {
            i++;
            while (i < s.length() && s[i] != '"') { // 跳出前面匹配到的双引号字符串
                i++;
            }
        }
        // 确保读一个完整的单词(不包含标点符号)
        while (i < s.length() && check(s[i])) {
            i++;
        }
        // 如果读到的字符超出英文句子长度，直接退出
        if (i == s.length()) {
            break;
        }
        string tl = s.substr(begin1, i - begin1); // 截取到单词
        begin1 = i + 1; // 下一次截取单词的首部索引
        string ts = tl;
        change(tl); // 单词的全大写形式
        if (aa[tl] != 0) { // tl在单词列表中出现过
            ans += to_string(aa[tl] - 1); // 用其索引值来代替原单词
        } 
        else { //如果在单词列表中找不到，则原样显示
            ans += ts;
        }
        ans += s[i]; // 添加英文句子中单词后面的标点符号
    }
    cout << ans << endl;
    return 0;
}


/*
方法2：参考Q群大佬
大佬的这种方法对API用得很熟
然后好像有bug，但是我没有时间debug了
后面找时间完成
2022-09-10
TODO

*/
// #include <bits/stdc++.h>

// using namespace std;

// int main() { 
//     string line, tmp, str;
//     vector<string> words;
//     vector<vector<int>> record;
//     getline(cin, line);
//     tmp = line;
//     transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
//     getline(cin, str);
//     transform(str.begin(), str.end(), str.end(), ::tolower);

//     vector<int> pair(2, 0);
//     bool flag = false;
//     for (int i = 0; i < line.size(); ++i) {
//         if (line[i] == '"') {
//             if (!flag) {
//                 pair[0] = i;
//             } else {
//                 pair[1] = i;
//                 record.push_back(pair);
//             }
//             flag = true;
//         }
//     }

//     string tmpStr;
//     stringstream ss(str);
//     while (ss >> tmpStr) {
//         words.push_back(tmpStr);
//     }

//     map<string, int> mp;
//     for (int i = 0; i < words.size(); ++i) {
//         mp[words[i]] = i;
//     }
//     auto findIn = [record](int index) {
//         for (auto& item : record) {
//             if (index > item[0] && index < item[1]) {
//                 return true;
//             }
//         }
//         return false;
//     };

//     for (auto& item : mp) {
//         auto pos = tmp.find(item.first);
//         if (pos != -1 && !findIn(pos)) {
//             line.replace(pos, item.first.size(), to_string(item.second));
//             tmp.replace(pos, item.first.size(), to_string(item.second));
//         }
//     }

//     cout << line << endl;
//     return 0;
// }