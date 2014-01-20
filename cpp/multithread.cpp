/*
 * allocation.cpp
 *
 *  Created on: 12 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <time.h>
#include "java4cpp/java_classes.h"
#include "java4cpp_thread.h"
#include "multithread.h"

#define NB_THREAD 10
#define NB_ITER 1000000
#define LENGTH 5

using namespace java4cpp::demos;

void allMultithread()
{
   std::cout << "================================" << std::endl;
   std::cout << "Multithread" << std::endl;
   std::cout << "================================" << std::endl;
   threadsafe();
   benchmark();
}

callback_t callbackThreadsafe(void *in)
{
   Threads* thread = (Threads*)in;
   for(int i = 0; i < NB_ITER; ++i)
   {
      thread->threadsafe();
   }

   return 0;
}

void threadsafe()
{
   Threads thread;
   thread_t threads[NB_THREAD];
   for (int i = 0; i < NB_THREAD; ++i)
   {
      thread_create(threads[i], callbackThreadsafe, &thread);
   }

   for (int i = 0; i < NB_THREAD; ++i)
   {
      thread_wait_close(threads[i]); thread_delete(threads[i]);
   }

   std::cout << "threadsafe: " << (thread.getIter() == NB_THREAD * NB_ITER) << std::endl;
}

callback_t callbackBenchmark(void *in)
{
   Benchmark benchmark;
   time_t start = time(NULL);
   long nbCall = 0;
   double elapsed;
   do
   {
      for (int i = 0; i < 10000; ++i)
      {
         benchmark.noArgMethod();
      }
      ++nbCall;
      elapsed = difftime(time(NULL),start);
   }while ( elapsed < LENGTH);
   *((long*)in) = (long)((nbCall * 10000) / elapsed);
   return 0;
}

void benchmark()
{
   for (int nbThread = 1; nbThread < 5; ++nbThread)
   {
      std::cout << "benchmark " << nbThread << " threads:" << std::endl;

      thread_t* threads = new thread_t[nbThread];
      long* results = new long[nbThread];
      for (int i = 0; i < nbThread; ++i)
      {
         thread_create(threads[i], callbackBenchmark, results + i);
      }

      for (int i = 0; i < nbThread; ++i)
      {
         thread_wait_close(threads[i]); thread_delete(threads[i]);
      }

      long total = 0;
      for (int i = 0; i < nbThread; ++i)
      {
         std::cout << "thread " << i << ": " << results[i] << " calls/sec" << std::endl;
         total += results[i];
      }
      std::cout << "total: " << total << " calls/sec" << std::endl;
      delete[] results;
      delete[] threads;
   }
}
