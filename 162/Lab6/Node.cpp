/***************************************************************************
**   Program Name: Lab 6 (Node.cpp)
**   Author: Andrew Clos
**   Date: 7/30/2019
**   Description: The Node Class contains a default constructor to establish 
**				  constructor default values (0, null, null) for a new Node.
**				  Additionally it has six get and set methods for its member
**				  variables and a default destructor.
****************************************************************************/

#include<iostream>
#include "Node.hpp"

/***************************************************************************
**   Description: Default constructor: next and previous initially set to
**				  null, and value is set to 0.
***************************************************************************/
Node::Node()
{
	next = nullptr;
	prev = nullptr;
	val = 0;
}

int Node::getVal()
{
	return val;
}

Node * Node::getNext()
{
	return this->next;
}

Node * Node::getPrevious()
{
	return this->prev;
}

void Node::setVal(int userVal)
{
	this->val = userVal;
}

void Node::setNext(Node *userNext)
{
	this->next = userNext;
}

void Node::setPrevious(Node *userPrev)
{
	this->prev = userPrev;
}

//default destructor
Node::~Node()
{

}
