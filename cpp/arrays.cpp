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
   oneDimPrimitive();
   oneDimObject();
   twoDimPrimitive();
   threeDimObject();
}

void oneDimPrimitive()
{
   std::vector<int> in;
   in.push_back(-1);
   in.push_back(0);
   in.push_back(1);
   std::vector<long long> out = Arrays().negate(in);
   std::cout << "negate: " << out.size() << ", " << out[0] << ", " << out[1] << ", " << out[2] << std::endl;

   std::vector<bool> in1;
   in1.push_back(true);
   in1.push_back(false);
   std::vector<bool> out1 = Arrays().invert(in1);
   std::cout << "invert: " << out1.size() << ", " << out1[0] << ", " << out1[1] << std::endl;

   std::vector<float> in2;
   in2.push_back(0);
   in2.push_back(1);
   in2.push_back(2);
   std::vector<double> out2 = Arrays().add(in2);
   std::cout << "add: " << out2.size() << ", " << out2[0] << ", " << out2[1] << ", " << out2[2] << std::endl;
}

void oneDimObject()
{
   std::vector<java::lang::Float> in;
   in.push_back(java::lang::Float(1.0f));
   in.push_back(java::lang::Float(2.3f));
   std::vector<java::lang::Double> out = Arrays().add(in);
   std::cout << "add: " << out.size() << ", " << out[0].doubleValue() << ", " << out[1].doubleValue() << std::endl;
   std::cout << "isNull: " << (out[2].getJavaObject() == NULL) << std::endl;
}

void twoDimPrimitive()
{
   std::vector < std::vector<float> > in;
   std::vector<float> elem1;
   elem1.push_back(1);
   elem1.push_back(2);
   in.push_back(elem1);
   std::vector<float> elem2;
   elem2.push_back(3);
   elem2.push_back(4);
   elem2.push_back(5);
   in.push_back(elem2);
   std::vector < std::vector<float> > out = Arrays().identity(in);
   std::cout << "identity: " << out.size() << ", " << out[0].size() << ", " << out[1].size() << std::endl;
   std::cout << out[0][0] << ", " << out[1][2] << std::endl;
}

void threeDimObject()
{
   std::vector < std::vector<std::vector<std::string> > > in;
   std::vector < std::vector<std::string> > elem1;
   std::vector < std::string > elem2;
   elem2.push_back("string");
   elem1.push_back(elem2);
   in.push_back(elem1);
   std::vector < std::vector<std::vector<std::string> > > out = Arrays().whatFor(in);
   std::cout << "three dims: " << out.size() << ", " << out[0].size() << ", " << out[0][0].size() << std::endl;
   std::cout << out[0][0][0] << std::endl;
}
