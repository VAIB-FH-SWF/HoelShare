//==========================================================
//
//	  Filename:	InputHandler.cpp
//
// Description: Kuemmert sich um das EingabeHandling eines Streams
//
//	   Version:	1.0
// 	   Created:	28.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include "InputHandler.h"
#include "InputException.h"
#include <string.h>
#include <iostream>
#include <cstdlib>

/**
 * Liesst ueber die Konsole eine vollstaendige Zeile ein
 */
std::string InputHandler::readLine (std::string request)
{
   std::string zeile = "";
   if (!request.empty())
   {
      std::cout << request;
   }
   getline(this->is, zeile);
   return (zeile);
}

/**
 * Liesst ein String ueber den Eingabestream ein
 */
std::string InputHandler::readString (std::string request)
{
   std::string sObject = "";
   if (!request.empty())
   {
      std::cout << request;
   }
   this->is >> sObject;
   return (sObject);
}

/**
 * Liesst ein Zeichen ueber den Eingabestream ein
 */
char InputHandler::readChar (std::string request)
{
   char zeichen;
   if (!request.empty())
   {
      std::cout << request;
   }
   this->is >> zeichen;
   return (zeichen);
}

/**
 * liesst eine Zeile ein und versucht diese ohne Fehler in eine Gleitkommazahl
 * umzuwandeln, sollte ein Fehler auftreten, wird es erneut ueber die Console eingelesen
 */
double InputHandler::readDouble (std::string request)
{
   double value = 0;
   if (!request.empty())
   {
      std::cout << request;
   }
   this->is >> value;
   if(this->is.fail())
   {
      throw InputException();
   }
   return (value);
}

/**
 * Liesst eine Gleitkommazahl ein und schneidet den Dezimalteil ab
 */
int InputHandler::readInt (std::string request)
{
   return ((int) readDouble(request));
}

