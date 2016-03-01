//==========================================================
//
//    Filename: main.cpp
//
// Description: Loesung zu Aufgabe 4.01, basierend auf dem Program 1.11.string
//
//     Version: 1.0
//     Created: 26.10.2015 18:08:53
//    Revision: none
//    Compiler: g++
//
//      Author: Sebastian Hoelscher, sebastian@hoelshare.de
//  Matrikelnr: 10050674
//
//==========================================================

#include <iomanip>   
#include <iostream>  

using namespace std;

/**
 * 
 * @return Fehlerhafter Programablauf?
 */
int main ( )
{
   int maxstring = 256;                      // Puffergroesse
   char text[maxstring];                     // Eingabepuffer
   char c;                                   // Hilfsvariable
   int i, summeal, summenr;                  // Schleifenzaehler,Buchstabezaehler

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

   summeal = summenr = 0;
   for (i = 0; text[i] != '\0'; i += 1)
   {
      if (isalpha(text[i]))
         summeal = summeal + 1;
      if (isdigit(text[i]))
         summenr = summenr + 1;
   }
   cout << setw(6) << summeal << " Buchstaben\n";
   cout << setw(6) << summenr << " Ziffern\n";

   return (0);
}     // ----------  end of function main  ----------
