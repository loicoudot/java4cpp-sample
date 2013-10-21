#include <iostream>
#include "javawrapper.h"
#include "java4cpp/java_classes.h"
#include "allocation.h"
#include "superclass.h"
#include "enumeration.h"
#include "arrays.h"
#include "exceptionHandling.h"
#include "benchmark.h"


/*
template<typename T>
class Java4CppList
{
public:

	Java4CppList(jobject obj) {
		setJavaObject(obj);
	}

	~Java4CppList()
	{
	   JNIEnv *javaEnv = Java4CppRuntime::attachCurrentThread();
	   if(javaEnv)
	      javaEnv->DeleteGlobalRef(_obj);
	}

	void setJavaObject(jobject obj)
	{
	   if( _obj != NULL )
	   {
	      JNIEnv *javaEnv = Java4CppRuntime::attachCurrentThread();
	      if(javaEnv)
	         javaEnv->DeleteGlobalRef(_obj);
	   }
	   if( obj != NULL )
	   {
	      JNIEnv *javaEnv = Java4CppRuntime::attachCurrentThread();
	      if(javaEnv)
	         _obj = javaEnv->NewGlobalRef(obj);
	   }
	   else
	      _obj = NULL;
	}

	void clear() {
		JNIEnv *javaEnv = Java4CppRuntime::attachCurrentThread();
		jclass cls = Java4CppRuntime::getClass(javaEnv, "java/util/List");
		jmethodID mid = Java4CppRuntime::getMethodID(javaEnv, cls, "clear", "()V");
		javaEnv->CallVoidMethod(_obj, mid);
		Java4CppRuntime::handleJavaException(javaEnv);
	}

	size_t size() const {
		JNIEnv *javaEnv = Java4CppRuntime::attachCurrentThread();
		jclass cls = Java4CppRuntime::getClass(javaEnv, "java/util/List");
		jmethodID mid = Java4CppRuntime::getMethodID(javaEnv, cls, "size", "()I");
		jint jresult = javaEnv->CallIntMethod(_obj, mid);
		Java4CppRuntime::handleJavaException(javaEnv);
		return (size_t)jresult;
	}

	bool empty() const {
	   JNIEnv *javaEnv = Java4CppRuntime::attachCurrentThread();
	   jclass cls = Java4CppRuntime::getClass(javaEnv, "java/util/List");
	   jmethodID mid = Java4CppRuntime::getMethodID(javaEnv, cls, "isEmpty", "()Z");
	   jboolean jresult = javaEnv->CallBooleanMethod(_obj, mid);
	   Java4CppRuntime::handleJavaException(javaEnv);
	   return (bool)jresult;
	}

	const T& operator[](int pos) const {
		JNIEnv *javaEnv = Java4CppRuntime::attachCurrentThread();
		jclass cls = Java4CppRuntime::getClass(javaEnv, "java/util/List");
		jmethodID mid = Java4CppRuntime::getMethodID(javaEnv, cls, "get", "(I)Ljava/lang/Object;");
		jobject jresult = (jobject)javaEnv->CallObjectMethod(_obj, mid, (jint)pos);
		Java4CppRuntime::handleJavaException(javaEnv);
		T result;
		if (jresult != NULL) {
			jclass cls1 = Java4CppRuntime::getClass(javaEnv, "Ljava/lang/Integer;");
			jmethodID mid1 = Java4CppRuntime::getMethodID(javaEnv, cls1, "intValue", "()I");
			result = (int)javaEnv->CallIntMethod(jresult, mid1);
			javaEnv->DeleteLocalRef(jresult);
		}
		return result;
	}

	void push_back(const T& arg1) {
	   JNIEnv *javaEnv = Java4CppRuntime::attachCurrentThread();
	   jclass cls = Java4CppRuntime::getClass(javaEnv, "java/util/List");
	   jmethodID mid = Java4CppRuntime::getMethodID(javaEnv, cls, "add", "(Ljava/lang/Object;)Z");
	   jobject jarg1 = NULL;
	   if (arg1) {
	   	jclass cls1 = Java4CppRuntime::getClass(javaEnv, "Ljava/lang/Integer;");
	   	jmethodID mid1 = Java4CppRuntime::getStaticMethodID(javaEnv, cls1, "valueOf", "(I)Ljava/lang/Integer;");
	   	jarg1 = javaEnv->CallStaticObjectMethod(cls1, mid1, (jint)arg1.get());
	   }
	   javaEnv->CallBooleanMethod(_obj, mid, jarg1);
	   Java4CppRuntime::handleJavaException(javaEnv);
	}

	class const_iterator {
	public:
		typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;

		const_iterator(jobject obj, int pos) {
			_obj = obj;
			_pos = pos;
		}

		bool operator==(const const_iterator& other) const {
			return _pos == other._pos;
		}

		bool operator!=(const const_iterator& other) const {
			return _pos != other._pos;
		}

		bool operator<(const const_iterator& other) const {
			return _pos < other._pos;
		}

		const_iterator& operator=(const const_iterator& other) {
			_obj = other._obj;
			_pos = other._pos;
			return *this;
		}

		const_iterator& operator--() {
			--_pos;
			return *this;
		}

		const_iterator operator--(int) {
			return const_iterator(_obj, _pos-1);
		}

		const_iterator& operator++() {
			++_pos;
			return *this;
		}

		const_iterator operator++(int) {
			return const_iterator(_obj, _pos+1);
		}

		const_iterator operator+(ptrdiff_t dist) {
			return const_iterator(_obj, _pos+dist);
		}

		ptrdiff_t operator-(const const_iterator& other) const {
			return other._pos - _pos;
		}

		const_iterator operator-(ptrdiff_t dist) {
			return const_iterator(_obj, _pos-dist);
		}

		T operator*() {
			JNIEnv *javaEnv = Java4CppRuntime::attachCurrentThread();
			jclass cls = Java4CppRuntime::getClass(javaEnv, "java/util/List");
			jmethodID mid = Java4CppRuntime::getMethodID(javaEnv, cls, "get", "(I)Ljava/lang/Object;");
			jobject jresult = (jobject)javaEnv->CallObjectMethod(_obj, mid, (jint)_pos);
			Java4CppRuntime::handleJavaException(javaEnv);
			T result;
			if (jresult != NULL) {
				jclass cls1 = Java4CppRuntime::getClass(javaEnv, "Ljava/lang/Integer;");
				jmethodID mid1 = Java4CppRuntime::getMethodID(javaEnv, cls1, "intValue", "()I");
				result = (int)javaEnv->CallIntMethod(jresult, mid1);
				javaEnv->DeleteLocalRef(jresult);
			}
			return result;
		}

	private:
		jobject _obj;
		int _pos;
	};

	const_iterator begin() const {
		return const_iterator(_obj, 0);
	}

	const_iterator end() const {
		return const_iterator(_obj, size());
	}

private:
	jobject _obj;
};
*/
int main(void)
{
	jw_addClassPath("../jars/java4cpp-sample-0.0.1-SNAPSHOT.jar");

	//allAllocation();
	//allSuperclass();
	//allEnumeration();
	allArrays();
	//allExceptionHandling();
	//allBenchmark();

	return 0;
}
