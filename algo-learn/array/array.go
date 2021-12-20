package array

// 2021-12-20 该版本代码有bug，Append 方法写得有问题，找时间修改

import (
	"errors"
	"fmt"
)

// 动态数组的实现

// 数组本身在定义的时候需要预先指定大小，因为需要分配连续的内存空间。
// 如果我们申请了大小为 10 的数组，当第 11 个数据需要存储到数组中时，
// 我们就需要重新分配一块更大的空间，将原来的数据复制过去，
// 然后再将新的数据插入。

const (
	DefaultCapacity   = 16   // 默认容量
	CapacityThreshold = 1024 // 容量阈值
)

// 定义数组
type Array struct {
	data     []interface{}
	capacity int
	size     int
}

// 新建数组
func New(capacity int) *Array {
	if capacity == 0 {
		return nil
	}

	return &Array{ // & 取得对象的内存地址，即指向对象的指针
		make([]interface{}, capacity, capacity), // make内部的参数分别为数据,长度,容量
		capacity,
		0,
	}
}

// 新建默认数组
func Default() *Array {
	return New(DefaultCapacity)
}

// 插入元素
func (arr *Array) Add(index int, val interface{}) error {
	err := arr.checkIndex(index)
	if err != nil {
		return err
	}

	// 扩容
	if arr.size >= arr.capacity {
		if arr.capacity >= CapacityThreshold {
			arr.resize(int(float64(arr.capacity) * 1.25))
		} else {
			arr.resize(arr.capacity << 1) // 放大2倍
		}
	}

	copy(arr.data[index+1:], arr.data[index:])
	arr.data[index] = val
	arr.size++
	return nil
}

// 插入至尾部
func (arr *Array) Append(val interface{}) error {
	// return arr.Add(arr.size, val) // Bug:此处应该是在容量的基础上add值,可是这样这里又会超出索引
	return arr.Add(arr.size, val)
	// 插入点的index
	// for i := arr.size; arr.data[arr.size] != nil && i < arr.capacity; i++ {
	// }
	// return arr.Add(arr.size, val)
}

// 按照索引查找
func (arr *Array) Find(index int) (interface{}, error) {
	err := arr.checkIndex(index)
	if err != nil {
		return nil, err
	}

	return arr.data[index], nil
}

// 是否包含
func (arr *Array) Contains(val interface{}) bool {
	if arr.Empty() {
		return false
	}

	for _, v := range arr.data {
		if v == val {
			return true
		}
	}
	return false
}

// 删除索引处的值
func (arr *Array) Delete(index int) error {
	err := arr.checkIndex(index + 1)
	if err != nil {
		return err
	}
	if arr.data[index] == nil {
		return nil
	}

	arr.data[index] = nil
	copy(arr.data[index:], arr.data[index+1:])

	arr.data[arr.size-1] = nil
	arr.size--
	return nil
}

// 获取数组元素数量
func (arr *Array) Size() int {
	return arr.size
}

// 判断数组是否为空
func (arr *Array) Empty() bool {
	return arr.size == 0
}

// 打印数组所有元素值
func (arr *Array) PrintData() {
	for i := 0; i < arr.capacity; i++ {
		// if arr.data[i] != nil {
		// 	fmt.Printf("index %d = %d ", i,arr.data[i])
		// 	// fmt.Print(arr.data[i], " ")
		// }
		fmt.Printf("index %d = %d ", i, arr.data[i])
	}
	fmt.Println()
}

// 修改数组容量
func (arr *Array) resize(newCap int) {
	data := make([]interface{}, newCap, newCap)
	copy(data, arr.data) // 内置函数,从源切片复制到目标切片中,第一个是dst,第二个是src

	arr.data = data
	arr.capacity = newCap
}

// 检查索引
func (arr *Array) checkIndex(index int) error {
	if index < 0 || index > arr.capacity {
		return errors.New("index out of range error") // 用给定的文本新返回一个错误
	}
	return nil
}
