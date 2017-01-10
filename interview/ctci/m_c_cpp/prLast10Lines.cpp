#include <iostream>
#include <string>
#include <fstream>

void printLast10Lines(char *fileName);

int main(int argc, char *argv[])
{
	char *fileName = argv[1];
	printLast10Lines(fileName);

	return 0;
}

void printLast10Lines(char *fileName)
{
	const int K = 10;
	std::ifstream file(fileName);
	std::string L[K];
	int size = 0;

	while (file.good()) {
		std::getline(file, L[size % K]);
		size++;
	}

	int start = size > K ? (size % K) : 0;
	int count = std::min(size, K);

	for (int i = 0; i < count; i++) {
		std::cout << L[(start + i) % K] << std::endl;
	}
}
