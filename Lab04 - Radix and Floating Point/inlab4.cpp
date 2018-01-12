// Charles Buyas, cjb8qf, 2-14-17, inlab4.cpp

#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

int main() {
  bool b;
  char c;
  int i;
  double d;
  int* is;
  float f;
  unsigned int u;
  char* cs;
  double* ds;
  //b = false;
  b = true;
  //c = '0';
  c = '1';
  //i = 0;
  i = 1;
  //d = 0;
  d = 1;
  is = NULL;
  f = 0;
  //f = 1;
  u = 0;
  cs = NULL;
  ds = NULL;
  //u  = 1;
  //float maxFloat = FLT_MAX;
  //cout << "max float is: " << maxFloat << endl;
  // set a breakpoint here so I can x/x &var at each variable to check the hex values
  cout << b << c << i << d << is << f << u << cs << ds << endl;

  // moving to final part of in-lab
  int intArray[10];
  char charArray[10];
  
  int intArray2D[6][5];
  // I tested my intArray2D with starting position...
  //... and position [3][2].
  // I observed a change in memory from
  // 0x7fffffffdc90 to
  // 0x7fffffffdcd4
  // I was able to observe this change in position in order to
  // formulate a proper formula for the change in address
  // in the 2D array of size [6][5].
  char charArray2D[6][5];
  return 0;
}
