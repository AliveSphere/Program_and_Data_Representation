// Charles Buyas, cjb8qf, 4-24-17, topological.cpp

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

/** @brief Creates the stringMap that will be a sorted
 * vector of the inputted strings.
 */
map<string, vector<string> > stringMap;

/** @brief Creates the edgeMap that will be a map that stores
 * the connections between inputted strings.
 */
map<string, int> edgeMap;

/** @brief Creates the edgeIter that will be used to iterate
 * through the created maps.
 */
map<string, int>::iterator edgeIter;

/** @brief This checks to see if the inDegree is 0.
 *
 * This function will run through my map of inDegrees and check
 * whether or not the stored value has an inDegree of 0.
 * @return The string with an inDegree of 0, or "" if none have 0.
 * @param inDegrees The inDegrees map
 * @todo Need to have a filled map.
 */

string checkZero(map<string, int> inDegrees) {
  map<string,int>::iterator iter1 = inDegrees.begin();
  // go through all inDegrees
  while (iter1 != inDegrees.end()) {
    // return first if second is 0
    if (iter1->second == 0) {
      return iter1->first;
    }
    // increase counter
    iter1++;
  }
  // return empty string if no 0's
  return "";
}

/** @brief Sorts topologically.
 *
 * This function uses an iterator to sort the inputted strings
 * using a topological algorithm from an acyclic graph.
 * @return A sorted vector of my string inputs.
 * @param graph The map that has my strings and what point to them.
 * @param inDegrees The map that stores inDegrees.
 * @todo Will be used to sort the values, which will later
 * be outputted.
 */

vector<string> topSort(map<string, vector<string> > graph, map<string, int> inDegrees) {
  vector<string>::iterator gotIt;
  vector<string> retVal;
  string deleted = "";
  // goes for every element
  for (int i = 0; i < graph.size(); i++) {
    // set deleted to item to be deleted
    deleted = checkZero(inDegrees);
    // add item to the return vector
    retVal.push_back(deleted);
    // traverse the gotIt vector
    gotIt = graph[deleted].begin();
    while (gotIt != graph[deleted].end()) {
      // subtract 1 for all edges where deleted is first
      inDegrees[*gotIt] = inDegrees[*gotIt] - 1;
      // erase element from deleted elements string vector
      graph[deleted].erase(gotIt);
    }
    // delete item at inDegrees[deleted item]
    inDegrees.erase(deleted);
  }
  return retVal;
}

// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    string string1, string2;
    vector<string> firstColumn;
    vector<string> secondColumn;
    // while loop to put into a map
    while (true) {
      // take in the first input
      file >> string1;
      // take in the second input
      file >> string2;
      // if at the end of the file
      if (string1 == "0" && string2 == "0") {
	break;
      }
      // otherwise set inDegree to 0
      edgeMap[string1] = 0;
      edgeMap[string2] = 0;
    }
    file.close();
    ifstream runfile1(argv[1], ifstream::binary);
    // reopen and loop through the file
    while (true) {
      // again get two inputs
      runfile1 >> string1;
      runfile1 >> string2;
      // checking if at end
      if (string1 == "0" && string2 == "0") {
	break;
      }
      // putting all strings into respective vectors
      firstColumn.push_back(string1);
      secondColumn.push_back(string2);
      edgeIter = edgeMap.find(string2);
      // keep track of all the inDegrees
      edgeMap[string2] = edgeMap[string2] + 1;
      // creates an edge between string1 -> string2
      stringMap[string1].push_back(string2);
    }
    runfile1.close();
    // for all first and second column strings
    for (int i = 0; i < secondColumn.size(); i++) {
      for (int j = 0; j < firstColumn.size(); j++) {
	// find all entries with no out arrow
	if (secondColumn[i] == firstColumn[j]) {
	  secondColumn.erase(secondColumn.begin() + i);
	}
      }
    }
    // for all second column strings,
    // place in a sentinel value to denote no out arrows
    for (int i = 0; i < secondColumn.size(); i++) {
      stringMap[secondColumn[i]].push_back("~");
    }
    // calls topSort
    vector<string> sorted = topSort(stringMap, edgeMap);
    // prints topSort results
    for (vector<string>::const_iterator i = sorted.begin(); i != sorted.end(); ++i) {
      cout << *i << " ";
    }
    cout << endl;
}
