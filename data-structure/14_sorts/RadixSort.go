package _4_sorts


// 辅助函数，求数据的最大位数
func maxbit(data []int, n int) int {
	var maxData int = data[0] // 最大数
	for i := 1; i < n; i++ {
		if maxData < data[i] {
			maxData = data[i]
		}
	}
	var d int = 1
	var p int = 10
	for maxData >= p {
		maxData /= 10
		d++
	}
	return d
}

// 基数排序,data 输入的数组，n 数组元素数量
func RadixSort(data []int, n int) {

	d := maxbit(data, n)
	tmp := make([]int, n) // 
	count := make([]int, 10) // 计数器

	var radix int = 1

	for i := 1; i <= d; i++ { // 进行d次排序
		for j := 0; j < 10; j++ {
			count[j] = 0 // 每次分配前清空计数器
		}

		for j := 0; j < n; j++ {
			k := (data[j] / radix) % 10 // 统计每个桶中的记录数
			count[k]++
		}

		for j := 1; j < 10; j++ {
			count[j] += count[j-1] //将tmp中的位置依次分配给每个桶
		}

		for j := n-1; j >= 0; j-- { // 将所有桶中记录依次收集到tmp中
			k := (data[j] / radix) % 10
			tmp[count[k] - 1] = data[j]
			count[k]--
		}

		for j := 0; j < n; j++ { // 将临时数组的内容复制到data中
			data[j] = tmp[j]
		}

		radix = radix * 10
	}

}
