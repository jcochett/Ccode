/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// CAPSTONE LAB I.3.A-1 ///////////////////////////////////////////
////////////////////////////////////////////////// "Advanced String Theory" /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The requirement for this lab is to define all of the EnglishFunctions.h functions as declared.
// The comment blocks for each function should clearly indicate what the requirements are for the function.
// There are a variety of appropriate solutions for many of these functions.
// Unit Test Code v1.c has been written to test all of the functions both individually and as a whole.
// This header definition file represents stub code that the students must define to complete this lab.
// Completion is indicated by passing all 311 tests.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* FUNCTION:   int is_it_alphabet(signed char inputChar);
*
* ARGUMENTS:  inputChar is a single signed character that represents a single character
*                 that is tested as an alphabet letter.
*
* RETURNS:	  1 if inputChar is an alphabet character
*             0 if inputChar is not an alphabet character
*
* NOTES:      This function should not care if inputChar is uppercase or lowercase
*             The return value represents a boolean response without using a 'bool' data type
*             The letters a through z and A through Z represent "alphabet letters" for
*                 the purposes of this assignment.
*/
int is_it_alphabet(signed char inputChar)
{
	/* INSERT CODE HERE */
	
	if (inputChar >= 'A' && inputChar <= 'Z' || inputChar >= 'a' && inputChar <= 'z')
	{
		return 1;
	}

	return 0; // You may want to modify this return statement
}


/*
* FUNCTION:   int remove_non_letters(char * sentenceString);
*
* ARGUMENTS:  senteceString is expected to be a pointer to a null-terminated string
*
* RETURNS:	  Number of characters that were removed
*             -1 if senteceString is NULL
*
* NOTES:      The execution of this function must utilize is_it_alphabet() to determine
*                 whether or not a given char is an alphabet letter or not.
*             In addition to removing non-alphabet letters, this function will also remove any
*                 "blank space".
*             Most importantly, sentenceString will be null-terminated before the function returns
*/
int remove_non_letters(char * sentenceString)
{
	/* INSERT CODE HERE */
	char *p;
	int count = 0;
	int i;
	
	// Check for sentenceString to be NULL
	if (sentenceString == 0)
	{
		return -1;
	}

	// Point to the string
	p = sentenceString;

	// The most dangerous while loop ever written
	while (*p != '\0')
	{
		// Check for a non-alphabet character
		if (!(is_it_alphabet(*p)))
		{
			i = 0;

			// Scrunch the array			
			// The second most dangerous while loop ever written
			while (*(p + i + 1) != '\0')
			{
				*(p + i) = *(p + i + 1);
				i++;
			}		

			*(p + i) = '\0';

			count++;
		}
		else
			p++;
	}
	*p = '\0';
	
	return count; // You may want to modify this return statement
}


/*
* FUNCTION:   int reverse_string(char * inputString, char * outputBuff, int inputPosition);
*
* ARGUMENTS:  inputString is expected to be a pointer to a null-terminated string
*             outputBuff is expected to be a pointer to a char array which will store the reversed string from inputString
*             inputPosition is the element of inputString that reverse_string() should reverse
*
* RETURNS:	  Number of characters that were reversed
*             -1 if either inputString or outputBuff is NULL
*             -2 if inputPosition is unrealistic
*                 Examples:
*                     inputPosition is negative
*                     inputPosition is out of the array's scope
*
* NOTES:      This function is recursive and, skipping over input validation, follows this algorithm:
*                 1. Reverse inputString[inputPosition] into outputBuff[]
*                 2. Call reverse_string() to reverse the next inputString[] position
*                 3. Count and return the total number of characters that were reversed from inputString[]
*                        into outputBuff[]
*             outputBuff is treated as the same length as inputString.  If outputBuff is longer, it
*                 will still be treated the same length as inputString.  Ideally, outputBuff and inputString
*                 are the exact same length.
*             Most importantly, outputBuff will be null-terminated before the function returns
*/
int reverse_string(char * inputString, char * outputBuff, int inputPosition)
{
	/* INSERT CODE HERE */
	int count = 1, check = 0, len = 0;
	
	// Check if inputString or outputBuff is NULL
	if (inputString == 0 || outputBuff == 0 )
	{
		return -1;
	}

	// Get the strlen of inputstring for testing
	len = strlen(inputString);

	// Check for inputPosition is negative or exceeding inputString length, strlen equal zero, or 
	// if the string is size exactly 1 and the inputPosition is greater than that
	if (inputPosition < 0 || len == 0 || inputPosition > len || ((len == 1) && (inputPosition > 0)))
	{
		return -2;
	}
	
	// If the string is only 1 character, it is effectively reversed, just copy
	if (strlen(inputString) == 1)
	{
		outputBuff[0] = inputString[0];
		//outputBuff[strlen(inputString) - inputPosition] = inputString[inputPosition - 1];
		return count;
	}
	
	// Check to see if inputString[inputPosistion] is at the string terminator
	// End the recursion
	if (inputString[inputPosition] == '\0')
	{
		return 0;  // I dont' think we count the string terminator
	}
	
	
	// Move the inputPosition towards the end of inputString
	inputPosition++;	
	
	// Recursive
	check = reverse_string(inputString, outputBuff, inputPosition);	
	
	// Reverse inputString[inputPosition] into outputBuff[]
	outputBuff[strlen(inputString) - inputPosition] = inputString[inputPosition - 1];

	// Most importantly, outputBuff will be null-terminated before the function returns
	//outputBuff[strlen(inputString) + 1] = '\0';
	outputBuff[strlen(inputString) - inputPosition + 1] = '\0';

	// Allow error to be returned to the original calling function
	if (check < 0)
	{
		return check;
	}
	else		// Add the previous interation to this one
	{
		count += check;
	}

	// Count and return the total number of characters that were reversed
	return count; 
}


/*
* FUNCTION:   int clear_a_buffer(char * fullBuff, int buffSize);
*
* ARGUMENTS:  fullBuff is expected to be a pointer to a char array
*             buffSize represents the dimension of fullBuff[]
*
* RETURNS:	  0 on success
*             -1 if fullBuff is NULL
*             -2 if buffSize is unrealistic
*                 Examples:
*                     buffSize is zero
*                     buffSize is negative
*
* NOTES:      This function 'zeroizes' all of the elements of fullBuff[buffSize]
*             fullBuff does not necessarily need to be a null-terminated string since the array's
*                 dimension is passed in as an argument (for safety)
*/
int clear_a_buffer(char * fullBuff, int buffSize)
{
	/* INSERT CODE HERE */
	// Check if fullBuff is NULL
	if (fullBuff == 0)
	{
		return -1;
	}

	// Check if buffSize is zero or nagative
	if (buffSize <= 0)
	{
		return -2;
	}

	//  Zero-ize all of the elements of fullBuff[buffSize]
	memset(fullBuff, 0, sizeof(char) * buffSize);

	return 0; // You may want to modify this return statement
}
