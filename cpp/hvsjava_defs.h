#ifndef _HVSJAVADEF_H
   #define _HVSJAVADEF_H

   #include "os/hvsdefs.h"

   #if defined (BUILD_HVSJAVA)
      #define HVSJAVACLASS HVS_CLASS_EXPORT
      #define HVSJAVAFUNC  HVS_FUNCTION_EXPORT
   #else
      #define HVSJAVACLASS HVS_CLASS_IMPORT
      #define HVSJAVAFUNC  HVS_FUNCTION_IMPORT
   #endif

#endif
