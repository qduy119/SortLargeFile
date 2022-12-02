#pragma once
#include <vector>
#include <string>
using namespace std;

string getId(string str);

struct MinHeapNode {
	string record;
	int index;
	string key;
	MinHeapNode() {
		record = "";
	}
	MinHeapNode(string r, int i) {
		record = r;
		index = i;
		key = getId(r);
	}
};

class MinHeap
{
	vector<MinHeapNode> heap;
	int size;
	void swap(MinHeapNode& x, MinHeapNode& y);
public:
	MinHeap(vector<MinHeapNode>& nodeList);
	void heapify(int i);
	int getParent(int i) {
		return (i - 1) / 2;
	}
	int getLeftChild(int i) {
		return 2 * i + 1;
	}
	int getRightChild(int i) {
		return 2 * i + 2;
	}
	MinHeapNode getMin() {
		return heap[0];
	}
	MinHeapNode getMax() {
		return heap[size - 1];
	}
	bool isEmpty() {
		return size == 0;
	}
	MinHeapNode pop();
	void push(MinHeapNode nNode);
};
