# Go-算法面试注意

## 算法思维

* 进入函数优先考虑边界
* 如果出现循环，进入循环时考虑`break`条件和`continue`条件
* 使用下标计算长度时，优先考虑区间的开闭
* 我们应该在做算法的过程中不断的思考和总结共性

## 面试注意

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

## 牛客网面试注意

牛客网比较坑，一切输入输出都要自己实现

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
