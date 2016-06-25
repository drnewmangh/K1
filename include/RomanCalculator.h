#ifndef _ROMANCALCULATOR_H_
#define _ROMANCALCULATOR_H_

// maximum length of a roman number including terminating NULL
#define MAX_ROMAN_NUMBER_LENGTH 16

#define MIN_ROMAN_NUMBER_VALUE 1
#define MAX_ROMAN_NUMBER_VALUE 3999

// converts a Roman number to an integer and returns the value
// if the input is invalid a zero is returned
int ConvertRomanToInteger(const char* RomanNumber);

// converts an integer to a Roman number and returns the value
// if the input is invalid a NULL is returned
//
// the user is expected to free this memory when finished with it
char* ConvertIntegerToRoman(int Value);

// Add two Roman numbers
// if the input is invalid a NULL is returned
//
// the user is expected to free this memory when finished with it
char* AddRomanNumbers(char* RomanNumber1, char* RomanNumber2);

// Subtract the second Roman number from the first
// if the input is invalid a NULL is returned
//
// the user is expected to free this memory when finished with it
char* SubtractRomanNumbers(char* RomanNumber1, char* RomanNumber2);

#endif
