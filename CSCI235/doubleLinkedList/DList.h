#include <iostream>

#include <string>
#include "Node.h"

class DList{
private:
  Node *head;
  Node *tail;
  //int listSize;
  
public:
  DList();
  ~DList();
  void push_back(std::string data); // inserts at tail 
  void push_front(std::string data); // inserts at head
  std::string getDebugString(); // returns a string of the entire list
  void insert(int loc, std::string data); // insert at location
  void remove(int loc); // remove from location
  std::string get(int loc); // return data from location
};


