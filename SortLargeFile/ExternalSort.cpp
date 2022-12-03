#include<string>
#include <iostream>
#include <fstream>
#include "MinHeap.h"
#include "ExternalSort.h"
#include "StringUtil.h"

int ExternalSort::partition(std::string* arr, int start, int end)
{
	std::string pivot = arr[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	arr[pivotIndex].swap(arr[start]);

	int i = start, j = end;
	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i < pivotIndex && j > pivotIndex) {
			arr[i++].swap(arr[j--]);
		}
	}
	return pivotIndex;
}

void ExternalSort::quickSort(std::string* arr, int start, int end)
{
	if (start >= end)
		return;
	int p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

void ExternalSort::externalSort(std::string inputFileName, std::string outputFileName) {
	std::fstream inputFile; inputFile.open(inputFileName, std::ios::in | std::ios::binary);
	int numWays = partitionAndSortFiles(inputFile);
	mergeFiles(outputFileName, numWays);
}

int ExternalSort::partitionAndSortFiles(std::fstream& inputFile) {
	int numRunWays = 0;
	bool moreInput = true;
	getline(inputFile, header);
	while (moreInput && inputFile.good())
	{
		std::string * arr = new std::string[runSize];
		int i = 0;
		for (; i < runSize; i++)
		{
			if (inputFile.good()) {
				getline(inputFile, arr[i]);
			}
			else {

				moreInput = false;
				break;
			}
		}
		quickSort(arr, 0, i - 1);
		std::string s = "f" + std::to_string(numRunWays);
		std::string fileName = s.append(".csv");
		std::fstream f;
		f.open(fileName, std::ios::out | std::ios::binary);
		for (int j = 0; j < i; j++)
		{
			f << arr[j];
			if (j != i - 1)
				f << std::endl;
		}
		f.close();
		numRunWays++;
		delete[] arr;
	}

	inputFile.close();
	return numRunWays;
}

void ExternalSort::mergeFiles(std::string outputFileName, int numRunWays) {
	std::fstream outputFile; outputFile.open(outputFileName, std::ios::out | std::ios::binary);
	std::fstream* runWayFiles = new std::fstream[numRunWays];
	for (int i = 0; i < numRunWays; i++)
	{
		std::string s = "f" + std::to_string(i);
		std::string fileName = s.append(".csv");
		runWayFiles[i].open(fileName, std::ios::in | std::ios::binary);
	}

	std::vector<MinHeapNode> nodeList(numRunWays);

	for (int i = 0; i < numRunWays; i++)
	{
		getline(runWayFiles[i], nodeList[i].record);
		nodeList[i].index = i;
		nodeList[i].key = getFirstToken(nodeList[i].record);
	}

	MinHeap minHeap(nodeList);
	outputFile << header << std::endl;
	while (!minHeap.isEmpty())
	{
		MinHeapNode minNode = minHeap.pop();
		outputFile << minNode.record << std::endl;
		int curIndex = minNode.index;
		if (!runWayFiles[curIndex].eof()) {
			std::string temp;
			getline(runWayFiles[curIndex], temp);
			MinHeapNode newNode(temp, curIndex);
			minHeap.push(newNode);
		}
	}
	for (int i = 0; i < numRunWays; i++)
	{
		runWayFiles[i].close();
		std::string s = "f" + std::to_string(i);
		std::string fileName = s.append(".csv");
		remove(fileName.c_str());

	}
	delete[] runWayFiles;
	outputFile.close();
}