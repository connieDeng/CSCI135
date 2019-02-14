#include <iostream>
using namespace std;
//#include "methods.h"

//methods.h--------------------------------------
template <class T>
class Vector
{
	public:
		
		Vector();
		Vector(int size, int val);
		//insert(int location, T item);
		resize(int newSize);
		insert(int index, T item);
		push_back(T item);
		deleteLocation(int index);
		//insert(int index, int numTimes, T item);
		printem();
		
	private:
		int vecSize;
		T array;
		T * arrayPointer = &array;
		
		//int maxSize;
		//void alloc_new();
};

//main--------------------------------------

int main()
{
	Vector<int> x(1, 2);
	x.printem();
	x.resize(4);
	x.printem();
	x.push_back(3);
	x.printem();
	x.deleteLocation(0);
	x.printem();
	return 0;
}

//methods.hxx--------------------------------------
template <class T>
Vector<T>::printem()
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
	vecSize = 0;
	arrayPointer = new T[0];
}

//initialize vector of size all with same val
template <class T>
Vector<T>::Vector(int size, int val)
{
	vecSize = size;
	arrayPointer = new T[size];
	for(int i = 0; i < size; i++)
	{
		arrayPointer[i] = val;
	}
}

//resize
template <class T>
Vector<T>::resize(int newSize)
{
  T * newArr = new T[newSize];
  for(int i = 0; i < newSize; i++)
  {
	if( i >= vecSize )
		newArr[i] = 0;
	else
		newArr[i] = arrayPointer[i];
  }

  vecSize = newSize;
  //delete [] arrayPointer;
  arrayPointer = newArr;
}

//insert one item
template <class T>
Vector<T>::insert(int index, T item)
{
	resize(vecSize+1);
	T * newArr = new T[vecSize];
	//arrayPointer = new T[size];
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
	resize(vecSize+1);
	T * newArr = new T[vecSize];
	
	for(int i = 0; i < vecSize; i++)
	{
		if( i == vecSize-1 )
			newArr[i] = item;
		else
			newArr[i] = arrayPointer[i];
	}
	//delete [] arrayPointer;
	arrayPointer = newArr;
}

//delete at index
template <class T>
Vector<T>::deleteLocation(int index)
{
	T * newArr = new T[vecSize - 1];
	bool skipped = false;
	
	for(int i = 0; i < vecSize; i++)
	{
		if(i == index)
		{
			skipped = true;
		}
		else if(skipped)
		{
			newArr[i-1] = arrayPointer[i];
		}
		else
		{
			newArr[i] = arrayPointer[i];
		}
	}

	vecSize = vecSize - 1;
	//delete [] data;
	arrayPointer = newArr;
}