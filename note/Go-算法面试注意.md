# Go-算法面试注意

## 算法思维

* 进入函数优先考虑边界
* 如果出现循环，进入循环时考虑`break`条件和`continue`条件
* 使用下标计算长度时，优先考虑区间的开闭
* 我们应该在做算法的过程中不断的思考和总结共性

## 面试注意

### 常用函数
一定要记得常用的函数，现场是没有办法可以查的

* 字符串去左右空格
* 字符串切割
* 随机数种子，随机数生成
* 内置排序函数
* int最小值最大值怎么取

**以Go为例**

```go
s = strings.TrimSpace(s)
arr := strings.Spilt(s, "")

rand.Seed(time.Now().UnixNano())
rand.Int()

sort.Int()
sort.Slice(x, func(i, j int)bool {
    // 降序
    return x[i]>x[j]
})

math.MaxInt32
math.MinInt32
```

### 输入输出

**牛客网**

- 输入：
  - `Scan`(常用): 使用"&"获取变量的内存地址, 通过键盘输入为变量指向的内存地址赋初值. 阻塞+可接收多个参数
  - `Scanln`: 用户输入参数默认使用**空格**分割输入设备传入的参数，遇到回车换行符就结束接收参数
  - `Sacnf`: 可以格式化用户输入的数据类型
- 输出：
  - `println`: Println 将变量的值取出来打印并换行,变量之间默认添加空格
  - `print`: Print 将变量的值取出来打印但不换行，变量之间默认直接连接
  - `printf`: 使用占位符格式化打印结果





## 牛客网面试注意

牛客网比较坑，一切输入输出都要自己实现


### 1-创建链表

