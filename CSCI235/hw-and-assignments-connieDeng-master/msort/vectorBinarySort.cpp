/*
Author: Connie Deng
Course: CSCI-235
Instructor: Mike Zamansky
Assignment: name, e.g., Lab1C

binary_search example
*/

#include <iostream>     // std::cout
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) 
{
    if(i < j)
        return true;
    else
        return false;
}

int main () 
{
	int myints[] = {1,2,3,4,5,4,3,2,1};
	std::vector<int> v(myints,myints+9);												 // 1 2 3 4 5 4 3 2 1

	// using default comparison:
	std::sort (v.begin(), v.end());

	std::cout << "search for 3: ";
	if (std::binary_search (v.begin(), v.end(), 3))
		std::cout << "found!\n"; 
    else 
        std::cout << "not found.\n";

	// using myfunction as comp:
	std::sort (v.begin(), v.end(), myfunction);

	std::cout << "search for 6: ";
	if (std::binary_search (v.begin(), v.end(), 6, myfunction))
		std::cout << "found\n"; 
	else 
        std::cout << "not found\n";

	return 0;
}