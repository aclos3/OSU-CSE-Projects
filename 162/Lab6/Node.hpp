/*************************************************************************** 
**   Program Name: Lab 6 (Node.hpp)
**   Author: Andrew Clos
**   Date: 7/30/2019
**   Description: Header file for a Node Object. Contains pointers to next 
**				  and previous Nodes so that an individual node is somewhat
**				  "self aware." Also contains val, for the integer value of
**				  a particular node. Also present are get and set methods for
**				  each data member as well as a default constructor and 
**				  destructor.
****************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP


class Node
{
private:
		
	Node * next;
	Node * prev;
	int val;

public:

	Node();
	int getVal();
	Node* getNext();
	Node* getPrevious();
	void setVal(int);
	void setNext(Node*);
	void setPrevious(Node*);
	~Node();

};
#endif