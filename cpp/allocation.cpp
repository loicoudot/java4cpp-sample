/*
 * allocation.cpp
 *
 *  Created on: 12 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <time.h>
#include "java4cpp/java_classes.h"
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
	Allocation A;
	Allocation Acopy(A);
	Allocation Acopy2(A.getJavaObject());
	Allocation Aclone = A.clone();
	std::cout << "A: " << A.getValue() << std::endl;
	std::cout << "Acopy: " << Acopy.getValue() << std::endl;
	std::cout << "Acopy2: " << Acopy2.getValue() << std::endl;
	std::cout << "Aclone: " << Aclone.getValue() << std::endl;

	A.setValue(2);
	std::cout << "A.setValue(2)" << std::endl;
	std::cout << "A: " << A.getValue() << std::endl;
	std::cout << "Acopy: " << Acopy.getValue() << std::endl;
	std::cout << "Acopy2: " << Acopy2.getValue() << std::endl;
	std::cout << "Aclone: " << Aclone.getValue() << std::endl;

	Aclone.setValue(3);
	std::cout << "Aclone.setValue(3)" << std::endl;
	std::cout << "A: " << A.getValue() << std::endl;
	std::cout << "Acopy: " << Acopy.getValue() << std::endl;
	std::cout << "Acopy2: " << Acopy2.getValue() << std::endl;
	std::cout << "Aclone: " << Aclone.getValue() << std::endl;

	Acopy.setValue(4);
	std::cout << "Acopy.setValue(4)" << std::endl;
	std::cout << "A: " << A.getValue() << std::endl;
	std::cout << "Acopy: " << Acopy.getValue() << std::endl;
	std::cout << "Acopy2: " << Acopy2.getValue() << std::endl;
	std::cout << "Aclone: " << Aclone.getValue() << std::endl;
}

void dynamically()
{
	Allocation* A = new Allocation();
	Allocation* Acopy = new Allocation(*A);
	Allocation* Aclone = new Allocation(A->clone());
	std::cout << "A: " << A->getValue() << std::endl;
	std::cout << "Acopy: " << Acopy->getValue() << std::endl;
	std::cout << "Aclone: " << Aclone->getValue() << std::endl;

	A->setValue(2);
	std::cout << "A->setValue(2)" << std::endl;
	std::cout << "A: " << A->getValue() << std::endl;
	std::cout << "Acopy: " << Acopy->getValue() << std::endl;
	std::cout << "Aclone: " << Aclone->getValue() << std::endl;

	Aclone->setValue(3);
	std::cout << "Aclone->setValue(3)" << std::endl;
	std::cout << "A: " << A->getValue() << std::endl;
	std::cout << "Acopy: " << Acopy->getValue() << std::endl;
	std::cout << "Aclone: " << Aclone->getValue() << std::endl;

	Acopy->setValue(4);
	std::cout << "Acopy->setValue(4)" << std::endl;
	std::cout << "A: " << A->getValue() << std::endl;
	std::cout << "Acopy: " << Acopy->getValue() << std::endl;
	std::cout << "Aclone: " << Aclone->getValue() << std::endl;
	delete Aclone;
	delete Acopy;
	std::cout << "A: " << A->getValue() << std::endl;
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
	} while(1);
}
