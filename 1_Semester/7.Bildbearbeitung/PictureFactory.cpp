//==========================================================
//
//	  Filename:	PictureFactory.cpp
//
// Description: TODO	
//
//	   Version:	1.0
// 	   Created:	07.11.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include "head/PictureFactory.h"
#include "head/Picture.h"
#include "head/EnumConverter.h"
#include "head/FILETYPE.h"
#include "head/P2PGMPicture.h"
#include "exception/FileNotFoundException.h"
#include "exception/NotImplementedException.h"
#include "exception/InvalidPictureException.h"
#include "exception/InputException.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <iomanip>
/**
 * Laedt das Bild im entsprechende Bild
 */
Picture* PictureFactory::create(std::string filename)
{
   Picture* picture;
   std::ifstream dateiStream;
   dateiStream.open(filename.c_str());

   if (!dateiStream)
   {
      throw FileNotFoundException(filename.c_str());
   }
   InputHandler       inputHandle(&dateiStream);
   // Wenn beim einlesen einer Zahl ein Fehler auftritt, dann wird eine
   // InvalidPictureException geworfen
   try
   {
      FILETYPE filetype = EnumConverter::getFiletype(inputHandle.readString());
      switch(filetype)
      {
         case P2:
            picture = new P2PGMPicture(&inputHandle);
            break;
         case UNKNOWN:
         default:
            dateiStream.close();
            throw NotImplementedException(EnumConverter::toString(UNKNOWN));
      }
   }
   catch (InputException &ex)
   {
      dateiStream.close();
      throw InvalidPictureException();
   }

   dateiStream.close();
   return (picture);

}

/**
 * Ruft den entsprechenden Konstruktor auf und gibt eine Kopie des Objekts zurueck
 */
Picture* PictureFactory::copyPicture(const Picture* orig)
{
   Picture* picture;
   switch(orig->getFiletype())
   {
      case P2:
         picture = new P2PGMPicture(orig);
         break;
      case UNKNOWN:
      default:
         throw NotImplementedException(EnumConverter::toString(UNKNOWN));
         break;
   }
   return (picture);
}
