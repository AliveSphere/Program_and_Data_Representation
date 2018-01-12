// Charles Buyas, cjb8qf, 2-8-17, stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"
#include "ListItr.h"
#include "postfixCalculator.h"
using namespace std;

//class ListItr;
//class List;
//class ListNode;

class myStack {
 public:
  myStack(); // Constructor
  void push(int x); // Adds the passed element
  ListItr top(); // Returns top of the stack
  void pop(); // Removes val on top
  bool empty() const; // Tells whether empty
 private:
  List myList;
};

#endif
