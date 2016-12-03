#include <cstring>
#include <iostream>
using namespace std;
extern "C" {
extern struct {
  double x;
  int a, b, c;
  char s10[10];
} abc_;
void cpps_() {
  cout << "cpps1: begin" << endl;
  abc_.x = 90023.876;
  abc_.a = 23;
  abc_.b = 1;
  abc_.c = -999;
  strncpy(abc_.s10, "ALLCHANGED", 10);
  cout << " x:" << abc_.x << endl;
  cout << " a,b,c:" << abc_.a << "," << abc_.b << "," << abc_.c << endl;
  cout << " s10:" << abc_.s10 << endl;
  cout << "cpps1: end" << endl;
}
}
