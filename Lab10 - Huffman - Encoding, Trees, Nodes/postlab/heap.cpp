// Charles Buyas, cjb8qf, 4-16-17, heap.cpp

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffTreeNode.h"
using namespace std;


heap::heap() : heap_size(0) {
  huffTreeNode* n = new huffTreeNode;
  n->freq = 0;
  minHeap.push_back(n);
}

heap::heap(vector<huffTreeNode*> vec) : heap_size(vec.size()) {
    minHeap = vec;
    minHeap.push_back(minHeap[0]);
    minHeap[0] = 0;
    for ( int i = heap_size/2; i > 0; i-- )
        percolateDown(i);
}

heap::~heap() {
}


vector<huffTreeNode*> heap::getVector() {
  return minHeap;
}


void heap::insert(huffTreeNode* x) {
    // a vector push_back will resize as necessary
    minHeap.push_back(x);
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    huffTreeNode *x = minHeap[hole];
    for ( ; (hole > 1) && (x->freq < minHeap[hole/2]->freq); hole /= 2 )
        minHeap[hole] = minHeap[hole/2];
    minHeap[hole] = x;
}

huffTreeNode* heap::deleteMin() {
    if ( heap_size == 0 )
        throw "deleteMin() called on empty heap";
    // save the value to be returned
    huffTreeNode* ret = minHeap[1];
    // move the last inserted position into the root
    minHeap[1] = minHeap[heap_size--];
    // make sure the vector knows that there is one less element
    minHeap.pop_back();
    // percolate the root down to the proper position
    percolateDown(1);
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffTreeNode *x = minHeap[hole];
    // while there is a left child...
    while ( hole*2 <= heap_size ) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ( (child+1 <= heap_size) && (minHeap[child+1]->freq < minHeap[child]->freq) )
            child++;
        // if the child is greater than the node...
        if ( x->freq > minHeap[child]->freq ) {
            minHeap[hole] = minHeap[child]; // move child up
            hole = child;             // move hole down
        } else
            break;
    }
    // correct position found!  insert at that spot
    minHeap[hole] = x;
}

huffTreeNode* heap::findMin() {
    if ( heap_size == 0 )
        throw "findMin() called on empty heap";
    else
      return minHeap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << minHeap[0]->freq << ") ";
    for ( int i = 1; i <= heap_size; i++ ) {
        cout << minHeap[i]->freq << " ";
        // next line from from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if ( isPow2 )
            cout << endl << "\t";
    }
    cout << endl;
}
