#ifndef JAVAWRAPPER_H_
#define JAVAWRAPPER_H_

#include <string>
#include "jni.h"

void jw_setJrePath(const std::string& jrePath);

void jw_clearOptions();

void jw_addOption(const std::string& option);

void jw_addOptionsFromFile(const std::string& fileName);

void jw_clearClassPath();

void jw_addClassPath(const std::string& path);

JavaVM* getJVM();

void setJVM(JavaVM* jvm);

#endif /* JAVAWRAPPER_H_ */
