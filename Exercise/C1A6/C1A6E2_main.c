//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 08 / 2020
// C1A6E2_main.c
// Win10
// Visual C++ 19.0
//
// This program prompts the user to enter 2 strings and compare them
// using strcmp and MyStrcmp
//

#include <stdio.h>
#include <string.h>

#define LENGTH  129

int MyStrcmp(const char *s1, const char *s2);

int main(void)
{
   char input1[LENGTH], input2[LENGTH];

   // get the users strings
   printf("Enter first string: ");
   fgets(input1, LENGTH, stdin);

   printf("Enter second string: ");
   fgets(input2, LENGTH, stdin);

   // remove newline character from strings
   input1[strcspn(input1, "\n")] = '\0';
   input2[strcspn(input2, "\n")] = '\0';

   // display results
   printf(
      "strcmp(\"%s\",\"%s\") returned %d\n",
      input1, input2, strcmp(input1, input2));
   printf(
      "MyStrcmp(\"%s\",\"%s\") returned %d\n",
      input1, input2, MyStrcmp(input1, input2));

   return 0;
}
