//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 08 / 2020
// C1A7E2_main.c
// Win10
// Visual C++ 19.0
//
// This program prompts the user to enter nutritional information for
// LUNCH_QTY number of food items contained in a 'lunch' Food structure array
// 2 items within this structure array have been initialized
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNCH_QTY 5
#define STR_LENGTH 129
#define PRE_INIT_STRUCT 2

int main(void)
{
   struct Food
   {
      char *name;           /* "name" attribute of food */
      int weight, calories; /* "weight" and "calories" attributes of food */
   }lunches[LUNCH_QTY] = {{"apple", 4, 100}, {"salad", 2, 80}};

   // Populate uninitialized structure array elements
   for (int lunchCnt = PRE_INIT_STRUCT; lunchCnt < LUNCH_QTY; lunchCnt++)
   {
      char buffer[STR_LENGTH];

      // get the users strings
      printf("Enter the whitespace separated name, weight, and calories: ");
      scanf("%128s%d%d",
         buffer,
         &lunches[lunchCnt].weight,
         &lunches[lunchCnt].calories);

      //  find number of characters input by user
      size_t buffSize = strlen(buffer);

      // increment buffsize to account for null character
      buffSize++;

      // Allocate memory to place name within structure element
      if ((lunches[lunchCnt].name = (char *)malloc(buffSize)) == NULL)
      {
         fputs("Not enough memory for name\n", stderr);
         exit(EXIT_FAILURE);
      }
      memcpy(lunches[lunchCnt].name, buffer, buffSize);
   }

   // Display Results
   for (int lunchCnt = 0; lunchCnt < LUNCH_QTY; lunchCnt++)
   {
      printf("%-15s %5d %5d\n",
         lunches[lunchCnt].name,
         lunches[lunchCnt].weight,
         lunches[lunchCnt].calories);
   }

   // free dynamically allocated memory
   for (int lunchCnt = PRE_INIT_STRUCT; lunchCnt < LUNCH_QTY; lunchCnt++)
   {
      free(lunches[lunchCnt].name);
   }

   return 0;
}
