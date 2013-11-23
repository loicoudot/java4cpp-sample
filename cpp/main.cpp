#include <iostream>
#include "java4cpp/jvm_launcher.h"
#include "java4cpp/java_classes.h"
#include "allocation.h"
#include "superclass.h"
#include "enumeration.h"
#include "arrays.h"
#include "exceptionHandling.h"
#include "benchmark.h"
#include "multithread.h"

int main(void)
{
#ifdef WIN32
	jw_setJrePath("c:/Program Files (x86)/Java/jre7/bin/client/jvm.dll" );
#else
	jw_setJrePath("/System/Library/Java/JavaVirtualMachines/1.6.0.jdk/Contents/Libraries/libserver.dylib");
#endif

	jw_addClassPath("../../jars/java4cpp-sample-1.0.0-SNAPSHOT.jar");

	try
	{
		allAllocation();
		allSuperclass();
		allEnumeration();
		allArrays();
		allExceptionHandling();
		allBenchmark();
		allMultithread();
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
	}

	return 0;
}
