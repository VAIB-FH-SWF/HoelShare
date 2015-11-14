//==========================================================
//
//	  Filename:	IndexOutOfRangeException.h
//
// Description: Definition der IndexOutOfRangeException
//
//	   Version:	1.0
// 	   Created:	31.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================
#ifndef EXCEPTION_INDEXOUTOFRANGEEXCEPTION_H_
#define EXCEPTION_INDEXOUTOFRANGEEXCEPTION_H_

#include "HoelShareException.h"
#include <string>

class IndexOutOfRangeException : public HoelShareException
{
   public:
      IndexOutOfRangeException (int);
   protected:
      int index;
};

#endif /* EXCEPTION_INDEXOUTOFRANGEEXCEPTION_H_ */
