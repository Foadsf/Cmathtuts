/*  DEC C program NUMBERS.C contains the following lines of    *
 *  code:                                                      */

#include <stdio.h>

struct xs {
  int first;
  int second;
  int third;
};

// #pragma extern_model common_block

extern struct xs numbers_;
void fnum_();

int main() {

  numbers_.first = 1;
  numbers_.second = 2;
  numbers_.third = 3;
  fnum_();
  return 0;
}
