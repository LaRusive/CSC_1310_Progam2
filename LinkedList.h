/*
    
*/
#ifndef LinkedList_H
#define LinkedList_H

class LinkedList
{
	private:
		// Declare a structure for the list
		struct ListNode
		{
			double value; 
            // To point to the next node
			ListNode *next;  	
		}; 
        //List head & tail pointer
		ListNode *head;	
        ListNode *tail;		

	public:
		// Constructor
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}

		// Destructor (deallocates all nodes)
		~LinkedList();

		// Linked list operations
		bool isEmpty();
		int getLength();
		int search(double);
		double getNodeValue(int);
		void appendNode(double);
		void insertNode(int, double);
		void deleteNode(double);
		void displayList() const;
};
#endif