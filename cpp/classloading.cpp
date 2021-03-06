/*
 * classloading.cpp
 *
 *  Created on: 25 nov. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include "java4cpp/java_classes.h"
#include "java4cpp/jvm_launcher.h"
#include "classloading.h"

using namespace java4cpp::demos;

void allClassloading()
{
   std::cout << "================================" << std::endl;
   std::cout << "Class Loading" << std::endl;
   std::cout << "================================" << std::endl;
   dynamicClassloader();
}

void dynamicClassloader()
{
   // try to instanciate unknow class
   std::cout << "not in class path: ";
   try
   {
      org::slf4j::helpers::BasicMarkerFactory factory;
      std::cout << "ko";
   } catch (std::exception& )
   {
      std::cout << "ok";
   }
   std::cout << std::endl;

   // add a jar dynaically in class path
   jvm_addClassPath("../../jars/slf4j-api-1.7.5.jar");

   // retry to instanciate
   std::cout << "now in class path: ";
   try
   {
      org::slf4j::helpers::BasicMarkerFactory factory;
      std::cout << "ok";
   } catch (std::exception& e)
   {
      std::cout << "ko" << std::endl << e.what();
   }
   std::cout << std::endl;
}
