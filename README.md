java4cpp-sample
===============

Demonstrate java4cpp capabilities.

Gets full informations directly on the [java4cpp-core](https://github.com/loicoudot/java4cpp-core/wiki) page project.

## Instalation ##

1. Download a copy of the project from git.
1. Generate proxies : type `mvn install` in the root directory.
1. Open the Xcode 5 project inside macosx directory or Visual Studio 10 project inside win32 directory.
1. Build and Run !

### Prerequisite ###

 - Mac OS X with Xcode 5 or later / Windows with Visual Studio 10 or later
 - A Java installation (JRE or JDK, 1.6 minimum)
 - Maven command line tools (and internet connection)

## How It Works ##

This project contains two parts :

1. A Java parts that define some classes that we want to use our C++ demos.
1. A C++ parts that use the proxies class to demonstrate the functionnalities: 

 - Instanciation of Java object
 - Calling methods
 - Managing hierarchie of classes
 - Deal with enums and arrays
 - Translation of Java exception as regular C++ exception
 - Multi-threadings environment
 - Dynamic class loading
 
The `pom.xml` file instruct maven to compile the Java classes into a jar and then execute 
 java4cpp on this jar to generate C++ proxies inside the java4cpp directory.
 
 
