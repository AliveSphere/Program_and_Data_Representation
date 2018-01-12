// Charles Buyas, cjb8qf, 3-16-17, hashtable.cpp

#include <iostream>
#include "hashtable.h"
#include <string.h>
#include <algorithm>

using namespace std;

hashtable::hashtable() {
  table = new list<string>*[421];
  size = 421;
  //table = new list<string>*[11];
  //size = 11;
  //table = new list<string>*[991];
  //size = 991;
}


hashtable::hashtable(int size) {
  if (checkPrime(size)) {
    table = new list<string>*[size];
    this->size = size;
  }
  else {
    table = new list<string>*[getNextPrime(size)];
    this->size = getNextPrime(size);
  }
  for (int i = 0; i < this->size; i++) {
    table[i] = NULL;
  }
}


hashtable::~hashtable() {
  delete[] table;
}


unsigned int hashtable::hashFunc(string element) {
  int wordSizeTotal = 0;
  int hashKey;
  string x;
  x = element;
  // I got rid of this for-loop for testing the ways to make my hashFunc slower by increasing the number of collisions.
  // calculate ascii total of the string
  for (int i = 0; i < x.length(); i++) {
    wordSizeTotal = wordSizeTotal + int(x[i]);
  }
  // mod by the size to get hash key
  hashKey = wordSizeTotal % size;
  return hashKey;
}


void hashtable::insert(string element) {
  int insertKey = hashFunc(element.c_str());
  // checks if anything is at the key
  if (table[insertKey] == NULL) {
    table[insertKey] = new list<string>();
  }
  // chains if there is something there already
  table[insertKey]->push_back(element);
}

bool hashtable::find(string element) {
  int x = hashFunc(element);
  if (table[x] != NULL) {
    if(::find(table[x]->begin(), table[x]->end(), element) != table[x]->end()) {
      return true;
    }
  }
  return false;
}


bool hashtable::checkPrime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashtable::getNextPrime (unsigned int n) {
    while ( !checkPrime(++n) );
    return n; // all your primes are belong to us
}

