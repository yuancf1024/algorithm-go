/* T1 Palindrome number 回文数

Description

Donciclearned the concept of palindrome number in class today. 
The palindrome number refers to an integer whose positive order 
(from left to right) and reverse order (from right to left) are 
the same.Please write a program to help him judge whether 
the numbers are palindrome.

Input

-2^31 <= x <= 2^31 - 1

Input an integer x.

Output

Returns true if x is a palindrome integer; otherwise, 
returns false.

Sample Input 1 

121

Sample Output 1

true

Sample Input 2 

-121

Sample Output 2

false

Sample Input 3 

10

Sample Output 3

false

Hint

Please pay attention to the data size.

题解: 输入一个数字判断是否是回文数.

比赛Golang实现思路: 判断输入是否小于0,如果小于0,返回false;
如果大于0,继续逻辑判断,将数字转化为字符串,使用双指针,
慢指针指向头部,快指针指向尾部,逐一比对是否相等;
如果相等,slow&fast向中间靠拢,否则,res=false,break

推荐思路: 大佬 @iphelf 的思路和我的一样,基本上是从处理字符串的角度出发的.😂
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    string number;
    while (cin >> number) {
        bool ok = true;
        if (number.back() == 0) // 判断尾字符是否为0
            number.pop_back();
        for (int i = 0; i < number.length(); i++) {
            if (number[i] != number[number.length() - 1 - i]) {
                ok = false;
                break;
            }
        }
        puts(ok ? "true" : "false");
    }
    return 0;
}
