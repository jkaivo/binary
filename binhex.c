#include <inttypes.h>
#include <stdio.h>
#include "binary.h"

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++) {
		int base = argv[i][0] == '0' && argv[i][1] == 'x' ? 16 : 2;
		char s[BINSTRLEN];
		uintmax_t n = strtoumax(argv[i], NULL, base);
		if (argc > 2) {
			printf("%s: ", argv[i]);
		}
		if (base == 2) {
			printf("%jx\n", n);
		} else {
			printf("%s\n", binstr(sizeof(s), s, n));
		}
	}
	return 0;
}
