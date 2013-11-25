/*
 * enumeration.cpp
 *
 *  Created on: 12 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <stdexcept>
#include "java4cpp/java_classes.h"
#include "enumeration.h"

using namespace java4cpp::demos;

void allEnumeration()
{
   std::cout << "================================" << std::endl;
   std::cout << "Enumeration" << std::endl;
   std::cout << "================================" << std::endl;
   enumeration();
   nullValue();
   innerEnumeration();
}

void enumeration()
{
   std::cout << "ONE enum value: " << EnumerationEnum::ONE << std::endl;
   std::cout << "ONE getEnumString: " << Enumeration::getEnumString(EnumerationEnum::ONE) << std::endl;
   Enumeration oneObject(EnumerationEnum::ONE);
   std::cout << "ONE getValue: " << oneObject.getValue() << std::endl;
}

void nullValue()
{
   std::cout << "NULL_VALUE enum value: " << EnumerationEnum::NULL_VALUE << std::endl;
   std::cout << "NULL_VALUE getEnumString: " << Enumeration::getEnumString(EnumerationEnum::NULL_VALUE) << std::endl;
   Enumeration nullObject(EnumerationEnum::NULL_VALUE);
   std::cout << "NULL_VALUE is null object: " << (nullObject.getJavaObject() == NULL) << std::endl;
}

void innerEnumeration()
{
   InnerEnumeration::Enumeration::EnumerationEnum result = InnerEnumeration::enumAsParameter(InnerEnumeration::Enumeration::ONE, InnerEnumeration::Enumeration::TWO);
   std::cout << "Return value: " << InnerEnumeration::Enumeration::getEnumString(result) << std::endl;
}
