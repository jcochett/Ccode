/*
	Bitwise.c

	Using and, or, xor, and not
	XOR copy

*/

#define square(X) X * X
#define half(X) X / 2
#define min(X, Y)  ((X) < (Y) ? (X) : (Y))

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <inttypes.h>

// Prints an 8 bit number in binary
void print8bits(uint8_t n)
{
	n & 128 ? printf("1") : printf("0");
	n & 64 ? printf("1") : printf("0");
	n & 32 ? printf("1") : printf("0");
	n & 16 ? printf("1") : printf("0");
	n & 8 ? printf("1") : printf("0");
	n & 4 ? printf("1") : printf("0");
	n & 2 ? printf("1") : printf("0");
	n & 1 ? printf("1") : printf("0");
}

int main(void)
{
	uint8_t x = 0, y = 0;

	// Get input to use
	printf("Enter two numbers in the range of 0-255 (e.g. 10 7): ");
	scanf("%hhu %hhu", &x, &y);

	// BITWISE AND use & operator
	printf("\nBitwise And: %hhu & %hhu = %hhu\n", x, y, x & y);

	print8bits(x);     printf("\n");
	print8bits(y);     printf("\n--------\n");
	print8bits(x & y); printf("\n\n");


	// BITWISE OR use | operator
	printf("\nBitwise Or: %hhu | %hhu = %hhu\n", x, y, x | y);

	print8bits(x);     printf("\n");
	print8bits(y);     printf("\n--------\n");
	print8bits(x | y); printf("\n\n");


	// BITWISE XOR use ^ operator
	printf("\nBitwise XOR: %hhu ^ %hhu = %hhu\n", x, y, x ^ y);

	print8bits(x);     printf("\n");
	print8bits(y);     printf("\n--------\n");
	print8bits(x ^ y); printf("\n\n");

	// Not ~ operator
	printf("\nNot ~: ~%hhu = %hhu\n", x, ~x);

	print8bits(x);     printf("\n");
	print8bits(~x); printf("\n\n");


	// Fancy XOR copy
	printf("Switch x = %hhu and y = %hhu values with XOR\n", x, y);
	x = x ^ y; 
	printf("x = x ^ y thus x is: ");  print8bits(x);
	y = x ^ y;
	printf("\ny = x ^ y thus y is: "); print8bits(y);
	x = x ^ y;
	printf("\nx = x ^ y thus x is: "); print8bits(x);
	printf("\nNow x = %hhu and y = %hhu values after XOR\n\n", x, y);

	return 0;
}