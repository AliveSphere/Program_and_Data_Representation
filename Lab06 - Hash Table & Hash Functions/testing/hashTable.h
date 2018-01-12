#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <iostream>
#include <string>
#include <list>

using namespace std;

class hashTable {
 public:
  hashTable();
  hashTable(int size);
  ~hashTable();
  void insert(string element);
  bool find(string element);
  unsigned int calcKey(string element);
  unsigned int calcKey2(string element);
  bool checkprime(unsigned int numb);
  int getNextPrime(unsigned int numb);
 
 private: 
  list<string>** table;
  int size;
};

#endif
