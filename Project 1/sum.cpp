/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: sum, e.g., Lab1C

calculate sum of integers from a different file
*/

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	int sum = 0;	//sum = variable that will keep track of sum
	int num = 0;	//will recieve input from numbers.txt
    while(cin >> num) // While the reading operation is a success
	{ 
		sum = sum + num; //calc sum
	}
	cout << sum;
}