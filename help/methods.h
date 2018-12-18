#pragma once

#include <iostream>

using namespace std;

template <class T>
class MyVector{
public:
  MyVector(T a, T b, T c, T d, T e);
  void printem();
  void insertLocation(int location, T item);
  void insertEnd(T item);
  void deleteLocation(int location);
  void resize();
  T* data = new T[size];
  //have to resize the array for when we insert and delete items

 private:
  int size = 5;
  
};


#include "methods.hxx"

