#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int partitionAndSortFiles(fstream& inputFile, int runSize) {
	cout << "Bat dau sap xep file\n";
	int numRunWays = 0;
	string* arr = new string[runSize];
	bool moreInput = true;
	string temp;
	getline(inputFile, temp);
	while (moreInput && inputFile.good())
	{

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
	}

	inputFile.close();
	delete[] arr;
	return numRunWays;
}

void externalSort(string inputFileName, string outputFileName) {
	int runSize = 500000;

	fstream inputFile; inputFile.open(inputFileName, ios::in | ios::binary);
	int numWays = partitionAndSortFiles(inputFile, runSize);
}

int main() {
	externalSort("test.csv", "sorted_books_rating.csv");
	return 0;
}