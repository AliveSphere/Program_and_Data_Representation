// Charles Buyas, cjb8qf, 3-30-17, postlab.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef CAR_H
#define CAR_H

class car {
public:
  car();
  string dir();
  bool driver();
  void crashes(string n);
private:
  int wheels;
  int weight;
  string direction;
};

#endif


car::car() {
  wheels = 4;
  weight = 2400;
}

string car::dir() {
  direction = "EAST";
  return direction;
}

bool car::driver() {
  return true;
}

void car::crashes(string a) {
  string numCrash;
  numCrash = a;
}


int main() {
  car a;
  a.crashes("Four crashes");
  a.driver();
  a.dir();
}
