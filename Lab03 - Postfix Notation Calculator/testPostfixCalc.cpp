// Charles Buyas, cjb8qf, 2-6-17, testPostfixCalc.cpp

#include <iostream>
//#include <stack>
#include "stack.h"
#include <cstdlib>
#include "postfixCalculator.h"
using namespace std;


int main() {

  
  
  //stack<int> s;
  
  /* ORIGINAL TESTING FOR PRE-LAB

  s.push(23); // adds values to the stack
  s.push(11);
  s.push(45);
  cout << "Size: " << s.size() << endl; // tests size
  cout << "is empty? ";
  if (s.empty()) { // tests the empty function
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
  s.push(10); // add more val
  s.push(72);
  s.push(6);
  s.push(8);
  s.push(12);
  s.push(2);
  
  cout << "Top val: " << s.top() << endl; // tests top
  s.add(); // tests add
  cout << "Top val after add: " << s.top() << endl; // tests top
  s.minus(); // tests minus
  cout << "Top val after minus: " << s.top() << endl; // tests top
  s.negate(); // tests negate
  cout << "Top val after negate: " << s.top() << endl; // tests top
  s.mult(); // tests mult
  cout << "Top val after mult: " << s.top() << endl; // tests top
  s.div(); // tests div
  cout << "Top val after div: " << s.top() << endl; // tests top
  
  while (!(s.size() == 0)) { // test size, top, and empty
    cout << "-------My stack size is: " << s.size() << endl;
    cout << "The top value currently is: " << s.top() << endl;
    s.pop(); // test pop
  }
  cout << "is empty now? ";
  if (s.empty()) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
  return 0;

  */
  
  pfCal s;

  while (cin.good()) {
    
    string string1;
    cin >> string1;
    
    const char *str = string1.c_str();

    if (string1 == "") {
      break;
    }

    if (isdigit(string1.at(0)) || (string1.at(0) == '-')) {
      if (string1 == "-") {
	s.minus();
      }
      else {
	int x = atoi(str);
	s.push(x);
      }
    }
    
    else if (string1 == "-") {
      s.minus();
    }

    else if (string1 == "+") {
      s.add();
    }
    
    else if (string1 == "*") {
      s.mult();
    }
    
    else if (string1 == "/") {
      s.div();
    }
    
    else if (string1 == "~") {
      s.negate();
    }
    
    else {
      break;
    }

    cout << string1 << endl;
    
  }

  cout << s.top() << endl;
  
  return 0;
}
