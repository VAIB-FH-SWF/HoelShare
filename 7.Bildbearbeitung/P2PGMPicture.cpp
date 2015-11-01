//==========================================================
//
//	  Filename:	P2PGMPicture.cpp
//
// Description: Laedt und speichert ein Bild im P2 Format
//
//	   Version:	1.0
// 	   Created:	31.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include "head\InputHandler.h"
#include "head\Picture.h"
#include "head\P2PGMPicture.h"
#include "head\EnumConverter.h"
#include "head\FILETYPE.h"
#include "exception/NotImplementedException.h"
#include "exception/InvalidPictureException.h"
#include "exception/FileNotFoundException.h"

using namespace std;

/**
 * Ladekontruktor
 */
P2PGMPicture::P2PGMPicture (InputHandler* inputHandle)
{
   this->inputHandle = inputHandle;
   this->filetype = P2;
   loadData();
}

/**
 * Kopier Konstruktor
 */
P2PGMPicture::P2PGMPicture (const Picture* origPic)
{
   this->filename = origPic->getFilename();
   this->filetype = origPic->getFiletype();
   this->greydepth = origPic->getGreydepth();
   this->height = origPic->getHeight();
   this->width = origPic->getWidth();
   this->data = new Pixel*[this->height];
   for (int row = 0; row < this->height; row++)
   {
      // Speicher pro Zeile beschaffen
      this->data[row] = new Pixel[this->width];
      for (int col = 0; col < this->width; col++)
      {
         this->data[row][col] = origPic->getData(row, col);
      }
   }
}

/**
 * Leerer Destruktor
 */
P2PGMPicture::~P2PGMPicture ()
{
   // Der Data Pointer wird im Destruktor von Picture freigegeben
}

/**
 * Speichert das Bild im P2 Format
 * Dateityp
 * Breite Hoehe
 * Maximale Grautiefe
 * [Breite*Hoehe] Grauwerte
 *
 * Laut Dateibeschreibung ist die Position eines Zeilenumbruchs nicht von
 * bedeutung und wird oft nach max 75 Zeichen gesetzt
 */
void P2PGMPicture::savePicture (std::string filename)
{
   ofstream dateiStream;
   dateiStream.open(filename.c_str());
   int ausgaben = 0;
   if(!dateiStream)
   {
      throw FileNotFoundException(filename.c_str());
   }
   dateiStream << EnumConverter::toString(this->filetype) << endl;
   dateiStream << this->width << " ";
   dateiStream << this->height << endl;
   dateiStream << this->greydepth << endl;
   dateiStream << right;
   for(int row = 0; row < this->height; row++)
   {
      for(int col = 0; col < this->width; col++)
      {
         dateiStream << " " << setw(3) << (int) (this->data[row][col]);
         if(++ausgaben % 18 == 0)    // Eine Zeile darf maximal 75 Zeichen beeinhalten
         {
            dateiStream << endl;
         }
      }
   }
   dateiStream.flush();
   dateiStream.close();
}

/**
 * Laedt das Bild im P2 Format
 * Format (bereits gelesen an diesem Punkt)
 * Breite Hoehe
 * Maximale Grautiefe
 * [Hoehe*Breite] Grauwerte
 */
void P2PGMPicture::loadData ( )
{
   // Der Filetyp wurde bereits ausgelesen!
   this->width = inputHandle->readInt();
   this->height = inputHandle->readInt();
   this->greydepth = inputHandle->readInt();
   // Dynamisch speicher beschaffen zum abspeichern der Bildpunkte
   this->data = new Pixel*[this->height];

   for (int row = 0; row < this->height; row++)
   {
      // Speicher pro Zeile beschaffen
      this->data[row] = new Pixel[this->width];
      for (int col = 0; col < this->width; col++)
      {
         this->data[row][col] = inputHandle->readInt();
      }
   }
}

/**
 * Prueft die Fachlichen Daten des Bildes
 */
bool P2PGMPicture::checkData()
{
   if(this->filetype != P2)
   {
      throw NotImplementedException(EnumConverter::toString(this->filetype));
   }
   if(this->greydepth < 0 || this->greydepth > 255)
   {
      throw InvalidPictureException();
   }
   return (true);
}
