#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include <ctype.h>

#include "ValidRomanTestData.h"

START_TEST(TestValidConvertRomanToInteger)
{
   int i;
   int res;

   for (i = 0; i < NUM_VALID_ROMAN_NUMBERS; i++)
   {
      res = ConvertRomanToInteger(ValidRomanTestData[i].RomanNumber);
      ck_assert_int_eq(res, ValidRomanTestData[i].Value);
   }
}
END_TEST

char* strlwr(char* buffer)
{
   int i;
   int len = strlen(buffer);
   for (i = 0; i < len; i++)
   {
      buffer[i] = tolower(buffer[i]);
   }
   return buffer;
}

START_TEST(TestValidConvertLowerCaseRomanToInteger)
{
   int i;
   int res;
   char buffer[MAX_ROMAN_NUMBER_LENGTH];

   for (i = 0; i < NUM_VALID_ROMAN_NUMBERS; i++)
   {
      strcpy(buffer, ValidRomanTestData[i].RomanNumber);

      strlwr(buffer);
      res = ConvertRomanToInteger(buffer);
      ck_assert_int_eq(res, 0);
   }
}
END_TEST

START_TEST(TestValidConvertIntegerToRoman)
{
   int i;
   char *s;
   for (i = 0; i < NUM_VALID_ROMAN_NUMBERS; i++)
   {
      s = ConvertIntegerToRoman(ValidRomanTestData[i].Value);
      ck_assert_str_eq(s, ValidRomanTestData[i].RomanNumber);
      free(s);
   }
   
}
END_TEST

