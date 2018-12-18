/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab11 E, e.g., Lab1C

Task E. Nested parentheses
*/

#include <cmath>
#include <iostream>
using namespace std;

void printRange(int left, int right);
int sumRange(int left, int right);
int sumArray(int *arr, int size);
bool isAlphanumeric(string s);
bool nestedParens(string s);

int main()
{
	cout << sumRange(1,3); //6
}

void printRange(int left, int right)
{
	if(left <= right) //outputs left until left is equal to right
	{
		cout << left;
		
		printRange(left+1,right);
	}
}

int sumRange(int left, int right)
{
	if(left > right)
	{
		return 0;
	}
	
	if(left == right) //2 base cases
	{
		return left;
	}
	
	else 
		return(left + sumRange(left+1,right)); //keep adding next number
	
}

int sumArray(int *arr, int size)
{
	if(size == 1)
	{
		return arr[0];
	}
	
	else
	{
		return (arr[size-1] + sumArray(arr, size-1));
	}
}

bool isAlphanumeric(string s)
{
	if(s.length() == 0)
	{
		return true;
	}
	
	if(isalnum(s[0]) == false) //checking if every letter is a alphanumeric
	{
		return false;
	}
	
	else
		return isAlphanumeric(s.substr(1, s.length()-1));
}

bool nestedParens(string s)
{
	if(s.length() == 0) //if string empty
	{
		return true;
	}
	
	if(s.length()%2 != 0) //check if even parentheses
	{
		return false;
	}
	
	if(!(s[0] == '(' && s[s.length()-1] == ')'))
	{
		return false;
	}
	
	else
		return (nestedParens(s.substr(1, s.length()-2)));
}