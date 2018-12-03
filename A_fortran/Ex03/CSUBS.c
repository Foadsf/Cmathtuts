/*  File CSUBS.C  */

#include <math.h>

int fact_(int* np) {
	int n = *np;
	if (n > 1) {
		int m = n-1;
		return (n * fact_(&m));
	};
	return 1;
}

void pythagoras_(float* a, float* b, float* c) { *c = sqrt(*a * *a + *b * *b); }
