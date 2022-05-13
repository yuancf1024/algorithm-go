/*
33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）
上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., 
nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，
则返回它的下标，否则返回 -1 。

 

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：

输入：nums = [1], target = 0
输出：-1

*/

// 遍历+二分查找
/*解题思路：
旋转排序数组的特点，里面有一个突变点，突变点两侧都是有序的。
因此首先需要找到突变点，很容易想到：如果元素大于右边相邻元素，
则该元素就是突变点。
找突变点后，将target与突变点进行比较，确定在哪一侧进行二分查找。
**问题**：该实现只能部分通过测试用例：98 / 195
*/
// func search(nums []int, target int) int {
//     n := len(nums)
//     var point int = 0
//     for i := 0; i < n-1; i++ {
//         if nums[i] > nums[i+1] {
//             point = i
//         }
//     }

//     if nums[point] == target { // 突变点确定查找范围
//         return point
//     } else if nums[0] < target { // nums[0]是值的一个分界线
//         bsearch(nums, 0, point-1, target) // 
//     } else {
//         bsearch(nums, point+1, n-1, target) // 
//     }
//     return -1
// }

// func bsearch(nums[] int, low int, high int, value int) int {
//     for (low <= high) {
//         mid := low + ((high - low) >> 1)
//         if nums[mid] == value {
//             return mid
//         } else if nums[mid] > value {
//             high = mid - 1
//         } else {
//             low = mid + 1
//         }
//     }
//     return -1
// }

// 二分查找
/*思路：
如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，
则左半段是有序的，我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，
这样就可以确定保留哪半边了。
*/

package leetcode

func search33(nums []int, target int) int {
    n := len(nums)
    low := 0
    high := n-1
    for (low <= high) {
        mid := low + ((high - low) >> 1)
        if nums[mid] == target {
            return mid
        } else if nums[mid] < nums[high] {
            if nums[mid] < target && target <= nums[high] {
                low = mid + 1
            } else {
                high = mid - 1
            }
        } else {
            if nums[low] <= target && target < nums[mid] {
                high = mid - 1
            } else {
                low = mid + 1
            }
        }
    }
    return -1
}