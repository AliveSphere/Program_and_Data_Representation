// Charles Buyas, cjb8qf, 4-16-17, huffmanenc.cpp


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "huffmanTree.h"
#include "huffTreeNode.h"

using namespace std;


int main (int argc, char **argv) {
  vector<int> intVec(128);
  int numLetters = 0;
  int distinctLet = 0;
  int totalBits = 0;
  int compBits = 0;
  float compRatio = 0;
  float costBits = 0;
  //cout << "I'm here." << endl;
    if ( argc != 2 ) {
        cout << "Must supply input file name as only param" << endl;
        exit(1);
    }
    FILE *fp = fopen(argv[1], "r");

    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' DNE" << endl;
        exit(2);
    }
    //cout << "I'm now here." << endl;
    char g;
    while ( (g = fgetc(fp)) != EOF ) {
      int i = (int) g;
      if (i > 31 && i < 128) {
	intVec[i]++; // counting the frequency of the letter
	numLetters++; // total symbols
	totalBits++;
      }
    }
    totalBits = totalBits*8;
    //cout << "Almost to the hard part." << endl;
    // step 1: use vector to make heap
    // step 2: use heap to make tree
    // step 3: kill myself
    // step 4: traverse tree to get prefix
    //vector<huffTreeNode*> heap1;
    heap(heap1);
    huffmanTree* tree1 = new huffmanTree;
    int i;
    //cout << "Getting harder." << endl;
    for (i = 0; i <= intVec.size(); i++) {
      if (intVec[i] > 0) {
	huffTreeNode* node1 = new huffTreeNode;
	node1->left = NULL;
	node1->right = NULL;
	node1->c = i;
	node1->freq = intVec[i];
	heap1.insert(node1);
      }
    }
    //cout << "Middle difficulty" << endl;
    heap heap2;
    heap2 = tree1->build(heap1);
    //heap1.print();
    //cout << "Dodged a bullet!" << endl;

    vector<string> stringVec(128);
    string pref1 = "";
    //int si = 0;
    //cout << "About to crash..." << endl;
    cout << tree1->makePrefix(heap2.findMin(), stringVec, pref1) << endl;
    //cout << "Made it past makePrefix!!!" << endl;
    //cout << "Print Prefix: " << tree1->printPrefix(heap2.findMin(), pref1) << endl;
    /*
    for (si = 0; si < stringVec.size(); si++) {
      //cout << "are we?" << endl;
      //if (stringVec[si]->freq != "") {
      //cout << "we're in" << endl;
      //cout << (char) si << stringVec[si] << endl;
	//}
      if (intVec[si] > 0) {
	cout << (char) si << " " << intVec[si] << endl;
      }
    }
    */
    cout << "-------------------------------------------------------" << endl;
    //cout << tree1->makePrefix(heap2.findMin(), stringVec, pref1);
    
    rewind(fp);
    char g3;
    int stringCount;
    while ( (g3 = fgetc(fp)) != EOF ) {
      int i = (int) g3;
      if (i > 31 && i < 128) {
	cout << stringVec[i] << " ";
	for (stringCount = 0; stringCount < stringVec[i].size(); stringCount++) {
	  compBits++;
	}
      }
    }
    cout << endl;
    
    cout << "-------------------------------------------------------" << endl;
    //cout << "Am I going to make it?" << endl;
    rewind(fp);
    int counter = 0;
    for (counter = 0; counter <= intVec.size(); counter++) {
      if (intVec[counter] != 0) {
	distinctLet++;
      }
    }
    compRatio = (float) totalBits/compBits;
    costBits = (float) 8/compRatio;
    cout << "There are a total of " << numLetters << " symbols that are encoded." << endl;
    cout << "There are " << distinctLet << " distinct symbols used." << endl;
    cout << "There were " << totalBits << " bits in the original file." << endl;
    cout << "There were " << compBits << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << compRatio << "." << endl;
    cout << "The cost of the Huffman tree is " << costBits << " bits per character." << endl;
    //cout << "What's going on??" << endl;
    fclose(fp);
}
