package leetcode

// 自己写的
func intersection(nums1 []int, nums2 []int) []int {
    var res []int
    m := map[int]int{} 

    for _, i := range nums1 {
        m[i]++
    }

    for _, j := range nums2 {
        if m[j] > 0 {
            res = append(res, j)
            m[j] = 0
        }
    }
    return res
}
/*
对于重复元素只需要输出一次，因此不必对每个元素计数，只需要记录其存在即可，
因此使用map[int]bool;
Go语言中删除散列表的操作：delete(m, j)
*/


/*Solution:
把数组一的每个数字都存进字典中，然后在数组二中依次判断字典中是否存在，
如果存在，在字典中删除它(因为输出要求只输出一次)。
*/

func intersection1(nums1 []int, nums2 []int) []int {
	m := map[int]bool{}
	var res []int
	for _, n := range nums1 {
		m[n] = true
	}
	for _, n := range nums2 {
		if m[n] {
			delete(m, n)
			res = append(res, n)
		}
	}
	return res
}