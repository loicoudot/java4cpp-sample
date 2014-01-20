//
//  testsunit.h
//  xcode5sample
//
//  Created by Loïc Oudot on 10/01/2014.
//  Copyright (c) 2014 java4cpp. All rights reserved.
//

#ifndef xcode5sample_testsunit_h
#define xcode5sample_testsunit_h

#include <stdexcept>
#include <sstream>
#include <math.h>

template<typename T>
class Assert
{
private:
   T _actual;
   
public:
   Assert(T actual) : _actual(actual) {}
   
   void isEqualTo(T expected) {
      if (expected != _actual) {
         std::ostringstream oss;
         oss << std::endl << "Error: expected " << expected << ", but was " << _actual;
         throw std::runtime_error(oss.str());
      }
   }

   void isNotEqualTo(T expected) {
      if (expected == _actual) {
         std::ostringstream oss;
         oss << std::endl << "Error: expected " << _actual << ", not to be equal to " << expected;
         throw std::runtime_error(oss.str());
      }
   }

   
   void isFalse() {
      isEqualTo(false);
   }
   
   void isTrue() {
      isEqualTo(true);
   }
   
   void isNull() {
      isEqualTo(NULL);
   }
   
   void isNotNull() {
      isNotEqualTo(NULL);
   }
};

template<>
inline void Assert<double>::isEqualTo(double expected) {
   if (fabs(expected - _actual) > 1e-5) {
      std::ostringstream oss;
      oss << std::endl << "Error: expected " << expected << ", but was " << _actual;
      throw std::runtime_error(oss.str());
   }
}

template<typename T>
std::vector<T> make_vector(int size, ...) {
   std::vector<T> result;
   va_list ap;
   va_start(ap, size);
   for(int j = 0; j < size; j++)
      result.push_back(va_arg(ap, T));
   va_end(ap);
   return result;
}

template<typename T>
std::ostream& operator<<(std::ostream& str, std::vector<T>& vector)
{
   std::string sep = "[";
   for(typename std::vector<T>::const_iterator it = vector.begin(); it != vector.end(); ++it) {
      str << sep << *it;
      sep = ", ";
   }
   str << ']';
   return str;
}

template<typename T>
class VectorAssert
{
private:
   typedef std::vector<T> type;
   type _actual;
   
public:
   VectorAssert(std::vector<T> actual) : _actual(actual) {}

   void hasSize(int size) {
      if (_actual.size() != size) {
         std::ostringstream oss;
         oss << std::endl << "Error: expected size of " << size << ", but was " << _actual.size();
         throw std::runtime_error(oss.str());
      }
   }
   
   void containsExactly(int size, ...) {
      va_list ap;
      std::vector<T> expected;
      va_start(ap, size);
      for(int j = 0; j < size; j++)
         expected.push_back(va_arg(ap, T));
      va_end(ap);
      if (_actual != expected) {
         std::ostringstream oss;
         oss << std::endl << "Error: expected " << expected << ", but was " << _actual;
         throw std::runtime_error(oss.str());
      }
   }
};

template<typename T>
Assert<T> assertThat(T expected) {
   return Assert<T>(expected);
}

template<typename T>
VectorAssert<T> assertThat(std::vector<T> expected) {
   return VectorAssert<T>(expected);
}

#endif
