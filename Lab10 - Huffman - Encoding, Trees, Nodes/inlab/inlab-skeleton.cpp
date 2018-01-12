// Charles Buyas, cjb8qf, 4-19-17, inlab-skeleton.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "huffTreeNode.h"
using namespace std;

/*
string pref = "";
huffTreeNode* makeATree (huffTreeNode* curNode, string prefix, int index) {
  huffTreeNode* node1 = new huffTreeNode;
  node1 = curNode;
  if (index == prefix.length()) {
    //cout << node1->c << " ";
    return node1;
    }
  if (prefix[index] == '0') {
      index++;
      pref = pref + prefix[index];
      //cout << node1->c << " " << prefix << endl;
      node1->left = makeATree(node1, pref, index);
    }
  if (prefix[0] == '1') {
      index++;
      pref = pref + prefix[index];
      //cout << node1->c << " " << prefix << endl;
      node1->right = makeATree(node1, pref, index);
    }
  return curNode;
}
*/



void buildTree(huffTreeNode* rootNode, char indexInArray, string prefixHere) {
  // cout << "PREFIX " << prefixHere << endl;
  if (prefixHere.length() == 0) {
    //cout << "Here's something: " << (char) indexInArray << endl;
        rootNode->c = indexInArray;
	//cout << rootNode->c;
	return;
      }
      if (prefixHere[0] == '0') {
	if (rootNode->left == NULL) {
	  huffTreeNode* tempNode = new huffTreeNode;
	      tempNode->c = ' ';
	      tempNode->prefix = "";
	      tempNode->left = NULL;
	      tempNode->right = NULL;
	  rootNode->left = tempNode;
	}

	string check1 = prefixHere;
	//cout << "CHECK CONCAT: " << check1.substr(1) << endl;
	buildTree(rootNode->left, indexInArray, prefixHere.substr(1));
      }
      if (prefixHere[0] == '1') {
	if (rootNode->right == NULL) {
	  huffTreeNode* tempNode2 = new huffTreeNode;
	     tempNode2->c = ' ';
	      tempNode2->prefix = "";
	      tempNode2->left = NULL;
	      tempNode2->right = NULL;
	  rootNode->right = tempNode2;
	}
	buildTree(rootNode->right, indexInArray, prefixHere.substr(1));
      }
    }

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters  
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in the first section of the file: the prefix codes
    //int i = 0;
    //INTIALIZE ARRAY
    string myDict [128] = {}; // MY ARRAY
    huffTreeNode* root = new huffTreeNode;
    root->c = ' ';
    root->prefix = "";
    root->left = NULL;
    root->right = NULL;
    while ( true ) {
        string character, prefix2;
	
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix2;
	//cout << "Print character _" << character << "_" << endl;
	//cout << "Print prefix _" << prefix2 << "_" << endl;
	//INSERT CHAR AND PREFIX INTO THE ARRAY
	//myDict[(int)character[0]] = prefix2;
	buildTree(root, character[0],prefix2);
        // do something with the prefix code
	
	//makeATree(newNode, prefix2, 0);
	//cout << "called makeATree" << endl;
    }
    //cout << "SHOULD BE I " << root->right->left->right->c << endl;
    // huffTreeNode* root = new huffTreeNode;
    //root->c = ' ';
    //root->prefix = "";
    //root->left = NULL;
    //root->right = NULL;
    
    //FOR LOOP that gets each element in data structure
    int i = 0;
    for (i = 0; i < 128; i++) {
      //if (i > 32 && i < 128) {
	if (myDict[i] != "") {
	  //buildTree(root, (char)i, myDict[i]);
	  //cout << " is char. ";
	  //cout << "My spot in the array is: " << i << " And ";
	  //cout << "My prefix is: " << myDict[i] << endl;
	}
	//}
    }
    //call make tree
    
    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    
    string allbits = sstm.str();
    //string allbits = "11";
    
    //string checker = "";
    huffTreeNode* iterNode = root;
    //iterNode = root;
    int x = 0;
    //cout << "ALL " << allbits << endl;
    //cout << "ANSWER " ;
    for (x = 0; x <= allbits.length(); x++) {
      if (iterNode->left == NULL && iterNode->right == NULL) {
      cout << iterNode->c;
      iterNode = root;
      }
      //cout << "AllBits[x] " << allbits[x] <<endl;
      if (allbits[x] == '0') {
	//if(iterNode->left == NULL && iterNode->right == NULL){
	//cout << iterNode->c;
	//iterNode = root;
	//} else {
	iterNode = iterNode->left;
	//}
	
      }
      if (allbits[x] == '1') {
	//if(iterNode->right == NULL && iterNode->left == NULL){
	//cout << iterNode->c;
	//iterNode = root;
	//} else{
	iterNode = iterNode->right;
	//}
      }
      /**checker += allbits[x];
      //cout << "Checker is " << checker << " and then ";
      cout << "all bits is " << allbits[x] << endl;
      if (allbits[x] == '0') {
	//cout << "in first if";
	if (iterNode->left->prefix == checker) {
	  //cout << "in second if";
	  cout << "This is the left char " << iterNode->left->c << endl;
	  iterNode = root;
	  checker = "";
	}
	else {
	  cout << "in else";
	  iterNode = iterNode->left;
	}
      }
      if (allbits[x] == '1') {
	//cout << "in third if";
	if (iterNode->right->prefix == checker) {
	  //cout << "in fourth if";
	  cout << iterNode->right->c;
	  iterNode = root;
	  checker = "";
	}
	else {
	  //cout << "in second else";
	  iterNode = iterNode->right;
	}
	}**/
    }
   
    
    // at this point, all the bits are in the 'allbits' string
    cout << endl;
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
}
