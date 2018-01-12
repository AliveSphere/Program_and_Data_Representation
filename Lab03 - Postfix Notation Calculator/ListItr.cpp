// Charles Buyas, cjb8qf, 1-29-17, ListItr.cpp

#include <iostream>
#include "ListItr.h"

using namespace std;

ListItr::ListItr() {

}

ListItr::ListItr(ListNode* theNode) {
  current = new ListNode;
  current = theNode;
}

bool ListItr::isPastEnd() const {
  if (current->next == NULL) {
    return true;
  }
  else {
    return false;
  }
}

bool ListItr::isPastBeginning() const {
  if (current->previous == NULL) {
    return true;
  }
  else {
    return false;
  }
}

void ListItr::moveForward() {
  ListItr itr(current);
  if (current->next != NULL) {
    current = current->next;
  }
}

void ListItr::moveBackward() {
  ListItr itr(current);
  if (current->previous != NULL) {
    current = current->previous;
  }
}

int ListItr::retrieve() const {
  return (*current).value;
}
