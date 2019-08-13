/***************************************************************************
**   Program Name: Lab 6 (DoubleLinkedList.cpp)
**   Author: Andrew Clos
**   Date: 7/30/2019
**   Description: Double linked list contains the functions to perform all 
**				  required aspects of the program, including memory management.
**				  A custom destructor was necessary to aid in the task of memory
**			      management.  
*******************************************************************************/

#include<iostream>
#include "DoubleLinkedList.hpp"

/***************************************************************************
**   Description: Default constructor
***************************************************************************/
DoubleLinkedList::DoubleLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

/***************************************************************************
**   Description: Adds a new Node with integer from the caller to the head
**				  of the list.  
***************************************************************************/
void DoubleLinkedList::addHead(int newHead)
{
	//create new Node
	Node* userNode = new Node;

	//set value of new Node
	userNode->setVal(newHead);
	
	//check to make sure tail is not at null pointer
	//if tail is at null ptr, it too must point to this new Node.
	if (tail == nullptr)
	{
		setTail(userNode);
	}
	//set head Node to the one we just created.	
	setHead(userNode);
}

/***************************************************************************
**   Description: Adds a new Node with integer from the caller to the tail
**				  of the list.
***************************************************************************/
void DoubleLinkedList::addTail(int newTail)
{
	//create new Node
	Node* userNode = new Node;

	//set value of new Node
	userNode->setVal(newTail);

	//check to make sure tail is not at null pointer
	//if tail is at null ptr, it too must point to this new Node.
	if (head == nullptr)
	{
		setHead(userNode);
	}
	//set head Node to the one we just created.	
	setTail(userNode);
}

/***************************************************************************************
**   Description: Deletes the first Node in the list and then moves the head
**				  and sets its prev and next Nodes appropriately. I looked for
**				  help in deleting from a double linked list and found it in this
**				  excellent Youtube video: https://www.youtube.com/watch?v=LvUgew66zOQ
***************************************************************************************/
void DoubleLinkedList::deleteFirst()
{

	//check to make sure head is not pointing to null
	if (head == nullptr)
	{
		std::cout << "Head points to null, cannot delete head!" << std::endl;
	}
	else if (getSize() <= 1)
	{
		std::cout << "List contains only 1 Node, cannot delete last node." << std::endl;
	}
	else
	{  //set up a temp Node, increment head to next, set head's previous pointer to null 
	   // to avoid leaving a dangling list Node address, delete temp node to free memory
		Node* temp = head;
		head = head->getNext();
		head->setPrevious(nullptr);
		delete temp;
	}
}

/***************************************************************************************
**   Description: Deletes the last Node in the list and then moves the tail
**				  and sets its prev and next Nodes appropriately. I looked for
**				  help in deleting from a double linked list and found it in this
**				  excellent Youtube video: https://www.youtube.com/watch?v=LvUgew66zOQ
***************************************************************************************/
void DoubleLinkedList::deleteLast()
{
	//check to make sure tail is not pointing to null
	if (tail == nullptr)
	{
		std::cout << "Tail points to null, cannot delete tail!" << std::endl;
	}
	//make sure we aren't deleting the last Node of the list
	else if (getSize() <= 1)
	{
		std::cout << "List contains only 1 Node, cannot delete last node." << std::endl;
	}
	else 
	{   //set up temp node, move to end of list,
		//increment temp to next.
	   	Node* temp = tail;
	
		//create new "oldNode", give it the pervious value, set its next node to 
		//null(the address that was at the end of the list) delete the temp pointer
		tail = temp->getPrevious();
		tail->setNext(nullptr);
		delete temp;
	}
}

/**********************************************************************************
**   Description: Prints the Node values in the list from tail to head.
***********************************************************************************/
void DoubleLinkedList::printReverse()
{
	Node * temp;
	temp = tail;

	if (temp != nullptr)
	{
		std::cout << "Reverse Print: ";
	}
	else
	{  //output a warning message if trying to print a null set.
		std::cout << "Tried to print, but tail was equal to null." << std::endl;
	}

	while (temp != nullptr)
	{  //step through each Node element and display its value to the console.
		std::cout << temp->getVal() << " ";
		temp = temp->getPrevious();
	}
	std::cout << std::endl;
}

/***************************************************************************
**   Description: Prints the Node values in the list from head to tail.
***************************************************************************/
void DoubleLinkedList::printForward()
{
	Node * temp;
	temp = head;

	if (temp != nullptr)
	{
		std::cout << "Forward Print: ";
	}
	else
	{  //output a warning message if trying to print a null set.
		std::cout << "Tried to print, but head was equal to null." << std::endl;
	}

	while (temp != nullptr)
	{  //step through each Node element and display its value to the console.
		std::cout << temp->getVal() << " ";
		temp = temp->getNext();
	}
	std::cout << std::endl;
}

