//==========================================================
//
//	  Filename:	FileNotFoundException.cpp
//
// Description: Implementierung der FileNotFoundException
//
//	   Version:	1.0
// 	   Created:	31.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include <string>
#include "FileNotFoundException.h"


/**
 * Standard Konstruktor fuer eine FileNotFoundException
 */
FileNotFoundException::FileNotFoundException (const char* _filename) :
      HoelShareException("File [" + std::string(_filename) + "] not found!"), filename(
            _filename)
{
}

/**
 * Gibt den Dateinamen zurueck
 */
const char* FileNotFoundException::getFilename()
{
   return (this->filename);
}
