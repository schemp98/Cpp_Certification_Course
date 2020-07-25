//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 07 / 23 / 2020
// C2A3E3_RecordOpinions.c
// Win10
// Visual C++ 19.0
//
// File contains RecordOpinions function, which prompts users for ratings of
// a product and summarizes the total quantity of each rating in a table
//

#define ENDPOINT 10
#define TERMINATE 15
#define TOTAL_RATINGS (2 * ENDPOINT + 1)

#include <stdio.h>

void RecordOpinions(void)
{
   int userResp = 0;
   // Initial Array to hold user rating
   // (rawArray[0] refers to rating of -ENDPOINT)
   int rawArray[TOTAL_RATINGS] = {0};
   // Pointer to access rawArray in by merely using user rating as an index
   // (ratingCounters[0] refers to rating of 0)
   int *ratingCounters = &rawArray[ENDPOINT];

   // prompt user for valid rating until 'TERMINATE' value is entered
   while (userResp != TERMINATE)
   {
      // get user rating
      printf("Enter your rating: (valid range -%d to %d, to end enter %d): ",
         ENDPOINT, ENDPOINT, TERMINATE);
      scanf("%d", &userResp);

      // increment count at response table index
      if (userResp >= -ENDPOINT && userResp <= ENDPOINT)
         ratingCounters[userResp]++;
      // Invalid Entry, prompt for new rating
      else if (userResp != TERMINATE)
         printf("Rating out of range, Try again!\n");
   }

   // Display table summary of ratings
   printf(
      "Rating  Responses\n"
      "------  ----------\n");
   for (int rating = -ENDPOINT; rating <= ENDPOINT; rating++)
      printf("%5d    %4d\n", rating, ratingCounters[rating]);
}
