/*
 * allocation.cpp
 *
 *  Created on: 12 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <time.h>
#include "java4cpp/java_classes.h"
#include "testsunit.h"
#include "allocation.h"

using namespace java4cpp::demos;

void allAllocation()
{
   std::cout << "================================" << std::endl;
   std::cout << "Allocation" << std::endl;
   std::cout << "================================" << std::endl;
   statically();
   dynamically();
   //memoryLeak();
}

void statically()
{
   std::cout << "statically" << std::endl;
   
   // Create a c++ proxy on an java Allocation object instance
   Allocation A;
   // Create another c++ proxy on the same java Allocation object instance
   Allocation Acopy(A);
   // Create another c++ proxy on the same java Allocation object instance
   Allocation Acopy2(A.getJavaObject());
   // Create a c++ proxy on another java Allocation object instance
   Allocation Aclone = A.clone();
   
   std::cout << "Allocation: ";
   assertThat(A.getValue()).isEqualTo(-1);
   assertThat(Acopy.getValue()).isEqualTo(-1);
   assertThat(Acopy2.getValue()).isEqualTo(-1);
   assertThat(Aclone.getValue()).isEqualTo(-1);
   std::cout << "ok" << std::endl;
   
   A.setValue(2);
   std::cout << "A.setValue(2): ";
   assertThat(A.getValue()).isEqualTo(2);
   assertThat(Acopy.getValue()).isEqualTo(2);
   assertThat(Acopy2.getValue()).isEqualTo(2);
   assertThat(Aclone.getValue()).isEqualTo(-1);
   std::cout << "ok" << std::endl;

   Aclone.setValue(3);
   std::cout << "Aclone.setValue(3): ";
   assertThat(A.getValue()).isEqualTo(2);
   assertThat(Acopy.getValue()).isEqualTo(2);
   assertThat(Acopy2.getValue()).isEqualTo(2);
   assertThat(Aclone.getValue()).isEqualTo(3);
   std::cout << "ok" << std::endl;

   Acopy.setValue(4);
   std::cout << "Acopy.setValue(4): ";
   assertThat(A.getValue()).isEqualTo(4);
   assertThat(Acopy.getValue()).isEqualTo(4);
   assertThat(Acopy2.getValue()).isEqualTo(4);
   assertThat(Aclone.getValue()).isEqualTo(3);
   std::cout << "ok" << std::endl;
}

void dynamically()
{
   std::cout << "dynamically" << std::endl;

   Allocation* A = new Allocation();
   Allocation* Acopy = new Allocation(*A);
   Allocation* Aclone = new Allocation(A->clone());
   
   std::cout << "Allocation: ";
   assertThat(A->getValue()).isEqualTo(-1);
   assertThat(Acopy->getValue()).isEqualTo(-1);
   assertThat(Aclone->getValue()).isEqualTo(-1);
   std::cout << "ok" << std::endl;

   A->setValue(2);
   std::cout << "A->setValue(2): ";
   assertThat(A->getValue()).isEqualTo(2);
   assertThat(Acopy->getValue()).isEqualTo(2);
   assertThat(Aclone->getValue()).isEqualTo(-1);
   std::cout << "ok" << std::endl;

   Aclone->setValue(3);
   std::cout << "Aclone->setValue(3): ";
   assertThat(A->getValue()).isEqualTo(2);
   assertThat(Acopy->getValue()).isEqualTo(2);
   assertThat(Aclone->getValue()).isEqualTo(3);
   std::cout << "ok" << std::endl;

   Acopy->setValue(4);
   std::cout << "Acopy->setValue(4): ";
   assertThat(A->getValue()).isEqualTo(4);
   assertThat(Acopy->getValue()).isEqualTo(4);
   assertThat(Aclone->getValue()).isEqualTo(3);
   std::cout << "ok" << std::endl;

   delete Aclone;
   assertThat(A->getValue()).isEqualTo(4);
   assertThat(Acopy->getValue()).isEqualTo(4);

   delete Acopy;
   assertThat(A->getValue()).isEqualTo(4);

   delete A;
}

void memoryLeak()
{
   do
   {
      // no leak
      Allocation A;
      Allocation Acopy(A);
      Allocation Anew = A.clone();
      // leak
      //Allocation* B = new Allocation();
   } while (1);
}
