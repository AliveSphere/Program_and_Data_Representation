// Charles Buyas, cjb8qf, 2-5-17, postfixCalculator.cpp

#include <iostream>
#include <stack>
#include "postfixCalculator.h"
using namespace std;


pfCal::pfCal() {
  //count = 0;
  stack<int> myStack;
}

void pfCal::push(int x) {
  myStack.push(x);
  //count++;
}

int pfCal::top() {
  return myStack.top();
}

void pfCal::pop() {
  myStack.pop();
}

bool pfCal::empty() const {
  return myStack.empty();
}

void pfCal::add() {
  int x = myStack.top();
  myStack.pop();
  int y = myStack.top();
  myStack.pop();
  int total = x+y;
  myStack.push(total);
  //count--;
}

void pfCal::minus() {
  int x = myStack.top();
  myStack.pop();
  int y = myStack.top();
  myStack.pop();
  int total = y-x;
  myStack.push(total);
  //count--;
}

void pfCal::mult() {
  int x = myStack.top();
  myStack.pop();
  int y = myStack.top();
  myStack.pop();
  int total = x*y;
  myStack.push(total);
  //count--;
}

void pfCal::div() {
  int x = myStack.top();
  myStack.pop();
  int y = myStack.top();
  myStack.pop();
  int total = y/x;
  myStack.push(total);
  //count--;
}

void pfCal::negate() {
  int x = myStack.top();
  myStack.pop();
  int total = (~x)+1;
  myStack.push(total);
}

int pfCal::size() const {
  int x = myStack.size();
  return x;
}


