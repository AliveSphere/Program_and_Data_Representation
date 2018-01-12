// Charles Buyas, cjb8qf, 4-16-17, huffTreeNode
#ifndef HUFFTREENODE_H
#define HUFFTREENODE_H

#include <iostream>
using namespace std;

class huffTreeNode {
public:
  char c; // char value
  huffTreeNode *right; // points to right
  huffTreeNode *left; // points to left
  int freq; // frequency
  string prefix; // prefix code field
};

#endif
