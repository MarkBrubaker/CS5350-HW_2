#include <fstream>
#include <vector>
#include "util.hpp"

int main() {
	std::vector<double> func1;
	std::vector<double> func2;
	std::vector<double> func3;
	std::vector<double> func4;
	int trials = 10;
	int n = 1000;

	for(int x = 0; x < trials; x++) {
		func1.push_back(Time(HelloWorld, n));

		func2.push_back(Time(RandomSortedNumbers, n));

		int* nums = new int[n];

		func3.push_back(Time(RandomNumbers, n, nums));

		func4.push_back(Time(SortNumbers, n, nums));

		delete[] nums;
	}

	std::ofstream file("output.txt");

	for(int x = 0; x < trials; x++) {
		file << func1[x] << "," << func2[x] << "," << func3[x] << "," << func4[x] << std::endl;
	}

	file.close();

	return 0;
}