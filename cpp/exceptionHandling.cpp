/*
 * exceptionHandling.cpp
 *
 *  Created on: 6 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <stdexcept>
#include "java4cpp/java_classes.h"
#include "exceptionHandling.h"

using namespace java4cpp::demos;

void allExceptionHandling()
{
   std::cout << "================================" << std::endl;
   std::cout << "Exception Handling" << std::endl;
   std::cout << "================================" << std::endl;
   nullInstance();
   nullPointerException();
   uncheckedException();
   checkedException();
   customCheckedException();
   customUncheckedException();
   badCastException();
}

/**
 * Handling of Null instance
 */
void nullInstance()
{
   // Create a null instance
   ExceptionClass nullInstance((jobject) NULL);
   try
   {
      std::cout << "Is null instance: " << (nullInstance.getJavaObject() == NULL) << std::endl;
      nullInstance.someMethod();
   } catch (std::exception& e)
   {
      std::cout << "Calling method on null instance: " << e.what() << std::endl;
   }

   // Receiving a null instance
   nullInstance = ExceptionClass::getNullInstance();
   try
   {
      std::cout << "Is null instance: " << (nullInstance.getJavaObject() == NULL) << std::endl;
      nullInstance.someMethod();
   } catch (std::exception& e)
   {
      std::cout << "Calling method on null instance: " << e.what() << std::endl;
   }
}

/**
 * Handling NullPointerException inside Java class
 */
void nullPointerException()
{
   try
   {
      ExceptionClass::generateNullPointerException();
   } catch (std::exception& e)
   {
      std::cout << "Method generating NullPointerException: " << e.what() << std::endl;
   }
}

/**
 * Handling unchecked exception inside Java class
 */
void uncheckedException()
{
   try
   {
      ExceptionClass::generateUncheckedException();
   } catch (std::exception& e)
   {
      std::cout << "Method generating unchecked exception: " << e.what() << std::endl;
   }
}

/**
 * Handling checked exception inside Java class
 */
void checkedException()
{
   try
   {
      ExceptionClass::generateCheckedException();
   } catch (std::exception& e)
   {
      std::cout << "Method generating checked exception: " << e.what() << std::endl;
   }
}

/**
 * Handling custom checked exception inside Java class
 */
void customCheckedException()
{
   try
   {
      ExceptionClass::generateCustomCheckedException();
   } catch (java4cpp::demos::CheckedException& e)
   {
      std::cout << "Method generating custom checked exception: " << e.what() << std::endl;
   }
}

/**
 * Handling custom unchecked exception inside Java class
 */
void customUncheckedException()
{
   try
   {
      ExceptionClass::generateCustomUncheckedException();
   } catch (java4cpp::demos::UncheckedException& e)
   {
      std::cout << "Method generating custom unchecked exception: " << e.what() << std::endl;
   }
}

void badCastException()
{
   ExceptionClass aClass;
   try
   {
      UncheckedException incompatibleClass(aClass.getJavaObject());
   } catch (std::exception& e)
   {
      std::cout << "Bad cast exception: " << e.what() << std::endl;
   }
}
