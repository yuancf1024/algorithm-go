package leetcode

import (
	"testing"
	"github.com/yuancf1024/algorithm-go/structures"
)

func TestAverageOfLevels(t *testing.T) {
	arr := []int{3, 9, 20, structures.NULL, structures.NULL, 15, 7}
	root := structures.Ints2TreeNode(arr)
	output := averageOfLevels(root)
	// 输出：[3.00000,14.50000,11.00000]
	t.Log(output)
}

func TestAverageOfLevels1(t *testing.T) {
	arr := []int{3, 9, 20, structures.NULL, structures.NULL, 15, 7}
	root := structures.Ints2TreeNode(arr)
	output := averageOfLevels1(root)
	// 输出：[3.00000,14.50000,11.00000]
	t.Log(output)
}