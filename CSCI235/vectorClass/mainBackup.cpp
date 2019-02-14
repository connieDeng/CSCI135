#include <iostream>
using namespace std;
//#include "methods.h"

//methods.h--------------------------------------
template <class T>
class Vector
{
	public:
		int getVectorSize();
		int getVectorCapacity();
		printVector();
		Vector();
		Vector(int size, int val);
		resize();
		insert(int index, T item);
		push_back(T item);
		deleteAtIndex(int index);
		pop_back();
		
	private:
		int vecSize;
		int capacity = 10;
		T * arrayPointer = NULL;
};

//main--------------------------------------

int main()
{
	cout << "initialize an empty vector with capacity of 10." << endl;
	Vector<int> vec1;
	vec1.printVector();
	cout << "Size: " << vec1.getVectorSize() << " Capacity: " << vec1.getVectorCapacity() << endl << endl;
	
	cout << "initialize an vector with 10 0s." << endl;
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

//methods.hxx--------------------------------------

//return number of elements
template <class T>
int Vector<T>::getVectorSize()
{
	return vecSize;
}

//returns capacity of vector
template <class T>
int Vector<T>::getVectorCapacity()
{
	return capacity;
}

//print vector
template <class T>
Vector<T>::printVector()
{
    for (int i = 0; i < vecSize; i++) 
	{
      cout << arrayPointer[i] << " ";
    }
    cout << "\n";
}

//default constructor
template <class T>
Vector<T>::Vector()	
{
	vecSize = 0;	//vectory is empty
	arrayPointer = new T[capacity];	//create vector with 10 capacity
}

//initialize vector of size all with same val
template <class T>
Vector<T>::Vector(int size, int val)
{
	arrayPointer = new T[capacity];
	
	if(size > capacity)
	{
		resize();
	}
	
	vecSize = size;
	for(int i = 0; i < size; i++)
	{
		arrayPointer[i] = val;
	}
}

//resize double the capacity size
template <class T>
Vector<T>::resize()
{
	capacity = capacity*2;
	//cout << capacity << endl;
	T * newArr = new T[capacity];
	
	for(int i = 0; i < vecSize; i++)
	{
		newArr[i] = arrayPointer[i];
	}
	
	delete [] arrayPointer;
	arrayPointer = newArr;
}

//insert one item
template <class T>
Vector<T>::insert(int index, T item)
{
	vecSize += 1;	//insert another element into vector	
	if(vecSize > capacity)
	{
		resize();
	}

	int* newArr = new int[vecSize];
	bool insert = false;
	for(int i = 0; i < vecSize; i++)
	{
		if(i == index)
		{
			newArr[i] = item;
			insert = true;
		}
		else if(insert)
		{
			newArr[i] = arrayPointer[i-1];
		}
		else
		{
			newArr[i] = arrayPointer[i];
		}
	}
  
  arrayPointer = newArr;
}


//push_back
template <class T>
Vector<T>::push_back(T item)
{
	vecSize += 1;	//insert element to end of vector	
	if(vecSize > capacity)
	{
		resize();
	}
	
	for(int i = 0; i < vecSize; i++)
	{
		if( i == vecSize-1 )
			arrayPointer[i] = item;
	}
}

//delete at index
template <class T>
Vector<T>::deleteAtIndex(int index)
{
	bool skipped = false;
	int i = 0;
	while(i < vecSize)
	{
		if(i == index)
		{
			skipped = true;
			i++;
		}
		else if(skipped)
		{
			arrayPointer[i-1] = arrayPointer[i];
			i++;
		}
		else
		{
			arrayPointer[i] = arrayPointer[i];
			i++;
		}
	}
	vecSize -= 1;	//taking away element
}


//pop_back
template <class T>
Vector<T>::pop_back()
{
	for(int i = 0; i < vecSize; i++)
	{
		if( i == vecSize-1 )
		{
			deleteAtIndex(i);
		}	
	}
}