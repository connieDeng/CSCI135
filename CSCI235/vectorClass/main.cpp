/*
Author: Connie Deng
Course: CSCI-133
Instructor: Mike Zamansky
Assignment: Lab13 E

recreate vector class with template
*/

#include <iostream>
#include "methods.h"
using namespace std;

int main()
{
	cout << "initialize an empty vector with capacity of 10." << endl;
	Vector<int> vec1;
	vec1.printVector();
	cout << "Size: " << vec1.getVectorSize() << " Capacity: " << vec1.getVectorCapacity() << endl << endl;
	
	cout << "initialize a vector with 10 0s." << endl;
	Vector<int> vec2(10, 0);
	vec2.printVector();
	cout << "Size: " << vec2.getVectorSize() << " Capacity: " << vec2.getVectorCapacity() << endl << endl;
	
	cout << "insert a 2 at index 1." << endl;
	vec2.insert(1,2);
	vec2.printVector();
	cout << "Size: " << vec2.getVectorSize() << " Capacity: " << vec2.getVectorCapacity() << endl << endl;
	
	cout << "add a 5 at the end." << endl;
	vec2.push_back(5);
	vec2.printVector();
	cout << "Size: " << vec2.getVectorSize() << " Capacity: " << vec2.getVectorCapacity() << endl << endl;
	
	cout << "delete the last element." << endl;
	vec2.pop_back();
	vec2.printVector();
	cout << "Size: " << vec2.getVectorSize() << " Capacity: " << vec2.getVectorCapacity() << endl << endl;
	
	cout << "delete index 1 (the 2)." << endl;
	vec2.deleteAtIndex(1);
	vec2.printVector();
	cout << "Size: " << vec2.getVectorSize() << " Capacity: " << vec2.getVectorCapacity() << endl << endl;
	
	return 0;
}