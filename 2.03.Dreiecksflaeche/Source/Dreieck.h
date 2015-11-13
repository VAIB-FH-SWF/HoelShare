//==========================================================
//
//	  Filename:	Dreieck.h
//
// Description: Definition eines Dreiecks
//
//	   Version:	1.0
// 	   Created:	19.10.2015 18:42:02
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================
#ifndef DREIECK_H_
#define DREIECK_H_

#include <string>

/**
 * Definiert ein Dreieck
 */
class Dreieck
{
   public:
      /**
       * Standardkonstruktor, die Seiten a,b,c koennen vorgegeben werden,
       * alternativ werden diese auf 0 gesetzt
       */
      Dreieck(double a = 0, double b = 0, double c = 0);

      /**
       * Gibt die Laenge der Seite A zurueck
       */
      double getLaengeA ( ) const
      {
         return (laengeA);
      }

      /**
       * Gibt die Laenge der Seite B zurueck
       */
      double getLaengeB() const
      {
         return (laengeB);
      }

      /**
       * Gibt die Laenge der Seite C zurueck
       */
      double getLaengeC() const
      {
         return (laengeC);
      }

      /**
       * Setzt die Laenge der Seite A
       */
      void setLaengeA (double a)
      {
         laengeA = a;
      }

      /**
       * Setzt die Laenge der Seite B
       */
      void setLaengeB (double b)
      {
         laengeB = b;
      }

      /**
       * Setzt die Laenge der Seite C
       */
      void setLaengeC (double c)
      {
         laengeC = c;
      }

      /**
       * Berechnet den Flaecheninhalt des Dreiecks
       */
      double berechneHeron1();

      /**
       * Berechnet den Flaecheninhalt des Dreiecks
       */
      double berechneHeron2();

      /**
       * Gibt die Daten des Dreiecks im String zurueck
       */
      std::string toString();
   private:
      double laengeA;            // Speichert die Seite A
      double laengeB;            // Speichert die Seite B
      double laengeC;            // Speichert die Seite C
      double berechneHilfeS();   // Berechnet die Hilfsvariable S
};



#endif /* DREIECK_H_ */
