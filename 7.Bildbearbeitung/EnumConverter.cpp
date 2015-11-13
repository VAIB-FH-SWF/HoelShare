//==========================================================
//
//	  Filename:	EnumConverter.cpp
//
// Description: Convertiert Enums in String und andersherum
//
//	   Version:	1.0
// 	   Created:	31.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include "head\EnumConverter.h"
#include <string>

using namespace std;

/**
 * Wandelt den String in einen Enum um
 */
FILETYPE EnumConverter::getFiletype(string filetype)
{
   if (filetype == "P2")
   {
      return (P2);
   }
   else
   {
      return (UNKNOWN);
   }
}

/**
 * Wandelt den Enum in einen String um
 */
const char* EnumConverter::toString(FILETYPE filetype)
{
   switch (filetype)
   {
      case P2:
         return ("P2");
      default:
         return ("UNKNOWN");
   }
}
