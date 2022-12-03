#include "ExternalSort.h"


int main() {
   
	ExternalSort exterSort(100000);
	exterSort.externalSort("Books_rating.csv", "sorted_books_rating.csv");
	return 0;
}
