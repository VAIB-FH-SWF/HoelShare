//==========================================================
//
//	  Filename:	FILETYPE.h
//
// Description: Definition des EnumConverters
//
//	   Version:	1.0
// 	   Created:	31.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================
#ifndef ENUMCONVERTER_H_
#define ENUMCONVERTER_H_

#include "FILETYPE.h"
#include <string>

class EnumConverter
{
   public:
      static FILETYPE getFiletype (std::string);
      static const char* toString (FILETYPE);
};

#endif /* ENUMCONVERTER_H_ */
