// Shaun Chemplavil U08713628
// shaun.chemplavil@gmail.com
// C/C++ Programming IV : Advanced Programming with Objects
// 152488 Raymond L. Mitchell III
// BingInt.cpp
// Win10
// Visual C++ 19.0
//
// The algorithms from this class were documented in
// 'Art of Computer Programming: Volume II' by Donald Knuth, these focused
// on non-negative numbers, so state machine logic was implemented
// to handle negative numbers

#include "BigInt.h"
#include <string>
#include <sstream>
#include <exception>
#include <algorithm>

const string negativeSign = "-", positiveSign = "+", ZeroStr = "0";
//Default Constructor
namespace Project1
{
   // Helper functions to aid with math operations
   // To aid with math functions, we need to hold values in separate
   // elements of an int vector
   vector<int> stringToIntVector(const string input)
   {
      vector<int> out;
      string tempString = input, character;

      for (string::iterator it = tempString.begin(); it != tempString.end(); ++it)
      {
         character = *it;
         // Handling of negative BigInt!
         if ((character.compare(negativeSign) == 0) && (it == tempString.begin()) && (tempString.size() > 1))
         {
            ++it;
            character = negativeSign + *it;
            out.push_back(stoi(character));
         }
         else
            out.push_back(stoi(character));
      }

      return out;
   }

   // Another way that helps simplify the math operations, we will
   // force the int vectors to be the same size (while retaining the
   // original BigInt decimal value
   vector<int> ZeroPadVector(vector<int> input, size_t desiredSize)
   {
      vector<int> out(desiredSize - input.size(), 0);
      out.insert(out.end(), input.begin(), input.end());
      return out;
   }

   // After Math functions are completed we need to place the int vector
   // elements into a string, this also helps prevents placing
   // non-int values into string
   string IntVectorToString(vector<int> input)
   {
      ostringstream out;
      copy(input.begin(), input.end(), ostream_iterator<int>(out));

      return out.str();
   }

   // BigInt Friend Functions
   ostream &operator<<(ostream &out, const BigInt &value)
   {
      out << value.bigDigitsString;
      return out;
   }

   istream &operator>>(istream &in, BigInt &value)
   {
      string tempString;
      in >> tempString;
      value.setbigDigitsString(tempString);
      return in;
   }

   const BigInt operator+(const BigInt &op1, const BigInt &op2)
   {
      BigInt out(op1);
      out += op2;
      return out;
   }

   const BigInt operator-(const BigInt &op1, const BigInt &op2)
   {
      BigInt out(op1);
      out -= op2;
      return out;
   }

   // BigInt Class Definitions
   // Default Constructor
   BigInt::BigInt() : bigDigitsString(ZeroStr), bigDigitsVector(0)
   {}

   BigInt::BigInt(const BigInt &input) : bigDigitsString(input.bigDigitsString), bigDigitsVector(input.bigDigitsVector)
   {}

   BigInt::BigInt(long long input)
   {
      string inputString = to_string(input);
      this->setbigDigitsString(inputString);
   }

   BigInt::BigInt(const string &input)
   {
      this->setbigDigitsString(input);
   }

   // Member functions

   // Private member function to set private variables
   void BigInt::setbigDigitsString(string input)
   {
      if (input.empty())
         throw invalid_argument("Empty string input to BigInt");

      string tempStr(input);
      string::iterator it = tempStr.begin();
      string character; character = *it;
      // See if a numeric 'sign' is in string
      // Retain Negative Sign in String
      if (character.compare(negativeSign) == 0)
         ++it;
      // Remove Superfluous Positive Sign in String
      else if (character.compare(positiveSign) == 0)
         tempStr.erase(0, 1);

      // Check if non-digits are in string
      if (!(!tempStr.empty() && all_of(it, tempStr.end(), isdigit)))
         throw invalid_argument("Invalid string input to BigInt");

      // Error if leading zeros
      if ((character.compare(ZeroStr) == 0) && (tempStr.size() > 1))
         throw invalid_argument("Invalid Input! Too many leading zeros!");

      // Set to Int Vector first to remove a potential -0 term
      bigDigitsVector = stringToIntVector(tempStr);
      bigDigitsString = IntVectorToString(bigDigitsVector);
   }

