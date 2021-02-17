/*===========================================================================
 * Homework #2 - CSE40478
 *
 * File:    main.cpp
 * Author:  Ray Mitchell
 * Date:    4/21/2012
 *
 * Program Output:
 *    Success: 22 tests passed.
 *    Test time: 0.00 seconds.
 *===========================================================================*/
#include <algorithm>
#include <exception>
#include <numeric>
using namespace std;

#include "Queue.h"
using RayMitchell::Homework2::Queue;

#include "UnitTest++.h"

TEST(QueueDefaultConstructor)
{
   Queue<int> q;
   CHECK(q.empty());
   CHECK(q.size() == 0);
}

TEST(QueueDestructor_EmptyQueue)
{
   Queue<int> *pQ = new Queue<int>();
   try
   {
      delete pQ;     // Verify doesn't throw
   }
   catch (...)
   {
      CHECK(false);
   }
}

TEST(QueueDestructor_NonEmptyQueue)
{
   Queue<int> *pQ = new Queue<int>();
   pQ->push(1);
   pQ->push(2);
   pQ->push(3);
   try
   {
      delete pQ;     // Verify doesn't throw
   }
   catch (...)
   {
      CHECK(false);
   }
}

TEST(QueueCopyConstructor_EmptyQueue)
{
   Queue<int> q1;
   Queue<int> q2(q1);
   CHECK(q2.empty());
}

TEST(QueueCopyConstructor_NonEmptyQueue)
{
   Queue<int> q1;
   q1.push(1);
   q1.push(2);
   q1.push(3);
   Queue<int> q2(q1);
   CHECK(q2.size() == 3);
   CHECK(q2.front() == 1);
   q2.pop();
   CHECK(q2.size() == 2);
   CHECK(q2.front() == 2);
   q2.pop();
   CHECK(q2.size() == 1);
   CHECK(q2.front() == 3);
   q2.pop();
   CHECK(q2.empty());
}

TEST(QueueCopyAssignmentOperator_EmptyQueueToEmptyQueue)
{
   Queue<int> q1;
   Queue<int> q2;
   q2 = q1;
   CHECK(q2.empty());
}

TEST(QueueCopyAssignmentOperator_EmptyQueueToNonEmptyQueue)
{
   Queue<int> q1;
   Queue<int> q2;
   q2.push(1);
   q2.push(2);
   q2.push(3);
   q2 = q1;
   CHECK(q2.empty());
}

TEST(QueueCopyAssignmentOperator_NonEmptyQueueToEmptyQueue)
{
   Queue<int> q1;
   q1.push(1);
   q1.push(2);
   q1.push(3);
   Queue<int> q2;
   q2 = q1;
   CHECK(q2.size() == 3);
   CHECK(q2.front() == 1);
   q2.pop();
   CHECK(q2.size() == 2);
   CHECK(q2.front() == 2);
   q2.pop();
   CHECK(q2.size() == 1);
   CHECK(q2.front() == 3);
   q2.pop();
   CHECK(q2.empty());
}

TEST(QueueCopyAssignmentOperator_NonEmptyQueueToNonEmptyQueue)
{
   Queue<int> q1;
   q1.push(1);
   q1.push(2);
   q1.push(3);
   Queue<int> q2;
   q2.push(4);
   q2.push(5);
   q2.push(6);
   q2 = q1;
   CHECK(q2.size() == 3);
   CHECK(q2.front() == 1);
   q2.pop();
   CHECK(q2.size() == 2);
   CHECK(q2.front() == 2);
   q2.pop();
   CHECK(q2.size() == 1);
   CHECK(q2.front() == 3);
   q2.pop();
   CHECK(q2.empty());
}

TEST(QueuePush_SinglePush)
{
   Queue<int> q;
   q.push(1);
   CHECK(q.size() == 1);
   CHECK(q.front() == 1);
}

TEST(QueuePush_MultiplePushes)
{
   Queue<int> q;
   q.push(1);
   CHECK(q.size() == 1);
   CHECK(q.front() == 1);
   q.push(2);
   CHECK(q.size() == 2);
   CHECK(q.front() == 1);
   q.push(3);
   CHECK(q.size() == 3);
   CHECK(q.front() == 1);
}

TEST(QueuePop_SinglePop)
{
   Queue<int> q;
   q.push(1);
   q.pop();
   CHECK(q.empty());
}

TEST(QueuePop_MultiplePops)
{
   Queue<int> q;
   q.push(1);
   q.push(2);
   q.push(3);
   q.pop();
   CHECK(q.size() == 2);
   CHECK(q.front() == 2);
   q.pop();
   CHECK(q.size() == 1);
   CHECK(q.front() == 3);
   q.pop();
   CHECK(q.empty());
}

TEST(QueuePop_EmptyQueue)
{
   Queue<int> q;
   CHECK_THROW(q.pop(), logic_error);
}

TEST(QueueFrontLValue_EmptyQueue)
{
   Queue<int> q;
   CHECK_THROW(q.front(), logic_error);
}

TEST(QueueFrontLValue_NonEmptyQueue)
{
   Queue<int> q;
   q.push(1);
   q.front() = 2;
   CHECK(q.front() == 2);
}

TEST(QueueFrontRValue_EmptyQueue)
{
   Queue<int> q1;
   const Queue<int> q2(q1);
   CHECK_THROW(q2.front(), logic_error);
}

TEST(QueueFrontRValue_NonEmptyQueue)
{
   Queue<int> q1;
   q1.push(1);
   const Queue<int> q2(q1);
   CHECK(q2.front() == 1);
}

TEST(QueueEmpty_EmptyQueue)
{
   Queue<int> q;
   CHECK(q.empty());
}

TEST(QueueEmpty_NonEmptyQueue)
{
   Queue<int> q;
   q.push(1);
   q.push(2);
   q.push(3);
   CHECK(!q.empty());
}

TEST(QueueSize_EmptyQueue)
{
   Queue<int> q;
   CHECK(q.size() == 0);
}

TEST(QueueSize_NonEmptyQueue)
{
   Queue<int> q;
   q.push(1);
   q.push(2);
   q.push(3);
   CHECK(q.size() == 3);
}

int main()
{
   int numFailedTests = UnitTest::RunAllTests();
   getchar();  // Keep console window from closing
   return numFailedTests;
}
