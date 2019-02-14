#include <iostream>

#include <string>
#include "Node.h"

class List{
private:
	Node *head;
public:
	List();
	~List();
	void insert(std::string data);
	void push_back(std::string data); // inserts at the end of the vector
	int size(); // returns the size
	//std::string &List::at(int); // returns the element at a location
	//std::string List::insert(int,std::string); // inserts string at location
	//void List::remove(int i); // removes the element at location i
	//std::string &List::operator[](int); // overloaded square brackets
	std::string getDebugString();
};


