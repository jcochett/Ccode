/*
Performance Lab I.1.g-5

Bitwise Shift Left
	Scan a dotted decimal format IP address (e.g., 172.16.142.97) on a single line
	Store each octet into its own uint8_t variable
	Print the full IP in dotted decimal format
	Store the full IP in a uint32_t as raw binary:
		Bitwise OR to turn on an octet’s bits in the uint32_t
		Use a Bitwise Shift Left to make room for the next octet
		Continue until all four octets are stored in your uint32_t
	Print all the octets in line, as hex, width 2, with zeros
	Print the uint32_t, as hex, width 8, with zeros
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
//#include <inttypes.h>

int main(void)
{
	uint8_t octet1 = 0, octet2 = 0, octet3 = 0, octet4 = 0;
	uint32_t ip = 0;

	printf("Enter an IP address in dotted decimal format: ");

	// Holy Fuck it was not discussed how to read into a freaking uint8_t
	// The fucking internet was so slow
	scanf("%hhd.%hhd.%hhd.%hhd", &octet1, &octet2, &octet3, &octet4);
		
	// Print the string
	printf("\nHere it is: %d.%d.%d.%d\n", octet1, octet2, octet3, octet4);

	// Bitwise OR to read in the value into the uint32, shifted the size of uint8
	ip |= octet1;
	ip <<= 8;
	ip |= octet2;
	ip <<= 8;
	ip |= octet3;
	ip <<= 8;
	ip |= octet4;
	
	//Print all the octets in line, as hex, width 2, with zeros
	printf("%02x %02x %02x %02x\n", octet1, octet2, octet3, octet4);

	//Print the uint32_t, as hex, width 8, with zeros
	printf("The uint32_t, as hex, width 8, with zeros\n");
	printf("%08x\n", ip);

	printf("IP as a decimal %d\n", ip);

	return 0;
}