#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'is_all_brackets_closed' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts STRING text as parameter.
 */

/*
括号匹配
*/

// 辅函数
char leftOf(char c) {
    if (c == ')') {
        return '(';
    }
    if (c == ']') {
        return '[';
    }
    return '{';
    
}

bool is_all_brackets_closed(string text) {
    stack<char> left;
    for (auto& x : text) {
        if (x == '(' || x == '[' || x == '{') {
            left.push(x);
        }
        else {
            if (!left.empty() && leftOf(x) == left.top()) {
                left.pop();
            }
            else {
                return false;
            }
        }
    }
    return left.empty();
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string text;
    getline(cin, text);

    bool result = is_all_brackets_closed(text);

    fout << result << "\n";

    fout.close();

    return 0;
}
