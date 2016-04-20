/*
Performance Lab I.1.g-6

Bitwise Shift Right
	Input an uint32_t userInput from stdin utilizing fscanf()
	Initialize another uint32_t bitChecker to 0x01
	Use a Bitwise Shift Left on bitChecker to ensure only the left most bit is turned on
	Print the binary representation of userInput to stdout using only the following:
		fprintf()
		Bitwise Shift Right (>>)
		Bitwise AND (&)
		Relational operator (e.g., >)

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

int main(void)
{
	uint32_t userInput = 15, bitChecker = 0x01;
	int i = 0;

	// Input an uint32_t userInput from stdin utilizing fscanf()
	printf("Input a number to convert to binary: ");
	fscanf(stdin, "%u", &userInput);
	printf("userInput: %u\n", userInput);
	
	// Use a Bitwise Shift Left on bitChecker to ensure only the left most bit is turned on
	bitChecker <<= 31;
	
	for (i = 0; i < 32; i++)
	{
		if (userInput & bitChecker)
			fprintf(stdout, "1");
		else
			fprintf(stdout, "0");
		bitChecker >>= 1;
	}

	return 0;
}