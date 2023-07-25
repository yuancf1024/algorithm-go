/**
 * @file T2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-27
 * 
 * @copyright Copyright (c) 2022
 * 不及格的小A
时间限制： 3000MS
内存限制： 786432KB
题目描述：
小A的英语考了个不及格，老师很生气，
并且发现他英语的语法几乎全错！
于是老师决定好好教教他英语语法。

老师想先从句子结构开始教他。
一个句子至少需要包含主谓结构，即主语和谓语，
并且主语在前，谓语在后。有些句子会在谓语后面加上宾语。
避免复杂，本题中句子的顺序严格按照
主语-谓语-宾语的顺序（即无宾语前置和倒装等情况）。

老师给了小A三张单词表，分别是主语单词表、谓语单词表
和宾语单词表。老师要让小A用这些单词表中的单词来造句，
并且规定：
- 谓语有且仅有一个单词，
- 主语和宾语可以包含任意个单词（主语不可为空）。

老师暂时不想让小A造出能保证意思通顺的句子，
他只想让小A能够学会基本的句子结构就行。

现在，小A根据这些单词造了m条句子，
现在假设你是老师，你需要判断每条句子
是否符合上述句子结构。


输入描述
第一行三个正整数n1,n2,n3，
分别表示主语、谓语、宾语单词表的单词数；

第二行包含n1个单词，单词仅由小写英文字母组成，
每两个单词之间有一个空格，单词长度不超过10；

第三行包含n2个单词，其他格式同上；

第四行包含n3个单词，其他格式同上；

第五行一个正整数m；

接下来m行，每行一个句子。
句子由若干单词（至少一个）组成，
并且保证出现的单词都在上面的单词表内。
每两个单词之间一个空格隔开。

数据保证一个单词最多只可做一种句子成分。
即每个单词仅会出现在一个单词表上。

1≤n1,n2,n3≤1000,
1≤m≤20,
1≤句子单词数≤10

输出描述
对于每条句子，如果其符合句子结构，
输出一行“YES”（不含引号），
否则输出一行“NO”（不含引号）。


样例输入
3 3 3
i you he
am is are
yours his hers
5
i am yours
you is his
he are hers yours
i am am yours
is his

样例输出
YES
YES
YES
NO
NO

提示
第四个句子谓语含有两个单词，不合法；
第五个句子。不含主语，不合法。

 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    // 读取数据
    int n1, n2, n3;
    int m;
    // vector<string> sub;
    // vector<string> verb;
    // vector<string> obj;
    // vector<string> sentences;
    unordered_set<string> sub;
    unordered_set<string> verb;
    unordered_set<string> obj;

    string temp;
    cin >> n1 >> n2 >> n3;
    for (int i = 0; i < n1; ++i) {
        cin >> temp;
        sub.insert(temp);
    }

    for (int i = 0; i < n2; ++i) {
        cin >> temp;
        verb.insert(temp);
    }

    for (int i = 0; i < n3; ++i) {
        cin >> temp;
        obj.insert(temp);
    }

    
    cin >> m;
    string s;
    // char t;
    // 核心代码
    for (int i = 0; i < m;) {
        vector<string> sen;
        while (cin >> s) {
            sen.push_back(s);
            if (cin.get() == '\n') {

                // 判断
                int n = sen.size();
                if (n == 1) {
                    cout << "NO" << endl;
                    break;
                }
                if (n == 2) {
                    if (sub.count(sen[0]) && verb.count(sen[1])) { // 跳过前面的主语
                        cout << "YES" << endl;
                    }
                    else {
                        cout << "NO" << endl;
                    }
                    break;
                }
                bool flag =  false;
                int numVerb = 0;
                for (int k = 0; k < n - 1; ++k) {
                    if (sub.count(sen[k]) && verb.count(sen[k+1])) { // 跳过前面的主语
                        flag = true;
                    }
                }
                for (int j = 0; j < n; ++j) {
                    if (verb.count(sen[j])) {
                        numVerb++;
                    }
                }
                if (numVerb > 1) {
                    flag = false;
                }

                if (flag) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
                break;
            }
        }
        ++i;
    }

    // 核心代码
    // cout <<
    return 0;
}