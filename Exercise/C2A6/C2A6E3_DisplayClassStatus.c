//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 14 / 2020
// C2A6E3_DisplayClassStatus.c
// Win10
// Visual C++ 19.0
//
// File contains Compare, SortStudents, and DisplayClassStatus functions,
//  Compare is custom version of the strcmp function that can easily used
//       with qsort and bsearch
//  SortStudents sorts an array of pointers to chars using qsort & Compare
//  DisplayClassStatus sorts an array of pointers to chars using qsort & Compare
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Compare(const void *elemA, const void *elemB)
{
   // Custom version of strcmp to use with qsort and bsearch functions
   return(strcmp(*(char **)elemA, *(char **)elemB));
}

void SortStudents(const char *studentList[], size_t studentCount)
{
   qsort(studentList, studentCount, sizeof(studentList[0]), Compare);
}

void DisplayClassStatus(const char *registrants[], size_t registrantCount,
   const char *attendees[], size_t attendeeCount)
{
   // Determine which registrants did not attend
   printf("Not present:\n");
   for (int name = 0; name < (int)registrantCount; name++)
   {
      // check if registered name attended, if not found (NULL), display name
      if (bsearch(&registrants[name],
         attendees, attendeeCount,
         sizeof(attendees[0]), Compare) == NULL)
         printf("%s\n", registrants[name]);
   }

   // Determine which attendees did not register
   printf("Not registered:\n");
   for (int name = 0; name < (int)attendeeCount; name++)
      // check if attendee name registered, if not found (NULL), display name
      if (bsearch(&attendees[name],
         registrants, registrantCount,
         sizeof(registrants[0]), Compare) == NULL)
         printf("%s\n", attendees[name]);
}
