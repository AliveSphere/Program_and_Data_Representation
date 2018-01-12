// Charles Buyas, cjb8qf, 3-27-17, mathfun.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" long mathlibpro (long, long);
extern "C" long mathlibpow (long, long);

int main() {

  long x, y; // declare variables
  cin >> x; // gets base
  cin >> y; // gets exponent/multiplier
  long sum = mathlibpro(x,y); // runs the product
  long pow = mathlibpow(x,y); // runs the power
  cout << "Product sum: " << sum << endl; // returns the product sum
  cout << "Power result: " << pow << endl; // returns the power result
  
}
