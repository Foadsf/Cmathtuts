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
  cout << "cpps: begin" << endl;
  abc_.x = 78.9998;
  abc_.a = abc_.b * abc_.c;
  abc_.b = 101;
  abc_.c = -54;
  strncpy(abc_.s10, "CHANGE_ALL", 10);
  cout << " x:" << abc_.x << endl;
  cout << " a,b,c:" << abc_.a << "," << abc_.b << "," << abc_.c << endl;
  cout << " s10:" << abc_.s10 << endl;
  cout << "cpps: end" << endl;
}
}
