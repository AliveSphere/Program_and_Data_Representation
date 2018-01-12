#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "hashTable.h"
#include "timer.h"
#include <string>
#include <sstream>

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
#define LOAD_FACTOR 1
char wordTable[MAXROWS][MAXCOLS];

bool readInTable (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // table[][] array.  In the process, we'll print the table to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            wordTable[r][c] = line[pos++];
        }
    }
    // return success!
    return true;
}

char* getWordInTable (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
	  return NULL;
        // set the next character in the output array to the next letter
        // in the table
        output[pos++] = wordTable[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes table[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}

bool readDictionary(string filename, hashTable* hash) {
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
  }
  string word = "";
  int x = 0;
  while(getline(file, word)) {
    x++;
  }
  return x;
}
  

int main (int argc, char* argv[]) {
    // to hold the number of rows and cols in the input file
    int rows, cols;
    // attempt to read in the file
    bool result = readInTable (argv[2], rows, cols);
    // if there is an error, report it
    if ( !result ) {
        cout << "Error reading in file!" << endl;
        exit(1); // requires the <stdlib.h> #include header!
    }
    // Get a word (of length 10), starting at position (2,2) in the
    // array, in each of the 8 directions
    hashTable* hash = new hashTable(fileLines(argv[1])/LOAD_FACTOR);
    readDictionary(argv[1], hash);
    char* word = NULL;
    int maxLength = 22;
    int found = 0;
    string outputted = "";
    timer* sec = new timer();
    ostringstream format;
    sec->start();
    for ( int x = 0; x < rows; x++) {
      for ( int y = 0; y < cols; y++) {
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
		  break; // north-east
		case 2:
		  format << "E ";
		  break; // east
		case 3:
		  format << "SE";
		  break; // south-east
		case 4:
		  format << "S ";
		  break; // south
		case 5:
		  format << "SW";
		  break; // south-west
		case 6:
		  format << "W ";
		  break; // west
		case 7:
		  format << "NW";
		  break; // north-west
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
    cout << format.str()<< endl;
    cout << found << " words found" << endl;
    cout << "Found all words in " << sec->getTime() << " seconds" << endl;
    cout << int(sec->getTime()*1000) << endl;
    delete hash;
    delete sec;
    return 0;
}
