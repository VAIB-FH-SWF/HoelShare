//==========================================================
//
//	  Filename:	InputHandler.h
//
// Description: Datei zur Definition des Eingabe Handlings
//
//	   Version:	1.0
// 	   Created:	19.10.2015 17:51:25
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================
#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_

#include <string>
#include "Dreieck.h"

class InputHandler
{
   public:
      /**
       * Verarbeitet die Eingabe und gibt eine Ganzzahl zurueck
       */
      static int leseGanzzahl(std::string aufforderung = "");
      /**
       * Verarbeitet die Eingabe und gibt eine Gleitkommazahl zurueck
       */
      static double leseGleitkomma(std::string aufforderung = "");
      /**
       * Verarbeitet die Eingabe und gibt diese als String zurueck
       */
      static std::string leseString(std::string aufforderung = "");

      /**
       * Liesst die drei Seiten eines Dreiecks ein
       */
      static Dreieck leseDreieck();
};



#endif /* INPUTHANDLER_H_ */
