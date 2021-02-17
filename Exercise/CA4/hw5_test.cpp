#include <iostream>
//#include <sstream>
#include <exception> // isdigit, toupper

// To avoid auto_ptr ambiguity we need to avoid using std namespace
using std::cout;
using std::clog;

template<class T>
class auto_ptr {
public:
   explicit auto_ptr(T *p = 0) : pointee(p) {} throw();
   template<class U>
   auto_ptr(auto_ptr<U>& rhs) : pointee(rhs.release()) {}
   ~auto_ptr() { delete pointee; }
   template<class U>
   auto_ptr<T>& operator=(auto_ptr<U>& rhs)
   {
      if (this != &rhs) reset(rhs.release());
      return *this;
   }
   T& operator*() const { return *pointee; }
   T* operator->() const { return pointee; }
   T* get() const { return pointee; }
   T* release()
   {
      T *oldPointee = pointee;
      pointee = 0;
      return oldPointee;
   }
   void reset(T *p = 0)
   {
      if (pointee != p) {
         delete pointee;
         pointee = p;
      }
   }
private:
   T *pointee;
   //template<class U>
   //friend class auto_ptr;
};

// Unit Tests
// Unit Tests:
void testAutoPtrDefaultConstructor()
{
   try
   {
      const int testInput(9);
      auto_ptr<int> testAutoPtr(new int(testInput));
      clog << "testAutoPtrDefaultConstructor PASSED\n";
   }
   catch (...)
   {
      clog << "testAutoPtrDefaultConstructor FAILED\n";
   }
}

void testAutoPtrCopyConstructor()
{
   try
   {
      const int testSource(9);
      auto_ptr<int> sourceAutoPtr(new int(testSource));
      auto_ptr<int> sinkAutoPtr(sourceAutoPtr);

      if ((testSource == *sinkAutoPtr) && (sourceAutoPtr.get() == 0))
         clog << "testAutoPtrCopyConstructor PASSED\n";
      else
         clog << "testUppercasingSPAProcess1 FAILED : Expected output "
         << testSource << " instead saw " << *sinkAutoPtr << "\n";
   }
   catch (...)
   {
      clog << "testAutoPtrCopyConstructor FAILED\n";
   }
}

void testAutoPtrCopyConstructorNewType()
{
   try
   {
      const int testSource(9);
      auto_ptr<int> sourceAutoPtr(new int(testSource));
      auto_ptr<int> sinkAutoPtr(sourceAutoPtr);

      if ((testSource == *sinkAutoPtr) && (sourceAutoPtr.get() == 0))
         clog << "testAutoPtrCopyConstructor PASSED\n";
      else
         clog << "testUppercasingSPAProcess1 FAILED : Expected output "
         << testSource << " instead saw " << *sinkAutoPtr << "\n";
   }
   catch (...)
   {
      clog << "testAutoPtrCopyConstructor FAILED\n";
   }
}

void testAutoPtrDeconstructor()
{
   const int testInput(9);
   auto_ptr<int> *testAutoPtr = new auto_ptr<int>(new int(testInput));

   try
   {
      delete testAutoPtr;
      clog << "testAutoPtrDeconstructor PASSED\n";
   }
   catch (...)
   {
      clog << "testAutoPtrDeconstructor FAILED\n";
   }
}

int main(void)
{
   testAutoPtrDefaultConstructor();
   testAutoPtrDeconstructor();
   testAutoPtrCopyConstructor();
   //cout << "\n\nTesting DigitStrippingSPA Behavior:\n\n";
}
