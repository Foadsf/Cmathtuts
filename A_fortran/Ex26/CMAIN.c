/*     File CMAIN.C   */

#include <stdio.h>

extern int fact_(int* n);
extern void pythagoras_(float* a, float* b, float* c);

int main()
{
    int n = 7;
    printf("Factorial of 7 is: %d\n", fact_(&n));

    float a, b, c;
    a = 30;
    b = 40;
    pythagoras_(&a, &b, &c);
    printf("Hypotenuse if sides 30, 40 is: %f\n", c);
    return 0;
}
