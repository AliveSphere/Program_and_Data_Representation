// Charles Buyas, cjb8qf, 2-8-17, stack.cpp

#include <iostream>
#include "stack.h"
using namespace std;

myStack::myStack() {
  List myList;
}

void myStack::push(int x) {
  myList.insertAtTail(x);
}

ListItr myStack::top() {
  
  ListItr itr;
  while (!(itr.isPastEnd())) {
    itr.moveForward();
  }
  return itr;
  
}

void myStack::pop() {
  myList.removeAtTail();
  
  /*
  ListItr itr;
  while (!(itr.isPastEnd())) {
    itr.moveForward();
  }
  */
}

bool myStack::empty() const {
  return myList.isEmpty();
}
