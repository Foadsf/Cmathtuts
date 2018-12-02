#include <stdio.h>

typedef struct {
	char s[30];
	int l;
} fstring;

extern fstring stringf_;

int main() {
	//printf("%s\n", stringf_.string);
	fstring stringc = stringf_;
	printf("%d\n", stringc.l);
	stringc.s[29] = '\0';
	printf("%s\n",stringc.s);
	return 0;
}
