//==========================================================
//
//    Filename: NotImplementedException.cpp
//
// Description: Implementierung der NotImplementedException
//
//     Version: 1.0
//     Created: 31.10.2015
//    Compiler: g++
//
//      Author: Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include "NotImplementedException.h"

/**
 * Standardkonstruktor
 */
NotImplementedException::NotImplementedException (std::string _filetype) :
      HoelShareException(_filetype + " not implemented yet"), filetype(
            _filetype)
{
}

/**
 * Leerer Destruktor
 */
NotImplementedException::~NotImplementedException ( ) throw ( )
{
}
