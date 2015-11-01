//==========================================================
//
//	  Filename:	Picture.cpp
//
// Description: Oberklasse fuer Bilder
//              Die Bildbearbeitungsmethoden sind ebenfalls hier beschrieben
//
//	   Version:	1.0
// 	   Created:	28.10.2015
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//
//==========================================================
#include "head\Picture.h"
#include "head\PGMPicture.h"
#include "head\P2PGMPicture.h"
#include "exception\FileNotFoundException.h"
#include "exception\InvalidPictureException.h"
#include "exception\NotImplementedException.h"
#include "exception\InputException.h"
#include "exception\IndexOutOfRangeException.h"
#include "head\InputHandler.h"
#include "head\EnumConverter.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>

using namespace std;

/**
 * Erstellt eine Kopie des Bildes, in der Pixel fuer Pixel invertiert wird
 * Invertiert = Maximales Grau - aktuelles Grau
 */
Picture* Picture::invertieren() const
{
   Picture* p = copyPicture(this);

   for(int row = 0; row < p->height; row++)
   {
      for(int col = 0; col < p->width; col++)
      {
         p->data[row][col] = p->greydepth - p->data[row][col];
      }
   }
   return (p);
}

/**
 * Erstellt eine geglaettete Kopie des Bildes
 * Zum glaetten wird der Mittelwert aus den umliegenden Pixeln berechnet
 */
Picture* Picture::glaetten() const
{
   Picture* p = copyPicture(this);
   int sum, anz = 0;
   for (int row = 0; row < p->height; row++)
   {
      for (int col = 0; col < p->width; col++)
      {
         sum = anz = 0;
         // Von Zeile - 1 bis Zeile + 1
         // falls diese im Bereich des Bildes sind
         for (int tRow = max(0, row - 1); tRow < min(p->height, row + 1); tRow++)
         {
            // Von Spalte - 1 bis Spalte + 1
            // falls diese im Bereich des Bildes sind
            for (int tCol = max(0, col - 1); tCol < min(p->width, col + 1);
                  tCol++)
            {
               // Summe und Anzahl erhoehen
               sum += this->data[tRow][tCol];
               anz++;
            }
         }
         // Den mittelwert berechnen und das Ergebnis runden
         p->data[row][col] = round(((double) sum) / anz);
      }
   }

   return (p);
}

/**
 * Erstellt eine Kopie des Objektes, bei denen die Kanten hervorgehoben sind
 * Dazu wird ueber die umliegenden Pixel eine Gewichtungsmatrix gelegt
 *  0 -1  0
 * -1 +4 -1
 *  0 -1  0
 */
Picture* Picture::kantenErkennung() const
{
   Picture* p = copyPicture(this);
   int sum, anz, anzDirekterNachbar;
   for (int row = 0; row < p->height; row++)
   {
      for (int col = 0; col < p->width; col++)
      {
         // Prueft ob das Feld im Bereich des Bildes liegt und summiert im Erfolgsfall
         // Erhoet dann ebenfalls die Anzahl
         sum = anz = anzDirekterNachbar = 0;
         for (int tRow = max(0, row - 1); tRow < min(p->height, row + 1); tRow++)
         {
            // Von Spalte - 1 bis Spalte + 1
            // falls diese im Bereich des Bildes sind
            for (int tCol = max(0, col - 1); tCol < min(p->width, col + 1);
                  tCol++)
            {
               // Summe und Anzahl erhoehen
               // Wenn der Pixel in der gleichen Spalte oder Reihe ist,
               // und nicht gleich der Pixel in der Mitte ist
               if ((tRow == row || tCol == col)
                     && !(tRow == row && tCol == col))
               {
                  sum -= this->data[tRow][tCol];
                  anzDirekterNachbar++;
               }
               anz++;
            }
         }
         // Der mittlere Pixel wird mit der Anzahl der Umgebungspixel Multipliziert
         // An dieser Stelle bin ich davon ausgegangen, das dieser mit der Anzahl 5
         // Gewichtet wird
         sum += (anzDirekterNachbar * this->data[row][col]);

         p->data[row][col] = abs(round(((double) sum) / anz));
      }
   }
   return (p);
}

