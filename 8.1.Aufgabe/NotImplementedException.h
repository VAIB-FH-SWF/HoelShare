//==========================================================
//
//	  Filename:	NotImplementedException.h
//
// Description: Definition der NotImplementedException
//
//	   Version:	1.0
// 	   Created:	29.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================
#ifndef NOTIMPLEMENTEDEXCEPTION_H_
#define NOTIMPLEMENTEDEXCEPTION_H_

#include "HoelShareException.h"
#include <string>

class NotImplementedException : public HoelShareException
{
   public:
      NotImplementedException (std::string _filetype);
      virtual ~NotImplementedException ( ) throw ( );
   private:
      std::string filetype;
};


#endif /* NOTIMPLEMENTEDEXCEPTION_H_ */
