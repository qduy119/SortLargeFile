#include "ExternalSort.h"
#include <time.h>
#include <iostream>

int main() {
   
	ExternalSort exterSort(800000);
	std::cout << "Dang sap xep file...\n";
	clock_t start = clock();
	exterSort.externalSort("Books_rating.csv", "sorted_books_rating.csv");
	clock_t end = clock();
	double usedTime = (double)(end - start) / CLOCKS_PER_SEC;
	int minute = usedTime / 60;
	int second = usedTime - minute * 60;

	std::cout << "Sap xep file da hoan thanh. Thoi gian sap xep: " << minute << " phut " << second << std::endl;
	return 0;
}
