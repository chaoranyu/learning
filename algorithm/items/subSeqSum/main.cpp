// test.cpp : 定义控制台应用程序的入口点。
//

#include "algorithm.h"
#include <iostream>

int main(int argc, char* argv[])
{
	vector<int> array;

	array.push_back(4);
	array.push_back(-3);
	array.push_back(5);
	array.push_back(-2);
	array.push_back(-1);
	array.push_back(2);
	array.push_back(6);
	array.push_back(-2);

    std::cout << maxSubSum1(array) << std::endl;
    std::cout << maxSubSum2(array) << std::endl;
    std::cout << maxSubSum3(array) << std::endl;
    std::cout << maxSubSum4(array) << std::endl;

	return 0;
}

