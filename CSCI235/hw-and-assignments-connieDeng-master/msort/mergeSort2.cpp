/*
Author: Connie Deng
Course: CSCI-235
Instructor: Mike Zamansky
Assignment: Merge Sort 
*/

#include <cmath>
#include <iostream>
#include <vector>
//using namespace std;

void printVec(std::vector<int>& vec);
void mergeSort(std::vector<int>& vec, int start, int end);
int findMid(int start, int end);

int main()
{
    std::vector<int> test;  
     
    test.push_back(1); 
    test.push_back(4); 
    test.push_back(2);
    test.push_back(5); 
    test.push_back(3);
    test.push_back(0);
    
    std::cout << "Before: ";
    printVec(test);    
    
    mergeSort(test, 0, test.size());
    std::cout << "After: ";
    printVec(test);
    
}

void mergeSort(std::vector<int>& vec, int start, int end) 
{

    //base case: stop splitting when each element is isolated;
    //index (size) is <= 1;
	if(end - start <= 1) 
		return; //start going back up to the previous call;
    
	else
    {
		int middle = findMid(start, end);
		int indexAStart = start; 
		int indexBStart = middle; 
        
        //split vector recursively;
        //merge(vec, start, middle);
        //merge(vec, middle, end);

        //at the last edge these are finalized;
        mergeSort(vec, indexAStart, middle);
        mergeSort(vec, indexBStart, end);
        
        //both have to complete before continuing;
        
        //create temp vector;
		std::vector<int> temp;
        
        //sort elements;
		while(indexAStart < middle && indexBStart < end) 
        {
			if(vec[indexAStart] <= vec[indexBStart]) 
            {
				temp.push_back(vec[indexAStart]);
				indexAStart++;
			} 
            
            else 
            {
				temp.push_back(vec[indexBStart]);
				indexBStart++;
			}
		}
        
        //remaining elements just get pushed (copied);
		while(indexAStart < middle) 
        {
			temp.push_back(vec[indexAStart]);
			indexAStart++;
		}
        
		while(indexBStart < end) 
        {
			temp.push_back(vec[indexBStart]);
			indexBStart++;
		}
        
        //temp array is merged into vec;
		for(int i = 0; i < temp.size(); i++) 
        {
			vec[start + i] = temp[i];
		}
	}
}

//find mid
int findMid(int start, int end)
{
    if(((start+end)%2) == 0)
        return (start+end)/2;
    else
        return((start+end)/2)+1;
}

//print vect
void printVec(std::vector<int>& vec)
{
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec.at(i) << " ";
    }
    
    std::cout << "\n";
}