/*
 * superclass.cpp
 *
 *  Created on: 11 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <time.h>
#include "java4cpp/java_classes.h"
#include "testsunit.h"
#include "superclass.h"

using namespace java4cpp::demos;

// SFINAE to detect presence of method baseMethod in a class
template<typename T>
class has_baseMethod
{
   struct Fallback { int baseMethod; };
   struct Derived : T, Fallback { };
   
   template<typename U, U> struct Check;
   
   typedef char ArrayOfOne[1];
   typedef char ArrayOfTwo[2];
   
   template<typename U>
   static ArrayOfOne & func(Check<int Fallback::*, &U::baseMethod> *);
   
   template<typename U>
   static ArrayOfTwo & func(...);
   
public:
   typedef has_baseMethod type;
   static const bool value = sizeof(func<Derived>(0)) == 2;
};

void allSuperclass()
{
   std::cout << "================================" << std::endl;
   std::cout << "Superclass" << std::endl;
   std::cout << "================================" << std::endl;
   superclass();
   casting();
}

void superclass()
{
   std::cout << "superclass: ";
   assertThat(Baseclass().baseMethod()).isEqualTo(1);
   assertThat(Baseclass().overridenMethod()).isEqualTo(2);
   assertThat(Superclass().baseMethod()).isEqualTo(1);
   assertThat(Superclass().overridenMethod()).isEqualTo(3);
   assertThat(Superclass::WithSuperclass().baseMethod()).isEqualTo(1);
   assertThat(Superclass::WithSuperclass().overridenMethod()).isEqualTo(4);
   assertThat(Superclass::WithoutSuperclass().overridenMethod()).isEqualTo(5);
   assertThat(has_baseMethod<Superclass::WithSuperclass>::value).isTrue();
   assertThat(has_baseMethod<Superclass::WithoutSuperclass>::value).isFalse();
   std::cout << "ok" << std::endl;
}

void casting()
{
   std::cout << "casting: ";
   
   Baseclass baseclass;
   assertThat(dynamic_cast<Baseclass*>(&baseclass)).isNotNull();
   
   Superclass superclass;
   assertThat(dynamic_cast<Baseclass*>(&superclass)).isNotNull();

   Superclass::WithSuperclass withSuperclass;
   assertThat(dynamic_cast<Baseclass*>(&withSuperclass)).isNotNull();

   Superclass::WithoutSuperclass withoutSuperclass;
   assertThat(dynamic_cast<Baseclass*>(&withoutSuperclass)).isNull();

   std::cout << "ok" << std::endl;
}
