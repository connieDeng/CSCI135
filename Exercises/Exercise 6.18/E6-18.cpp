/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: E6.18, e.g., Lab1C

Appends one vector after another
*/

#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

vector<int> append(vector<int> a, vector<int> b);

int main()
{
	vector<int> a{ 1, 4, 9, 16 }; 
	vector<int> b{ 9, 7, 4, 9, 11}; 
	vector<int> c;
	c = append(a,b);
	
	for(int x = 0; x < (a.size() + b.size()); x++)
	{
		cout << c[x] << " ";
	}
}

vector<int> append(vector<int> a, vector<int> b)
{
	for(int i = 0; i < b.size(); i++)
	{
		a.push_back(b[i]);
	}
	return a;
}