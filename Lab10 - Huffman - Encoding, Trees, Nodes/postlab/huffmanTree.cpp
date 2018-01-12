// Charles Buyas, cjb8qf, 4-16-17, huffmanTree.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "huffTreeNode.h"
#include "huffmanTree.h"

using namespace std;

huffmanTree::huffmanTree() {
}

void huffmanTree::getPrefix(char c) {
}

heap huffmanTree::build(heap h) {
  while (h.size() > 1) {
    huffTreeNode* n = new huffTreeNode;
    n->left = h.deleteMin();
    n->right = h.deleteMin();
    n->freq = n->left->freq + n->right->freq;
    h.insert(n);
  }
  return h;
}

string huffmanTree::makePrefix(huffTreeNode* n, vector<string> &m, string prefix1) {
  //int count = 0;
  huffTreeNode* curNode = new huffTreeNode;
  curNode = n;
  if (curNode->left == NULL && curNode->right == NULL) {
    m[(int)curNode->c] = prefix1;
    //cout <<  prefix1 << endl;
    n->prefix = prefix1;
    cout << n->c << " " <<  n->prefix << " " << endl;
    return prefix1;
  }
  if (curNode->right != NULL) {
    //prefix = prefix + "1";
    //return makePrefix(curNode->right);
    //cout << "This might be the prefix" << prefix << endl;
    //count++;
    makePrefix(curNode->right, m, prefix1 + "1");
  }
  if (curNode->left != NULL) {
    //prefix = prefix + "0";
    //return makePrefix(curNode->left);
    //cout << "This may be the prefix" << prefix << endl;
    //count++;
    makePrefix(curNode->left, m, prefix1 + "0");
  }
  //string x = "done";
  return prefix1;
}
/*
string huffmanTree::printPrefix(huffTreeNode* n, string prefix1) {
  huffTreeNode* curNode = new huffTreeNode;
  curNode = n;
  if (curNode->left == NULL && curNode->right == NULL) {
    // m[(int)curNode->c] = prefix
    return "prefix code: " + prefix;
  }
  if (curNode->right != NULL) {
    //prefix = prefix + "1";
    cout << "do I get here?" << endl;
    printPrefix(curNode->right, prefix + "1");
    //makePrefix(curNode->right);
  }
  if (curNode->left != NULL) {
    //prefix = prefix + "0";
    cout << "do I even get here" << endl;
    printPrefix(curNode->left, prefix + "0");
    //makePrefix(curNode->left);
  }
  return "done";
}
*/

/*
string huffmanTree::makePrefix(huffTreeNode* n) {
  Hufftreenode* curNode = new huffTreeNode;
  curNode = n;
  if (curNode->left == NULL && curNode->right == NULL) {
    // m[(int)curNode->c] = prefix
    return prefix;
  }
  if (curNode->right != NULL) {
    prefix = prefix + "1";
    return makePrefix(curNode->right);
    //makePrefix(curNode->right);
  }
  if (curNode->left != NULL) {
    prefix = prefix + "0";
    return makePrefix(curNode->left);
    //makePrefix(curNode->left);
  }
  return 0;
}
*/


/*
    x
   / \
  x   x
   \ /
   a b


in main, 
new vector of strings vec1
string for prefix is "" pref
makePrefix(tree1->root, vec1, pref)
in each spot, if not empty string 
I want to loop through the constructed vector, and print out the type-casted index of the vector, and the value there

print out
(char) i << m[i] 

 */
