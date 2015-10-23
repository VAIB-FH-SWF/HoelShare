//==========================================================
//
//	  Filename:	Dreieck.cpp
//
// Description: Implementierung der Dreiecksdefintion
//
//	   Version:	1.0
// 	   Created:	19.10.2015 18:41:51
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================

#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include "Dreieck.h"
#include "DreieckException.h"

Dreieck::Dreieck (double a, double b, double c)
{
   this->laengeA = a;
   this->laengeB = b;
   this->laengeC = c;
}

/**
 * Berechnet die Hilfsvariable S
 * s = 0.5 * (a+b+c)
 */
double Dreieck::berechneHilfeS ( )
{
   return (0.5 * (this->laengeA + this->laengeB + this->laengeC));
}

/**
 * Berechnet den Flaecheninhalt des Dreiecks nach folgender Rechenregel:
 * A = WURZEL(s(s-a)(s-b)(s-c))
 * mit s = 0.5*(a+b+c)
 * Sollte der Ausdruck unter der Wurzel < 0 sein, wird eine Exception geworfen
 */
double Dreieck::berechneHeron1 ( )
{
   double zwischenergebnis = 0.0;
   double sHilfe = berechneHilfeS();
   zwischenergebnis = sHilfe * (sHilfe - laengeA) * (sHilfe - laengeB)
         * (sHilfe - laengeC);
   if (zwischenergebnis < 0)
   {
      throw DreieckException(this, zwischenergebnis);
   }
   return (sqrt(zwischenergebnis));
}

/**
 * Berechnet der den Flaecheninhalt des Dreiecks nach folgender Rechenregel
 * A = 0.25 * WURZEL((a+b+c)(a+b-c)(b+c-a)(c+a-b))
 *
 * Sollte der Ausdruck unter der Wurzel < 0 sein, wird eine Exception geworfen
 */
double Dreieck::berechneHeron2 ( )
{
   double zwischenergebnis = 0.0;
   zwischenergebnis = (laengeA + laengeB + laengeC)
         * (laengeA + laengeB - laengeC) * (laengeB + laengeC - laengeA)
         * (laengeC + laengeA - laengeB);
   if (zwischenergebnis < 0)
   {
      throw DreieckException(this, zwischenergebnis);
   }
   return (0.25 * sqrt(zwischenergebnis));
}

/**
 * Gibt die Daten des Dreiecks als String zurueck
 */
std::string Dreieck::toString()
{
   std::stringstream NumberStream;
   NumberStream << std::setprecision(2) << "[a:" << laengeA << "; b:" << laengeB
         << "; c: " << laengeC << "]";
   return (NumberStream.str());
}
