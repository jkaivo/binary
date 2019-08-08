#include <stdint.h>
#include <string.h>

#include "binary.h"

uintmax_t binary(const char *s)
{
	char array[BINSTRLEN];
	memset(array, '0', sizeof(array));
	strcpy(array + (sizeof(array) - strlen(s)) - 1, s);
	return BIN_FROM_ARRAY(array);
}

char *binstr(size_t n, char s[n], uintmax_t b)
{
	memset(s, '0', n);
	s[n - 1] = '\0';
	for (size_t i = 0; i < n - 2 && i < BIN_UINTMAXBITS; i++) {
		if (b & ((uintmax_t)1 << i)) {
			s[n - (i + 2)] = '1';
		}
	}
	return s;
}
