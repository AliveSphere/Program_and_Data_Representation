// Charles Buyas, cjb8qf, 2-16-17, bitCounter.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int count = 1;

int reBin(int num) {
  cout << "the num is: " << num << endl;
  if (num%2 == 0) {
    return reBin(num/2);
  }
  
  else if ((num%2 == 1) && (!(num == 1))) {
    count++;
    return reBin(num/2);
  }
  else {
    return 0;
  }
}

int main(int argc, char **argv) {
  if (!(argv[1] == NULL)) {
    int x = atoi(argv[1]);
    reBin(x);
    cout << "count of 1's: " << count << endl;
  }
  else {
    cout << "ERROR: no command number input." << endl;
  }
  return 0;
}
