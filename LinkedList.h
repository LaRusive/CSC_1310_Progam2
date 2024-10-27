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
		double getNodeValue(int);
		void appendNode(T);
		void deleteNode(T);
		void displayList() const;
		void bubbleSort();
		void swap(int, int);
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

template <typename T>
double LinkedList<T>::getNodeValue(int position)
{
	ListNode *nodePtr;
	if(!head)
		return -1;
	else
	{
		if(position == 0)
			return head->value;
		nodePtr = head;
		int currentPos = 0;
		while(position >= currentPos && nodePtr != NULL)
		{
			if(position == currentPos)
				return nodePtr->value;
			currentPos++;
			nodePtr = nodePtr->next;
		}
	}
	return -1;
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
void LinkedList<T>::bubbleSort()
{
	for(int last = getLength()-1; last > 0; last--)
	{
		for(int i=0; i<last; i++)
		{
			//compare adjacent nodes
			if(getNodeValue(i) > getNodeValue(i+1))
			{
				//swap the values in the two nodes
				swap(i+1, i);
			}
		}
	}
}

template <typename T>
void LinkedList<T>::swap(int pos1, int pos2)
{
	ListNode *nodePtr1=NULL;
	ListNode *nodePtr2=NULL;
	double tempValue;
	
	nodePtr1 = head;
	
	int curPos = 0;
	while(nodePtr1 != NULL && pos1 != curPos)
	{
		//traverse to next node
		nodePtr1 = nodePtr1->next;
		curPos++;
	}
	//now nodePtr1 is pointing to pos1 
	nodePtr2 = head;
	curPos = 0;
	while(nodePtr2 != NULL && pos2 != curPos)
	{
		//traverse to next node
		nodePtr2 = nodePtr2->next;
		curPos++;
	}	
	//now nodePtr2 is pointing to pos2 	

	tempValue = nodePtr1->value;
	nodePtr1->value = nodePtr2->value;
	nodePtr2->value = tempValue;
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
