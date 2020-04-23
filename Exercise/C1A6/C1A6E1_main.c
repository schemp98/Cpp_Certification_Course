//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 04 / 23 / 2020
// C1A6E1_main.c
// Win10
// Visual C++ 19.0
//
// This program prompts the user to enter a string and returns the length
// using strlen and MyStrlen
//

#include <stdio.h>
#include <string.h>
#include <string.h>

#define LINE_SIZE 128
#define LENGTH  (LINE_SIZE + 1)

size_t MyStrlen(const char *s1);

int main(void)
{
   char input[LENGTH];

   // get the users string
   printf("Enter a string: ");
   fgets(input, LENGTH, stdin);

   // remove newline character from string
   input[strcspn(input, "\n")] = '\0';

   // display results
   printf("strlen(\"%s\") returned %d\n", input, strlen(input));
   printf("MyStrlen(\"%s\") returned %d\n", input, MyStrlen(input));

   return 0;
}
