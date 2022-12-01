#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int partitionAndSortFiles(fstream& inputFile, int runSize) {
	cout << "Bat dau sap xep file\n";
	int numRunWays = 0;
	bool moreInput = true;
	string temp;
	getline(inputFile, temp);
	while (moreInput && inputFile.good())
	{
		string* arr = new string[runSize];
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
		//quickSort(arr, 0, i - 1);
		string s = "f" + to_string(numRunWays);
		string fileName = s.append(".csv");
		fstream f;
		f.open(fileName, ios::out | ios::binary);
		for (int j = 0; j < i; j++)
		{
			f << arr[j];
			if (j != i - 1)
				f << endl;
		}
		f.close();
		if (numRunWays % 1000 == 0) cout << "Da ghi duoc " << numRunWays << " file\n";
		numRunWays++;
		delete[] arr;
	}

	inputFile.close();
	return numRunWays;
}

void externalSort(string inputFileName, string outputFileName) {
	int runSize = 500000;

	fstream inputFile; inputFile.open(inputFileName, ios::in | ios::binary);
	int numWays = partitionAndSortFiles(inputFile, runSize);
}

int partition(string* arr, int start, int end)
{

	string pivot = arr[start];

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

void quickSort(string* arr, int start, int end)
{
	if (start >= end)
		return;
	int p = partition(arr, start, end);
	quickSort(arr, start, p - 1);
	quickSort(arr, p + 1, end);
}

int main() {
	externalSort("test.csv", "sorted_books_rating.csv");
	return 0;
}
