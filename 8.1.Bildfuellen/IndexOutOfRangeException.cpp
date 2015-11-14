//==========================================================
//
//	  Filename:	IndexOutOfRangeException.cpp
//
// Description: Implementierung der IndexOutOfRangeException
//
//	   Version:	1.0
// 	   Created:	31.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include "IndexOutOfRangeException.h"
#include <string>
#include <iostream>
#include <sstream>

/**
 * Standard Konstruktor fuer eine IndexOutOfRangeException
 */
IndexOutOfRangeException::IndexOutOfRangeException(int index) : HoelShareException("")
{
   this->index = index;
   std::stringstream sStream;
   sStream << "Index[" << index << "] out of Range";
   this->err_msg = sStream.str();
}

