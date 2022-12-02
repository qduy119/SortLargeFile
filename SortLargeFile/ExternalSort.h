#pragma once
#include<string>
class ExternalSort {
private:
	int runSize;
	int partition(std::string* arr, int start, int end);
	void quickSort(std::string* arr, int start, int end);
	int partitionAndSortFiles(std::fstream& inputFile);
	void mergeFiles(std::string outputFileName, int numRunWays);
public:
	ExternalSort() {
		runSize = 1000;
	}
	void externalSort(std::string inputFileName, std::string outputFileName);
};