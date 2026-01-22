/*****************************************************************//**
 * @file   Source.cpp
 * @brief  pointers, memory allocation, vectors
 * 
 * @author Sparky
 * @date   2026-1-22
 *********************************************************************/

#include <iostream>
#include <iomanip>
using namespace std; 




int main() {
	int* iPeker = nullptr;
	iPeker = new int[100];

	char* cPeker = nullptr;
	cPeker = new char[80];

	//strcpy(cPeker, "wow lots of text!");




	int nums[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++) {
		cout << nums[i]; //readonly copy of array 
	}

	//new way of getting all nums from entire array

	for (int val : nums) {
		cout << val; 
	}

	cout << "\n"; 

	for (int& val : nums) {
		cout << val; // using & to get actual data instead of copy
	}

	cout << "\n"; 

	for (const int& val : nums) {
		cout << val; // using actual data instead of copy, but as readonly.
	}

}
