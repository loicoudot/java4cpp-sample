/*
 * enumeration.cpp
 *
 *  Created on: 12 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <stdexcept>
#include "java4cpp/java_classes.h"
#include "testsunit.h"
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
   std::cout << "enumeration: ";
   assertThat(Enumeration::getEnumString(EnumerationEnum::ONE)).isEqualTo("ONE");
   assertThat(Enumeration::valueOf("TWO")).isEqualTo(EnumerationEnum::TWO);
   assertThat(Enumeration(EnumerationEnum::THREE).toEnum()).isEqualTo(EnumerationEnum::THREE);
   assertThat(Enumeration(EnumerationEnum::THREE).getValue()).isEqualTo(30);
   assertThat(Enumeration::identity(EnumerationEnum::ONE)).isEqualTo(EnumerationEnum::ONE);
   std::cout << "ok" << std::endl;
}

void nullValue()
{
   std::cout << "nullValue: ";
   assertThat(Enumeration::getEnumString(EnumerationEnum::NULL_VALUE)).isEqualTo("NULL_VALUE");
   assertThat(Enumeration(EnumerationEnum::NULL_VALUE).toEnum()).isEqualTo(EnumerationEnum::NULL_VALUE);
   assertThat(Enumeration(EnumerationEnum::NULL_VALUE).getJavaObject()).isNull();
   assertThat(Enumeration::identity(EnumerationEnum::NULL_VALUE)).isEqualTo(EnumerationEnum::NULL_VALUE);
   std::cout << "ok" << std::endl;
}

void innerEnumeration()
{
   std::cout << "innerEnumeration: ";
   InnerEnumeration::Enumeration::EnumerationEnum result = InnerEnumeration::enumAsParameter(InnerEnumeration::Enumeration::ONE, InnerEnumeration::Enumeration::TWO);
   assertThat(result).isEqualTo(InnerEnumeration::Enumeration::EnumerationEnum::THREE);
   assertThat(InnerEnumeration::Enumeration::identity(InnerEnumeration::Enumeration::ONE)).isEqualTo(InnerEnumeration::Enumeration::ONE);
   assertThat(InnerEnumeration::Enumeration::identity(InnerEnumeration::Enumeration::NULL_VALUE)).isEqualTo(InnerEnumeration::Enumeration::NULL_VALUE);
   std::cout << "ok" << std::endl;
}
