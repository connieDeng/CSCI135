/*
Author: Connie Deng
Course: CSCI-235
Instructor: Mike Zamansky
Assignment: name, e.g., Lab1C

insert sort
*/

#include <cmath>
#include <iostream>
using namespace std;

void insertSort(int arr[], int n);
void printArr(int arr[], int size);

int main()
{
    const int SIZE = 6;
	int test[SIZE] = {3,4,5,6,1,2};
    insertSort(test, SIZE);
    printArr(test, SIZE);
    
}

void insertSort(int arr[], int size) 
{ 
   int i, key, j; 
   for (i = 1; i < size; i++) 
   { 
       key = arr[i]; 
       j = i-1; 
  
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
   
   /*int keyInd = 0;
   while(keyInd < size)
   {
       for(int i = 1; i < size; i++)
       {
           if(arr[keyInd] )
       }
       
   }*/
} 

//void selectionSort

void printArr(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " "; 
    }
}
