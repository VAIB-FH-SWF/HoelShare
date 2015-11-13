//==========================================================
//
//	  Filename:	DreieckException.cpp
//
// Description: Implementierung der DreiecksException
//
//	   Version:	1.0
// 	   Created:	19.10.2015 19:20:19
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================
#include "Dreieck.h"
#include "DreieckException.h"


/**
 * Standard Konstruktor fuer die Dreiecksexception
 */
DreieckException::DreieckException(Dreieck *dreieck, double zwischenergebnis)
{
   this->zwischenergebnis = zwischenergebnis;
   this->dreieck = *dreieck;
}

/**
 * Gibt das entsprechende Dreieck oder NULL zurueck
 */
Dreieck DreieckException::getDreieck()
{
   return (this->dreieck);
}

/**
 * Gibt das bis zur Exception berechnete Zwischenergebnis zurueck oder 0
 */
double DreieckException::getZwischenergebnis()
{
   return (this->zwischenergebnis);
}
