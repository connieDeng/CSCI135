/*
Author: Connie Deng
Course: CSCI-136
Instructor: Genady Maryash
Assignment: E6.7, e.g., Lab1C

E6.7 reverse an array
*/

#include <iostream>
#include <array>
#include <cmath>
using namespace std;

void printArray(int arr[], int size);
void revArray(int arr[], int start, int end);

int main()
{
	int SIZE = 9;
	int start = 0;
	int end = 9;
	int numArr[SIZE] = {1, 4, 9, 16, 9, 7, 4, 9, 11};
	
	
	revArray(numArr, start, end);
	printArray(numArr, SIZE);
}

void revArray(int arr[], int start, int end)
{
	while(start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end-1];
		arr[end-1] = temp;
		start++;
		end--;
	}
}

void printArray(int arr[], int size) 
{ 
   for (int i = 0; i < size; i++) 
   cout << arr[i] << " "; 
  
   cout << endl; 
}  
