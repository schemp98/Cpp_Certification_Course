//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 14 / 2020
// C2A6E4_List.c
// Win10
// Visual C++ 19.0
//
// File contains CreateList, PrintList, and FreeList functions, respectively
//  1) creates a Singly Linked List that stores and tracks strings in a file
//  2) Prints the strings and count stored in the list
//  3) Frees memory allocated during list creation
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "C2A6E4_List-Driver.h"

#define BUFSIZE 256
List *CreateList(FILE *fp)
{
   char buf[BUFSIZE];
   List *head = NULL;

   // place current line into buf
   while (fgets(buf, (int)sizeof(buf), fp))
   {
      // search for delimiters
      for (char *word = buf; word = strtok(word, " \t\n"); word = NULL)
      {
         List *ptr;

         //  Check every node in list
         for (ptr = head; ptr != NULL; ptr = ptr->next)
         {
            //check to see if this string has been encountered
            if (strcmp(word, ptr->str) == 0)
            {
               ptr->count++;
               break;
            }
         }

         // This is a new string
         if (ptr == NULL)
         {
            size_t strSize = strlen(word) + (size_t)1;

            // Allocate memory for new node
            if ((ptr = malloc(sizeof(List))) == NULL)
            {
               fputs("Not enough memory for new Node\n", stderr);
               exit(EXIT_FAILURE);
            }

            // Allocate memory for string
            if ((ptr->str = malloc(strSize)) == NULL)
            {
               fputs("Not enough memory for new Node string\n", stderr);
               exit(EXIT_FAILURE);
            }
            // Set values of node
            memcpy(ptr->str, word, strSize);
            ptr->count = 1;

            // push new node onto list
            ptr->next = head;
            head = ptr;
         }
      }
   }

   return(head);
}

List *PrintList(const List *head)
{
   // Traverse List and display the string and count
   for (List *p = (List *)head; p != NULL; p = p->next)
      printf("%-15s %5d ea\n", p->str, p->count);

   return((List *)head);
}

void FreeList(List *head)
{
   for (List *p = head; p != NULL;)
   {
      // Retain pointer to "current" node
      List *ptr = p;
      //Set current node to next node, to avoid memory leak
      p = p->next;
      // First delete memory allocated to string
      free(ptr->str);
      // Finally delete memory allocated to node
      free(ptr);
   }
}
