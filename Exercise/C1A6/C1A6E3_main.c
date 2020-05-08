//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 08 / 2020
// C1A6E3_main.c
// Win10
// Visual C++ 19.0
//
// This program prompts the user to enter a string, then extracts characters
// identifed by the user via an index and character count
//

#include <stdio.h>
#include <string.h>

#define LENGTH  257

char *GetSubstring(const char source[], int start, int count, char result[]);

int main(void)
{
   char source[LENGTH], result[LENGTH];
   int start, count;

   // get the users strings
   printf("Enter a sequence of 0 or more arbitrary printable characters: ");
   fgets(source, LENGTH, stdin);

   printf("Enter a space-separated start index and character count: ");
   scanf("%d%d", &start, &count);

   // remove newline character from string
   source[strcspn(source, "\n")] = '\0';

   // display results
   printf(
      "\"%s\", %d, %d, extracts \"%s\"\n",
      source, start, count, GetSubstring(source, start, count, result));

   return 0;
}
