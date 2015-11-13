//==========================================================
//
//	  Filename:	InvalidPictureException.h
//
// Description: Definition der InvalidPictureException
//
//	   Version:	1.0
// 	   Created:	29.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================
#ifndef INVALIDPICTUREEXCEPTION_H_
#define INVALIDPICTUREEXCEPTION_H_

#include "HoelShareException.h"
#include <string>

class InvalidPictureException : public HoelShareException
{
   public:
      InvalidPictureException (std::string error = "");
};

#endif /* INVALIDPICTUREEXCEPTION_H_ */
