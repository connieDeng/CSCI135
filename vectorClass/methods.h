#pragma once
#include <iostream>

using namespace std;

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

#include "methods.hxx"

