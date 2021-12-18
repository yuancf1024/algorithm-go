# Go-algorithm

[toc]

## 更新记录

- [x] 2021-11-11 创建Go-algorithm
- [x] 2021-12-01 开始一点点
- [ ] 
## Readme

参考阿里霜神的[Leetcode-cookbook](https://books.halfrost.com/leetcode) 

## 模板

**题目大意**

**解题思路**

**code**

# leetcode-go

## 01-Array

### 001-Two Sum

**题目大意**

在数组中找到 2 个数之和等于给定值的数字，结果返回 2 个数字在数组中的下标。

Example:

```go
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]
```

**解题思路**

这道题最优的做法时间复杂度是 O(n)。

顺序扫描数组，对每一个元素，在 map 中找能组合给定值的另一半数字，如果找到了，直接返回 2 个数字的下标即可。如果找不到，就把这个数字存入 map 中，等待扫到“另一半”数字的时候，再取出来返回结果。

```go
package leetcode
func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
    for i := 0; i < len(nums); i++ {
        another := target - nums[i]
        if _, ok := m[another]; ok {
            return []int{m[another], i}
        }
        m[nums[i]] = i
    }
    return nil
}
```

### 026-Remove Duplicates from Sorted Array

**题目大意** 

给定一个有序数组 nums，对数组中的元素进行去重，使得原数组中的每个元素只有一个。最后返回去重以后数组的长度值。

**Clarification 说明**

为什么返回值是整数而你的答案是数组?  
 
注意，输入数组是通过引用传入的，这意味着对输入数组的修改也会被调用者知道。  
 
在内部你可以这样想:  

```c++
// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

**示例 1：**

输入：nums = [1,1,2]
输出：2, nums = [1,2]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。

**示例 2：**

输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。

**解题思路**
这道题和第 27 题很像。这道题和第 283 题，第 27 题基本一致，283 题是删除 0，27 题是删除指定元素，这一题是删除重复元素，实质是一样的。

*这里数组的删除并不是真的删除，只是将删除的元素移动到数组后面的空间内，然后返回数组实际剩余的元素个数*，OJ 最终判断题目的时候会读取数组剩余个数的元素进行输出。

```go
// 解法1

func removeDuplicates(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    last, finder := 0, 0
    for last < len(nums)-1 {
        for nums[finder] == nums[last] {
            finder++
            if finder == len(nums) {
                return last + 1
            }
        }
        nums[last+1] = nums[finder]
        last++
    }
    return last + 1
}

// 解法2
func removeDuplicates1(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    length := len(nums)
    lastNum := nums[length-1]
    i := 0
    for i = 0; i < length-1; i++ {
        if nums[i] == lastNum {
            break
        }
        if nums[i+1] == nums[i] {
            removeElement1(nums, i+1, nums[i])
            // fmt.Printf("此时 num = %v length = %v\n", nums, length)
        }
    }
    return i + 1
}

func removeElement1(nums []int, start, val int) int {
    if len(nums) == 0 {
        return 0
    }
    j := start
    for i := start; i < len(nums); i++ {
        if nums[i] != val {
            if i != j {
                nums[i], nums[j] = nums[j], nums[i]
                j++
            } else {
                j++
            }
        }
    }
    return j
}
```

**leetcode 官方题解**

*双指针&快慢指针*

```go
func removeDuplicates(nums []int) int {
    n := len(nums)
    if n == 0{
        return 0
    }
    slow := 1
    for fast := 1; fast<n; fast++ {
        if nums[fast] != nums[fast-1] {
            nums[slow] = nums[fast]
            slow++
        }
    }
    return slow
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，其中 n 是数组的长度。快指针和慢指针最多各移动 n 次。
* 空间复杂度：$O(1)$。只需要使用常数的额外空间。

### 027-Remove Element

给定一个数组 nums 和一个数值 val，将数组中所有等于 val 的元素删除，并返回剩余的元素个数。

**解题思路**
这道题和第 283 题很像。这道题和第 283 题基本一致，283 题是删除 0，这一题是给定的一个 val，实质是一样的。

这里数组的删除并不是真的删除，只是将删除的元素移动到数组后面的空间内，然后返回数组实际剩余的元素个数，OJ 最终判断题目的时候会读取数组剩余个数的元素进行输出。

```go
// 自己写的
func removeElement(nums []int, val int) int {
    if len(nums) == 0 {
        return 0
    }
    slow, fast := 0, 0
    for fast < len(nums) {
        if nums[fast] != val {
            nums[slow] = nums[fast]
            slow++
        }
        fast++
    }
    return slow
}

// 修改打磨版本
func removeElement(nums []int, val int) int {
    n := len(nums)
    if n == 0 {
        return 0
    }
    // slow, fast := 0, 0
    slow := 0
    for fast := 0; fast < n; fast++ {
        if nums[fast] != val {
            nums[slow] = nums[fast]
            slow++
        }
    }
    return slow
}

// 官方题解：
```

