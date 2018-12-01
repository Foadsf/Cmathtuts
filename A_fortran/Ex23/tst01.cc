#include <iostream>

extern "C" {
void tstfunc_();
extern struct { float data[5][5]; } test_;
}

void printmtrx(float (&a)[5][5]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      std::cout << a[i][j] << '\t';
      a[i][j] += 2;
    }
    std::cout << std::endl;
  }
}

int main() {
  // start...
  tstfunc_();

  printmtrx(test_.data); // here i want to call delta and manipulate it.
  return 0;
}
