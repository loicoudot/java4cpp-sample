/*
 * arrays.cpp
 *
 *  Created on: 19 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <time.h>
#include "java4cpp/java_classes.h"
#include "arrays.h"

using namespace java4cpp::demos;

void allArrays()
{
	std::cout << "================================" << std::endl;
	std::cout << "Arrays" << std::endl;
	std::cout << "================================" << std::endl;
	oneDimensionPrimitive();
}

void oneDimensionPrimitive()
{
	std::vector<int> in;
	in.push_back(-1); in.push_back(0); in.push_back(1);
	std::vector<long long> out = Arrays().negate(in);
	std::cout << "negate: " << out.size() << ", " << out[0] << ", " << out[1] << ", " << out[2];

	std::vector<bool> in1;
	bool* a = &in1[0];
	in1.push_back(true); in1.push_back(false);
	std::vector<bool> out1 = Arrays().invert(in1);
	std::cout << "invert: " << out1.size() << ", " << out1[0] << ", " << out1[1];
}
