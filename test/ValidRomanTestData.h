#ifndef _VALIDROMANTESTDATA_H
#define _VALIDROMANTESTDATA_H

#include "RomanCalculator.h"

typedef struct
{
   int Value;
   char* RomanNumber;
} stRomanTestData;

#define NUM_VALID_ROMAN_NUMBERS (MAX_ROMAN_NUMBER_VALUE - MIN_ROMAN_NUMBER_VALUE + 1)
extern stRomanTestData ValidRomanTestData[NUM_VALID_ROMAN_NUMBERS];

#endif

