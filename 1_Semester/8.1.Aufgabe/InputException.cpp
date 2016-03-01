//==========================================================
//
//	  Filename:	InputException.cpp
//
// Description: Implementierung der InputException
//
//	   Version:	1.0
// 	   Created:	31.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include "InputException.h"

/**
 * Standardkonstruktor
 */
InputException::InputException ( ) :
      HoelShareException("Error while reading Input!")
{
}

