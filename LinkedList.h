/*
    Author: Weston LaRue
	Date: Oct 22, 2024
	Title: LinkedList.h
	Purpose: Define Linked list class and function prototypes
*/
#ifndef LinkedList_H
#define LinkedList_H
#include <iostream>
using namespace std;

//template definition and class definition
template <class T>
class LinkedList
{
    //private definition
    private:
        struct ListNode
        {
            T value;
            ListNode *next;
        };
   
    ListNode* head;
	ListNode* tail;

    //public definition
    public:
        //Constructor
        LinkedList()
        { 
			head = NULL; 
		}

		//Destructor
		~LinkedList();
   
   		// Linked list operations
		bool isEmpty();
		int getLength();
		//double getNodeValue(int);
		void appendNode(T);
		//void insertNode(int, T);
		void deleteNode(T);
		void displayList() const;
};

//isEmpty function
template <typename T>
bool LinkedList<T>::isEmpty()
{
	bool status;

	ListNode* temp;

	if(temp->next == NULL)
		return true;
	else
		return false;
}

//getLength function
template <typename T>
int LinkedList<T>::getLength()
{
	int counter = 0;
	ListNode *nodePtr;
	
	nodePtr = head;
	
	while(nodePtr)
	{
		counter++;
		nodePtr = nodePtr->next;
	}
	return counter;
}

//appendNode function
template <typename T>
void LinkedList<T>::appendNode(T val)
{
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = val;
	newNode->next = NULL;
	cout << "\nappendNode:  dynamically created new node & set value";

	// If there are no nodes in the list make newNode the first node.
	if (!head) 
	{
		head = newNode;
		cout << "\nappendNode:  new node is head of list";
	}
	else  // Otherwise, insert newNode at end.
	{
		cout << "\nappendNode:  traversing through list  ";
		//must traverse the list to find the end
		nodePtr = head;
		int counter = 0;
		while(nodePtr->next != NULL)
		{
			cout << "- node " << counter++;
			nodePtr = nodePtr->next;
		}
		//now we are at the end
		nodePtr->next = newNode;
		cout << "\nappendNode:  new node is at end of list";
	}
	return;
}

//DeleteNode Funciton
template <typename T>
void LinkedList<T>::deleteNode(T val)
{
	//define list pointers
	ListNode *nodePtr;
	ListNode *PrvNode;

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == val)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
			nodePtr = head;

		// Skip all nodes whose value member is not equal to num.
		while (nodePtr != NULL && nodePtr->value != val)
		{  
			PrvNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		if (nodePtr)
		{
			if(nodePtr == tail)
			{
				tail = PrvNode;
			}
			PrvNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
	return;
}

template <typename T>
void LinkedList<T>::displayList() const
{
	ListNode *nodePtr;  // To move through the list

	if(head != NULL)
	{
		// Position nodePtr at the head of the list.
		nodePtr = head;
		// While nodePtr points to a node, traverse the list.
		while(nodePtr)
		{
			// Display the value in this node.
			cout << nodePtr->value << endl;

			// Move to the next node.
			nodePtr = nodePtr->next;
		}
	}
	else
		cout << "\nThere are no nodes in the list.\n\n";
}


template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;
		cout << "\ndestructor:  deleting node with value " << nodePtr->value;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

#endif
