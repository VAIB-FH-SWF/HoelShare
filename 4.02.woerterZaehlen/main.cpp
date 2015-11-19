//==========================================================
//
//    Filename: main.cpp
//
// Description: Loesung zu Aufgabe 4.02, basierend auf dem Program 1.11.string
//
//     Version: 1.0
//     Created: 26.10.2015 18:17:01
//    Revision: none
//    Compiler: g++
//
//      Author: Sebastian Hoelscher, sebastian@hoelshare.de
//  Matrikelnr: 10050674
//
//==========================================================

#include <iomanip>   
#include <iostream>
#include "ZUSTAND.h"

using namespace std;

int main ( )
{
   int maxstring = 256;                      // Puffergroesse
   char text[maxstring];                     // Eingabepuffer
   char c;                                   // Hilfsvariable
   int i, summeWoerter;                      // Schleifenzaehler,Buchstabezaehler
   ZUSTAND aktZustand = LEER;
   cout << "***** Klein- und Grossbuchstaben abzaehlen *****\n";
   cout << "Geben Sie eine Textzeile ein: ";

   i = 0;
   while ((c = cin.get()) != '\n')
   {                                          // Einzelzeichen lesen
      text[i] = c;                            //  und im Feld ablegen
      i = i + 1;                              // Schleifenzaehler erhoehen
   }
   text[i] = '\0';                            // Zeichenkette abschliessen

   cout << "Der eingegebene Text lautet: '" << text << "'\n";

   summeWoerter = 0;
   // Woerter und andere Zeichen werden als WORT
   // nur SPACE, Tabs usw. werden als LEER gezaehlt
   for (i = 0; text[i] != '\0'; i += 1)
   {
      if(isspace(text[i]))
      {
         aktZustand = LEER;
      }
      else
      {
         // Wenn der Zustand nicht
         summeWoerter += (aktZustand != WORT ? 1 : 0);
         aktZustand = WORT;
      }
   }
   cout << setw(6) << summeWoerter << " Woerter\n";

   return (0);
}     // ----------  end of function main  ----------
