//==========================================================
//
//	  Filename:	InputException.h
//
// Description: Definition der InputException
//
//	   Version:	1.0
// 	   Created:	29.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================
#ifndef INPUTEXCEPTION_H_
#define INPUTEXCEPTION_H_

#include "HoelShareException.h"

class InputException : public HoelShareException
{
   public:
      InputException();
};


#endif /* INPUTEXCEPTION_H_ */