START_TEST(TestInvalidConvertRomanToInteger)
{
   int res;

   res = ConvertRomanToInteger(NULL);
   ck_assert_int_eq(res, 0);
   res = ConvertRomanToInteger("");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("IIII");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("VV");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("XXXX");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("LL");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("CCCC");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("DD");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("MMMM");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("IVIV");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("IXIX");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("XLXL");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("XCXC");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("CDCD");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("CMCM");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("IM");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("ID");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("IC");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("IL");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("VM");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("VD");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("VC");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("VL");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("VX");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("XM");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("XD");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("LM");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("LD");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("LC");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("DM");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("AI");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("IA");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("AD");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("DA");
   ck_assert_int_eq(res, 0);

   res = ConvertRomanToInteger("MMMDCCCLXXXVIIII");
   ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(TestInvalidConvertIntegerToRoman)
{
   char* s;

   s = ConvertIntegerToRoman(-1);
   ck_assert(s == NULL);

   s = ConvertIntegerToRoman(0);
   ck_assert(s == NULL);

   s = ConvertIntegerToRoman(MAX_ROMAN_NUMBER_VALUE + 1);
   ck_assert(s == NULL);
}
END_TEST

START_TEST(TestValidRomanAdd)
{
   char* s;

   s = AddRomanNumbers("I", "I");
   ck_assert_str_eq(s, "II");
   free(s);

   s = AddRomanNumbers("IV", "I");
   ck_assert_str_eq(s, "V");
   free(s);

   s = AddRomanNumbers("V", "I");
   ck_assert_str_eq(s, "VI");
   free(s);

   s = AddRomanNumbers("VIII", "I");
   ck_assert_str_eq(s, "IX");
   free(s);

   s = AddRomanNumbers("IX", "I");
   ck_assert_str_eq(s, "X");
   free(s);

   s = AddRomanNumbers("X", "I");
   ck_assert_str_eq(s, "XI");
   free(s);

   s = AddRomanNumbers("XIII", "I");
   ck_assert_str_eq(s, "XIV");
   free(s);

   s = AddRomanNumbers("XL", "I");
   ck_assert_str_eq(s, "XLI");
   free(s);

   s = AddRomanNumbers("XLIX", "I");
   ck_assert_str_eq(s, "L");
   free(s);

   s = AddRomanNumbers("L", "I");
   ck_assert_str_eq(s, "LI");
   free(s);

   s = AddRomanNumbers("XC", "I");
   ck_assert_str_eq(s, "XCI");
   free(s);

   s = AddRomanNumbers("XCIX", "I");
   ck_assert_str_eq(s, "C");
   free(s);

   s = AddRomanNumbers("C", "I");
   ck_assert_str_eq(s, "CI");
   free(s);

   s = AddRomanNumbers("CD", "C");
   ck_assert_str_eq(s, "D");
   free(s);

   s = AddRomanNumbers("CDIX", "I");
   ck_assert_str_eq(s, "CDX");
   free(s);

   s = AddRomanNumbers("CD", "I");
   ck_assert_str_eq(s, "CDI");
   free(s);

   s = AddRomanNumbers("CDXCIX", "I");
   ck_assert_str_eq(s, "D");
   free(s);

   s = AddRomanNumbers("D", "I");
   ck_assert_str_eq(s, "DI");
   free(s);

   s = AddRomanNumbers("DCCCXCIX", "I");
   ck_assert_str_eq(s, "CM");
   free(s);

   s = AddRomanNumbers("MMMCMXLVIII", "I");
   ck_assert_str_eq(s, "MMMCMXLIX");
   free(s);
}
END_TEST

START_TEST(TestValidRomanSubtract)
{
   char* s;

   s = SubtractRomanNumbers("II", "I");
   ck_assert_str_eq(s, "I");
   free(s);

   s = SubtractRomanNumbers("V", "I");
   ck_assert_str_eq(s, "IV");
   free(s);

   s = SubtractRomanNumbers("VI", "I");
   ck_assert_str_eq(s, "V");
   free(s);

   s = SubtractRomanNumbers("IX", "I");
   ck_assert_str_eq(s, "VIII");
   free(s);

   s = SubtractRomanNumbers("X", "I");
   ck_assert_str_eq(s, "IX");
   free(s);

   s = SubtractRomanNumbers("XI", "I");
   ck_assert_str_eq(s, "X");
   free(s);

   s = SubtractRomanNumbers("XIV", "I");
   ck_assert_str_eq(s, "XIII");
   free(s);

   s = SubtractRomanNumbers("XLI", "I");
   ck_assert_str_eq(s, "XL");
   free(s);

   s = SubtractRomanNumbers("L", "I");
   ck_assert_str_eq(s, "XLIX");
   free(s);

   s = SubtractRomanNumbers("LI", "I");
   ck_assert_str_eq(s, "L");
   free(s);

   s = SubtractRomanNumbers("XCI", "I");
   ck_assert_str_eq(s, "XC");
   free(s);

   s = SubtractRomanNumbers("C", "I");
   ck_assert_str_eq(s, "XCIX");
   free(s);

   s = SubtractRomanNumbers("CI", "I");
   ck_assert_str_eq(s, "C");
   free(s);

   s = SubtractRomanNumbers("D", "C");
   ck_assert_str_eq(s, "CD");
   free(s);

   s = SubtractRomanNumbers("CDX", "I");
   ck_assert_str_eq(s, "CDIX");
   free(s);

   s = SubtractRomanNumbers("CDI", "I");
   ck_assert_str_eq(s, "CD");
   free(s);

   s = SubtractRomanNumbers("D", "I");
   ck_assert_str_eq(s, "CDXCIX");
   free(s);

   s = SubtractRomanNumbers("DI", "I");
   ck_assert_str_eq(s, "D");
   free(s);

   s = SubtractRomanNumbers("CM", "I");
   ck_assert_str_eq(s, "DCCCXCIX");
   free(s);

   s = SubtractRomanNumbers("MMMCMXLIX", "I");
   ck_assert_str_eq(s, "MMMCMXLVIII");
   free(s);
}
END_TEST

START_TEST(TestInvalidRomanAdd);
{
   char* s;

   s = AddRomanNumbers("MM", "MM");
   ck_assert(s == NULL);

   s = AddRomanNumbers("MMI", "MM");
   ck_assert(s == NULL);

   s = AddRomanNumbers("A", "MM");
   ck_assert(s == NULL);

   s = AddRomanNumbers("MM", "A");
   ck_assert(s == NULL);


}
END_TEST

START_TEST(TestInvalidRomanSubtract);
{
   char* s;

   s = SubtractRomanNumbers("III", "IV");
   ck_assert(s == NULL);

   s = SubtractRomanNumbers("MM", "MM");
   ck_assert(s == NULL);

   s = SubtractRomanNumbers("A", "MM");
   ck_assert(s == NULL);

   s = SubtractRomanNumbers("MM", "A");
   ck_assert(s == NULL);

   s = SubtractRomanNumbers("XCIV", "C");
   ck_assert(s == NULL);


}
END_TEST


Suite* roman_calculator_suite(void)
{
   Suite *s;
   TCase *tc_core;

   s = suite_create("RomanCalculator");

   /* Core test case */
   tc_core = tcase_create("Core");

   tcase_add_test(tc_core, TestValidConvertRomanToInteger);
   tcase_add_test(tc_core, TestValidConvertIntegerToRoman);
   tcase_add_test(tc_core, TestValidConvertLowerCaseRomanToInteger);
   tcase_add_test(tc_core, TestInvalidConvertRomanToInteger);
   tcase_add_test(tc_core, TestInvalidConvertIntegerToRoman);
   tcase_add_test(tc_core, TestValidRomanAdd);
   tcase_add_test(tc_core, TestValidRomanSubtract);
   tcase_add_test(tc_core, TestInvalidRomanAdd);
   tcase_add_test(tc_core, TestInvalidRomanSubtract);
   suite_add_tcase(s, tc_core);

   return s;
}

int main(void)
{
   int number_failed;
   Suite *s;
   SRunner *sr;

   s = roman_calculator_suite();
   sr = srunner_create(s);

   srunner_run_all(sr, CK_NORMAL);
   number_failed = srunner_ntests_failed(sr);
   srunner_free(sr);
   return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