/***************************************************************************
**   Description: Returns 1 if head is null, 2 if tail is null, 3 if both 
**				  are null and 0 if neither are null.  In theory, it should
**				  never be able to return 1 or 2 -- this is more of a debug
**				  check.
***************************************************************************/
int DoubleLinkedList::checkForNulls()
{
	int nullCode = 0;

	if (head == nullptr && tail != nullptr)
	{
		nullCode = nullCode + 1;
	}
	else if (tail == nullptr && head != nullptr)
	{
		nullCode = nullCode + 2;
	}
	else if (head == nullptr && tail == nullptr)
	{
		nullCode = nullCode + 3;
	}
	
	return nullCode;
}

/***************************************************************************
**   Description: This function runs through a while loop to count up the 
**				  number of elements in the list. This is called by the 
**				  delete functions to prevent the list from going empty and
**				  becoming orphaned.
***************************************************************************/
int DoubleLinkedList::getSize()
{
	Node* temp = head;
	int counter = 0;

	while (temp != nullptr)
	{
		temp = temp->getNext();
		counter++;
	}

	return counter;
}

/***************************************************************************
**   Description: Implemented as part of the Extra Credit Task 1 to print
**				  the value in the Node that is pointed to by head.
***************************************************************************/
void DoubleLinkedList::printHeadVal()
{
	//calling getVal on a null pointing Node would seg fault!
	if (head == nullptr)
	{
		std::cout << "The head points to null." << std::endl;
	}
	else
	{
		std::cout << "The head points to a Node with the value of: " << head->getVal() << std::endl;
	}
}

/***************************************************************************
**   Description: Implemented as part of the Extra Credit Task 1 to print
**				  the value in the Node that is pointed to by tail.
***************************************************************************/
void DoubleLinkedList::printTailVal()
{
	
	//calling getVal on a null pointing Node would seg fault!
	if (tail == nullptr)
	{
		std::cout << "The tail points to null." << std::endl;
	}
	else
	{
		std::cout << "The tail points to a Node with the value of: " << tail->getVal() << std::endl;
	}
}

/***************************************************************************
**   Description: Recieves a Node from the caller and attempts to set this
**				  node as a new head Node in the list.
***************************************************************************/
void DoubleLinkedList::setHead(Node * tempNode)
{
	//don't place a nullptr in the list
	if (tempNode == nullptr)
	{
		std::cout << "Error! tempNode was null." << std::endl;
	}
	else
	{  //set this node's next and previous nodes.
		tempNode->setNext(head);
		tempNode->setPrevious(nullptr);

	}
	if (head == nullptr)
	{   //this should print when the initial value is added to the string, not an indication of an error
		std::cout << "Head was equal to null. This is expected after the first addition to the list." << std::endl;
	}
	else
	{ //update the "old" head Node
		head->setPrevious(tempNode);
	}
	//place the new Node in as the head.
	head = tempNode;
}

/***************************************************************************
**   Description: Recieves a Node from the caller and attempts to set this
**				  node as a new tail Node in the list.
***************************************************************************/
void DoubleLinkedList::setTail(Node * tempNode)
{
	//don't place a nullptr in the list
	if (tempNode == nullptr)
	{
		std::cout << "Error! tempNode was null." << std::endl;
	}
	else
	{   //set this node's next and previous nodes.
		tempNode->setPrevious(tail);
		tempNode->setNext(nullptr);

	} //this should print when the initial value is added to the string, not an indication of an error
	if (tail == nullptr)
	{   
		std::cout << "Tail was equal to null. This is expected after the first addition to the list." << std::endl;
	}
	else
	{ //update the "old" tail Node
		tail->setNext(tempNode);
	}
	//place the new Node in as the tail.
	tail = tempNode;
}

/***************************************************************************
**   Description: Deletes each element of the list until it finds a nice that
**				  is equal to the nullptr. source cited for help deleting 
**			      the list elements: https://www.geeksforgeeks.org/remove-first-node-of-the-linked-list/
***************************************************************************/
DoubleLinkedList::~DoubleLinkedList()
{
	Node* nextDelete = head;

	while (nextDelete != nullptr)
	{
		Node* temp = nextDelete;

		nextDelete = nextDelete->getNext();

		delete temp;
	}
}