   // Private member function to set private variables
   void BigInt::setbigDigitsVector(vector<int> input)
   {
      string tempString = IntVectorToString(input);
      this->setbigDigitsString(tempString);
   }

   // Private member function to "Negate" the BigInt value
   // This aids with Math Operations
   void BigInt::negate()
   {
      // if greater than 0 add a negative sign to string
      if (bigDigitsVector[0] > 0)
         bigDigitsString.insert(0, 1, '-');
      // if less than 0 remove negative sign from string
      else
         bigDigitsString.erase(0, 1);

      bigDigitsVector[0] *= -1;
   }

   const BigInt &BigInt::operator+=(const BigInt &input)
   {
      // For easier implementation need temp variables to ensure that
      // vector/string sizes are the same...
      BigInt op1Temp(*this), op2Temp(input);

      // Because original algorithms were for non-negative numbers,
       // check to see how we can "rephrase" the addition/subtraction
       // friend operators to accommodate negative BigInts
      bool op1Neg = op1Temp.bigDigitsVector[0] < 0,
         op2Neg = op2Temp.bigDigitsVector[0] < 0, negateOutput{false};

      // If signs of entries are different, leverage 'subtraction' algorithms
      if (!op1Neg && op2Neg) // subtraction
      {
         op2Temp.negate();
         *this -= op2Temp;
      }
      else if (op1Neg && !op2Neg)// The alternative subtraction
      {
         op1Temp.negate();
         op2Temp -= op1Temp;
         *this = op2Temp;
      }
      else // signs are the same, addition algorithm should be used
      {
         vector<int>  left, right;
         int sum(0), carry(0), base(0), radix(10);

         if (op1Neg && op2Neg) // if both BigInts are negative do addition but change sign of input/output
         {
            op1Temp.negate(); op2Temp.negate();
            negateOutput = !negateOutput;
         }

         // We need to force the our inputs to be the same vector length to
         // aid with algorithm implementation
         if (op1Temp > op2Temp)
         {
            left = op1Temp.bigDigitsVector;
            right = ZeroPadVector(op2Temp.bigDigitsVector, left.size());
         }
         else if (op1Temp < op2Temp)
         {
            right = op2Temp.bigDigitsVector;
            left = ZeroPadVector(op1Temp.bigDigitsVector, right.size());
         }
         else
         {
            left = op1Temp.bigDigitsVector;
            right = op2Temp.bigDigitsVector;
         }

         // Initialize an appropriately sized int vector to hold the result of
         // algorithm
         vector<int> tempOut(left.size(), 0);

         //
         vector<int>::reverse_iterator itR = right.rbegin(), itO = tempOut.rbegin(), itL = left.rbegin();
         for (; itL != left.rend(); ++itL)
         {
            // add the ints (and carry value) at this place in vector
            sum = *itL + *itR + carry;

            // The int that is placed needs to be between 0 and 9
            base = sum % radix;

            // See if we "Carry the One" to next element
            carry = sum / radix;
            *itO = base;
            ++itR; ++itO;
         }

         // if necessary add additional element to hold 'carry' value
         if (carry != 0)
            tempOut.emplace(tempOut.begin(), carry);

         this->setbigDigitsVector(tempOut);

         // If we were initially adding negative numbers negate Output!
         if (negateOutput)
            this->negate();
      }

      return *this;
   }

