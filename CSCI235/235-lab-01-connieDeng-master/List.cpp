#include <iostream>

#include <string>
#include "List.h"

List::List(){
  head = nullptr; //first item of the list
}

List::~List(){
  std::cout << "In the destructor\n";
  if (head != nullptr){
    Node *t,*t2;
    
    t=head->getNext();
    while (t!=nullptr){
      t2=t;
      t=t->getNext();
      delete t2;
    }
  }
  
  
}

void List::insert(std::string data){
  Node *t = new Node(data,nullptr);
  if (head==nullptr)
    head=t;
  else{
    t->setNext(head);
    head = t;
  }
}

void List::push_back(std::string data)//push data the end of the list
{
	//creates the last node that holds the data
	Node *last = new Node;
	last->setData(data);

	if(head == NULL)
	{
	
	}
	
	else
	{
		
	}
}

int List::size()
{
	Node *t = head;
	int num = 0;
	while (t != nullptr)
	{
		num += 1;
		t=t->getNext();
	}
	return num;
}

std::string List::getDebugString(){
  std::string s = "";
  Node *t = head;
  while (t != nullptr){
    s = s + t->getData()+"->";
    t=t->getNext();
  }
  s=s+" NULL\n";
  return s;
}
