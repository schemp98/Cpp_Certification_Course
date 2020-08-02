//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming I : Fundamental Programming Concepts
// 146359 Raymond L. Mitchell Jr.
// 05 / 01 / 2020
// C1A5E1_main.c
// Win10
// Visual C++ 19.0
//
// This file will implement a survey to customers to indicate how much they
// enjoy a product, and then display results of all participants
//

#include <stdio.h>

#define MAX_RESPONDENTS      3
#define MIN_RESPONSE_VALUE  (-3)
#define MAX_RESPONSE_VALUE  (-3)
#define OUT_OF_RANGE_LIMIT   3
#define RESPONSE_VALUES (1 + MAX_RESPONSE_VALUE + -MIN_RESPONSE_VALUE)

int main(void)
{
   int consecutiveRangeErrors = 0, ratingDisp = MAX_RESPONSE_VALUE;
   int ratingCounters[RESPONSE_VALUES] = {0};

   // Request and Store User Input
   for (int numResponses = 0; numResponses < MAX_RESPONDENTS;)
   {
      int rating;

      // get user rating
      printf("Enter your rating: ");
      scanf("%d", &rating);

      // check rating validity... if invalid, prompt new response a maximum
      // of OUT_OF_RANGE_LIMIT times
      if (rating >= MIN_RESPONSE_VALUE && rating <= MAX_RESPONSE_VALUE)
      {
         consecutiveRangeErrors = 0;
         ++ratingCounters[MAX_RESPONSE_VALUE - rating];
         ++numResponses;
      }
      else // Invalid response
      {
         ++consecutiveRangeErrors;

         if (consecutiveRangeErrors < OUT_OF_RANGE_LIMIT)
         {
            printf("Rating out of range, Try again!\n");
            continue;
         }
         else
         {
            printf("Reached MAX Out of Range entries, ending survey\n");
            break;
         }
      }
   }

   // Display summary of ratings
   printf(
      "Rating  Responses\n"
      "------  ----------\n");
   for (int rating = 0; rating < RESPONSE_VALUES; rating++)
   {
      printf("%5d    %4d\n", ratingDisp, ratingCounters[rating]);
      --ratingDisp;
   }

   return 0;
}
