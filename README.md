# binary

This is a liblet (a very small library consisting of one header file and
one source file) for working with binary numbers in C.

The header file, `binary.h`, defines two macros for external use, `BIN` and
`BINSTRLEN`. It also declares one function which is defined in the source
file `binary.c`. Additional macros in `binary.h` which begin with `BIN_`
are implementation details and should not be considered part of the defined
interface.

## BIN

The macro `BIN` converts a binary literal number to a `uintmax_t`. For example:

	uintmax_t n = BIN(1010);

This will result in the variable `n` having the value `0xa` (the hex
representation of the binary literal `1010`).

## BINSTRLEN

The symbolic constant `BINSTRLEN` defines the length of a `uintmax_t`
represented as a string of characters. Its primary use is for declaring an
array large enough to hold the results of `binstr()` (see below):

	char s[BINSTRLEN];

## binstr()

	char *binstr(size_t n, char s[n], uintmax_t b);

This function converts the number `b` to its string representation in base 2.
The least significant `n - 1` bits are stored in the array `s`. The string
will be null terminated.

## See Also

There is no inverse function of `binstr()` provided, as this can be fulfilled
by calling `strtoumax()` with the third paramater (`base`) set to `2`.
