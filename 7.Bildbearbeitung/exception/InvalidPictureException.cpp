//==========================================================
//
//	  Filename:	InvalidPictureException.cpp
//
// Description: Implementierung der InvalidPictureException
//
//	   Version:	1.0
// 	   Created:	31.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include "InvalidPictureException.h"

/**
 * Standardkonstruktor
 */
InvalidPictureException::InvalidPictureException (std::string error) :
      HoelShareException(
            "Could not load the Picture" + (error.empty() ? "" : ": " + error))
{
}
