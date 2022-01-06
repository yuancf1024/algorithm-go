package Recursion

import "fmt"

// 实现一组数据集合的全排列
// 排列类型结构体
type RangeType struct {
	value []interface{}
}

// 新建排列切片，返回一个指向ta的指针
func NewRangeArray(n int) *RangeType {
	return &RangeType{
		make([]interface{}, n), // n代表切片长度
	}
}

// 求全排列
func (slice *RangeType) RangeALL (start int) {
	len := len(slice.value)
	if start == len -1 {
		// 如果已经是最后位置，直接将数组数据合并输出
		fmt.Println(slice.value)
	}

	// 2022-01-06 这段递归代码不是很好理解，需要反复思考

	for i := start; i < len; i++ {
		// i = start 时输出自己
		// 如果i和start的值相同就没有必要交换
		if i == start || slice.value[i] != slice.value[start] {
			// 交换当前这个与后面的位置
			slice.value[i], slice.value[start] = slice.value[start], slice.value[i]
			// 递归处理索引+1
			slice.RangeALL(start+1)
			// 换回来，因为是递归，如果不换回来会影响后面的操作，并且出现重复
			slice.value[i], slice.value[start] = slice.value[start], slice.value[i]
		}
	}
}
