//==========================================================
//
//	  Filename:	HoelShareException.cpp
//
// Description: Implementierung der HoelShareException
//              Oberklasse fuer die Selbst geschriebene exceptions
//              Alle selbst geschriebenen Exceptions erben von dieser
//
//	   Version:	1.0
// 	   Created:	31.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include "HoelShareException.h"
#include <string>

using namespace std;

/**
 * Standardkonstruktor fuer eine HoelShareException
 */
HoelShareException::HoelShareException(string error)
{
   this->err_msg = error;
}

/**
 * Leerer Destruktor
 */
HoelShareException::~HoelShareException ( ) throw ( )
{
}

/**
 * Liefert die Errormessage zurueck
 */
const char* HoelShareException::what ( ) const throw ( )
{
   return (this->err_msg.c_str());
}
