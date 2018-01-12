// Charles Buyas, cjb8qf, 2-13-17, prelab4.cpp

#include <iostream>
#include <string>
#include <tgmath.h>
#include <math.h>
#include <cmath>
using namespace std;


void sizeOfTest() {
  int x;
  cout << "size of int: " << sizeof(x) << endl;
  unsigned int y;
  cout << "size of unsigned int: " << sizeof(y) << endl;
  float z;
  cout << "size of float: " << sizeof(z) << endl;
  double a;
  cout << "size of double: " << sizeof(a) << endl;
  char b;
  cout << "size of char: " << sizeof(b) << endl;
  bool c;
  cout << "size of bool: " << sizeof(c) << endl;
  int* d;
  cout << "size of int*: " << sizeof(d) << endl;
  char* e;
  cout << "size of char*: " << sizeof(e) << endl;
  double* g;
  cout << "size of double*: " << sizeof(g) << endl;
}


void outputBinary(unsigned int x) {
  string myString = "";
  int bArray[32] = {};
  int y = x;
  int z;
  cout << "the number is: " << y << endl;
  cout << "now for binary: " << endl;
  while (y > 0) {
    for (int d = 32; d >= 0; d--) {
      if (y%2 == 1) {
        bArray[d-1] = 1;
        y = y/2;
//cout << "in the +1 section: " << y << endl;
      }
      else if (y%2 == 0) {
        bArray[d-1] = 0;
        y = y/2;
//cout << "in the +0 section: " << y << endl;
      }
    }
  }
  for (int x = 0; x < 32; x++) {
//myString = myString.add(bArray[x]);
    cout << " " << bArray[x];
  }
  cout << myString << endl;
}


/*
  std::string output;
  pow(int, int);
  int n = 32;
  while (x > 0) {
    int y = 0;
    while (x >= pow(2, n)) {
      output + "1";
      x = x - pow(2, n);
      n--;
    }
    output + "0";
    x = x - y;
  }
  cout << "~~~the output is: " << output << endl;
*/


void overflow() {
unsigned int x;
x = 4294967295;
cout << "max unsigned int is: " << x << endl;
cout << "what happens when you add 1?: ";
x = x+1;
cout << x << endl;
cout << "looks like it reset to 0! " << endl;
cout << "somehow the program doesn't halt. " << endl;
cout << "the answer becomes 0. " << endl;
cout << "this occurs because the numbers start looping back to one another. For example, adding 2 to the max number would then reset it to 1. Adding 10 would reset it to 9. Etc." << endl;
}

union foo {
float f;
int *x;
} bar;

int main() {
  sizeOfTest();
  cout << "enter an integer, x,  to turn into binary: " << endl;
  int x;
  cin >> x;
  outputBinary(x);
  overflow();
  bar.f = (1.248046875*(2));
  cout << bar.x << endl;
 return 0;
}
