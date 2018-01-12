// Charles Buyas, cjb8qf, 4-11-17, inlab.cpp
#include <iostream>

using namespace std;

int main() {
  int x;
  int counter;
  counter = 0;
  cin >> x;
  while (x > 1) {
    if (x%2 != 0) {
      counter++;
      x = (3*x) + 1;
    }
    else {
      counter++;
      x = x/2;
    }
  }
  return 0;

}
