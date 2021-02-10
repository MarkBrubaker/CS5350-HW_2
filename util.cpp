#include "util.hpp"

std::random_device   RandomNumberGenerator::m_rd;
std::mt19937         RandomNumberGenerator::m_rng(RandomNumberGenerator::m_rd());

double RandomNumberGenerator::getRandomNumber(const double& rangeStart, const double& rangeEnd) {
	std::uniform_real_distribution<> randomizer(rangeStart, rangeEnd);
	return randomizer(m_rng);
}

void HelloWorld(int n) {
	std::ios_base::sync_with_stdio(false); //makes cout run much faster
	for(int x = 0; x < n; x++) {
		std::cout << "Hello, World" << std::endl;
	}
}

void RandomSortedNumbers(int n) {
	int* nums = new int[n];

	for(int x = 0; x < n; x++) {
		nums[x] = RandomNumberGenerator::getRandomNumber(1, n + 1);
		for(int y = x; y > 0; y--) {
			if(nums[y] < nums[y - 1]) {
				int temp = nums[y];
				nums[y] = nums[y - 1];
				nums[y - 1] = temp;
			}
		}
	}

	for(int x = 0; x < n; x++) {
		std::cout << nums[x] << ", ";
	}
	std::cout << std::endl;

	delete[] nums;
}

void RandomNumbers(int n, int* nums) {
	for(int x = 0; x < n; x++) {
		nums[x] = RandomNumberGenerator::getRandomNumber(1, 4);
	}
}

void SortNumbers(int n, int* nums) {
	int oneCount = 0;
	int twoCount = 0;
	int threeCount = 0;

	for(int x = 0; x < n; x++) {
		switch(nums[x]) {
		case 1:
			oneCount++;
			break;
		case 2:
			twoCount++;
			break;
		case 3:
			threeCount++;
			break;
		default:
			std::cout << "Out of range" << std::endl;
			break;
		}
	}

	for(int x = 0; x < oneCount; x++) {
		nums[x] = 1;
	}

	for(int x = oneCount; x < oneCount + twoCount; x++) {
		nums[x] = 2;
	}

	for(int x = oneCount + twoCount; x < n; x++) {
		nums[x] = 3;
	}
}
