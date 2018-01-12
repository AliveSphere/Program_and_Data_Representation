// Charles Buyas, cjb8qf, 4-13-17, postlab.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

class A {
public:
  virtual void car() {
  }
  virtual int speed() {
    return 1;
  }
};

class B : public A {
public:
  virtual void car() {
  }
  virtual int speed() {
    return 2;
  }
};

int main () {
    int which;
    A *bar;
    if ( which ) {
        bar = new A();
    }
    else {
        bar = new B();
    }
    //bar->car();
    bar->speed();
    return 0;
}
