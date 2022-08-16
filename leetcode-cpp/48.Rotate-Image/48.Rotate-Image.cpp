/**
 * @file 48.Rotate-Image.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * leetcode-48.旋转图像
 * 
给定一个 n × n 的二维矩阵 matrix 表示一个图像。
请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。
请不要 使用另一个矩阵来旋转图像。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]

示例 2：
输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

提示：

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
 */

// 方法一：使用辅助数组
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) { 
        int n = matrix.size();
        // C++这里的 = 拷贝是值拷贝，会得到一个新的数组
        auto matrix_new = matrix;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix_new[j][n - i - 1] = matrix[i][j];
            }
        }
        // 这里也是值拷贝
        matrix = matrix_new;
    }
};

// 方法二：原地旋转 需要推导一定的公式
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) { 
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};

// 方法三：用翻转代替旋转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) { 
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

// 

/**
 * @brief 
 * 方法一：使用辅助数组
我们以题目中的示例二

5  1  9  11
2  4  8  10
13 3  6  7
15 14 12 16


作为例子，分析将图像旋转 90 度之后，这些数字出现在什么位置。

对于矩阵中的第一行而言，在旋转后，它出现在倒数第一列的位置：

5  1  9  11
o  o  o  o
o  o  o  o
o  o  o  o

旋转后
​
o  o  o  5
o  o  o  1
o  o  o  9
o  o  o  11
 
并且，第一行的第 x 个元素在旋转后恰好是倒数第一列的第x 个元素。

对于矩阵中的第二行而言，在旋转后，它出现在倒数第二列的位置：

o  o  o  o
2  4  8  10
o  o  o  o
o  o  o  o

旋转后

o  o  2  o
o  o  4  o
o  o  8  o
o  o 10  o
​

对于矩阵中的第三行和第四行同理。这样我们可以得到规律：

> 对于矩阵中第i 行的第j 个元素，在旋转后，
它出现在倒数第i 列的第j 个位置。

我们将其翻译成代码。由于矩阵中的行列从0 开始计数，
因此对于矩阵中的元素matrix[row][col]，
在旋转后，它的新位置为matrix_new[col][n−row−1]。

这样以来，我们使用一个与matrix 大小相同的辅助数组 
matrix_new，临时存储旋转后的结果。
我们遍历matrix 中的每一个元素，根据上述规则将该元素存放到matrix_new中对应的位置。

在遍历完成之后，再将matrix_new​中的结果复制到原数组中即可。

复杂度分析

时间复杂度：O(N^2)，其中N是matrix 的边长。
空间复杂度：O(N^2)。我们需要使用一个和matrix 大小相同的辅助数组。



方法二：原地旋转

题目中要求我们尝试在不使用额外内存空间的情况下进行矩阵的旋转，
也就是说，我们需要「原地旋转」这个矩阵。那么我们如何在方法一的基础上
完成原地旋转呢？

我们观察方法一中的关键等式：

matrix_new[col][n−row−1]=matrix[row][col]

它阻止了我们进行原地旋转，这是因为如果我们直接将matrix[row][col] 
放到原矩阵中的目标位置matrix[col][n−row−1]：

matrix[col][n−row−1]=matrix[row][col]

原矩阵中的matrix[col][n−row−1] 就被覆盖了！这并不是我们想要的结果。
因此我们可以考虑用一个临时变量 temp 暂存 matrix[col][n−row−1] 的值，
这样虽然matrix[col][n−row−1] 被覆盖了，我们还是可以通过temp 获取它原来的值：

  
temp = matrix[col][n−row−1]
matrix[col][n−row−1] = matrix[row][col]
​
那么matrix[col][n−row−1] 经过旋转操作之后会到哪个位置呢？
我们还是使用方法一中的关键等式，不过这次，我们需要将

row = col
col = n−row−1

带入关键等式，就可以得到：

matrix[n−row−1][n−col−1]=matrix[col][n−row−1]

同样地，直接赋值会覆盖掉matrix[n−row−1][n−col−1] 原来的值，
因此我们还是需要使用一个临时变量进行存储，不过这次，
我们可以直接使用之前的临时变量temp：

temp = matrix[n−row−1][n−col−1]
matrix[n−row−1][n−col−1] = matrix[col][n−row−1]
matrix[col][n−row−1] = matrix[row][col]
​

我们再重复一次之前的操作，matrix[n−row−1][n−col−1] 经过旋转操作之后会到哪个位置呢？

row = n−row−1
col = n−col−1
​

带入关键等式，就可以得到：

matrix[n−col−1][row]=matrix[n−row−1][n−col−1]

写进去：


temp = matrix[n−col−1][row]
matrix[n−col−1][row] = matrix[n−row−1][n−col−1]
matrix[n−row−1][n−col−1] = matrix[col][n−row−1]
matrix[col][n−row−1] = matrix[row][col]
​

不要灰心，再来一次！matrix[n−col−1][row] 经过旋转操作之后回到哪个位置呢？

row = n−col−1
col = row
​

带入关键等式，就可以得到：

matrix[row][col]=matrix[n−col−1][row]

我们回到了最初的起点 matrix[row][col]，也就是说：

matrix[row][col]
matrix[col][n−row−1]
matrix[n−row−1][n−col−1]
matrix[n−col−1][row]
​

这四项处于一个循环中，并且每一项旋转后的位置就是下一项所在的位置！
因此我们可以使用一个临时变量temp 完成这四项的原地交换：


temp = matrix[row][col]
matrix[row][col] = matrix[n−col−1][row]
matrix[n−col−1][row] = matrix[n−row−1][n−col−1]
matrix[n−row−1][n−col−1] = matrix[col][n−row−1]
matrix[col][n−row−1] = temp
​

当我们知道了如何原地旋转矩阵之后，还有一个重要的问题在于：
我们应该枚举哪些位置(row,col) 进行上述的原地交换操作呢？
由于每一次原地交换四个位置，因此：

- 当 n为偶数时，我们需要枚举 n^2 / 4 = (n/2)×(n/2) 个位置，
可以将该图形分为四块，以4×4 的矩阵为例：


保证了不重复、不遗漏；

- 当 n为奇数时，由于中心的位置经过旋转后位置不变，
我们需要枚举 (n^2-1) / 4 = ((n−1)/2)×((n+1)/2) 个位置，
需要换一种划分的方式，以5×5 的矩阵为例：

同样保证了不重复、不遗漏，矩阵正中央的点无需旋转。

复杂度分析

时间复杂度：O(N^2)，其中N 是matrix 的边长。
我们需要枚举的子矩阵大小为O(⌊n/2⌋×⌊(n+1)/2⌋)=O(N^2)。

空间复杂度：O(1)。为原地旋转。


方法三：用翻转代替旋转
我们还可以另辟蹊径，用翻转操作代替旋转操作。我们还是以题目中的示例二

5  1  9  11
2  4  8  10
13 3  6  7
15 14 12 16
​

作为例子，先将其通过水平轴翻转得到：

5  1  9  11
2  4  8  10
13 3  6  7
15 14 12 16
​
水平翻转

​15 14 12 16
13 3  6  7
2  4  8  10
5  1  9  11


再根据主对角线翻转得到：

​15 14 12 16
13 3  6  7
2  4  8  10
5  1  9  11
  
主对角线翻转
​
​15 13 2  5
14 3  4  1
12 6  8  9
16 7 10  11

就得到了答案。这是为什么呢？对于水平轴翻转而言，
我们只需要枚举矩阵上半部分的元素，和下半部分的元素进行交换，即

matrix[row][col] 水平轴翻转 matrix[n−row−1][col]

对于主对角线翻转而言，我们只需要枚举对角线左侧的元素，
和右侧的元素进行交换，即

matrix[row][col] 主对角线翻转 matrix[col][row]

将它们联立即可得到：

matrix[row][col] 水平轴翻转   matrix[n−row−1][col]
                 主对角线翻转 matrix[col][n−row−1]
​
和方法一、方法二中的关键等式：

matrix_new[col][n−row−1]=matrix[row][col]

是一致的。

复杂度分析

时间复杂度：O(N^2)，其中N 是 matrix 的边长。
对于每一次翻转操作，我们都需要枚举矩阵中一半的元素。

空间复杂度: O(1)。为原地翻转得到的原地旋转。

 */