#include <iostream>
#include "java4cpp/jvm_launcher.h"
#include "allocation.h"
#include "superclass.h"
#include "enumeration.h"
#include "arrays.h"
#include "exceptionHandling.h"
#include "classloading.h"
#include "benchmark.h"
#include "multithread.h"

int main(void)
{
#ifdef WIN32
   //jvm_setJrePath("c:/Program Files (x86)/Java/jre7/bin/client/jvm.dll" );
   jvm_setJrePath("c:/Program Files (x86)/Java/jdk1.7.0_45/jre/bin/client/jvm.dll" );
#else
   jvm_setJrePath("/System/Library/Java/JavaVirtualMachines/1.6.0.jdk/Contents/Libraries/libserver.dylib");
#endif

   jvm_addClassPath("../../jars/java4cpp-sample-1.0.0-SNAPSHOT.jar");

   try
   {
      allAllocation();
      allSuperclass();
      allEnumeration();
      allArrays();
      allExceptionHandling();
      allClassloading();
      allBenchmark();
      allMultithread();
   } catch (std::exception& e)
   {
      std::cout << e.what() << std::endl;
   }

   return 0;
}
