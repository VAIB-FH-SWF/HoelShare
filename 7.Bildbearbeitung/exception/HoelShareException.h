//==========================================================
//
//	  Filename:	HoelShareException.h
//
// Description: Definition der HoelShareException
//              Oberklasse fuer die Selbst geschriebene exceptions
//              Alle selbst geschriebenen Exceptions erben von dieser
//
//	   Version:	1.0
// 	   Created:	29.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================
#ifndef HOELSHAREEXCEPTION_H_
#define HOELSHAREEXCEPTION_H_

#include <string>

/**
 * Oberklasse fuer die Selbst geschriebene exceptions
 * Alle selbst geschriebenen Exceptions erben von dieser
 */
class HoelShareException: public std::exception
{
   public:
      HoelShareException (std::string error = "");
      virtual ~HoelShareException () throw ();
      virtual const char* what ( ) const throw ( );
   protected:
      std::string err_msg;
};



#endif /* HOELSHAREEXCEPTION_H_ */
