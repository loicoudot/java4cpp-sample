/*
 * benchmark.cpp
 *
 *  Created on: 6 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <time.h>
#include "java4cpp/java_classes.h"
#include "benchmark.h"

using namespace java4cpp::demos;

void allBenchmark()
{
   std::cout << "================================" << std::endl;
   std::cout << "Benchmark" << std::endl;
   std::cout << "================================" << std::endl;
   noArgBenchmark();
   primitiveArgBenchmark();
   classArgBenchmark();
}

void noArgBenchmark()
{
   Benchmark benchmark;
   clock_t start = clock();
   long nbCall = 0;
   do
   {
      for (int i = 0; i < 10000; ++i)
      {
         benchmark.noArgMethod();
      }
      ++nbCall;
   } while ((clock() - start) / CLOCKS_PER_SEC < 1);
   std::cout << "java4cpp no arg method call speed: " << nbCall * 10000 << " method calls/sec" << std::endl;
}

void primitiveArgBenchmark()
{
   Benchmark benchmark;
   clock_t start = clock();
   long nbCall = 0;
   int a = 2;
   double b = 3.0;
   do
   {
      for (int i = 0; i < 10000; ++i)
      {
         benchmark.primitiveArgMethod(a, b);
      }
      ++nbCall;
   } while ((clock() - start) / CLOCKS_PER_SEC < 1);
   std::cout << "java4cpp primitive arg method call speed: " << nbCall * 10000 << " method calls/sec" << std::endl;
}

void classArgBenchmark()
{
   Benchmark benchmark;
   clock_t start = clock();
   long nbCall = 0;
   Benchmark a;
   do
   {
      for (int i = 0; i < 10000; ++i)
      {
         Benchmark result = benchmark.classArgMethod(a);
      }
      ++nbCall;
   } while ((clock() - start) / CLOCKS_PER_SEC < 1);
   std::cout << "java4cpp class arg method call speed: " << nbCall * 10000 << " method calls/sec" << std::endl;
}

