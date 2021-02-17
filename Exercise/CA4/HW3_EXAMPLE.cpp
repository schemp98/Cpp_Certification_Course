#include <cassert>
#include <cctype>
using ::toupper;
using ::isdigit;

#include <cstring>
using std::strpbrk;

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;

#include <algorithm>
using std::transform;

#include <limits>
using std::numeric_limits;

#include "random.hh"

namespace characters
{
   static const string lowers = "abcdefghijklmnopqrstuvwxyz";
   static const string uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   static const string digits = "0123456789";
}

using characters::lowers;
using characters::uppers;
using characters::digits;

struct StreamProcessorAlgorithm
{
   StreamProcessorAlgorithm(istream &in, ostream &out)
      : in(in), out(out)
   {}

   void process()
   {
      // For each whitespace separated string (token) read from the input stream:
      while (in)
      {
         string token;
         in >> token;

         // If the token passes through the filter
         if (filterToken(token) == true)
         {
            // Process the token and output it to the output stream
            processToken(token);
            out << token;
         }
      }
   }

   virtual ~StreamProcessorAlgorithm()
   {}

private:
   virtual bool filterToken(const string &token) const = 0;
   virtual void processToken(string &token) const = 0;
   istream &in;
   ostream &out;
};

struct UppercasingSPA : public StreamProcessorAlgorithm
{
   UppercasingSPA(istream &in, ostream &out)
      : StreamProcessorAlgorithm(in, out)
   {}

   ~UppercasingSPA()
   {}

private:
   bool filterToken(const string &token) const
   {
      return true;
   }

   void processToken(string &token) const
   {
      transform(token.begin(), token.end(), token.begin(), toupper);
   }

public:
   struct tests
   {
      static void constructor()
      {
         UppercasingSPA spa(cin, cout);
      }

      static void filterToken()
      {
         static const auto min = numeric_limits<char>::lowest();
         static const auto max = numeric_limits<char>::max();

         UppercasingSPA spa(cin, cout);

         char buffer[2] = {0};

         for (short i = min; i <= max; ++i)
         {
            buffer[0] = i;
            assert(spa.filterToken(buffer) == true);
         }

         assert(spa.filterToken("") == true);
      }

      static void processToken()
      {
         UppercasingSPA spa(cin, cout);
         string token;

         token = characters::lowers;
         spa.processToken(token);
         assert(token == characters::uppers);

         token = characters::uppers;
         spa.processToken(token);
         assert(token == characters::uppers);

         token = characters::digits;
         spa.processToken(token);
         assert(token == characters::digits);
      }
   };

   friend class tests;
};

struct DigitStrippingSPA : public StreamProcessorAlgorithm
{
   DigitStrippingSPA(istream &in, ostream &out)
      : StreamProcessorAlgorithm(in, out)
   {}

   ~DigitStrippingSPA()
   {}

private:
   bool filterToken(const string &token) const
   {
      return std::find_if(token.begin(), token.end(), isdigit) != token.end();
   }

   void processToken(string &token) const
   {
      token.erase(remove_if(token.begin(), token.end(), isdigit), token.end());
   }

public:
   struct tests
   {
      static void constructor()
      {
         DigitStrippingSPA spa(cin, cout);
      }

      static void filterToken()
      {
         static const auto min = numeric_limits<char>::lowest();
         static const auto max = numeric_limits<char>::max();

         DigitStrippingSPA spa(cin, cout);

         auto test = [spa](const char min, const char max, bool expect)
         {
            char buffer[2] = {0};

            for (short i = min; i <= max; ++i)
            {
               buffer[0] = i;
               assert(spa.filterToken(buffer) == expect);
            }
         };

         test(min, '0' - 1, false);
         test('0', '9', true);
         test('9' + 1, max, false);
         assert(spa.filterToken("") == false);
      }

      static void processToken()
      {
         DigitStrippingSPA spa(cin, cout);

         auto processToken = [spa](string token)
         {
            spa.processToken(token);
            return token;
         };

         assert(processToken("") == "");
         assert(processToken(digits) == "");

         assert(processToken(digits + lowers) == lowers);
         assert(processToken(lowers + digits) == lowers);
         assert(processToken(digits + uppers) == uppers);
         assert(processToken(uppers + digits) == uppers);

         assert(processToken(digits + lowers + digits) == lowers);
         assert(processToken(uppers + digits + lowers) == uppers + lowers);
      }
   };

   friend class tests;
};

int main()
{
   UppercasingSPA::tests::constructor();
   UppercasingSPA::tests::filterToken();
   UppercasingSPA::tests::processToken();

   DigitStrippingSPA::tests::constructor();
   DigitStrippingSPA::tests::filterToken();
   DigitStrippingSPA::tests::processToken();
}