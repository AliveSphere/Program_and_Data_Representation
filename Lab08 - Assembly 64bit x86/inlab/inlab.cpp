// Charles Buyas, cjb8qf, 3-28-17, inlab.cpp

#include <iostream>
#include <cstdlib>

using namespace std;
/*
class getRekt1 {
public:
  getRekt1(int a, int b);
private:
  int goodShit;
  int letsGo;
};

void object1(getRekt1 banana) {}
void object2(getRekt1 &banana) {}
*/
//void i1(int n) {}
//void i2(int &n) {}

//void c1(char n) {}
//void c2(char &n) {}

//void f1(float n) {}
//void f2(float &n) {}

//void p1(int *n) {}

//void multi1(int a, string b) {}
//void multi2(int &a, string &b) {}

int array1(int a[]) {
  int x = a[2];
  return a[0] + a[1];
}

int main() {
  
  //int i = 1;
  // i1(i);
  //i2(i);
  
  //char c = 'a';
  //c1(c);
  //c2(c);
  
  //float f = 1.0;
  //f1(f);
  //f2(f);
  
  //int *p;
  //p1(p);
  
  int a[] = {2, 4, 5, 6};
  array1(a);
  /*
  int x = 1;
  string y;
  y = "Hello World.";
  multi1(x, y);
  multi2(x, y);
  */

  //  getRekt1 yolo(1, 2);
  //object1(yolo);
  //object2(yolo);
  
  return 0;
  
}

