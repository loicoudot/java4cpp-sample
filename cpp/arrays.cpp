/*
 * arrays.cpp
 *
 *  Created on: 19 oct. 2013
 *      Author: Loic Oudot
 */

#include <iostream>
#include <time.h>
#include "java4cpp/java_classes.h"
#include "testsunit.h"
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
   strings();
}

void oneDimPrimitive()
{
   std::cout << "oneDimPrimitive: ";

   std::vector<long long> out = Arrays().negate(make_vector<int>(3, -1, 0, 1));
   assertThat(out).containsExactly(3, 1LL, 0LL, -1LL);

   std::vector<bool> out1 = Arrays().invert(make_vector<bool>(2, true, false));
   assertThat(out1).containsExactly(2, false, true);

   std::vector<float> in2;
   in2.push_back(0);
   in2.push_back(1);
   in2.push_back(2);
   std::vector<double> out2 = Arrays().add(in2);
   assertThat(out2).containsExactly(3, 0.5, 1.5, 2.5);
   
   std::cout << "ok" << std::endl;
}

void oneDimObject()
{
   std::cout << "oneDimObject: ";
   std::vector<java::lang::Float> in;
   in.push_back(java::lang::Float(1.0f));
   in.push_back(java::lang::Float(2.3f));
   std::vector<java::lang::Double> out = Arrays().add(in);
   assertThat(out).hasSize(3);
   assertThat(out[0].doubleValue()).isEqualTo(1.5);
   assertThat(out[1].doubleValue()).isEqualTo(2.8);
   assertThat(out[2].getJavaObject()).isNull();
   std::cout << "ok" << std::endl;
}

void twoDimPrimitive()
{
   std::cout << "twoDimPrimitive: ";
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
   assertThat(out).hasSize(2);
   assertThat(out[0]).hasSize(2);
   assertThat(out[1]).hasSize(3);
   assertThat(out[0][0]).isEqualTo(1);
   assertThat(out[1][2]).isEqualTo(5);
   std::cout << "ok" << std::endl;
}

void threeDimObject()
{
   std::cout << "threeDimObject: ";
   std::vector < std::vector<std::vector<std::string> > > in;
   std::vector < std::vector<std::string> > elem1;
   std::vector < std::string > elem2;
   elem2.push_back("string");
   elem1.push_back(elem2);
   in.push_back(elem1);
   std::vector < std::vector<std::vector<std::string> > > out = Arrays().whatFor(in);
   assertThat(out).hasSize(1);
   assertThat(out[0]).hasSize(1);
   assertThat(out[0][0]).hasSize(1);
   assertThat(out[0][0][0]).isEqualTo("test");
   std::cout << "ok" << std::endl;
}

void strings()
{
   std::cout << "strings: ";
   assertThat(Arrays().diacritic()).isEqualTo("&é§èçà$€");
   std::cout << "ok" << std::endl;
}
