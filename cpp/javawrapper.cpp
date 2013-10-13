#include <fstream>
#include <vector>
#include <dlfcn.h>

#include "javawrapper.h"
#include "stdexcept"

#define CLASS_PATH "-Djava.class.path="

typedef std::vector<std::string> JvmOptions;

JavaVM* _pVMJvm = NULL;
std::string _jrePath;
JvmOptions _options;
JvmOptions _classPath;

void jw_setJrePath(const std::string& jrePath)
{
   _jrePath = jrePath;
}

void jw_clearOptions()
{
   _options.clear();
}

void jw_addOption(const std::string& option)
{
   _options.push_back(option);
}

void jw_addOptionsFromFile(const std::string& fileName)
{
   std::ifstream file( fileName.c_str() );
   if( file.good() )
   {
      std::string option;
      while( std::getline(file, option) )
      {
         if( !option.empty() && option.at(0) != '#')
         {
            _options.push_back( option );
         }
      }
   }
}

void jw_clearClassPath()
{
   _classPath.clear();
}

void jw_addClassPath(const std::string& path)
{
   if( std::find(_classPath.begin(), _classPath.end(), path) != _classPath.end() )
   {
      return;
   }

   if( _pVMJvm != NULL )
   {
     // fr::harvest::hvsjava::RuntimeClassPath::add(path);
   }
   _classPath.push_back(path);
}

void setClassPath()
{
   std::string classPath = CLASS_PATH;

   // Recheche le classpath dans les options
   for(JvmOptions::iterator it = _options.begin(); it != _options.end(); ++it)
   {
      if( it->find(CLASS_PATH) != std::string::npos )
      {
         classPath = *it;
         _options.erase(it);
         break;
      }
   }

   for(JvmOptions::iterator it = _classPath.begin(); it != _classPath.end(); ++it)
   {
      if( classPath.find(*it) == std::string::npos )
      {
         if( classPath != CLASS_PATH )
            classPath += ";";
         classPath += *it;
      }
   }

   _options.push_back(classPath);
}

void initJVM()
{
   if( _pVMJvm != NULL )
      return;

   bool debug = false;
   JNIEnv* pVMEnv = NULL;
   try
   {
	   void *handle = dlopen("/System/Library/Java/JavaVirtualMachines/1.6.0.jdk/Contents/Libraries/libserver.dylib", RTLD_NOW);
		typedef jint (*JNI_GetCreatedJavaVMs_t)(JavaVM **, jsize, jsize *);
		JNI_GetCreatedJavaVMs_t JNI_GetCreatedJavaVMs = (JNI_GetCreatedJavaVMs_t)dlsym(handle, "JNI_GetCreatedJavaVMs_Impl");

      // try to get an already created JVM
      jsize nbVMs = 0;
      JNI_GetCreatedJavaVMs(&_pVMJvm, 1, &nbVMs);
      if( nbVMs == 0 )
      {
          // Else : create a new JVM
         setClassPath();
         long nbOptions = (long)_options.size();
         JavaVMOption *aOptions = new JavaVMOption[nbOptions];
         for( long i = 0; i < nbOptions; ++i )
         {
            if( _options[i] == "-Xdebug" )
               debug = true;
            aOptions[i].optionString = (char*)_options[i].c_str();
         }

         JavaVMInitArgs oVMArgs;
         memset(&oVMArgs, 0, sizeof(oVMArgs));
         oVMArgs.version = JNI_VERSION_1_6;
         oVMArgs.nOptions = nbOptions;
         oVMArgs.options = aOptions;

         // Get the CreateJavaVM procedure address
         typedef jint (*JNI_CreateJavaVM_t)(JavaVM **pvm, void **penv, void *args);

         JNI_CreateJavaVM_t JNI_CreateJavaVM = (JNI_CreateJavaVM_t)dlsym(handle, "JNI_CreateJavaVM_Impl");
         jint res = JNI_CreateJavaVM(&_pVMJvm, (void**)&pVMEnv, (void*)&oVMArgs);

         delete[] aOptions;

      }
      else
      {
      }
   }
   catch( ... )
   {
   }
}

JavaVM* getJVM()
{
   if( _pVMJvm == NULL )
      initJVM();

   if( _pVMJvm == NULL )
      throw std::runtime_error("getJVM: Pas de JVM.");

   return _pVMJvm;
}

void setJVM(JavaVM* jvm)
{
   _pVMJvm = jvm;
}

//--------------------------------------------------------------------
// End of file
//--------------------------------------------------------------------
