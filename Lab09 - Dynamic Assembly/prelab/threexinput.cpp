// Charles Buyas, cjb8qf, 4-10-17, threexinput.cpp

#include <iostream>
#include <cstdlib>
#include "timer.h"

using namespace std;

extern "C" long threexplusone (long);

int main() {
  long x; // declare x
  long n; // declare n
  long numResult;
  timer *clock = new timer();
  cout << "Enter an x: " << endl;
  cin >> x; // gets input
  cout << "Enter an n: " << endl;
  cin >> n; // gets number of times to run
  clock->start();
  for (int i = 0; i < n; i++) {
    numResult = threexplusone(x); // runs the algorithm
  }
  clock->stop();
  cout << "The algorithm required this many steps: " << numResult << endl;
  cout << "Average time is: " << clock->getTime()*1000/n;
  return 0;
}
