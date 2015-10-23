//==========================================================
//
//	  Filename:	InputHandler.cpp
//
// Description: Realisierung des Eingabe Handlings
//
//	   Version:	1.0
// 	   Created:	19.10.2015 17:51:11
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================

#include "InputHandler.h"
#include "Dreieck.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/**
 * Liesst ueber die Konsole eine vollstaendige Zeile ein
 */
std::string InputHandler::leseString (std::string aufforderung)
{
   std::string zeile = "";
   if (!aufforderung.empty())
   {
      std::cout << aufforderung;
   }
   getline(std::cin, zeile);
   return (zeile);
}

/**
 * liesst eine Zeile ein und versucht diese ohne Fehler in eine Gleitkommazahl
 * umzuwandeln, sollte ein Fehler auftreten, wird es erneut ueber die Console eingelesen
 */
double InputHandler::leseGleitkomma (std::string aufforderung)
{
   char *err;
   double value = 0;
   std::string wert = leseString(aufforderung);
   value = strtod(wert.c_str(), &err);
   if (*err != 0)
   {
      delete err;
      return (leseGleitkomma(aufforderung));
   }
   delete err;
   return (value);
}

/**
 * Liesst eine Gleitkommazahl ein und schneidet den Dezimalteil ab
 */
int InputHandler::leseGanzzahl (std::string aufforderung)
{
   return ((int) leseGleitkomma(aufforderung));
}

/**
 * Liesst die drei Seiten eines Dreiecks ein
 * Negative Werte sind unzulaessig und werden in positive umgewandelt
 */
Dreieck InputHandler::leseDreieck ( )
{
   double a = InputHandler::leseGleitkomma("Bitte gib die Seitenlänge A ein: ");
   double b = InputHandler::leseGleitkomma("Bitte gib die Seitenlänge B ein: ");
   double c = InputHandler::leseGleitkomma("Bitte gib die Seitenlänge C ein: ");
   /**
    * Da bei der Konstruktion eines Dreiecks nur Positive Werte Sinnvoll sind,
    * werden die Negativen negiert
    */
   a = (a < 0 ? -a : a);
   b = (b < 0 ? -b : b);
   c = (c < 0 ? -c : c);

   return (Dreieck(a, b, c));
}

