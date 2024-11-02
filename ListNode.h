#ifndef LISTNODE_H
#define LISTNODE_H

//Very simple
//ListNode is basically a struct that exists outside of LinkedList
template <class T>
class ListNode{
    public:
        T value;
        ListNode *next;
};

#endif