#include <limits.h>
#include <string.h>
#include <stdint.h>

#define BIN_UINTMAXBITS (sizeof(uintmax_t) * CHAR_BIT)

#define BIN_BIT(_s, _b) (\
	sizeof(_s) < (_b + 2) || (_b + 2) > BIN_UINTMAXBITS ? \
		(uintmax_t)0 : \
		_s[sizeof(_s)-(_b+2)] == '0' ? \
			(uintmax_t)0 : \
			(uintmax_t)1 << _b\
)

#define BIN_FROM_ARRAY(_s) (\
	BIN_BIT(_s, 0) + BIN_BIT(_s, 1) + BIN_BIT(_s, 2) + BIN_BIT(_s, 3) + \
	BIN_BIT(_s, 4) + BIN_BIT(_s, 5) + BIN_BIT(_s, 6) + BIN_BIT(_s, 7) + \
	BIN_BIT(_s, 8) + BIN_BIT(_s, 9) + BIN_BIT(_s, 10) + BIN_BIT(_s, 11) +\
	BIN_BIT(_s, 12) + BIN_BIT(_s, 13) + BIN_BIT(_s, 14) + BIN_BIT(_s, 15) +\
	BIN_BIT(_s, 16) + BIN_BIT(_s, 17) + BIN_BIT(_s, 18) + BIN_BIT(_s, 19) +\
	BIN_BIT(_s, 20) + BIN_BIT(_s, 21) + BIN_BIT(_s, 22) + BIN_BIT(_s, 23) +\
	BIN_BIT(_s, 24) + BIN_BIT(_s, 25) + BIN_BIT(_s, 26) + BIN_BIT(_s, 27) +\
	BIN_BIT(_s, 28) + BIN_BIT(_s, 29) + BIN_BIT(_s, 30) + BIN_BIT(_s, 31) +\
	BIN_BIT(_s, 32) + BIN_BIT(_s, 33) + BIN_BIT(_s, 34) + BIN_BIT(_s, 35) +\
	BIN_BIT(_s, 36) + BIN_BIT(_s, 37) + BIN_BIT(_s, 38) + BIN_BIT(_s, 39) +\
	BIN_BIT(_s, 40) + BIN_BIT(_s, 41) + BIN_BIT(_s, 42) + BIN_BIT(_s, 43) +\
	BIN_BIT(_s, 44) + BIN_BIT(_s, 45) + BIN_BIT(_s, 46) + BIN_BIT(_s, 47) +\
	BIN_BIT(_s, 48) + BIN_BIT(_s, 49) + BIN_BIT(_s, 50) + BIN_BIT(_s, 51) +\
	BIN_BIT(_s, 52) + BIN_BIT(_s, 53) + BIN_BIT(_s, 54) + BIN_BIT(_s, 55) +\
	BIN_BIT(_s, 56) + BIN_BIT(_s, 57) + BIN_BIT(_s, 58) + BIN_BIT(_s, 59) +\
	BIN_BIT(_s, 60) + BIN_BIT(_s, 61) + BIN_BIT(_s, 62) + BIN_BIT(_s, 63) \
)

#define BINSTRLEN	(BIN_UINTMAXBITS + 1)
#define BIN(_n)		(BIN_FROM_ARRAY(#_n))

static uintmax_t binfromstr(const char *s)
{
	char array[BINSTRLEN];
	memset(array, '0', sizeof(array));
	strcpy(array + (sizeof(array) - strlen(s)) - 1, s);
	return BIN_FROM_ARRAY(array);
}

static char *binstr(size_t n, char s[n], uintmax_t b)
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
