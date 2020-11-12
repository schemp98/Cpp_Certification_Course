/*
* Airplane Monitoring System Project
* CSE-40477
*
* main.cpp
* YOU MUST NOT CHANGE THIS FILE.
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Uncomment this section and the section at the start of main to dump a memory
// leak report at program terimination when using Visual Studio.
// See http://msdn.microsoft.com/en-us/library/x98tx3cf.aspx for more info.
#define _CRTDBG_MAP_ALLOC

#include "UnitTest.h"

int main()
{
   // Uncomment this section and the section at the start of this file to
// dump a memory leak report at program termination when using Visual
// Studio.
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

   // Uncomment this section to set a memory-allocation breakpoint at the
// given memory allocation number when using Visual Studio.
   //_CrtSetBreakAlloc(947);

   // Initialize
   Project2UnitTest::Initialize(cout);

   // Run tests
   Project2UnitTest::TestTime();
   Project2UnitTest::TestDataRecorder();
   Project2UnitTest::TestConstantSignal();
   Project2UnitTest::TestSawtoothSignal();
   Project2UnitTest::TestSineSignal();
   Project2UnitTest::TestAngularSensor();
   Project2UnitTest::TestPressureSensor();
   Project2UnitTest::TestTemperatureSensor();
   Project2UnitTest::TestVibrationSensor();
   Project2UnitTest::TestMonitoringSystem();

   // Display test results
   Project2UnitTest::DisplaySummary();

   // Wait for user input
   cout << endl << "Press enter to continue...";
   cin.get();
}
