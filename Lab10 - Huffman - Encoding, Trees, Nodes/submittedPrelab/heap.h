// Charles Buyas, cjb8qf, 4-16-17, heap.h

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "huffTreeNode.h"
//#include "huffmanTree.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<huffTreeNode*> vec);
    ~heap();
    vector<huffTreeNode*> getVector();
    void insert(huffTreeNode* x);
    huffTreeNode* findMin();
    huffTreeNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    vector<huffTreeNode*> minHeap;

private:
    //vector<huffTreeNode*> minHeap;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
