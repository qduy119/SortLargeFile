#include "MinHeap.h"

void MinHeap::swap(MinHeapNode& x, MinHeapNode& y)
{
	MinHeapNode temp = x;
	x = y;
	y = temp;
}

MinHeap::MinHeap(std::vector<MinHeapNode>& nodeList)
{
	size = (int)nodeList.size();
	heap = nodeList;
	int i = (size - 1) / 2;
	for (; i >= 0; i--)
	{
		heapify(i);
	}
}

MinHeapNode MinHeap::pop() {
	MinHeapNode minNode;
	if (size == 1) {
		minNode = heap[0];
		size--;
		heap.erase(heap.begin());
	}
	else {
		minNode = heap[0];
		heap[0] = heap[size - 1];
		heap.erase(heap.end() - 1);
		size--;
		heapify(0);
	}

	return minNode;
}

void MinHeap::push(MinHeapNode nNode) {
	int i = size;
	heap.push_back(nNode);
	size++;
	while (i != 0 && heap[i] < heap[getParent(i)])
	{
		swap(heap[i], heap[getParent(i)]);
		i = getParent(i);
	}
}

void MinHeap::heapify(int i) {
	int left = getLeftChild(i);
	int right = getRightChild(i);
	int smallest = i;

	if (left < size && heap[left] < heap[smallest])
		smallest = left;

	if (right < size && heap[right] < heap[smallest])
		smallest = right;

	if (smallest != i) {
		swap(heap[i], heap[smallest]);
		heapify(smallest);
	}
}
