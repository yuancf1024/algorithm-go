/**
 * @file 640.Solve-the-Equation.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-10
 * 
 * @copyright Copyright (c) 2022
 * leetcode-640.Solve the Equation
 * 
求解一个给定的方程，将x以字符串 "x=#value" 的形式返回。
该方程仅包含 '+' ， '-' 操作，变量 x 和其对应系数。

如果方程没有解，请返回 "No solution" 。
如果方程有无限解，则返回 “Infinite solutions” 。

如果方程中只有一个解，要保证返回值 'x' 是一个整数。题目保证有解时解是整数

示例 1：
输入: equation = "x+5-3+x=6+x-2"
输出: "x=2"

示例 2:
输入: equation = "x=x"
输出: "Infinite solutions"

示例 3:
输入: equation = "2x=x"
输出: "x=0"

提示:
3 <= equation.length <= 1000
equation 只有一个 '='.
equation 方程由整数组成，其绝对值在 [0, 100] 范围内，
不含前导零和变量 'x' 。 
 */

class Solution {
public:
    string solveEquation(string equation) { 
        int factor = 0, val = 0; // 变量系数、常量值
        int index = 0, n = equation.size(), sign1 = 1; // 等式左边默认系数为正
        while (index < n) {
            if (equation[index] == '=') { // 遇到等式前系数为正
                sign1 = -1; // 等式右边默认系数为负
                index++;
                continue;
            }

            int sign2 = sign1, number = 0;
            bool valid = false; // 记录number是否有效
            if (equation[index] == '-' || equation[index] == '+') {
                sign2 = (equation[index] == '-') ? -sign1 : sign1;
                index++;
            }
            while (index < n && isdigit(equation[index])) { // 解析多位数
                number = number * 10 + (equation[index] - '0');
                index++;
                valid = true;
            }
            if (index < n && equation[index] == 'x') { // 变量
                factor += valid ? sign2 * number : sign2;
                index++;
            } else { // 数值
                val += sign2 * number;
            }
        }
        if (factor == 0) {
            return val == 0 ? "Infinite solutions" : "No solution";
        }
        if (val % factor != 0) {
            return "No solution";
        }
        return string("x=") + to_string(-val / factor);
    }
};

/**
 * @brief 
 * 方法一：解析
我们将等式右边的项都移到等式左边，那么等式右边的项的默认系数为−1。
我们依次解析方程的项，并将同类项进行合并，使用 factor 表示变量的系数，
val 表示常量值。

初始时默认系数 sign_1=1，当我们解析到等号时，说明解析到等式右边的项，
令 sign_1 = -1。使用变量sign_2表示项的符号，
初始时sign_2 = sign_1，如果我们解析到 ‘+’ 或 ‘-’，
那么相应的更改 sign_2​。
使用 number 记录数字，valid 表示number 是否有效（变量 xx 前面可能没有数字），
如果我们解析到的项是变量项，那么相应的更改factor；
如果我们解析到的项是常量项，那么相应的更改 val。

如果 factor=0 成立，说明变量 x 对方程无影响，然后判断 val=0 是否成立，
成立则说明方程有无数解，返回 "Infinite solutions", 
否则返回 "No solution"。如果 val mod factor != 0，
说明方程无整数解，返回 "No solution"，
否则返回对应的整数解 x=  −val / factor。

不同语言对于负数取余的处理不同，但是本题只需要判断 val 能否被factor 整除，
即判断余数是否为零，因此余数的正负对结果无影响。

复杂度分析
时间复杂度：O(n)，其中 n 是字符串 equation 的长度。

空间复杂度：O(1)。
 */