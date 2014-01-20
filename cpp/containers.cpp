/*
 * containers.cpp
 *
 *  Created on: 12 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <algorithm>
#include "jlist.h"
#include "java4cpp/java_classes.h"
#include "containers.h"

using namespace java4cpp::demos;



void allContainers()
{
   std::cout << "================================" << std::endl;
   std::cout << "Containers" << std::endl;
   std::cout << "================================" << std::endl;
   listObject();
}

void listObject()
{
   
   InnerClass inner;
  // std::cout << inner.method(2).get() << std::endl;
  // std::cout << inner.method(4).get() << std::endl;
  // std::cout << inner.method(boost::optional<short>()) << std::endl;
   
   Containers containers;
   
}