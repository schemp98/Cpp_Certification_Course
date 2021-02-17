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
const string negativeSign = "-";
//Default Constructor
namespace Project1
{
   vector<int> stringToIntVector(const string input);

   BigInt::BigInt() : bigDigitsString("0"), bigDigitsVector(0)
   {}

   BigInt::BigInt(const BigInt &input) : bigDigitsString(input.bigDigitsString), bigDigitsVector(input.bigDigitsVector)
   {}

   BigInt::BigInt(long long input)
   {
      bigDigitsString = to_string(input);
      bigDigitsVector = stringToIntVector(bigDigitsString);
   }

   BigInt::BigInt(const string &input)
   {
      bigDigitsString = input;
      bigDigitsVector = stringToIntVector(bigDigitsString);
   }

   ostream &operator<<(ostream &out, const BigInt &value)
   {
      out << value.bigDigitsString;
      return out;
   }

   istream &operator>>(istream &in, BigInt &value)
   {
      in >> value.bigDigitsString;
      return in;
   }

   // Helper function to aid with math operations
   vector<int> stringToIntVector(const string input)
   {
      vector<int> out;
      string tempString = input;
      string character;

      for (std::string::iterator it = tempString.begin(); it != tempString.end(); ++it)
      {
         character = *it;
         // Handling of negative BigInt!
         if ((character.compare(negativeSign) == 0) && (it == tempString.begin()))
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

   string IntVectorToString(vector<int> input)
   {
      string out;
      vector<int>::iterator it = input.begin();
      for (; it != input.end(); ++it)
         out += to_string(*it);

      return out;
   }

   void BigInt::negate()
   {
      if (bigDigitsVector[0] > 0)
         bigDigitsString.insert(0, 1, '-');
      else
         bigDigitsString.erase(0);

      bigDigitsVector[0] *= -1;
   }

   const BigInt operator+(const BigInt &op1, const BigInt &op2)
   {
      // Because original algorithms were for non-negative numbers,
      // check to see how we can "rephrase" the addition/subtraction
      // friend operators to accommodate negative BigInts
      bool op1Neg = op1.bigDigitsVector[0] < 0;
      bool op2Neg = op2.bigDigitsVector[0] < 0, negateOutput{false};

      BigInt op1Temp(op1), op2Temp(op2);

      if (op1Neg && op2Neg) // if both BigInts are negative do addition  but change signs
      {
         op1Temp.negate(); op2Temp.negate();
         negateOutput = true;
      }
      else if (!op1Neg && op2Neg)
      {
         op2Temp.negate();
         BigInt outTemp = op1Temp - op2Temp;
         return outTemp;
      }
      else if (op1Neg && !op2Neg)
      {
         op1Temp.negate();
         BigInt outTemp = op2Temp - op1Temp;
         return outTemp;
      }
      string tempStrOut;

      vector<int>  left, right;

      size_t sz1 = op1Temp.bigDigitsVector.size(), sz2 = op2Temp.bigDigitsVector.size();

      if (sz1 > sz2)
      {
         left = op1Temp.bigDigitsVector;
         vector<int> temp(sz1 - sz2, 0);
         right.insert(right.end(), temp.begin(), temp.end());
         right.insert(right.end(), op2Temp.bigDigitsVector.begin(), op2Temp.bigDigitsVector.end());
      }
      else if (sz1 < sz2)
      {
         right = op2Temp.bigDigitsVector;
         vector<int> temp(sz2 - sz1, 0);
         left.insert(left.end(), temp.begin(), temp.end());
         left.insert(left.end(), op1Temp.bigDigitsVector.begin(), op1Temp.bigDigitsVector.end());
      }
      else
      {
         left = op1Temp.bigDigitsVector;
         right = op2Temp.bigDigitsVector;
      }

      vector<int> tempOut(left.size(), 0);
      int sum(0), carry(0), base(0), radix(10);
      vector<int>::reverse_iterator itR = right.rbegin();
      vector<int>::reverse_iterator itO = tempOut.rbegin();
      for (vector<int>::reverse_iterator itL = left.rbegin(); itL != left.rend(); ++itL)
      {
         sum = *itL + *itR + carry;
         base = sum % radix;
         carry = sum / radix;
         *itO = base;
         ++itR; ++itO;
      }

      // add additional element to hold 'carry' value
      if (carry != 0)
         tempOut.emplace(tempOut.begin(), carry);

      tempStrOut = IntVectorToString(tempOut);
      BigInt out(tempStrOut);
      //vector<int>::iterator it2 = op2.bigDigitsVector.begin();

      if (negateOutput)
         out.negate();

      return out;
   }

   const BigInt operator-(const BigInt &op1, const BigInt &op2)
   {
      // Because original algorithms were for non-negative numbers,
            // check to see how we can "rephrase" the addition/subtraction
            // friend operators to accommodate negative BigInts
      bool op1Neg = op1.bigDigitsVector[0] < 0,
         op2Neg = op2.bigDigitsVector[0] < 0, negateOutput{false};

      BigInt op1Temp(op1), op2Temp(op2);

      if (op1Neg && op2Neg) // if both BigInts are negative
      {
         op1Temp.negate(); op2Temp.negate();
         negateOutput = true;
      }
      else if (!op1Neg && op2Neg)
      {
         op2Temp.negate();
         BigInt outTemp = op1Temp + op2Temp;
         return outTemp;
      }
      else if (op1Neg && !op2Neg)
      {
         op1Temp.negate();
         BigInt outTemp = op1Temp + op2Temp;
         return outTemp;
      }

      vector<int>  left, right;

      size_t sz1 = op1.bigDigitsVector.size(), sz2 = op2.bigDigitsVector.size();

      int sum(0), carry(0), base(0), radix(10), scaleFactor(1);

      if (sz1 > sz2)
      {
         left = op1.bigDigitsVector;
         vector<int> temp(sz1 - sz2, 0);
         right.insert(right.end(), temp.begin(), temp.end());
         right.insert(right.end(), op2.bigDigitsVector.begin(), op2.bigDigitsVector.end());
      }
      else if (sz1 < sz2)
      {
         left = op2.bigDigitsVector;
         vector<int> temp(sz2 - sz1, 0);
         right.insert(right.end(), temp.begin(), temp.end());
         right.insert(right.end(), op1.bigDigitsVector.begin(), op1.bigDigitsVector.end());
         scaleFactor = -1;
      }
      else
      {
         left = op1.bigDigitsVector;
         right = op2.bigDigitsVector;
      }

      vector<int> tempOut(left.size(), 0);
      vector<int>::reverse_iterator itR = right.rbegin(), itO = tempOut.rbegin();
      for (vector<int>::reverse_iterator itL = left.rbegin(); itL != left.rend(); ++itL)
      {
         sum = *itL - *itR + carry;
         base = sum % radix;
         if (base < 0)
         {
            base += radix;
            carry = -1;
         }
         else
            carry = 0;// sum / radix;
         *itO = base;
         ++itR; ++itO;
      }

      tempOut[0] *= scaleFactor;

      string tempStrOut = IntVectorToString(tempOut);
      BigInt out(tempStrOut);

      if (negateOutput)
         out.negate();

      return out;
   }

   const BigInt &BigInt::operator=(const BigInt &input)
   {
      if (this != &input) // not a self-assignment
      {
         if (this->bigDigitsString.size() != input.bigDigitsString.size())
         {
            this->bigDigitsString = input.bigDigitsString;
            this->bigDigitsVector = input.bigDigitsVector;
         }
      }
      return *this;
   }

   bool operator==(const BigInt &op1, const BigInt &op2)
   {
      if (op1.bigDigitsVector.size() == op2.bigDigitsVector.size())
         return op1.bigDigitsVector == op2.bigDigitsVector;
      else
         return false;
   }

   bool operator!=(const BigInt &op1, const BigInt &op2)
   {
      return !(op1 == op2);
   }

   bool operator<(const BigInt &op1, const BigInt &op2)
   {
      //first check if signs of operators are the same
      bool op1Neg = op1.bigDigitsVector[0] < 0,
         op2Neg = op2.bigDigitsVector[0] < 0;

      // if signs are different, if op1Neg is true, we know that op2Neg is false,
      // (and vice versa) thus, we return we can op1Neg
      if (op1Neg != op2Neg)
         return op1Neg;

      // Now that we know signs are the same, we first check if the number of
      // bigDigits are equal to each other
      if (op1.bigDigitsVector.size() != op2.bigDigitsVector.size())
         return op1.bigDigitsVector.size() < op2.bigDigitsVector.size();

      // if both operators have the same size, we can use string comparison
      return op1.bigDigitsString.compare(op2.bigDigitsString) < 0;
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
