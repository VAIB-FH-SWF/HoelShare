//==========================================================
//
//	  Filename:	unendlicheReihen.cpp
//
// Description: Die Datei spiegelt die Loesung der Aufgabe
//							1.02 wider, Unendliche Reihen.
//
//	   Version:	1.0
// 	   Created:	29.09.2015 13:41:42
//	  Revision:	none
//	  Compiler:	g++
//
//	    Author:	Sebastian Hoelscher, sebastian@hoelshare.de
//	Matrikelnr:	10050674
//
//==========================================================

#include <iostream>
#include <iomanip>

//----------------------------------------------------------
//  Hauptprogramm
//----------------------------------------------------------
int
main ()
{
   std::cout << "Praktikum 'Programmierung mit C++ 1' / Blatt 1 / Aufgabe 1.2\n";
   std::cout << "Summenbildung bei unendlichen Reihen\n\n";

   int n; 									// Anzahl der Summanden
   int width = 18; 							// Ausgabebreite der Summe
   int precision = 16; 						// Nachkommastellen Summe
   double summe, vergleichssumme; 			// Reihensumme (Ergebnis)
   double summand;							// Hilfsvariable

   //--------------------------------------------------------
   //  Summation der Geometrischen Reihe
   //--------------------------------------------------------
   summe = 0.0;
   summand = 1.0;
   n = 0;
   do // vergleichssumme benoetigt keinen dummy Inital-Wert
   {
      vergleichssumme = summe;					// Die alte Summe zum Vergleich speichern
      summe = summe + summand;
      summand = 0.5 * summand;
      n++;
   }
   while(summe != vergleichssumme);
   std::cout << "Summe der Geometrischen Reihe von 1..." << n << ": ";
   std::cout << std::fixed << std::setw (width) << std::setprecision (precision)
         << std::dec << summe << "\n";
   return 0;
}

