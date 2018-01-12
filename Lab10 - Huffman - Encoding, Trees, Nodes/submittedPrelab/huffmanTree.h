// Charles Buyas, cjb8qf, 4-17-17, huffmanTree.h

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "huffTreeNode.h"

using namespace std;


class huffmanTree {
public:
  huffmanTree();
  void getPrefix(char c);
  heap build(heap h);
  string printPrefix(huffTreeNode* n, string prefix);
  //string makePrefix(huffTreeNode* n);
  string makePrefix(huffTreeNode* n, vector<string> &m, string prefix);
  //private:
  //string prefix;
};

#endif 
