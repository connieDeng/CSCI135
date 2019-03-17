#include <iostream>

#include <string>
#include "DList.h"

DList::DList(){
    Node *dummy = new Node("dummy",nullptr); //implement dummy node
    head = dummy;
    //listSize = 0;
}

DList::~DList(){
    std::cout << "In the destructor\n";
	if (head != nullptr){
		Node *t,*t2;
		
		t=head->getNext();
		while (t!=nullptr){
			t2=t;
			t=t->getNext();
			delete t2;
		}
		delete head;
	}
}

// inserts at tail 
void DList::push_back(std::string data){
  // our code here
}

// inserts at head
void DList::push_front(std::string data){
  // your code here
}


// insert at location
void DList::insert(int loc, std::string data){
  // your code here
}

// remove from at location
void DList::remove(int loc){
  // your code here
}

// get value from 
std::string DList::get(int loc){
  // your code here
  return "";
}
