/*
 * Filename: ListNode.h
 * Description: ListNode class definition
 */
// Charles Buyas, cjb8qf, 1-30-17, ListNode.h
#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class ListNode {
public:
    ListNode();                 // Constructor
    //int getValue() const;
    //void setValue(int x);

private:
    int value;
    ListNode *next, *previous;	// for doubly linked lists

    // List needs to be able to access/change ListNode's next and
    // previous pointers
    friend class List;

    // ListItr needs to access/change ListNode as well
    friend class ListItr;

    // Not writing a destructor is fine in this case since there is no
    // dynamically allocated memory in this class.  No constructor is
    // necessary, as an object will be set up by the List class.
};

#endif
