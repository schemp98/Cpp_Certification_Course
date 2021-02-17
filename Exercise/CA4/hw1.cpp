// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 152488 Raymond L. Mitchell III
// hw1.cpp
// Win10
// Visual C++ 19.0
//

#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
#include <exception>
#include <iterator>        // contains back_inserter
#include <numeric>         // contains accumulate
#include <sstream>          // contains ostringstream

using namespace std;

// class generators:
struct UniqueNumbers {
   int current;
   UniqueNumbers() { current = 0; }
   int operator()() { return ++current; }
} uniqueNumber;

struct LowerCharUnique {
   char current;
   LowerCharUnique() { current = 'a'; }
   char operator()() { return current++; }
} uniqueLowerLetter;

// Parser Function:
bool isEven(int i) { return (i % 2) == 0; }

// Unit Tests:
void testDeque()
{
   const size_t NUM_VALUES = 10;
   const int  VALID_VALUE = 55;
   deque<int> tempDeque;

   generate_n(back_inserter(tempDeque), NUM_VALUES, uniqueNumber);


   // 1b) add all values within the testDeque (initial value is 0)
   int testValue = accumulate(tempDeque.begin(), tempDeque.end(), 0);


  
   // 1c) Check if expected value is calculated
   if (testValue == VALID_VALUE)
      clog << "testDeque PASSED\n";
   else
      clog << "testDeque FAILED : Expected accumulation "
      << VALID_VALUE << " instead saw " << testValue << "\n";
}

void testString()
{
   const size_t NUM_VALUES = 26;
   string  tempString;
   const string VALID_VALUE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

   // 2a) populate tempString with lowercase letters ascending order
   generate_n(back_inserter(tempString), NUM_VALUES, uniqueLowerLetter);

   // 2b) use transform to convert string to uppercase
   transform(tempString.begin(), tempString.end(), tempString.begin(), toupper);

   // 2c) Check if expected value is calculated (if true output = 0)
   if (tempString.compare(VALID_VALUE) == 0)
      clog << "testString PASSED\n";
   else
      clog << "testString FAILED : Expected string "
      << VALID_VALUE << " instead saw " << tempString << "\n";
}

void testVector()
{
   vector<int>::iterator divider;
   const string VALID_VALUE = "24681013579";
   ostringstream tempOStream;
   std::ostream_iterator<int> out_it(tempOStream);

   //3a) create an array literal containing the values 10 to 1
   const int INIT_ARRAY[] = {10,9,8,7,6,5,4,3,2,1};

   //3b) initialize vector to initArray using iterator range constructor
   vector<int> tempVector(INIT_ARRAY, INIT_ARRAY + sizeof(INIT_ARRAY) / sizeof(int));

   //3c) rearrange values to place even numbers in lower half of vector
   divider = partition(tempVector.begin(), tempVector.end(), isEven);

   //3d) sort on each partition
   // sort even partition
   sort(tempVector.begin(), divider);
   // sort odd partition
   sort(divider, tempVector.end());

   // 3e) Copy vector to an ostring_stream
   copy(tempVector.begin(), tempVector.end(), out_it);

   // 3f) Verify ostring_stream contents
   if (tempOStream.str().compare(VALID_VALUE) == 0)
      clog << "testVector PASSED\n";
   else
      clog << "testVector FAILED : Expected output "
      << VALID_VALUE << " instead saw " << tempOStream.str() << "\n";
}

int main(void)
{
   //unit test demonstrating deque & algorithm functionality
   testDeque();

   //unit test demonstrating string & algorithm functionality
   testString();

   // unit test demonstrating vector & algorithm functionality
   testVector();
}
