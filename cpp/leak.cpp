/*
 * leak.cpp
 *
 *  Created on: 14 jan. 2014
 *      Author: Loic Oudot
 */

#include <iostream>
#include <time.h>
#include "java4cpp/java_classes.h"
#include "testsunit.h"
#include "leak.h"

using namespace java4cpp::demos;

void allLeak()
{
   std::cout << "================================" << std::endl;
   std::cout << "Memory Leak" << std::endl;
   std::cout << "================================" << std::endl;
   general();
}

void general()
{
   std::vector < std::vector<std::vector<std::string> > > threeDims;
   std::vector < std::vector<std::string> > dim1;
   std::vector < std::string > dim2;
   dim2.push_back("string");
   dim1.push_back(dim2);
   threeDims.push_back(dim1);

   do
   {
      // Allocation
      Allocation A;
      Allocation Acopy(A);
      Allocation Anew = A.clone();

      // Arrays
      std::vector<std::vector<std::vector<std::string> > > out = Arrays().whatFor(threeDims);

      // Strings
      assertThat(Arrays().diacritic()).isEqualTo("&é§èçà$€");

      // Enums
      assertThat(Enumeration::identity(EnumerationEnum::ONE)).isEqualTo(EnumerationEnum::ONE);
      assertThat(Enumeration::identity(EnumerationEnum::NULL_VALUE)).isEqualTo(EnumerationEnum::NULL_VALUE);
      assertThat(InnerEnumeration::Enumeration::identity(InnerEnumeration::Enumeration::ONE)).isEqualTo(InnerEnumeration::Enumeration::ONE);
      assertThat(InnerEnumeration::Enumeration::identity(InnerEnumeration::Enumeration::NULL_VALUE)).isEqualTo(InnerEnumeration::Enumeration::NULL_VALUE);
   } while (1);
}
