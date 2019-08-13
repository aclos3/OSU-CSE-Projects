/*******************************************************************************
**   Program Name: Lab 6 (DoubleLinkedList.hpp)
**   Author: Andrew Clos
**   Date: 7/30/2019
**   Description: Double linked list has private data members for head and tail.
**				  There is one private helper get-function as well as set methods
**				  for head and tail Nodes. Additionally, there are nine public
**				  functions to carry out each required aspect of the program as
**				  well as default constructor and a destructor.
*******************************************************************************/

#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

#include "Node.hpp"

class DoubleLinkedList
{
private:
	
	Node * head;
	Node * tail;
	int getSize();

public:
	DoubleLinkedList();
	void addHead(int);
	void addTail(int);
	void deleteFirst();
	void deleteLast();
	void printReverse();
	void printForward();
	int checkForNulls();

	//print methods for extra credit Task 1	
	void printHeadVal();
	void printTailVal();

	
	void setHead(Node*);
	void setTail(Node*);

	~DoubleLinkedList();

};
#endif