//
// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C / C++ Programming II : Dynamic Memory and File I / O Concepts
// 149123 Raymond L.Mitchell, Jr., M.S.
// 08 / 18 / 2020
// C2A7E1_main.c
// Win10
// Visual C++ 19.0
//
//This program will run at the command line with two space separated arguments
// first argument specifies a text file name, and the second specifies the
// how many bins should be used within a HashTable that contains strings within
// the file (bin # = string length % # of bins), within each bin a binary tree
// is used to organize the nodes so that they are ordered in alphabetical order
// according to the string it contains
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 256                // size of input buffer
#define BUFFMT "%255"               // field width for input buffer scan

void *SafeMalloc(size_t size)
{
   void *vp;

   if ((vp = malloc(size)) == NULL)
   {
      fputs("Out of memory\n", stderr);
      exit(EXIT_FAILURE);
   }
   return(vp);
}

FILE *OpenFile(const char *fileName)
{
   FILE *fp;

   if ((fp = fopen(fileName, "r")) == NULL)
   {
      fprintf(stderr, "File \"%s\" didn't open.\n", fileName);
      perror(fileName);
      exit(EXIT_FAILURE);
   }
   return fp;
}

#define MIN_ARGS 3                     // fewest command line arguments
#define FILE_ARG_IX 1                  // index of file name argument
#define BINS_ARG_IX 2                  // index of bin count argument

typedef struct Node NODE;
struct Node                            // type of each list node
{
   char *strng;                        // string for this node
   size_t count;                       // occurrences of this string
   NODE  *left, *right;                         // next node in list
};

typedef struct                         // type of table array elements
{
   size_t nodes;                       // # of list nodes for this bin
   NODE *root;                         // root node in this bin's list
} BIN;

typedef struct                         // type of hash table descriptor
{
   size_t bins;                        // bins in hash table
   BIN *firstBin;                      // first bin
} TABLE;

//
// BuildTree will search the binary tree at pNode for a node representing the
// string in str.  If found, its string count will be incremented.  If not
// found, a new node for that string will be created, put in alphabetical
// order, and its count set to 1.  A pointer to the node for string str is
// returned.
//
NODE *BuildTree(NODE *pNode, char *str, BIN *bp)
{
   if (pNode == NULL)                                    // string not found
   {
      size_t length = strlen(str) + 1;                   // length of string

      pNode = (NODE *)SafeMalloc(sizeof(NODE));          // allocate a node
      pNode->strng = (char *)SafeMalloc(length);
      memcpy(pNode->strng, str, length);                 // copy string
      pNode->count = 1;                                  // 1st occurrence
      pNode->left = pNode->right = NULL;                 // no subtrees
      ++bp->nodes;                                       // update bin node cnt
   }
   else
   {
      int result = strcmp(str, pNode->strng);            // compare strings

      if (result == 0)                                   // new str == current
         ++pNode->count;                                 // increment occurrence
      else if (result < 0)                               // new str < current
         pNode->left = BuildTree(pNode->left, str, bp);  // traverse left
      else                                               // new str > current
         pNode->right = BuildTree(pNode->right, str, bp);// traverse right
   }
   return(pNode);
}

// PrintTree recursively prints the binary tree in pNode alphabetically.
void PrintTree(const NODE *pNode)
{
   if (pNode != NULL)                                 // if child exists
   {
      PrintTree(pNode->left);                         // traverse left
      printf("%4d  %s\n", (int)pNode->count, pNode->strng);
      PrintTree(pNode->right);                        // traverse right
   }
}

// FreeTree recursively frees the binary tree in pNode.
void FreeTree(NODE *pNode)
{
   if (pNode != NULL)                                 // if child exists
   {
      FreeTree(pNode->left);                          // traverse left
      FreeTree(pNode->right);                         // traverse right
      free(pNode->strng);                             // free the string
      free(pNode);                                    // free the node
   }
}

int HashFunction(const char *key, size_t bins)  // get bin value from key
{
   return((int)(strlen(key) % bins));           // value = char count % bins
}

// CreateTable creates and initializes the hash table and its bins
TABLE *CreateTable(size_t bins)
{
   TABLE *hashTable;
   BIN  *end;

   hashTable = (TABLE *)SafeMalloc(sizeof(TABLE));          // alloc desc struct
   hashTable->bins = bins;                                  // how many bins
   // alloc bins
   hashTable->firstBin = (BIN *)SafeMalloc(bins * sizeof(BIN));
   end = hashTable->firstBin + bins;                        // end of bins

   for (BIN *bin = hashTable->firstBin; bin < end; ++bin)   // initialize bins
   {
      bin->nodes = 0;                                       // no list nodes
      bin->root = NULL;                                     // no list
   }
   return(hashTable);
}

//
// BuildList calls BuildTree, which ultimately orders all nodes within the bin
// that is passed to it, using the string that is also passed to it
//
void BuildList(BIN *bp, char *str)
{
   bp->root = BuildTree(bp->root, str, bp);
}

// PrintTable prints the hash table.
void PrintTable(const TABLE *hashTable)
{
   BIN  *end;

   end = hashTable->firstBin + hashTable->bins;             // end of bins
   for (BIN *bin = hashTable->firstBin; bin < end; ++bin)   // visit bins
   {
      printf("%d entries for bin %d:\n",
         (int)bin->nodes,
         (int)(bin - hashTable->firstBin));

      // Print all nodes in bin
      PrintTree(bin->root);
   }
}

// FreeTable frees the hash table.
void FreeTable(TABLE *hashTable)
{
   BIN *bin, *end;

   end = hashTable->firstBin + hashTable->bins;       // end of bins
   for (bin = hashTable->firstBin; bin < end; ++bin)  // visit bins
      FreeTree(bin->root);                            // free all nodes in bin

   free(hashTable->firstBin);                         // free all bins
   free(hashTable);                                   // free table descriptor
}

int main(int argc, char *argv[])
{
   char buf[LINE_LEN];                             // word string buffer
   char fileName[LINE_LEN];                        // file name buffer
   int howManyBins;                                // number of bins to create
   TABLE *hashTable;                               // pointer to hash table
   FILE *fp;

   // Read file name from command line.
   if (argc < MIN_ARGS || sscanf(argv[FILE_ARG_IX], BUFFMT "s", fileName) != 1)
   {
      fprintf(stderr, "No file name specified on command line\n");
      return EXIT_FAILURE;
   }
   fp = OpenFile(fileName);

   // Read bin count from command line.
   if (sscanf(argv[BINS_ARG_IX], "%d", &howManyBins) != 1)
   {
      fprintf(stderr, "No bin count specified on command line\n");
      return EXIT_FAILURE;
   }
   hashTable = CreateTable((size_t)howManyBins);   // allocate table array

   //
   // The following loop will read one string at a time from stdin until
   // EOF is reached.  For each string read the BuildList function will
   // be called to update the hash table.
   //
   while (fscanf(fp, BUFFMT "s", buf) != EOF)      // get string from file
   {
      // Find appropriate bin.
      BIN *bin = &hashTable->firstBin[HashFunction(buf, (size_t)howManyBins)];
      BuildList(bin, buf);                         // put string in list
   }
   fclose(fp);
   PrintTable(hashTable);                          // print all strings
   FreeTable(hashTable);                           // free the table
   return(EXIT_SUCCESS);
}
