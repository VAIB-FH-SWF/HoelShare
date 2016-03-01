//==========================================================
//
//	  Filename:	DreieckException.h
//
// Description: Definition der DreiecksException
//
//	   Version:	1.0
// 	   Created:	19.10.2015 19:02:39
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================
#ifndef DREIECKEXCEPTION_H_
#define DREIECKEXCEPTION_H_

#include <iostream>
#include "Dreieck.h"

/**
 * Exceptions die bei der Erstellung von Dreiecken auftreten koennen
 */
class DreieckException: std::exception
{
   public:
      /**
       * Standard Konstruktor
       */
      DreieckException (Dreieck *dreieck = NULL, double zwischenergebnis = 0);

      /**
       * Gibt das aktuelle Dreieck oder NULL zurueck
       */
      Dreieck getDreieck();

      /**
       * Gibt das bis dahin berechnete Zwischenergbnis zurueck oder 0
       */
      double getZwischenergebnis();

   private:
      // Speichert das zwischenerbnis
      double zwischenergebnis;
      // Speichert das Dreieck
      Dreieck dreieck;
};

#endif /* DREIECKEXCEPTION_H_ */
