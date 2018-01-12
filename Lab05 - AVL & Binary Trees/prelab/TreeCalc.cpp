// Charles Buyas, cjb8qf, 2-27-17, TreeCalc.cpp
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
  stack<TreeNode*> myStack;
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
  if (myStack.size() != 0) {
    cleanTree(myStack.top());
  }
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  if (ptr->left != NULL) {
    cleanTree(ptr->left);
  }
  //delete ptr;
  if (ptr->right != NULL) {
    cleanTree(ptr->right);
  }
  if (ptr->left == NULL && ptr->right == NULL) {
    delete ptr;
  }
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
  TreeNode* valNode = new TreeNode(val);
  if (!(val == "/" || val == "*" || val == "-" || val == "+")) {
    //valNode = myStack.push(val);
    myStack.push(valNode);
  }
  else {
    valNode->right = myStack.top();
    myStack.pop();
    valNode->left = myStack.top();
    myStack.pop();
    myStack.push(valNode);
  }
  
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
  if (ptr != NULL) {
    cout << ptr->value << " ";
    if (ptr->left != NULL)
      printPrefix(ptr->left);
    if (ptr->right != NULL)
      printPrefix(ptr->right);
  }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
  
  if (ptr != NULL) {
    if (ptr->value == "+" || ptr->value == "-" || ptr->value == "*"
	|| ptr->value == "/") {
      cout << "(";
    }
    printInfix(ptr->left);
    if (ptr->value == "+" || ptr->value == "-" || ptr->value == "*"
	|| ptr->value == "/") {
      cout << " " << ptr->value << " ";
    }
    if (!(ptr->value == "+" || ptr->value == "-" || ptr->value == "*"
	  || ptr->value == "/")) {
      cout << ptr->value;
    }
    printInfix(ptr->right);
    if (ptr->value == "+" || ptr->value == "-" || ptr->value == "*"
	|| ptr->value == "/") {
      cout << ")";
    }
  }
  
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form
  if (!(ptr == NULL)) {
    if (ptr->left != NULL)
      printPostfix(ptr->left);
    if (ptr->right != NULL)
      printPostfix(ptr->right);
    cout << ptr->value << " ";
  }
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (myStack.size()!=0 && myStack.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
	printPostfix(myStack.top());
        cout << endl;
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
	printInfix(myStack.top());
        cout << endl;
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
	printPrefix(myStack.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
  int retVal;
  if (ptr->left == NULL && ptr->right == NULL) {
    string ptrVal = ptr->value;
    const char *str = ptrVal.c_str();
    return atoi(str);
  }
  if (ptr->value == "/") {
    int leftNum = calculate(ptr->left);
    int rightNum = calculate(ptr->right);
    return leftNum/rightNum;
  }
  if (ptr->value == "*") {
    int leftNum = calculate(ptr->left);
    int rightNum = calculate(ptr->right);
    return leftNum*rightNum;
  }
  if (ptr->value == "+") {
    int leftNum = calculate(ptr->left);
    int rightNum = calculate(ptr->right);
    return leftNum+rightNum;
  }
  if (ptr->value == "-") {
    int leftNum = calculate(ptr->left);
    int rightNum = calculate(ptr->right);
    return leftNum-rightNum;
  }
  else {
    return 0;
  }
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    i = calculate(myStack.top());
    return i;
}
