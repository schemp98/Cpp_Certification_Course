/*===========================================================================
 * Homework #2 - CSE40478
 *
 * File:    Queue.h
 * Author:  Ray Mitchell
 * Date:    4/21/2012
 *===========================================================================*/
#ifndef RAYMITCHELL_HOMEWORK2_QUEUE_H
#define RAYMITCHELL_HOMEWORK2_QUEUE_H

#include <algorithm>
#include <cassert>
#include <exception>
using namespace std;

namespace RayMitchell { namespace Homework2
{
   //--------------------------------------------------------------------------
   // Helpers
   //--------------------------------------------------------------------------
   template <typename T>
   T *
   newCopy(const T *src,
           size_t srcsize,
           size_t destsize)
   {
      assert(destsize >= srcsize);
      
      T *dest = 0;
      if (destsize > 0)
      {
         dest = new T[destsize];
         if (src != 0 && srcsize != 0)
         {
            try
            {
               copy(src, src + srcsize, dest);
            }
            catch (...)
            {
               delete[] dest;             // This can't throw
               throw;                     // Rethrow original exception
            }
         }
      }
      return dest;
   }

   //--------------------------------------------------------------------------
   // Queue
   //--------------------------------------------------------------------------
   template <typename T>
   class Queue
   {
   public:
      Queue();                         // Construct empty queue
      ~Queue();                        // Destructor
      Queue(const Queue &);            // Copy constructor
      Queue &operator=(const Queue &); // Copy assignment operator
      void push(const T &);            // Add elem to back of queue
      void pop();                      // Remove front elem from queue
      T &front();                      // Return ref to front elem in queue
      const T &front() const;          // Return ref to front elem in queue
      bool empty() const;              // Return whether queue is empty
      size_t size() const;             // Return # of elems in queue

   private:
      T *v_;                           // Pointer to beginning of T buffer
      T *front_;                       // Pointer to first used T in buffer
      size_t vsize_;                   // # T's in buffer
      size_t vused_;                   // # used T's in buffer
   };

   template <typename T>
   Queue<T>::Queue()
      : v_(0),
        front_(0),
        vsize_(0),
        vused_(0)
   {}

   template <typename T>
   Queue<T>::~Queue()
   {
      delete[] v_;
   }

   template <typename T>
   Queue<T>::Queue(const Queue &other)
      : v_(newCopy(other.front_,
                   other.vused_,
                   other.vused_)),
        front_(v_),
        vsize_(other.vused_),
        vused_(other.vused_)
   {}

   template <typename T>
   Queue<T> &
   Queue<T>::operator=(const Queue &other)
   {
      if (this != &other)
      {
         T *v_new = newCopy(other.front_,
                            other.vused_,
                            other.vused_);
         delete[] v_;                  // This can't throw
         v_ = v_new;                   // Take ownership
         front_ = v_;
         vsize_ = other.vused_;
         vused_ = other.vused_;
      }
      return *this;
   }

   template <typename T>
   void
   Queue<T>::push(const T &t)
   {
      size_t vsize_new = vused_ + 1;
      T *v_new = newCopy(front_, vused_, vsize_new);
      try
      {
         v_new[vsize_new - 1] = t;     // Copy t into new buffer
      }
      catch (...)
      {
         delete[] v_new;               // This can't throw
         throw;                        // Rethrow original exception
      }
      delete[] v_;                     // This can't throw
      v_ = v_new;
      front_ = v_;
      vsize_ = vsize_new;
      ++vused_;
   }

   template <typename T>
   void
   Queue<T>::pop()
   {
      if (vused_ == 0)
      {
         throw logic_error("pop from empty Queue");
      }
      ++front_;
      --vused_;
   }

   template <typename T>
   T &
   Queue<T>::front()
   {
      if (vused_ == 0)
      {
         throw logic_error("front from empty Queue");
      }
      return *front_;
   }

   template <typename T>
   const T &
   Queue<T>::front() const
   {
      if (vused_ == 0)
      {
         throw logic_error("front from empty Queue");
      }
      return *front_;
   }

   template <typename T>
   bool
   Queue<T>::empty() const
   {
      return vused_ == 0;
   }

   template <typename T>
   size_t
   Queue<T>::size() const
   {
      return vused_;
   }
}}

#endif
