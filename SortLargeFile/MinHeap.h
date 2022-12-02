#pragma once
#include <vector>
#include <string>
#include "StringUtil.h"

struct MinHeapNode {
	std::string record;
	int index;
	std::string key;
	MinHeapNode() {
		record = "";
	}
	MinHeapNode(std::string r, int i) {
		record = r;
		index = i;
		key = getFirstToken(r);
	}
	bool operator<(const MinHeapNode& n) {
		return this->key < n.key;
	}
};

class MinHeap
{
private:
	std::vector<MinHeapNode> heap;
	int size;
	void swap(MinHeapNode& x, MinHeapNode& y);
	int getParent(int i) {
		return (i - 1) / 2;
	}
	int getLeftChild(int i) {
		return 2 * i + 1;
	}
	int getRightChild(int i) {
		return 2 * i + 2;
	}
public:
	MinHeap(std::vector<MinHeapNode>& nodeList);
	MinHeapNode pop();
	void push(MinHeapNode nNode);
	void heapify(int i);
	bool isEmpty() {
		return size == 0;
	}
};
