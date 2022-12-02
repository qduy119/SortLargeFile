#include "ExternalSort.h"


int main() {
	ExternalSort exterSort;
	exterSort.externalSort("organizations-500000.csv", "sorted_books_rating.csv");
	return 0;
}
