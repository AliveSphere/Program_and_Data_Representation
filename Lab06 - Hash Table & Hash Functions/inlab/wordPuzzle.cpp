// Charles Buyas, cjb8qf, 3-13-17, wordPuzzle.cpp

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "hashtable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
#define LOAD_FACTOR 1
char wordTable[MAXROWS][MAXCOLS];

bool readInTable (string filename, int &rows, int &cols) {
  string line; // c++ string to hold the line of data that is read in
  ifstream file(filename.c_str()); // set up file stream to read in the file
  // takes in a c-style char* string, not c++ string
  if (!file.is_open()) { // if there's an error
    return false;
  }
  file >> rows; // reads in the number of rows
  getline (file,line);
  file >> cols; // reads in the number of columns
  getline (file,line);
  getline (file,line); // actual data for the word puzzle
  file.close();
  int pos = 0;
  for (int r = 0; r < rows; r++) { // make 2d array table
    for (int c = 0; c < cols; c++) {
      wordTable[r][c] = line[pos++];
    }
  }
  return true;
}

char* getWordInTable (int startRow, int startCol, int dir,
		      int len, int numRows, int numCols) {
  static char output[256];
  if (len >= 255) { // length not bigger than array
    len = 255;
  }
  int pos = 0; // position of output array
  int r = startRow; // position of current row
  int c = startCol; // position of current column
  for (int i = 0; i < len; i++) {
    if ((c >= numCols) || (r >= numRows) || (r < 0) || (c < 0)) {
      //make sure nothing out of bounds
      return NULL;
    }
    output[pos++] = wordTable[r][c]; // next in output to the next in table
    switch (dir) { // assume that [0][0] is upper-left of table, move dir
    case 0: // n
      r--;
      break;
    case 1: // ne
      r--;
      c++;
      break;
    case 2: // e
      c++;
      break;
    case 3: // se
      r++;
      c++;
      break;
    case 4: // s
      r++;
      break;
    case 5: // sw
      r++;
      c--;
      break;
    case 6: // w
      c--;
      break;
    case 7: // nw
      r--;
      c--;
      break;
    }
  }
  output[pos] = 0; // set the next character, end of string, to 0
  return output; // return the c-style char* string, not c++ string
}

bool readDictionary(string filename, hashtable* hash) {
  ifstream file(filename.c_str());
  if (!file.is_open()) {
    return false;
  }
  string word = "";
  while(getline(file, word)) {
    hash->insert(word);
  }
  return true;
}

int fileLines(string filename) {
  ifstream file(filename.c_str());
  if (!file.is_open()) {
    return NULL;
    //return -1;
  }
  string word = "";
  int x = 0;
  while (getline(file, word)) {
    x++;
  }
  return x;
}

int main(int argc, char* argv[]) {
  int rows, cols; // # of rows and columns in input file
  bool result = readInTable(argv[2], rows, cols); // read file
  if (!result) { // check for error
    cout << "Error reading. " << endl;
    exit(1);
  }
  hashtable* hash = new hashtable(fileLines(argv[1])/LOAD_FACTOR);
  readDictionary(argv[1], hash);
  char* word = NULL;
  int maxLength = 22;
  int found = 0;
  string outputted = "";
  timer* sec = new timer();
  ostringstream format;
  sec->start();
  for (int x = 0; x < rows; x++) {
    for (int y = 0; y < cols; y++) {
      for (int l = 3; l <= maxLength; l++) {
	for (int d = 0; d < 8; d++) {
	  word = getWordInTable(x, y, d, l, rows, cols);
	  if (word != NULL) {
	    if (hash->find(word)) {
	      found++;
	      switch (d) {
	      case 0:
		format << "N ";
		break; // north
	      case 1:
		format << "NE";
		break; // north east
	      case 2:
		format << "E ";
		break; // east
	      case 3:
		format << "SE";
		break; // south east
	      case 4:
		format << "S ";
		break; // south
	      case 5:
		format << "SW";
		break; // south west
	      case 6:
		format << "W ";
		break; // west
	      case 7:
		format << "NW";
	        break; // north west
	      }
	      format << "(" << x << ", ";
	      format << y << "):       " << word << "\n";
	    }
	  }
	}
      }
    }
  }
  sec->stop();
  cout << format.str() << endl;
  cout << found << " words found" << endl;
  cout << "Found all words in " << sec->getTime() << " seconds" << endl;
  cout << int(sec->getTime()*1000) << endl;
  delete hash;
  delete sec;
  return 0;
}

