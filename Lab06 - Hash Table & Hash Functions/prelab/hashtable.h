// Charles Buyas, cjb8qf, 3-12-17, hashtable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <list>
#include "timer.h"

using namespace std;

class hashtable {
 public:
  hashtable();
  hashtable(int size);
  ~hashtable();
  string direction();
  bool find(string element);
  void insert(string element);
  bool checkPrime(unsigned int num);
  int getNextPrime(unsigned int num);
  unsigned int hashFunc(string element);
  
 private:
  list<string>** table;
  int size;
};

#endif
