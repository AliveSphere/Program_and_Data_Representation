#include "hashTable.h"
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

hashTable::hashTable() {
  table = new list<string>*[113];
  size = 113;
}

hashTable::hashTable(int size) {
  if (checkprime(size)) {
    table = new list<string>*[size];
    this->size = size;
  }
  else{
    table = new list<string>*[getNextPrime(size)];
    this->size = getNextPrime(size);
  }
  for (int i = 0; i < this->size; i++) {
    table[i] = NULL;
  }
}

hashTable::~hashTable() {
  delete[] table;
}

unsigned int hashTable::calcKey(string element) {
  unsigned int sum = 0;
  for (int x = 0; x < element.size(); x++) {
    char val = element[x];
    sum += int(val);
  }
  return sum % size;
}

unsigned int hashTable::calcKey2(string element) {
  unsigned int key = 5381;
  int i = 0;
  while (i < element.length()) {
    key = (key << 5) + key + element[i];
    i++;
  }
  return key % size;
}
      
void hashTable::insert(string element) {
  int key = calcKey2(element.c_str());
  if (table[key] == NULL) {
    table[key] = new list<string>();
  }
  table[key]->push_back(element);
}


bool hashTable::find(string element) {
  int x = calcKey2(element);
  if (table[x] != NULL) {
    if(::find(table[x]->begin(), table[x]->end(), element) != table[x]->end()){
      return true;
    }
  }
  return false;
}

  

bool hashTable::checkprime(unsigned int p) {
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

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}   
