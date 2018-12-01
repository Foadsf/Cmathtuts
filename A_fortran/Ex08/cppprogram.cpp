#include <iostream>

using namespace std;

extern "C" {
void ffunction_(float *a, float *b);
}

extern "C" {
void cfunction(float *a, float *b);
}

void cppfunction(float *a, float *b);

int main() {
  float a = 1.0, b = 2.0;

  cout << "Before running Fortran function:" << endl;
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;

  ffunction_(&a, &b);

  cout << "After running Fortran function:" << endl;
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;

  cout << "Before running C function:" << endl;
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;

  cfunction(&a, &b);

  cout << "After running C function:" << endl;
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;

  cout << "Before running C++ function:" << endl;
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;

  cppfunction(&a, &b);

  cout << "After running C++ function:" << endl;
  cout << "a=" << a << endl;
  cout << "b=" << b << endl;

  return 0;
}