   const BigInt &BigInt::operator-=(const BigInt &input)
   {
      // Because original algorithms were for non-negative numbers,
            // check to see how we can "rephrase" the addition/subtraction
            // friend operators to accommodate negative BigInts
      bool op1Neg = this->bigDigitsVector[0] < 0,
         op2Neg = input.bigDigitsVector[0] < 0, negateOutput{false};

      BigInt op1Temp(*this), op2Temp(input);

      // This is actually addition
      if (!op1Neg && op2Neg)
      {
         op2Temp.negate();
         *this += op2Temp;
      }
      // This is actually addition with negative values (negate input/output)
      else if (op1Neg && !op2Neg)
      {
         op1Temp.negate();
         op1Temp += op2Temp;
         *this = op1Temp;
         negateOutput = !negateOutput;
      }
      else // Implement Subtraction Algorithm
      {
         int sum(0), carry(0), base(0), radix(10);

         // For the original algorithm we assume that both values are positive
         // and the "left" variable is larger than the "right" variable
         // we will force the this to be the case when implementing the algorithm

         if (op1Neg && op2Neg)
         {
            op1Temp.negate(); op2Temp.negate();
            negateOutput = !negateOutput;
         }
         vector<int>  left, right;

         if (op1Temp > op2Temp)
         {
            left = op1Temp.bigDigitsVector;
            right = ZeroPadVector(op2Temp.bigDigitsVector, left.size());
         }
         else if (op1Temp < op2Temp)
         {
            left = op2Temp.bigDigitsVector;
            right = ZeroPadVector(op1Temp.bigDigitsVector, left.size());
            negateOutput = !negateOutput;
         }
         else
         {
            left = op1Temp.bigDigitsVector;
            right = op2Temp.bigDigitsVector;
         }

         vector<int> tempOut(left.size(), 0);
         vector<int>::reverse_iterator itR = right.rbegin(), itOr = tempOut.rbegin();
         for (vector<int>::reverse_iterator itL = left.rbegin(); itL != left.rend(); ++itL)
         {
            // subtract the ints (and carry value) at this place in vector
            sum = *itL - *itR + carry;
            base = sum % radix;

            // if the sum was less than zero, we might "borrow from the 0"
            if (sum < 0)
               sum = -radix;

            // be sure we do not place a negative value in digit
            if (base < 0)
               base += radix;

            // determines if we need to "borrow from the 0"
            carry = sum / radix;
            *itOr = base;
            ++itR; ++itOr;
         }

         // we need to remove leading zeros for valid input
         string tempStr = IntVectorToString(tempOut);
         tempStr.erase(0, min(tempStr.find_first_not_of('0'), tempStr.size() - 1));

         this->setbigDigitsString(tempStr);
      }
      if (negateOutput)
         this->negate();
      return *this;
   }
   const BigInt &BigInt::operator=(const BigInt &input)
   {
      if (this != &input) // not a self-assignment
         this->setbigDigitsString(input.bigDigitsString);

      return *this;
   }

   bool operator==(const BigInt &op1, const BigInt &op2)
   {
      // check if vector sizes are same, then check if vectors are the same
      return ((op1.bigDigitsVector.size() == op2.bigDigitsVector.size()) && (op1.bigDigitsVector == op2.bigDigitsVector));
   }

   bool operator!=(const BigInt &op1, const BigInt &op2)
   {
      return !(op1 == op2);
   }

   bool operator<(const BigInt &op1, const BigInt &op2)
   {
      //first check if signs of operators are the same
      bool op1Neg = op1.bigDigitsVector[0] < 0,
         op2Neg = op2.bigDigitsVector[0] < 0, out{false};

      // if signs are different, if op1Neg is true, we know that op2Neg is false,
      // (and vice versa) thus, we return we can op1Neg
      if (op1Neg != op2Neg)
         out = op1Neg;

      // Now that we know signs are the same, we first check if the number of
      // bigDigits are equal to each other
      if (op1.bigDigitsVector.size() != op2.bigDigitsVector.size())
      {
         out = op1.bigDigitsVector.size() < op2.bigDigitsVector.size();
         if (op1Neg && op2Neg)
            out = !out;
      }
      else  // both vectors same size
      {
         // if both operators have the same size, we can use string comparison
         out = op1.bigDigitsString.compare(op2.bigDigitsString) < 0;
         if ((op1Neg && op2Neg) && (op1 != op2))
            out = !out;
      }
      return out;
   }

   bool operator<=(const BigInt &op1, const BigInt &op2)
   {
      return (op1 == op2) || (op1 < op2);
   }

   bool operator>(const BigInt &op1, const BigInt &op2)
   {
      return !(op1 <= op2);
   }

   bool operator>=(const BigInt &op1, const BigInt &op2)
   {
      return !(op1 < op2);
   }
}