/**
 * Erstellt eine geschaerfte Kopie des Bildes
 * Dazu wird ueber die umliegenden Pixel eine Gewichtungsmatrix gelegt
 * -1 -1 -1
 * -1 +9 -1
 * -1 -1 -1
 */
Picture* Picture::schaerfen() const
{
   Picture* p = copyPicture(this);
   int sum, anz;
   for (int row = 0; row < p->height; row++)
   {
      for (int col = 0; col < p->width; col++)
      {
         sum = anz = 0;
         // Von Zeile - 1 bis Zeile + 1
         // falls diese im Bereich des Bildes sind
         for (int tRow = max(0, row - 1); tRow < min(p->height, row + 1); tRow++)
         {
            // Von Spalte - 1 bis Spalte + 1
            // falls diese im Bereich des Bildes sind
            for (int tCol = max(0, col - 1); tCol < min(p->width, col + 1);
                  tCol++)
            {
               // Wenn die aktuelle Zeile/Spalte <> der eigentlichen Zeile/Spalte ist,
               // wird der Wert mit -1 Multipliziert und dann addiert
               if(row != tRow || col != tCol)
               {
                  sum -= this->data[tRow][tCol];
                  anz++;
               }
            }
         }
         // der Wert wird mit Anzahlumliegende Felder +1 multipliziert
         sum += this->data[row][col] * (anz + 1);
         // Wenn der Wert kleiner als 0 ist wird dieser zu 0
         // Wenn der Wert groeser als der Max. Grauwird wird dieser zu diesem
         // Ansonsten wird der Wert uebernommen
         sum = (sum < 0 ? 0 : sum > p->greydepth ? p->greydepth : sum);
         p->data[row][col] = sum;
      }
   }

   return (p);
}

/**
 * Gibt den Speicher des Bildes wieder frei
 */
Picture::~Picture()
{
   // Speicher wieder freigeben
   for (int row = 0; row < this->height; row++)
   {
      delete[] this->data[row];
   }
   delete[] this->data;
}

/**
 * Laedt das Bild im entsprechende Bild
 */
Picture* Picture::loadPicture(string filename)
{
   Picture* picture;
   ifstream dateiStream;
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
      throw InvalidPictureException();
   }

   dateiStream.close();
   return (picture);
}

/**
 * Ruft den entsprechenden Konstruktor auf und gibt eine Kopie des Objekts zurueck
 */
Picture* Picture::copyPicture(const Picture* orig)
{
   Picture* picture;
   switch(orig->filetype)
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

/**
 * Gibt die Breite des Bildes zurueck
 */
int Picture::getWidth ( ) const
{
   return (this->width);
}

/**
 * Gibt die Hoehe des Bildes zurueck
 */
int Picture::getHeight ( ) const
{
   return (this->height);
}

/**
 * Gibt die maximale Grautiefe zurueck
 */
int Picture::getGreydepth( ) const
{
   return (this->greydepth);
}

/**
 * Gibt den Dateinamen zurueck
 */
std::string Picture::getFilename ( ) const
{
   return (this->filename);
}

/**
 * Gibt den Dateityp zurueck
 */
FILETYPE Picture::getFiletype ( ) const
{
   return (this->filetype);
}

/**
 * Gibt die Grautiefe des Pixels an der Stelle [row, col] zurueck
 */
Pixel Picture::getData (int row, int col) const
{
   if(row > getHeight() || row < 0)
   {
      throw IndexOutOfRangeException(row);
   }
   if(col > getWidth() || col < 0)
   {
      throw IndexOutOfRangeException(col);
   }
   return (this->data[row][col]);
}
