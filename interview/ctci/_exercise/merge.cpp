#include <iostream> // std::cout, std::endl
#include <iomanip>  // std::setw

void merge(int va[], int vb[], int lastA, int lastB)
{
    int indexA = lastA - 1;
    int indexB = lastB - 1;
    int indexMerged = lastA + lastB - 1;

    while (indexA >= 0 && indexB >= 0) {
        if (va[indexA] > vb[indexB]) {
            va[indexMerged] = va[indexA];
            indexMerged--;
            indexA--;
        } else {
            va[indexMerged] = vb[indexB];
            indexMerged--;
            indexB--;
        }
    }

    while (indexB >= 0) {
        va[indexMerged] = vb[indexB];
        indexMerged--;
        indexB--;
    }
}

int main()
{
	int va[12] = {1,3,5,7,8,9};
	for(auto a : va)
		std::cout << std::setw(5) << a;
	std::cout << std::endl;


	int vb[6] = {2, 3, 4, 6, 8, 10};
	for(auto a : vb)
		std::cout << std::setw(5) << a;
	std::cout << std::endl;

    merge(va, vb, 6, 6);
	for(auto a : va)
		std::cout << std::setw(5) << a;
	std::cout << std::endl;

	return 0;
}
