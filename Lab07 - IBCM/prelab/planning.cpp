// Charles Buyas, cjb8qf, 3-20-17, planning.cpp

#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a;
  cin >> b;
  cin >> c;
  while (a + b + c != 0) {
    cout << "Doesn't equal zero. " << endl;
    cin >> a;
    cin >> b;
    cin >> c;
  }
  cout << a << " " << b << " " << c << endl;
}