还要劳记**链表创建代码**，[完整代码](https://github.com/coding3min/interview-leetcode/tree/5cb2e5224e55a017aa569f71ee31714371f1a8cd/LeetCode/all/0.%e5%88%9b%e5%bb%ba%e9%93%be%e8%a1%a8.go)

```go
package main

import "fmt"

type LinkNode struct {
    Val int
    Next *LinkNode
}

func createNode(a []int) *LinkNode {
    head := &LinkNode{
        0,
        nil,
    } // * 解引用，& 获取内存地址

    prev := head
    for i := 0; i<len(a); i++ {
        node := &LinkNode {
            a[i],
            nil,
        }
        prev.Next = node
        prev = node
    }
    return head.Next
}

func printLinkNode (node *LinkNode) {
    for node != nil {
        fmt.Println(node.Val)
        node = node.Next
    }
}

func main() {
    node := createNode([]int{1, 2, 3, 4, 5})
    printLinkNode(node)
}
// 1 2 3 4 5

```

### 2-创建二叉树

同时要**牢记二叉树的创建代码**，[完整代码](https://github.com/coding3min/interview-leetcode/tree/5cb2e5224e55a017aa569f71ee31714371f1a8cd/LeetCode/all/0.%e5%88%9b%e5%bb%ba%e4%ba%8c%e5%8f%89%e6%a0%91.go)

```go
package main

import "fmt"

type BTnode struct {
    Val int
    Left *BTnode
    Right *BTnode
}

func createTree(a []int) *BTnode {
    if len(a) == 0 || len(a)%2 == 0 {
        return nil
    }
    root := &BTnode{
        a[0],
        nil,
        nil,
    }
    stack := []*BTnode{root}
    i := 1
    for len(stack) > 0 && i < len(a) {
        node := stack[0]
        stack = stack[1:]
        node.Left = &BTnode{a[i], nil, nil}
        node.Right = &BTnode{a[i+1], nil, nil}
        stack = append(stack, node.Left)
        stack = append(stack, node.Right)
        i = i + 2
    }
    return root
}

func printTree(root *BTnode) {
    if root == nil {
        return
    }
    fmt.Println(root.Val)
    printTree(root.Left)
    printTree(root.Right)
}

func main() {
    root := createTree([]int{1, 2, 3, 4, 5})
    printTree(root)
}

// Output: 1 2 4 5 3
//     1
//    / \
//   2   3
//  / \
// 4   5
```

### 3-数字输入

**单个数字输入**

```go
package main

import (
    "fmt"
)

func main() {
    a := 0
    b := 0
    for {
        n, _ := fmt.Scan(&a, &b)
        if n == 0 {
            break
        } else {
            fmt.Printf("%d\n", a + b)
        }
    }
}
```

**输入N，然后输入N个数**

```go
package main

import (
    "fmt"
)

// 第一行输入N， 第二行是N个数
func main() {
    var n, m int
    for {
        a, _ := fmt.Scan(&n)
        if a == 0 {
            break
        }
        nums := make([]int, 0)
        for i := 0; i < n; i++ {
            _, _ = fmt.Scan(&m)
            nums = append(nums, m)
        }
        // 下面是处理逻辑
    }
}
```

### 4-字符输入

**输入单个字符**

```go

// 使用bufio.NewReader(os.Stdin)+ReadLine()
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    data, _, _ := reader.ReadLine()
    str := string(data)
    fmt.Println(str)
}

// 使用bufio.NewReader(os.Stdin)+ReadBytes()
func main() {
    reader := bufio.NewReader(os.Stdin)
    data, _ := reader.ReadBytes('\n')
    str := string(data)
    fmt.Println(str)
    return
}

// 使用bufio.NewReader(os.Stdin)+ReadString()
func main() {
    reader := bufio.NewReader(os.Stdin)
    data, _ := reader.ReadString('\n')
    str := string(data)
    fmt.Println(str)
    return
}

// 使用bufio.NewScanner(os.Stdin)+Scan()+Text()
func main() {
    scan := bufio.NewScanner(os.Stdin)
    scan.Scan()
    str := scan.Text()
    fmt.Println(str)
}

```

**第一行输入2个字符串a和b**

```go
package main

import (
    "fmt"
)

func main() {
    var a, b string
    for {
        n, _ := fmt.Scanf("%s %s", &a, &b)
        if n == 0 {
            break
        }
        // 下面是处理逻辑
    }
}
```


### 5-二维切片的创建

```go
// 一维切片的初始化
var a = [5]int{1, 2, 3, 4, 5} // 用var
b := [5]int{1, 2, 3, 4, 5} // 用类型推断
var c = [...]int{1, 2, 3, 4, 5} // 不确定长度
d := [...]int{1, 2, 3, 4, 5} 

var a [5]int
b := [5]int{}
c := make([]int, 5)

// 二维数组初始化, 固定长度时不能是变量
var a [3][4]int
a := [3][4]int{}

m, n := 3, 4
var a [m][n]int // 报错，必须是常量表达式

// 生成固定长度的二维切片，可以是变量
func main() {
	m, n := 3, 4
	a := make([][]int, m) // 二维切片，3行
	for i := range a {
		a[i] = make([]int, n) // 每一行4列
	}
	fmt.Println(a)
}
```

## 常用排序算法

常用排序算法在某些公司是会问到的，*思路和时间复杂度*如果都不知道，对结果的冲击是很大的.

|排序算法|	平均时间复杂度|	最坏时间复杂度|	最好时间复杂度|	空间复杂度|	稳定性|
|-|:-:|:-:|:-:|:-:|-|
|冒泡排序|	O(n²)|	O(n²)|	O(n)|	O(1)|	稳定
|直接选择排序|	O(n²)|	O(n²)|	O(n)|	O(1)|	不稳定
|直接插入排序|	O(n²)|	O(n²)|	O(n)|	O(1)|	稳定
|快速排序|	O(nlogn)|	O(n²)|	O(nlogn)|	O(nlogn)|	不稳定
|堆排序|	O(nlogn)|	O(nlogn)|	O(nlogn)|	O(1)|	不稳定
|希尔排序|	O(nlogn)|	O(ns)|	O(n)|	O(1)|	不稳定
|归并排序|	O(nlogn)|	O(nlogn)|	O(nlogn)|	O(n)|	稳定
|计数排序|	O(n+k)|	O(n+k)|	O(n+k)|	O(n+k)|	稳定
|基数排序|	O(N\*M) |	O(N\*M)|	O(N\*M)|	O(M)|	稳定

## Reference

1. https://leetcode.coding3min.com/leetcode/suan-fa-mian-shi-zhu-yi/
2. 
