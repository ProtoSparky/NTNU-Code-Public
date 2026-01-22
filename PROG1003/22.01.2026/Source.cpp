/*****************************************************************//**
 * @file   Source.cpp
 * @brief  pointers, memory allocation, vectors
 * 
 * @author Sparky
 * @date   2026-1-22
 *********************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std; 

//vectors



struct Person {
	string navn;
	int alder;
	Person(const string nvn, const int ald) { navn = nvn; alder = ald; }
};

void skrivVektor(vector <int> vect);





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

	cout << "\n"; 

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






	//vectors







	int i;
	vector <int> tall;				//empty vector
	vector <int> tall2(100);		//100 element long vector

	vector <int> tall3 {3,7, 11};	//3 element long defined vector
	vector <int> tall4(20, 7);		//20 element long full of "7" in all elements

	vector <int> tall5(tall3);		//vector copy of tall3
	vector <char> bokstsaver(10, 'Z');// vectors with X-s 
	vector <string> navn(10); 

	//vectors are dynamically resizeable, which is a huge pro

	cout << "tall3 :";
	for (int i = 0; i < tall3.size(); i++) {
		cout << tall3[i];
	}


	for (int val : tall4) {
		cout << val;
	}

	for (int i = 0; i < tall2.size(); i++) {
		cout << tall2[i]; 
	}



	/*
	can use tall3.at(place) instead of tall3[place]. 
	this prevents from reading a non existent value, but this will cause an exception	
	*/



	navn[0] = "per, ";
	navn[1] = "pål";
	navn[2] = "Espen";

	
	//navn.pop_back()  removes the last element
	//navn.push_back() add element
	//navn.empty() true if it is empty
	//nanvn.capacity() elements left in vector
	//navn.clear() empty entire vector






	//vectors to structs



	Person pers = { "joe", 30 };
	Person* pers2;
	vector <Person> personer;
	personer.push_back(pers);
	pers2 = new Person("bob", 69);
	delete pers2; pers2 = nullptr; 


}
