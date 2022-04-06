package heap

type Heap struct {
	a []int
	n int
	count int
}

// init heap 初始化堆
func NewHeap(capacity int) *Heap {
	heap := &Heap{}
	heap.n = capacity
	heap.a = make([]int, capacity+1)
	heap.count = 0
	return heap
}

// top-max heap -> heapify from down to up
// 最大堆的插入，自底向上堆化
func (heap *Heap) insert(data int) {
	// defensive
	if heap.count == heap.n {
		return
	}

	heap.count++
	heap.a[heap.count] = data

	// compare with parent node
	i := heap.count
	parent := i / 2
	for parent > 0 && heap.a[parent] < heap.a[i] {
		swap(heap.a, parent, i)
		i = parent
		parent = i / 2
	}
}

// heapify from up to down 自顶向下堆化
func (heap *Heap) removeMax() {

	// defensive
	if heap.count == 0 {
		return
	}

	// swap max = last
	swap(heap.a, 1, heap.count)
	heap.count--

	// heapify from up to down
	heapifyUpToDown(heap.a, heap.count)
}

// heapify 堆化
func heapifyUpToDown(a []int, count int) {
	for i := 1; i <= count/2; {

		maxIndex := i
		if a[i] < a[i*2] {
			maxIndex = i * 2
		}

		if i*2+1 <= count && a[maxIndex] < a[i*2+1] {
			maxIndex = i*2 + 1
		}

		if maxIndex == i { 
			// 说明在此节点时，该节点比左右孩子都要大，满足二叉树特性，堆化结束
			break
		}

		swap(a, i, maxIndex)
		i = maxIndex
	}
}

// swap two elements
func swap(a []int, i int, j int) {
	tmp := a[i]
	a[i] = a[j]
	a[j] = tmp
}