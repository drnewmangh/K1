//
// This file implements the code to allow Roman number addition and subtraction
// The supported values are from I => MMMCMXLIX
//
// lower case i, v, x, l, c, d, m are not considered Roman numbers

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "RomanCalculator.h"

typedef struct
{
   char Symbol;
   int Value;
   bool CanBePrefix;
   int MaxInRow;
} stRomanInputInfo;

stRomanInputInfo RomanInputInfo[] =
{
   {'M', 1000, false, 3},
   {'D',  500, false, 1},
   {'C',  100, true,  3},
   {'L',   50, false, 1},
   {'X',   10, true,  3},
   {'V',    5, false, 1},
   {'I',    1, true,  3}
};
// convenience for number of array elements
#define MAX_ROMAN_NUMBER_INPUT_INFO (sizeof(RomanInputInfo) / sizeof(stRomanInputInfo))

// difference in array positions between a prefix character and
// the start of the possible values after the prefix
#define ROMAN_PREFIX_INDEX_DIFF 2

typedef struct
{
   char* Symbols;
   int Value;
} stRomanOutputInfo;

stRomanOutputInfo RomanOutputInfo[] =
{
   {"M", 1000},
   {"CM", 900},
   {"D",  500},
   {"CD", 400},
   {"C",  100},
   {"XC",  90},
   {"L",   50},
   {"XL",  40},
   {"X",   10},
   {"IX",   9},
   {"V",    5},
   {"IV",   4},
   {"I",    1}
};
// convenience for number of array elements
#define MAX_ROMAN_NUMBER_OUTPUT_INFO (sizeof(RomanOutputInfo) / sizeof(stRomanOutputInfo))

// converts a Roman number to an integer and returns the value
// if the input is invalid a zero is returned
//
int ConvertRomanToInteger(const char* RomanNumber)
{
   int Value = 0;
   int i = 0;
   int NumInRow = 0;
   int MinSymbolIdx = 0;
   int LastSymbolIdx = -1;
   int SymbolIdx;

   // don't allow NULL string input
   if (RomanNumber == NULL)
   {
      return 0;
   }

   for (i = 0; (i < MAX_ROMAN_NUMBER_LENGTH) && RomanNumber[i] != '\0'; i++)
   {
      char CurSymbol = RomanNumber[i];
      for (SymbolIdx = MinSymbolIdx; SymbolIdx < MAX_ROMAN_NUMBER_INPUT_INFO; SymbolIdx++)
      {
         if (RomanInputInfo[SymbolIdx].Symbol == CurSymbol)
         {
            if (SymbolIdx == LastSymbolIdx)
            {
               // repeating symbol

               NumInRow++;
               if (NumInRow > RomanInputInfo[SymbolIdx].MaxInRow)
               {
                  return 0;
               }
            }
            else
            {
               if (SymbolIdx < LastSymbolIdx)
               {
                  // large value found following prefix character
                  // allowable symbols must now be smaller than the prefix character
                  MinSymbolIdx += ROMAN_PREFIX_INDEX_DIFF + 1;

                  // subtract the prefix character
                  // since it was already added to sum
                  // twice its value must be subtracted
                  Value -= RomanInputInfo[LastSymbolIdx].Value * 2;
               }
               else
               {
                  // new smaller value found
                  MinSymbolIdx = SymbolIdx; 
                  if (RomanInputInfo[SymbolIdx].CanBePrefix)
                  {
                     // this may be a prefix character so allow larger values for the next iteration
                     MinSymbolIdx -= ROMAN_PREFIX_INDEX_DIFF;
                  }
               }
               NumInRow = 1;
            }
            Value += RomanInputInfo[SymbolIdx].Value;
            LastSymbolIdx = SymbolIdx;
            break;
         }
      }
      if (SymbolIdx == MAX_ROMAN_NUMBER_INPUT_INFO)
      {
         // symbol not found in list of current valid symbols
         return 0;
      }
   }

   return Value;
}

// converts an integer to a Roman number and returns the value
// if the input is invalid a NULL is returned
//
// the user is expected to free this memory when finished with it
//
char* ConvertIntegerToRoman(int Value)
{
   int i = 0;
   char buffer[MAX_ROMAN_NUMBER_LENGTH];
   char* ptr=&buffer[0];
   char* RomanNumber;
   *ptr = '\0';
   if ((Value < MIN_ROMAN_NUMBER_VALUE) || (Value > MAX_ROMAN_NUMBER_VALUE))
   {
      return NULL;
   }

   // determine the representation of the Roman number
   while (Value > 0)
   {
      while (Value >= RomanOutputInfo[i].Value)
      {
         strcat(ptr, RomanOutputInfo[i].Symbols);
         ptr += strlen(RomanOutputInfo[i].Symbols);
         Value -= RomanOutputInfo[i].Value;
      }
      i++;
   }

   // allocate minimum size buffer to return the Roman number
   RomanNumber = malloc(strlen(buffer) + 1);
   if (RomanNumber != NULL)
   {
      strcpy(RomanNumber, buffer);
   }
   return RomanNumber;
}

// Add two Roman numbers
// if the input is invalid a NULL is returned
//
// the user is expected to free this memory when finished with it
//
char* AddRomanNumbers(char* RomanNumber1, char* RomanNumber2)
{
   int Result = 0;
   int Value1 = ConvertRomanToInteger(RomanNumber1);
   if (Value1 != 0)
   {
      int Value2 = ConvertRomanToInteger(RomanNumber2);
      if (Value2 != 0)
      {
         Result = Value1 + Value2;
      }
   }
   return(ConvertIntegerToRoman(Result));
}

// Subtract the second Roman number from the first
// if the input is invalid a NULL is returned
//
// the user is expected to free this memory when finished with it
char* SubtractRomanNumbers(char* RomanNumber1, char* RomanNumber2)
{
   int Result = 0;
   int Value1 = ConvertRomanToInteger(RomanNumber1);
   if (Value1 != 0)
   {
      int Value2 = ConvertRomanToInteger(RomanNumber2);
      if (Value2 != 0)
      {
         Result = Value1 - Value2;
      }
   }
   return(ConvertIntegerToRoman(Result));
}

