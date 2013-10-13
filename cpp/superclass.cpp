/*
 * superclass.cpp
 *
 *  Created on: 11 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <time.h>
#include "java4cpp/java_classes.h"
#include "superclass.h"

using namespace java4cpp::demos;

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
	std::cout << "baseclass baseMethod: " << Baseclass().baseMethod() << std::endl;
	std::cout << "baseclass overridenMethod: " << Baseclass().overridenMethod() << std::endl;
	std::cout << "superclass baseMethod: " << Superclass().baseMethod() << std::endl;
	std::cout << "superclass overridenMethod: " << Superclass().overridenMethod() << std::endl;
	std::cout << "withSuperclass baseMethod: " << Superclass::WithSuperclass().baseMethod() << std::endl;
	std::cout << "withSuperclass overridenMethod: " << Superclass::WithSuperclass().overridenMethod() << std::endl;
	// Compilation error because of superclass=false
	//std::cout << "withoutSuperclass baseMethod: " << Superclass::WithoutSuperclass().baseMethod() << std::endl;
	std::cout << "withoutSuperclass overridenMethod: " << Superclass::WithoutSuperclass().overridenMethod() << std::endl;
}

void casting()
{
	Baseclass baseclass;
	std::cout << "casting baseclass to baseclass: " << (dynamic_cast<Baseclass*>(&baseclass) != NULL) << std::endl;

	Superclass superclass;
	std::cout << "casting superclass to baseclass: " << (dynamic_cast<Baseclass*>(&superclass) != NULL) << std::endl;

	Superclass::WithSuperclass withSuperclass;
	std::cout << "casting withSuperclass to baseclass: " << (dynamic_cast<Baseclass*>(&withSuperclass) != NULL) << std::endl;

	Superclass::WithoutSuperclass withoutSuperclass;
	std::cout << "casting withoutSuperclass to baseclass (must fail): " << (dynamic_cast<Baseclass*>(&withoutSuperclass) != NULL) << std::endl;
}
